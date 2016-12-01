#include "easywsclient.hpp"
//#include "easywsclient.cpp" // <-- include only if you don't want compile separately
#ifdef _WIN32
#pragma comment( lib, "ws2_32" )
#include <WinSock2.h>
#endif
#include <assert.h>
#include <stdio.h>
#include <string>

#include <sstream>
#include <vector>
#include <iostream>
#include <cstdlib>
 #include "Board.h"

//hacky fix
#include <sstream>

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

int conv2int(std::string x);
std::string conv2str(int x);

void split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

using easywsclient::WebSocket;
static WebSocket::pointer ws = NULL;


std::string password = "PersiaRocks!";
std::string user = "Red Obiwan77";

std::string otherPlayer;


Board* myBoard1;
Board* myBoard2;
Deck* myDeck;



int getGameCode(std::vector<std::string> inputVector){
    //std::atoi(inputVector[i].c_str())

    if(inputVector[0] == "GAME" && inputVector[2] == "MOVE" && inputVector[4] == "PLAYER" && inputVector[6] == "PLACED" && inputVector[8] == "AT"){

        std::cout << "We gonna place tile: " << inputVector[7] << "at " << inputVector[9] << "," << inputVector[10] << std::endl;

        Tile* newTile = myDeck->getTile(std::atoi(inputVector[7].c_str()));
//        Tile* newTile = myDeck.getTile(16);
        for(int i = 0; i < std::atoi(inputVector[11].c_str())/90; i++){
        	 newTile->rotateL();
        }

        myBoard1->addTile(newTile,std::atoi(inputVector[9].c_str()),std::atoi(inputVector[10].c_str()));
        myBoard1->exportBoardState();

        ws->send("boardstate exported");

    }
    else if(inputVector[0] == "THIS" && inputVector[1] == "IS" && inputVector[2] == "SPARTA!"){

        string output = "JOIN ";
        output.append(password);
        ws->send(output);
	}
    else if(inputVector[0] == "HELLO!"){
    	std::string output = "I AM ";
    	output.append(user);
    	ws->send(output);
	}
	else if(inputVector[0] == "NEW" && inputVector[1] == "CHALLENGE" && inputVector[3] == "YOU" &&
	 inputVector[4] == "WILL" && inputVector[5] == "PLAY" && (inputVector[7] == "MATCH" || inputVector[7] == "MATCHES")){
	}
	else if(inputVector[0] == "BEGIN" && inputVector[1] == "ROUND" && inputVector[3] == "OF"){
	   myBoard1 = new Board();
       myBoard2 = new Board();
    }
	else if(inputVector[0] == "YOUR" && inputVector[1] == "OPPONENT" && inputVector[2] == "IS" &&
		 inputVector[3] == "PLAYER"){
        otherPlayer = inputVector[4];
	}
	else if(inputVector[0] == "STARTING" && inputVector[1] == "TILE" && inputVector[2] == "IS" &&
			inputVector[4] == "AT"){
	}
	else if(inputVector[0] == "THE" && inputVector[1] == "REMAINING" && inputVector[3] == "TILES" &&
			inputVector[4] == "ARE"){
	}
	else if(inputVector[0] == "MATCH" && inputVector[1] == "BEGINS" && inputVector[2] == "IN" &&
			inputVector[4] == "SECONDS"){
	}
	else if(inputVector[0] == "MAKE" && inputVector[1] == "YOUR" && inputVector[2] == "MOVE" &&
		inputVector[3] == "IN" && inputVector[4] == "GAME" && inputVector[6] == "WITHIN" &&
		inputVector[8] == "SECOND:" && inputVector[9] == "MOVE" && inputVector[11] == "PLACE" ){

        if(inputVector[5] == "A"){

            int tileNum = conv2int(inputVector[12]);

            Tile* newTile =  myDeck->getTile(tileNum);

        	//below this im just testing output move to server

        	std::string outputString;

//    			cout << "tileNum: " << newTile->tileNum << endl;
    			int abort = myBoard1->makeRandomMove(newTile);
    			if(abort != 9999){
    				outputString = "GAME A MOVE ";
    				outputString.append(inputVector[10]);
    				outputString.append("PLACE ");
    				outputString.append(inputVector[12]);
    				outputString.append(" AT ");
    	//            tempString = patch::to_string(40);
    				outputString.append(patch::to_string(newTile->xPos - 40));
    				outputString.append(" ");
    				outputString.append(patch::to_string(40 - newTile->yPos));
    				outputString.append(" ");
    				outputString.append(patch::to_string(90 * newTile->getRotations()));
    				outputString.append(" ");

    				int meepNum = newTile->determineMeeple();

    				if(meepNum == 0 || myBoard1->meepleCount == 0){

    					outputString.append("NONE");

    				}
    				else{

    					outputString.append("TIGER ");
    					outputString.append(patch::to_string(meepNum));
    					myBoard1->meepleCount--;
    				}
    			}
    			else{
    				outputString = "GAME A MOVE ";
    				outputString.append(inputVector[10]);
    				outputString.append("TILE ");
    				outputString.append(inputVector[12]);
    				outputString.append("UNPLACEABLE PASS");
    			}
                ws->send(outputString);

    		myBoard1->exportBoardState();

        }
        else if(inputVector[5] == "B"){

        	int tileNum = conv2int(inputVector[12]);

            Tile* newTile =  myDeck->getTile(tileNum);

        	//below this im just testing output move to server

        	std::string outputString;

//    			cout << "tileNum: " << newTile->tileNum << endl;
			int abort = myBoard2->makeRandomMove(newTile);
			if(abort != 9999){
				outputString = "GAME A MOVE ";
				outputString.append(inputVector[10]);
				outputString.append("PLACE ");
				outputString.append(inputVector[12]);
				outputString.append(" AT ");
	//            tempString = patch::to_string(40);
				outputString.append(patch::to_string(newTile->xPos - 40));
				outputString.append(" ");
				outputString.append(patch::to_string(40 - newTile->yPos));
				outputString.append(" ");
				outputString.append(patch::to_string(90 * newTile->getRotations()));
				outputString.append(" ");

				int meepNum = newTile->determineMeeple();

				if(meepNum == 0 || myBoard2->meepleCount == 0){

					outputString.append("NONE");

				}
				else{

					outputString.append("TIGER ");
					outputString.append(patch::to_string(meepNum));
					myBoard2->meepleCount--;
				}
			}
			else{
				outputString = "GAME A MOVE ";
				outputString.append(inputVector[10]);
				outputString.append("TILE ");
				outputString.append(inputVector[12]);
				outputString.append("UNPLACEABLE PASS");
			}
            ws->send(outputString);

        	myBoard2->exportBoardState();

        }

	}
	else if(inputVector[0] == "GAME" && inputVector[2] == "MOVE" && inputVector[4] == "PLAYER" &&
		inputVector[6] == "PLACED" && inputVector[8] == "AT"){
        if(inputVector[5] == otherPlayer){
            int tileNum = conv2int(inputVector[7]);

            Tile* newTile = myDeck->getTile(tileNum);


            for(int i = 0; i < std::atoi(inputVector[11].c_str())/90; i++){
                newTile->rotateL();
            }

            int tempX = std::atoi(inputVector[9].c_str());
            int tempY = std::atoi(inputVector[10].c_str());


            if(inputVector[1] == "A"){

                myBoard1->addTile(newTile,tempX,tempY);


            }
            else if(inputVector[1] == "B"){

                myBoard2->addTile(newTile,tempX,tempY);

            }
        }


	}
	else if(inputVector[0] == "THANK" && inputVector[1] == "YOU" && inputVector[2] == "FOR" && inputVector[3] == "PLAYING!" &&
		inputVector[4] == "GOODBYE"){
	}
    else if(inputVector[0] == "END" && inputVector[1] == "OF" && inputVector[2] == "ROUND"){
        delete myBoard1;
        delete myBoard2;
    }


}


void handle_message(const std::string & message)
{
    printf(">>> %s\n", message.c_str());
    // ws->send("hello");
    // if (message == "world") { ws->close(); }

    std::vector<std::string> inputVector;

    split(message,' ',inputVector);

    for(int i = 0; i < inputVector.size(); i++){

        std::cout << "index: " << i << " vec: " << inputVector[i] << std::endl;

    }

    getGameCode(inputVector);


}

int main()
{
#ifdef _WIN32
    INT rc;
    WSADATA wsaData;

    rc = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (rc) {
        printf("WSAStartup Failed.\n");
        return 1;
    }
#endif

    myBoard1 = new Board();
    myBoard2 = new Board();
    myDeck = new Deck();
    ws = WebSocket::from_url("ws://localhost:8126/foo");
    assert(ws);
    ws->send("goodbye");

    // ws->poll();
    // ws->poll(-1);
    // ws->dispatch(handle_message);
    while (ws->getReadyState() != WebSocket::CLOSED) {
      ws->poll();
      ws->dispatch(handle_message);
    }
    // ws->close();
    delete ws;
#ifdef _WIN32
    WSACleanup();
#endif
    return 0;
}


int conv2int(std::string x){

    if(x == "JJJJ-")
        return 0;
    else if(x =="LLLL-")
        return 1;
    else if(x == "TLJT-")
        return 2;
    else if(x == "TLTT-")
        return 3;
    else if(x == "JJJJX")
        return 4;
    else if(x == "JLLL-")
        return 5;
    else if(x == "TLJTP")
        return 6;
    else if(x == "TLTTP")
        return 7;
    else if(x == "JJTJX")
        return 8;
    else if(x == "LLJJ-")
        return 9;
    else if(x == "JLTT-")
        return 10;
    else if(x == "TLLT-")
        return 11;
    else if(x == "TTTT-")
        return 12;
    else if(x == "JLJL-")
        return 13;
    else if(x == "JLTTB")
        return 14;
    else if(x == "TLLTB")
        return 15;
    else if(x == "TJTJ-")
        return 16;
    else if(x == "LJLJ-")
        return 17;
    else if(x == "TLTJ-")
        return 18;
    else if(x == "LJTJ-")
        return 19;
    else if(x == "TJJT-")
        return 20;
    else if(x == "LJJJ-")
        return 21;
    else if(x == "TLTJD")
        return 22;
    else if(x == "LJTJD")
        return 23;
    else if(x == "TJTT-")
        return 24;
    else if(x == "JLLJ-")
        return 25;
    else if(x == "TLLL-")
        return 26;
    else if(x == "TLLLC")
        return 27;

}

string conv2str(int x){


    if(x == 0)
        return "JJJJ-";
    else if(x ==1)
        return "LLLL-";
    else if(x == 2)
        return "TLJT-";
    else if(x == 3)
        return "TLTT-";
    else if(x == 4)
        return "JJJJX";
    else if(x == 5)
        return "JLLL-";
    else if(x == 6)
        return "TLJTP";
    else if(x == 7)
        return "TLTTP";
    else if(x == 8)
        return "JJTJX";
    else if(x == 9)
        return "LLJJ-";
    else if(x == 10)
        return "JLTT-";
    else if(x == 11)
        return "TLLT-";
    else if(x == 12)
        return "TTTT-";
    else if(x == 13)
        return "JLJL-";
    else if(x == 14)
        return "JLTTB";
    else if(x == 15)
        return "TLLTB";
    else if(x == 16)
        return "TJTJ-";
    else if(x == 17)
        return "LJLJ-";
    else if(x == 18)
        return "TLTJ-";
    else if(x == 19)
        return "LJTJ-";
    else if(x == 20)
        return "TJJT-";
    else if(x == 21)
        return "LJJJ-";
    else if(x == 22)
        return "TLTJD";
    else if(x == 23)
        return "LJTJD";
    else if(x == 24)
        return "TJTT-";
    else if(x == 25)
        return "JLLJ-";
    else if(x == 26)
        return "TLLL-";
    else if(x == 27)
        return "TLLLC";


}

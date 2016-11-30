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

int gameID;
Board myBoard;
Deck myDeck;


int getGameCode(std::vector<std::string> inputVector){
    //std::atoi(inputVector[i].c_str())
    
    if(inputVector[0] == "GAME" && inputVector[2] == "MOVE" && inputVector[4] == "PLAYER" && inputVector[6] == "PLACED" && inputVector[8] == "AT"){
        
        std::cout << "We gonna place tile: " << inputVector[7] << "at " << inputVector[9] << "," << inputVector[10] << std::endl;
        
        Tile* newTile = myDeck.getTile(std::atoi(inputVector[7].c_str()));
//        Tile* newTile = myDeck.getTile(16);
        for(int i = 0; i < std::atoi(inputVector[11].c_str())/90; i++){
        	 newTile->rotateL();
        }

        
        
        myBoard.addTile(newTile,std::atoi(inputVector[9].c_str()),std::atoi(inputVector[10].c_str()));
        myBoard.exportBoardState();
        
        
        
        
        
    }
    else if(inputVector[0] == "THIS" && inputVector[1] == "IS" && inputVector[2] == "SPARTA!"){
    	std::cout << "sparta works" << std::endl;

	}
    else if(inputVector[0] == "HELLO!"){
	}
	else if(inputVector[0] == "NEW" && inputVector[1] == "CHALLENGE" && inputVector[3] == "YOU" &&
	 inputVector[4] == "WILL" && inputVector[5] == "PLAY" && (inputVector[7] == "MATCH" || inputVector[7] == "MATCHES")){
	}
	else if(inputVector[0] == "BEGIN" && inputVector[1] == "ROUND" && inputVector[3] == "OF"){
	}
	else if(inputVector[0] == "YOUR" && inputVector[1] == "OPPONENT" && inputVector[2] == "IS" &&
		 inputVector[3] == "PLAYER"){
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
	}
	else if(inputVector[0] == "GAME" && inputVector[2] == "MOVE" && inputVector[4] == "PLAYER" &&
		inputVector[6] == "PLACED" && inputVector[8] == "AT"){
	}
	else if(inputVector[0] == "GAME" && inputVector[2] == "MOVE" && inputVector[4] == "PLAYER" &&
		inputVector[6] == "PLACED" && inputVector[8] == "AT"){
	}
	else if(inputVector[0] == "THANK" && inputVector[1] == "YOU" && inputVector[2] == "FOR" && inputVector[3] == "PLAYING!" &&
		inputVector[4] == "GOODBYE"){
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

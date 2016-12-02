#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include "Board.h"

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

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

std::string password = "TIGERZONE\n";
std::string user = "TEAMT IAMT\n";
char buffer[256];

std::string otherPlayer;

int sockfd;

Board* myBoard1;
Board* myBoard2;
Deck* myDeck;


////////////////////////////////////////////////////////////////////////
//                                                                    // 
//          game receive handler                                      //
//                                                                    //
////////////////////////////////////////////////////////////////////////


int getGameCode(){
    //std::atoi(inputVector[i].c_str())
    std::vector<std::string> inputVector;
    
    std::string strbuf(buffer);
    std::cout << "strbuf: " << strbuf << std::endl;
    
    split(strbuf,' ',inputVector);
    
    inputVector[inputVector.size()-1].erase(inputVector[inputVector.size()-1].size()-1);
    inputVector[inputVector.size()-1].erase(inputVector[inputVector.size()-1].size()-1);

    
    cout << "size of vector: " << inputVector.size() << std::endl;
    cout << "size of last term: " << inputVector[inputVector.size()-1].size() << endl;
    
    for(int i = 0; i < inputVector[inputVector.size()-1].size(); i++){
        cout << "index: " << i << " " << inputVector[inputVector.size()-1].at(i) << endl;
    }
    
    // for(int i = 0; i < inputVector.size(); i++){
        
    //     std::cout << "index : " << i << " " << inputVector[i] << std::endl;
        
    // }
    
    // cout << "first test: " << (inputVector[0] == "THIS") << std::endl;
    // cout << "2nd test: " << (inputVector[1] == "IS") << std::endl;
    // cout << "3rd test: " << (inputVector[2] == "SPARTA!") << std::endl;
    
    // cout << "sizeof test: " << sizeof(inputVector[2]) << std::endl;
    
//     if(inputVector[0] == "GAME" && inputVector[2] == "MOVE" && inputVector[4] == "PLAYER" && inputVector[6] == "PLACED" && inputVector[8] == "AT"){

//         std::cout << "We gonna place tile: " << inputVector[7] << "at " << inputVector[9] << "," << inputVector[10] << std::endl;

//         Tile* newTile = myDeck->getTile(std::atoi(inputVector[7].c_str()));
// //        Tile* newTile = myDeck.getTile(16);
//         for(int i = 0; i < std::atoi(inputVector[11].c_str())/90; i++){
//              newTile->rotateL();
//         }

//         myBoard1->addTile(newTile,std::atoi(inputVector[9].c_str()),std::atoi(inputVector[10].c_str()));
//         myBoard1->exportBoardState();

        

//     }
    if(inputVector[0] == "THIS" && inputVector[1] == "IS" && inputVector[2] == "SPARTA!"){
        std::cout << "we got this is sparta ayy" << std::endl;
        string output = "JOIN ";
        output.append(password);
        bzero(buffer,256);
        strcpy(buffer, output.c_str());
        write(sockfd, buffer, strlen(buffer));
    }
    else if(inputVector[0] == "HELLO!"){
        std::cout << "got in hello\n";
        std::string output = "I AM ";
        output.append(user);
        bzero(buffer,256);
        strcpy(buffer, output.c_str());
        write(sockfd, buffer, strlen(buffer));
    }
    else if(inputVector[0] == "WELCOME" && inputVector[2] == "PLEASE"){
        std::cout << "got please\n";
    }
    else if(inputVector[0] == "NEW" && inputVector[1] == "CHALLENGE" && inputVector[3] == "YOU" &&
     inputVector[4] == "WILL" && inputVector[5] == "PLAY" && (inputVector[7] == "MATCH" || inputVector[7] == "MATCHES")){
        cout << "got in challenge\n";
        int tempNum = std::atoi(inputVector[6].c_str());
        return tempNum;
        
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

//              cout << "tileNum: " << newTile->tileNum << endl;
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
                
                

            myBoard1->exportBoardState();

        }
        else if(inputVector[5] == "B"){

            int tileNum = conv2int(inputVector[12]);

            Tile* newTile =  myDeck->getTile(tileNum);

            //below this im just testing output move to server

            std::string outputString;

//              cout << "tileNum: " << newTile->tileNum << endl;
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
            

            myBoard2->exportBoardState();

        }
        
        bzero(buffer,256);
        strcpy(buffer, output.c_str());
        write(sockfd, buffer, strlen(buffer));

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



////////////////////////////////////////////////////////////////////////
//                                                                    // 
//          main                                                      //
//                                                                    //
////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    
    //the main two io functions:
    // 1.  n = read(sockfd, buffer, 255);
    // 2.  n = write(sockfd, buffer, strlen(buffer));
    // make sure to clear buffer with:  bzero(buffer,256);      
    
    int portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    
    myBoard1 = new Board();
    myBoard2 = new Board();
    myDeck = new Deck();

    // char buffer[256];
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
    // printf("Please enter the message: ");
    bzero(buffer,256);
    
    //this is sparta
    n = read(sockfd, buffer, 255);
    
    getGameCode();
    
    bzero(buffer,256);
    
    //hello
    n = read(sockfd, buffer, 255);
    
    getGameCode();
    cout << "gets out of send gamecode\n";
    bzero(buffer,256);
    
    //welcome message, will probably delete getgamecode from this one
    n = read(sockfd, buffer, 255);
    
    getGameCode();
    
    bzero(buffer,256);
    
    while(true){
        
        //new challenge
        int matchNum = read(sockfd, buffer, 255);
        
        for(int i = 0; i < matchNum; i++){
            
            bzero(buffer,256);
    
            //begin round
            read(sockfd, buffer, 255);
            
            
            bzero(buffer,256);
    
            //your opponent is player yada yada
            read(sockfd, buffer, 255);
            
            getGameCode();
            
            bzero(buffer,256);
    
            //starting tile at/ do nothing
            read(sockfd, buffer, 255);
            
            getGameCode();
            
            bzero(buffer,256);
    
            //the remaining tiles / do nothing
            read(sockfd, buffer, 255);
            
            getGameCode();
            
            bzero(buffer,256);
    
            //match begins in 15
            n = read(sockfd, buffer, 255);
            
            getGameCode();
            
            bzero(buffer,256);
            
            while(true){
                //make your move
                n = read(sockfd, buffer, 255);
                
                if(n == 9999){
                    break;
                }
                
                getGameCode();
                
                bzero(buffer,256);
            }   
            
        }
        
    }
    
    
    // if(getGameCode(buffer) != 9999){
        
    // }
    // else{
        
    // }
    
    //right now test server
    //ip: 10.136.73.30
    //port: 4444
    
    
    
    
    // fgets(buffer,255,stdin);
    // n = write(sockfd, buffer, strlen(buffer));
    // if (n < 0) 
    //      error("ERROR writing to socket");
    // bzero(buffer,256);
    // n = read(sockfd, buffer, 255);
    // if (n < 0) 
    //      error("ERROR reading from socket");
    // printf("%s\n", buffer);
    close(sockfd);
    return 0;
}




////////////////////////////////////////////////////////////////////////
//                                                                    // 
//          conversion functions                                      //
//                                                                    //
////////////////////////////////////////////////////////////////////////



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
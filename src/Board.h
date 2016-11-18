#ifndef BOARD_H
#define BOARD_H


#include <stdlib.h>
#include <iostream>

#include "Feature.cpp"
#include "Deck.cpp"
#include "Tile.cpp"
#include "Player.cpp"

using namespace std;


class Board{
    
public:
	  
    
    Board();
    void addTile();
    void printBoard();
    string exportBoardState();
    int calcScore();
    struct loc {
        int x;
        int y;
    };
    

private:

    Tile gameGraph[80][80];
	Feature fields[10];
	Feature cities[10];
	Feature roads[10];
	Feature monasteries[10];
	bool turn;
	Player Player1;
	Player Player2;
    loc openLocArray[100];
    int sizeX;
    int sizeY;
		
};

inline Board::Board( )          // constructor
{
    sizeX=80;
    sizeY=80;
    cout << "in constructor \n";
    turn = true;                
   
}

#endif
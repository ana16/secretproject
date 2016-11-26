#ifndef BOARD_H
#define BOARD_H


#include <stdlib.h>
#include <iostream>

#include "Feature.h"
#include "Deck.h"
#include "Tile.h"
#include "Player.cpp"

using namespace std;


class Board{
    
public:
	  
    Tile* getTile(int x, int y);
    Board();
    void addTile(Tile* tileToAdd,int x,int y);
    void printBoard();
    string exportBoardState();
    int calcScore();
    struct loc {
        int x;
        int y;
    };
    void availPosAroundTile(Tile);

    

private:

    Tile* gameGraph[80][80];
	Feature fields[10];
	Feature cities[10];
	Feature roads[10];
	Feature monasteries[10];
	bool turn;
	Player Player1;
	Player Player2;
    vector<loc> openLocVector;
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

#ifndef Board_h
#define Board_h

#include <iostream>
#include "Board.h"


using namespace std;



int main(){
     Board myBoard;
     myBoard.addTile();
     myBoard.printBoard();
    
    return 0;
}

void Board::addTile(){
        
        if(turn){
        //ai will rotate for us, we just need to place it, keeps api simple
        int test1 [15] = {0, 2, 0, 1, 1, 1, 0, 2, 0, 0, 0, 0, 2, 3, 0};
        int test2 [15];
		//pop tile from stack
        
        Tile firstTile = Tile(test);
        cout << "Tile has been accessed\n";
        //check available positions on board from array
        gameGraph[25][25] = firstTile;
        cout << "Tile has been placed\n";
        
        //check if placement is legal
        
        //place tile and connect the sides 
            
        //check which meeple placements are legal
            
        //if it is city/road connect it to a feature
            
        }

	return;	
	
}

void Board::printBoard(){
		//print rows one by one
    cout << "made it into printboard";
        for (int i = 0; i<sizeX; i++){
            
            for(int j = 0; j < sizeY; j++){
                
                if(&gameGraph[i][j] != NULL){
                    
                    cout<< "0";
                    
                }
            }
        }
	}

	string Board::exportBoardState(){
		//need to find best format for exporting, needs to be quick to deliver to ai
		return "";
	}
	
	int Board::calcScore(){

		return 0;
	};


#endif












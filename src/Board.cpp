#ifndef Board_h
#define Board_h

#include <iostream>
#include "Board.h"


using namespace std;



int main(){
     Board myBoard;
     myBoard.addTile();
    
    return 0;
}

void Board::addTile(){
        
        if(turn){
        //ai will rotate for us, we just need to place it, keeps api simple
        int test [15] = {0, 2, 0, 1, 1, 1, 0, 2, 0, 0, 0, 0, 2, 3, 0};
		//pop tile from stack
        
        Tile firstTile = Tile(test);
        cout << "Tile has been accessed";
        //check available positions on board from array
        gameGraph[25][25] = firstTile;
        cout << "Tile has been placed";
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
                    
                    cout<< "write something here";
                    
                }
            }
        }
	}

	string exportBoardState(){
		//need to find best format for exporting, needs to be quick to deliver to ai
	}
	
	int calcScore(){

		
	};


#endif












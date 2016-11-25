#ifndef Board_h
#define Board_h
#include <vector>
#include <iostream>
#include "Board.h"
#include <typeinfo>
#include "Deck.cpp"

#include <fstream>

using namespace std;



int main(){
//    Board myBoard;
//    myBoard.addTile();
//    // myBoard.printBoard();
//
//    myBoard.exportBoardState();

	cout << "main in board\n";
	Deck myDeck;


    return 0;
}

void Board::addTile(){
        
        if(turn){
        //ai will rotate for us, we just need to place it, keeps api simple
        int test1 [15] = {2, 2, 1, 2, 0, 0, 0, 0, 2, 1, 0, 3};
        int test2 [15] = {0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 0, 4};
		//pop tile from stack
        
        Tile firstTile = Tile(test1);
        Tile secondTile = Tile(test2);
        cout << "Tile has been accessed\n";
       
        gameGraph[40][40] = firstTile;
        gameGraph[40][41] = secondTile;
        cout << "Tile has been placed\n";
        firstTile.xPos = 40;
        firstTile.yPos = 40;
        secondTile.xPos = 40;
        secondTile.yPos = 41;
        
        //check available positions on board from array
        // availPosAroundTile(firstTile);
            
        //check if placement is legal
        
        //place tile and connect the sides 
            
        //check which meeple placements are legal
            
        //if it is city/road connect it to a feature
            
        }

	return;	
	
}

void Board::printBoard(){
		//print rows one by one
    cout << "made it into printboard\n";
        for (int i = 0; i<sizeX; i++){
            
            for(int j = 0; j < sizeY; j++){
                
                if(gameGraph[i][j].isEmpty==0){
                    
                    cout<< i << ","<< j << "is full";
                    
                }
            }
        }
	}

	string Board::exportBoardState(){
		//need to find best format for exporting, needs to be quick to deliver to ai
		
//		cout << "1\n";
		ofstream myFile;
		myFile.open("../graphics/exportBoard.txt");
//		myFile << "what what";
		// myFile.close();
		
//		cout << "2\n";
		
		for(int i = 0; i < 80; i++){
			for(int j = 0; j < 80; j++){
				
//				cout << "3\n";
				
				if(gameGraph[i][j].isEmpty == 1){
					
					 myFile << "0;";
					
					
				}
				else{
					
					myFile << gameGraph[i][j].exportTileInfo() << ";";
					
					
				}
				
				
			}
			myFile << "\n";
			
			
			
		}
		
		
		
		
		
		return "";
	}
	
	int Board::calcScore(){

		return 0;
	}
    
    void Board::availPosAroundTile(Tile tile){

		if (tile.North == NULL) {
			int x = tile.xPos;
			int y = tile.yPos;

			loc mypoint;
			mypoint.x = x-1;
			mypoint.y = y;

			openLocVector.push_back(mypoint);

		}
		if (tile.East == NULL) {
			int x = tile.xPos;
			int y = tile.yPos;

			loc mypoint;
			mypoint.x = x;
			mypoint.y = y+1;

			openLocVector.push_back(mypoint);

		}
		if (tile.South == NULL) {
			int x = tile.xPos;
			int y = tile.yPos;

			loc mypoint;
			mypoint.x = x+1;
			mypoint.y = y;

			openLocVector.push_back(mypoint);

		}
		if (tile.West == NULL) {
			int x = tile.xPos;
			int y = tile.yPos;

			loc mypoint;
			mypoint.x = x;
			mypoint.y = y-1;

			openLocVector.push_back(mypoint);

		}
    
		cout << "Board has :" << openLocVector.size() << " elements\n";

    }

    

#endif












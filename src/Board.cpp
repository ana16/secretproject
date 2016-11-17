#include <iostream>
#include "Feature.cpp"
#include "Deck.cpp"
#include "Tile.cpp"

using namespace std;

 struct loc {
        int x;
        int y;
 }
    

class Board{
	
private:
	
	Tile gameGraph[][];
	Feature fields[];
	Feature cities[];
	Feature roads[];
	Feature monasteries[];
	bool turn;
	Player Player1;
	Player Player2;
    loc openLocArray[];
		
public:
	
	Board{
        //x is row number
        //y is column number
		int x = 50, y = 50;
        Tile gameGraph[x][y];
        Player1.meeples = 7;
        Player2.meeples = 7;
        
		
		
		
	
	
   }
	
	
	void addTile(){
        
        if(turn){
        //ai will rotate for us, we just need to place it, keeps api simple
        
		//pop tile from stack
        Tile firstTile = Tile[0, 2, 0, 1, 1, 1, 0, 2, 0, 0, 0, 0, 2, 3, 0];
        //check available positions on board from array
        gameGraph[x/2][y/2] = firstTile;
        //check if placement is legal
        
        //place tile and connect the sides 
            
        //check which meeple placements are legal
            
        //if it is city/road connect it to a feature
            
        }

		
	
	}
	
	void printBoard(){
		//print rows one by one
        
        for (i = 0; i<x; i++){
            
            for(j = 0; j < y; j++){
                
                if(gameGraph[i][j] != NULL){
                    
                    cout << "x: " << x << "\n";
                    
                    cout << "y: " << y << "\n";
                    
                }
            }
        }
	}
	
	string exportBoardState(){
		//need to find best format for exporting, needs to be quick to deliver to ai
	}
	
	int calcScore(){
		
		
		
		
		
		
	}
	
};

int main(){
    
    
    addTile();
    printBoard();
    
    return 0;
}















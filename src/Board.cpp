#include <iostream>
// #include "Feature.cpp"
// #include "Deck.cpp"


using namespace std;

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
		
public:
	
	Board{
		int x = 50, y = 50;
        Tile gameGraph[x][y];
        Player1.meeples = 7;
        Player2.meeples = 7;
        
		
		
		
	}
	
	
	
	void addTile(Tile tile){
        
        if(turn){
        //ai will rotate for us, we just need to place it, keeps api simple
        
		//pop tile from stack
        
        //check available positions on board from array
        
        //check if placement is legal
        
        //place tile and connect the sides 
            
        //check which meeple placements are legal
            
        //if it is city/road connect it to a feature
            
        }

		
	
	}
	
	void printBoard(){
		//print rows one by one
	}
	
	string exportBoardState(){
		//need to find best format for exporting, needs to be quick to deliver to ai
	}
	
	int calcScore(){
		
		
		
		
		
		
	}
	
};

















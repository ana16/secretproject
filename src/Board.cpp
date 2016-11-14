#include <iostream>
// #include "Feature.cpp"


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
		
		
		
		
	}
	
	
	
	void addTile(Tile tile){
		//ai will rotate for us, we just need to place it, keeps api simple
		
		
	
	}
	
	void printBoard(){
		//print to console for debug
	}
	
	string exportBoardState(){
		//need to find best format for exporting, needs to be quick to deliver to ai
	}
	
	int calcScore(){
		
		
		
		
		
		
	}
	
};

















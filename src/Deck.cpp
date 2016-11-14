#include <iostream>
#include "Feature.cpp"
#include "Tile.cpp"
#include <stack>


using namespace std;



class Deck{
	
private:
	
	stack<Tile> tileStack;
	int size;
	
public:
	
	Deck{
		//do stuff, make tiles and shuffle
	}
	
	Tile pop(){
		return tileStack.pop();
	}
	
	int getSize(){
		return tileStack.size();
	}
};

















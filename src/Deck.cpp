#include <iostream>
#include "Feature.cpp"
#include "Tile.cpp"
#include <string>
#include <stack>
#include <vector>


using namespace std;



class Deck{
	
private:
	
	stack<Tile> tileStack;
	int size;
	
	
public:
	
	Deck() {};
	void pop();
	int getSize();
	
//0-field(jungle), 1-city(lake), 2-road(gametrail), 3-monestary(den)
	int type[4] = {0, 1, 2, 3};

//0-none, 1-boar, 2-buffalo, 3- deer
	int animal[4] = {0, 1, 2, 3};

	Deck(int features[]) {};
		
//R1 - R12: starting with upper left corner, going clockwise
	//R1-R12, center, amount of tile, animal


//went by column
	
	int tZero[15] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 };
	/*int t1[15] = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0];
	int t2[15] = [0, 2, 0, 1, 1, 1, 0, 0, 0, 0, 2, 0, 2, 1, 0];
	int t3[15] = [0, 2, 0, 1, 1, 1, 0, 2, 0, 0, 2, 0, 2, 1, 0];
	int t4[15] = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 0];
	int t5[15] = [0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0];
	int t6[15] = [0, 2, 0, 1, 1, 1, 0, 0, 0, 0, 2, 0, 2, 2, 1];
	//^ has boar(shield)
	int t7[15] = [0, 2, 0, 1, 1, 1, 0, 2, 0, 0, 2, 0, 2, 2, 1];
	//^ has boar(shield)
	int t8[15] = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 2, 0];
	int t9[15] = [1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 5, 0];
	int t10[15] = [0, 0, 0, 1, 1, 1, 0, 2, 0, 0, 2, 0, 2, 1, 0];
	int t11[15] = [0, 2, 0, 1, 1, 1, 1, 1, 1, 0, 2, 0, 0, 3, 0];
	int t12[15] = [0, 2, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 2, 1, 0];
	int t13[15] = [0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 3, 0];
	int t14[15] = [0, 0, 0, 1, 1, 1, 0, 2, 0, 0, 2, 0, 2, 2, 2];
	//^ has buffalo(shield)
	int t15[15] = [0, 2, 0, 1, 1, 1, 1, 1, 1, 0, 2, 0, 0, 2, 2];
	//^ has buffalo(shield)
	int t16[15] = [0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 8, 0];
	int t17[15] = [1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 3, 0];
	int t18[15] = [0, 2, 0, 1, 1, 1, 0, 2, 0, 0, 0, 0, 2, 3, 0];
	//^ starting tile
	int t19[15] = [1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 2, 0];
	int t20[15] = [0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 9, 0];
	int t21[15] = [1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0];
	int t22[15] = [0, 2, 0, 1, 1, 1, 0, 2, 0, 0, 0, 0, 2, 2, 3];
	//^ has deer(shield)
	int t23[15] = [1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 2, 3];
	//^ has deer(shield)
	int t24[15] = [0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 2, 4, 0];
	int t25[15] = [0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0];
	int t26[15] = [0, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 0]; */
};
	
	 void Deck::pop(){
		return tileStack.pop();
	}
	
	int Deck::getSize(){
		return tileStack.size();
	}


















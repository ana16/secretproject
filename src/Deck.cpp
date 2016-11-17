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

//0-field(jungle), 1-city(lake), 2-road(gametrail), 3-monestary(den)
	int type[4] = {0, 1, 2, 3};

	Deck(String features[], string options){
		
//R1 - R12: starting with upper left corner, going clockwise


	}
//went by column
	Deck t0(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1);
	Deck t1(1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
	Deck t2(0, 2, 0, 1, 1, 1, 0, 0, 0, 0, 2, 0, 2, 1);
	Deck t3(0, 2, 0, 1, 1, 1, 0, 2, 0, 0, 2, 0, 2, 1);
	Deck t4(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4);
	Deck t5(0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4);
	Deck t6(0, 2, 0, 1, 1, 1, 0, 0, 0, 0, 2, 0, 2, 2);
	//^ has boar(shield)
	Deck t7(0, 2, 0, 1, 1, 1, 0, 2, 0, 0, 2, 0, 2, 2);
	//^ has boar(shield)
	Deck t8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 2);
	Deck t9(1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 5);
	Deck t10(0, 0, 0, 1, 1, 1, 0, 2, 0, 0, 2, 0, 2, 1);
	Deck t11(0, 2, 0, 1, 1, 1, 1, 1, 1, 0, 2, 0, 0, 3);
	Deck t12(0, 2, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 2, 1);
	Deck t13(0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 3);
	Deck t14(0, 0, 0, 1, 1, 1, 0, 2, 0, 0, 2, 0, 2, 2);
	//^ has buffalo(shield)
	Deck t15(0, 2, 0, 1, 1, 1, 1, 1, 1, 0, 2, 0, 0, 2);
	//^ has buffalo(shield)
	Deck t16(0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 8);
	Deck t17(1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 3);
	Deck t18(0, 2, 0, 1, 1, 1, 0, 2, 0, 0, 0, 0, 2, 3);
	//^ starting tile
	Deck t19(1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 2);
	Deck t20(0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 9);
	Deck t21(1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5);
	Deck t22(0, 2, 0, 1, 1, 1, 0, 2, 0, 0, 0, 0, 2, 2);
	//^ has deer(shield)
	Deck t23(1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 2);
	//^ has deer(shield)
	Deck t24(0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 2, 4);
	Deck t25(0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2);
	Deck t26(0, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3);
	}
	
	Tile pop(){
		return tileStack.pop();
	}
	
	int getSize(){
		return tileStack.size();
	}
};

















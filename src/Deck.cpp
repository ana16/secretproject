
#include <iostream>
#include <cstdlib> //for srand and rand
#include "Feature.h"
#include "Tile.h"
#include <stack>
#include <time.h> //for srand seed
#include "Deck.h"


//using namespace std;

Tile* Deck::getTile(int x){
	
	Tile* newTile = new Tile(t[x]);
	
	return newTile;
}

Deck::Deck(){
	cout << "this runs\n";

	srand(time(NULL));

	int deadLockCount = 0;

	t[18][9]--; //decrease starting tile by one, we're gonna add at the end, to place at top of stack


		Tile* newTile;
	while(true){

		int randNum = rand() % 28;
//			cout << randNum << endl;

		if(t[randNum][9] != 0){
			t[randNum][9]--;
			newTile = new Tile(t[randNum]);
			tileStack.push(newTile);
		}
		else{
			if(deadLockCount > 1000){
				break;
			}
			else{
				deadLockCount++;
			}
		}


	}

	newTile = new Tile(t[18]);
	tileStack.push(newTile);

//	Tile printer;
//	cout << "stacksize: " << tileStack.size() << endl;
//
//	int origStackSize = tileStack.size();
//	for(int i = 0; i < origStackSize; i++){
//		printer = tileStack.top();
//		cout << "i: " << i << ",  " << printer.tileNum << endl;
//		tileStack.pop();
//	}

	
}

// //0-field(jungle), 1-city(lake), 2-road(gametrail), 3-monestary(den)
// 	int type[4] = {0, 1, 2, 3};

// //0-none, 1-boar, 2-buffalo, 3- deer
// 	int animal[4] = {0, 1, 2, 3};

// Deck(string features[]){


// }
//went by column
/*
int t0[12] = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0];
int t1[12] = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1];
int t2[12] = [0, 2, 0, 1, 1, 1, 0, 0, 0, 0, 2, 0, 2, 1, 0, 2];
int t3[12] = [0, 2, 0, 1, 1, 1, 0, 2, 0, 0, 2, 0, 2, 1, 0, 3];
int t4[12] = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 0, 4];
int t5[12] = [0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0, 5];
int t6[12] = [0, 2, 0, 1, 1, 1, 0, 0, 0, 0, 2, 0, 2, 2, 1, 6];
//^ has boar(shield)
int t7[12] = [0, 2, 0, 1, 1, 1, 0, 2, 0, 0, 2, 0, 2, 2, 1, 7];
//^ has boar(shield)
int t8[12] = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 2, 0, 8];
int t9[12] = [1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 5, 0, 9];
int t10[12] = [0, 0, 0, 1, 1, 1, 0, 2, 0, 0, 2, 0, 2, 1, 0, 10];
int t11[12] = [0, 2, 0, 1, 1, 1, 1, 1, 1, 0, 2, 0, 0, 3, 0, 11];
int t12[12] = [0, 2, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 2, 1, 0, 12];
int t13[12] = [0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 3, 0, 13];
int t14[12] = [0, 0, 0, 1, 1, 1, 0, 2, 0, 0, 2, 0, 2, 2, 2, 14];
//^ has buffalo(shield)
int t15[12] = [0, 2, 0, 1, 1, 1, 1, 1, 1, 0, 2, 0, 0, 2, 2, 15];
//^ has buffalo(shield)
int t16[12] = [0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 8, 0, 16];
int t17[12] = [1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 3, 0, 17];
int t18[12] = [0, 2, 0, 1, 1, 1, 0, 2, 0, 0, 0, 0, 2, 3, 0, 18];
//^ starting tile
int t19[12] = [1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 2, 0, 19];
int t20[12] = [0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 9, 0, 20];
int t21[12] = [1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 21];
int t22[12] = [0, 2, 0, 1, 1, 1, 0, 2, 0, 0, 0, 0, 2, 2, 3, 22];
//^ has deer(shield)
int t23[12] = [1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 2, 3, 23];
//^ has deer(shield)
int t24[12] = [0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 2, 4, 0, 24];
int t25[12] = [0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 25];
int t26[12] = [0, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 0, 26];
*/

//N, S, E, W, ne, nw, se, sw, center, tile amount, animal, tile #
//0-Jungle, 1-Lake, 2-Game-trail, 3-Den
	//0-nothing, 1-buffalo, 2-crocodile, 3-deer, 4-boar

//	int t0[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0};
//	int t1[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1};
//	int t2[12] = {2, 0, 1, 2, 0, 0, 0, 0, 2, 1, 0, 2};
//	int t3[12] = {2, 2, 1, 2, 0, 0, 0, 0, 2, 1, 0, 3};
//	int t4[12] = {0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 0, 4};
//	int t5[12] = {0, 1, 1, 1, 0, 0, 1, 1, 0, 4, 0, 5};
//	int t6[12] = {2, 0, 1, 2, 0, 0, 0, 0, 2, 2, 4, 6};
//	//^ has boar(shield)
//	int t7[12] = {2, 2, 1, 2, 0, 0, 0, 0, 2, 2, 4, 7};
//	//^ has boar(shield)
//	int t8[12] = {0, 2, 0, 0, 0, 0, 0, 0, 3, 2, 0, 8};
//	int t9[12] = {1, 0, 1, 0, 1, 0, 0, 0, 1, 5, 0, 9};
//	int t10[12] = {0, 2, 1, 2, 0, 0, 0, 0, 2, 1, 0, 10};
//	int t11[12] = {2, 1, 1, 2, 0, 0, 1, 0, 0, 3, 0, 11};
//	int t12[12] = {2, 2, 2, 2, 0, 0, 0, 0, 2, 1, 0, 12};
//	int t13[12] = {0, 0, 1, 1, 0, 0, 0, 0, 1, 3, 0, 13};
//	int t14[12] = {0, 2, 1, 2, 0, 0, 0, 0, 2, 2, 1, 14};
//	//^ has buffalo(shield)
//	int t15[12] = {2, 1, 1, 2, 0, 0, 1, 0, 0, 2, 1, 15};
//	//^ has buffalo(shield)
//	int t16[12] = {2, 2, 0, 0, 0, 0, 0, 0, 2, 8, 0, 16};
//	int t17[12] = {1, 1, 0, 0, 0, 0, 0, 0, 0, 3, 0, 17};
//	int t18[12] = {2, 2, 1, 0, 0, 0, 0, 0, 2, 3, 0, 18};
//	//^ starting tile
//	int t19[12] = {1, 2, 0, 0, 0, 0, 0, 0, 2, 1, 0, 19};
//	int t20[12] = {2, 0, 0, 2, 0, 0, 0, 0, 2, 9, 0, 20};
//	int t21[12] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 21};
//	int t22[12] = {2, 2, 1, 0, 0, 0, 0, 0, 2, 2, 3, 22};
//	//^ has deer(shield)
//	int t23[12] = {1, 2, 0, 0, 0, 0, 0, 0, 2, 2, 3, 23};
//	//^ has deer(shield)
//	int t24[12] = {2, 2, 0, 2, 0, 0, 0, 0, 2, 4, 0, 24};
//	int t25[12] = {0, 1, 1, 0, 0, 0, 0, 0, 0, 2, 0, 25};
//	int t26[12] = {2, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 26};
//	int t27[12] = {2, 1, 1, 1, 0, 0, 1, 1, 1, 2, 2, 27};


Tile* Deck::pop(){

	Tile* returnVal = tileStack.top();
	
	tileStack.pop();
	
	return returnVal;
}

int Deck::getSize(){
	return tileStack.size();
}
















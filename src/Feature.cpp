
#include <iostream>
//#include "Tile.cpp"
 #include <string>
#include "Feature.h"


using namespace std;


Feature::Feature() {

	name = "Feature";
};


string Feature::getName(){
	return name;
}

//make tile class then put tileList here

bool Feature::getComplete(){
	//check if feature is bounded
	return 0;
}

int Feature::addTile(Tile* tileToAdd){
	//was void, but I want to return a legality int
	int addCheck = 0;
	for(int i = 0; i < 9; i++){

		if(tileList.empty() == false && tileList[i] == tileToAdd){
			addCheck = 1;
			break;
		}

	}
	if(addCheck == 0){
		tileList.push_back(tileToAdd);
	}




}

int Feature::getPotential(){
	//very basic point potential
}

void Feature::releaseMeeples(){
	//return meeples to the players
}

Field::Field(){

	name = "Field";

}

string Field::getName(){
	return name;
}

City::City(){

	name = "City";

}

string City::getName(){
	return name;
}

Road::Road(){

	name = "Road";

}

string Road::getName(){
	return name;
}

Monastery::Monastery(){

	name = "Monastery";

}

string Monastery::getName(){
	return name;
}



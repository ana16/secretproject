
#include <iostream>
//#include "Tile.cpp"
 #include <string>
#include <vector>
#include "Feature.h"


//using namespace std;
using std::cout;
using std::endl;


Feature::Feature() {

	name = "Feature";
};

Feature::Feature(Tile* firstTile){

	addTile(firstTile);

}

void Feature::changePointers(Feature* origPointer, Feature* newPointer){

	int sizeToUse = tileList.size();

	for(int i = 0; i < sizeToUse; i++){
		tileList[i]->repointPointers(origPointer, newPointer);
		newPointer->addTile(tileList[i]);
	}


}

int Feature::getTileListSize(){

	return tileList.size();

}

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

	int tempSize = tileList.size();
	int addCheck = 0;
	for(int i = 0; i < tempSize; i++){

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

Field::Field(Tile* startingTile){

	name = "Field";
	addTile(startingTile);

}

string Field::getName(){
	return name;
}

City::City(){

	name = "City";

}

City::City(Tile* startingTile){

	name = "City";
	addTile(startingTile);

}

string City::getName(){
	return name;
}

Road::Road(){

	name = "Road";

}

Road::Road(Tile* startingTile){

	name = "Road";
	addTile(startingTile);

}

string Road::getName(){
	return name;
}

Monastery::Monastery(){

	name = "Monastery";

}

Monastery::Monastery(Tile* startingTile){

	name = "Monastery";
	addTile(startingTile);

}

string Monastery::getName(){
	return name;
}



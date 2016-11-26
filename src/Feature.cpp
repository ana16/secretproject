
#include <iostream>
//#include "Tile.cpp"
 #include <string>
#include "Feature.h"


using namespace std;


Feature::Feature() {};


string Feature::getName(){
	return name;
}

//make tile class then put tileList here

bool Feature::getComplete(){
	//check if feature is bounded
	return 0;
}

int Feature::addTile(){
	//was void, but I want to return a legality int
}

int Feature::getPotential(){
	//very basic point potential
}

void Feature::releaseMeeples(){
	//return meeples to the players
}









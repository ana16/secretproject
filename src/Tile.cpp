

#include <iostream>
#include <sstream>
#include <string>
#include "Feature.h"
#include "Tile.h"



Tile::Tile() {
	North = South = East = West = 0;
	xPos = 1;
	yPos = 1;
	isEmpty=1;
	rotations = 0;

}
Tile::Tile(int featureInput[]){
	isEmpty=0;
	North = South = East = West = 0;

	Feature* toBeAdded;


	for(int i = 0; i < 9; i++){
		if(featureInput[i] == 0){
			toBeAdded = new Field();
			std::cout << "added field\n";
		}
		else if(featureInput[i] == 1){
			toBeAdded = new City;
			std::cout <<"added city\n";
		}
		else if(featureInput[i] == 2){
			toBeAdded = new Road;
			std::cout <<"added road\n";
		}
		else if(featureInput[i] == 3){
			toBeAdded = new Monastery;
			std::cout <<"added monastery\n";
		}
		Features[i] = toBeAdded;
	}

	//animal is 10
	animalCount[featureInput[10]]++;
	
	tileNum = featureInput[11];
	
	rotations = 0;

	
	//animal = featureInput[14];
	
	toBeAdded = NULL;//not sure if necessary
	delete toBeAdded; //Not sure if this removes last pointer or deleted pointer variable.
}

void Tile::rotateR(){
	//
}
void Tile::rotateL(){
	//
}

std::string Tile::exportTileInfo(){
	
	std::string outputString;
	std::string tempString;
	std::ostringstream conversion;

	conversion << tileNum;
	outputString.append(conversion.str());
	conversion.str("");

	conversion << ",";
	outputString.append(conversion.str());
	conversion.str("");

	conversion << rotations;
	outputString.append(conversion.str());
//		std::cout << outputString << endl;

	return outputString;
}


















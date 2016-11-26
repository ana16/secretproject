

#include <iostream>
#include <sstream>
#include <string>
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

	//animal is 10
	animalCount[featureInput[10]]++;
	
	tileNum = featureInput[11];
	
	rotations = 0;

	//now do edge cases/connect the features for individual tiles

	if(tileNum == 0){
		Features[0] = new Field();
		Features[1] = Features[0];
		Features[2] = Features[0];
		Features[3] = Features[0];
		Features[4] = Features[0];
		Features[5] = Features[0];
		Features[6] = Features[0];
		Features[7] = Features[0];
		Features[8] = Features[0];
	}
	else if(tileNum == 1){
		Features[0] = new City();
		Features[1] = Features[0];
		Features[2] = Features[0];
		Features[3] = Features[0];
	}
	else if(tileNum == 2){
		Features[0] = new Road();
		Features[3] = Features[0];

		Features[5] = new Field();

		Features[4] = new Field();
		Features[7] = Features[4];
		Features[1] = Features[4];
		Features[6] = Features[4];

		Features[2] = new City();
	}
	else if(tileNum == 4) {
		Features[0] = new Field();
		Features[1] = Features[0];
		Features[2] = Features[0];
		Features[3] = Features[0];
		Features[4] = Features[0];
		Features[5] = Features[0];
		Features[6] = Features[0];
		Features[7] = Features[0];
		Features[8] = new Monastery();
	}
	else if(tileNum == 5){
		Features[0] = new Field();
		Features[4] = Features[0];
		Features[5] = Features[0];

		Features[2] = new City();
		Features[3] = Features[2];
		Features[1] = Features[2];
	}
	else if(tileNum == 13) {
		Features[0] = new Field();
		Features[4] = Features[0];
		Features[5] = Features[0];
		Features[1] = new Field();
		Features[6] = Features[1];
		Features[7] = Features[1];
		Features[2] = new City();
		Features[3] = Features[2];
	}
	else if(tileNum == 17) {
		Features[0] = new City();
		Features[1] = new City();
		Features[2] = new Field();
		Features[3] = Features[2];
		Features[4] = Features[2];
		Features[5] = Features[2];
		Features[6] = Features[2];
		Features[7] = Features[2];
	}
	else{
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
		toBeAdded = NULL;//not sure if necessary
		delete toBeAdded; //Not sure if this removes last pointer or deleted pointer variable.

	}

	//for reference
	//N, S, E, W, ne, nw, se, sw, center, tile amount, animal, tile #
	
	//animal = featureInput[14];
	

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


int Tile::addToFeature(int featureNum,Tile* tileToAdd){
	//returns 1 if it's safe to delete the original feature
	if(Features[featureNum] != NULL){
		Features[featureNum]->addTile(tileToAdd);
		return 1;
	}
	return 0;
}

Feature* Tile::getFeature(int index){
	if(this != NULL){
		return Features[index];
	}
	else{
		return NULL;
	}


}


void Tile::repointFeature(Feature* featureInput, int index){

	for(int i = 0; i < 9; i++){
		if(Features[i] != NULL && Features[i] == Features[index] && i != index){
			Features[i] = featureInput;
		}

	}

	delete Features[index];

	Features[index] = featureInput;



}


void Tile::printTileFeatures(){

	for(int i = 0; i < 9; i++){
		if(Features[i] != NULL){
			cout << "pointer: " << Features[i] << " , name: " << Features[i]->getName() << endl;
		}
		else{
			cout << "NULL" << endl;
		}

	}

}









#include <iostream>
#include <sstream>
#include <string>
#include "Tile.h"

using std::cout;
using std::endl;


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
		Features[0] = new Field(this);
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
		Features[0] = new City(this);
		Features[1] = Features[0];
		Features[2] = Features[0];
		Features[3] = Features[0];
	}

	else if(tileNum == 2){
		Features[0] = new Road(this);
		Features[3] = Features[0];

		Features[2] = new City(this);

		Features[1] = new Field(this);
		Features[4] = Features[1];
		Features[6] = Features[1];
		Features[7] = Features[1];

		Features[5] = new Field(this);

	}
	else if(tileNum == 3) {
		Features[0] = new Road(this);
		Features[1] = new Road(this);
		Features[3] = new Road(this);

		Features[2] = new City(this);

		Features[4] = new Field(this);
		Features[6] = Features[4];

		Features[5] = new Field(this);

		Features[7] = new Field(this);
	}
	else if(tileNum == 4) {
		Features[0] = new Field(this);
		Features[1] = Features[0];
		Features[2] = Features[0];
		Features[3] = Features[0];
		Features[4] = Features[0];
		Features[5] = Features[0];
		Features[6] = Features[0];
		Features[7] = Features[0];

		Features[8] = new Monastery(this);

	}
	else if(tileNum == 5) {
		Features[0] = new Field(this);
		Features[4] = Features[0];
		Features[5] = Features[0];

		Features[1] = new City(this);
		Features[2] = Features[1];
		Features[3] = Features[1];
	}
	else if(tileNum == 6) {
		Features[0] = new Road(this);
		Features[3] = Features[0];

		Features[1] = new Field(this);
		Features[4] = Features[1];
		Features[6] = Features[1];
		Features[7] = Features[1];

		Features[5] = new Field(this);

		Features[2] = new City(this);

	}
	else if(tileNum == 7) {
		Features[0] = new Road(this);
		Features[1] = new Road(this);
		Features[3] = new Road(this);

		Features[2] = new City(this);

		Features[4] = new Field(this);
		Features[6] = Features[4];

		Features[5] = new Field(this);
		Features[7] = new Field(this);
	}
	else if(tileNum == 8) {
		Features[0] = new Field(this);
		Features[2] = Features[0];
		Features[3] = Features[0];
		Features[4] = Features[0];
		Features[5] = Features[0];
		Features[6] = Features[0];
		Features[7] = Features[0];


		Features[1] = new Road(this);

		Features[8] = new Monastery(this);
	}
	else if(tileNum == 9) {
		Features[0] = new City(this);
		Features[2] = Features[0];

		Features[1] = new Field(this);
		Features[3] = Features[1];
		Features[5] = Features[1];
		Features[6] = Features[1];
		Features[7] = Features[1];
		//check with dillon

	}
	else if(tileNum == 10) {
		Features[0] = new Field(this);
		Features[4] = Features[0];
		Features[5] = Features[0];
		Features[6] = Features[0];

		Features[1] = new Road(this);
		Features[3] = Features[1];

		Features[7] = new Field(this);

		Features[2] = new City(this);
	}
	else if(tileNum == 11) {
		Features[0] = new Road(this);
		Features[3] = Features[0];

		Features[1] = new City(this);
		Features[2] = Features[1];

		Features[4] = new Field(this);
		Features[7] = Features[4];

		Features[5] = new Field(this);
	}
	else if(tileNum == 12) {
		Features[0] = new Road(this);
		Features[1] = new Road(this);
		Features[2] = new Road(this);
		Features[3] = new Road(this);

		Features[4] = new Field(this);
		Features[5] = new Field(this);
		Features[6] = new Field(this);
		Features[7] = new Field(this);
	}
	else if(tileNum == 13) {
		Features[0] = new Field(this);
		Features[4] = Features[0];
		Features[5] = Features[0];

		Features[1] = new Field(this);
		Features[6] = Features[1];
		Features[7] = Features[1];

		Features[2] = new City(this);
		Features[3] = Features[2];
	}
	else if(tileNum == 14) {
		Features[0] = new Field(this);
		Features[4] = Features[0];
		Features[5] = Features[0];
		Features[6] = Features[0];

		Features[7] = new Field(this);

		Features[1] = new Road(this);
		Features[3] = Features[1];

		Features[2] = new City(this);
	}
	else if(tileNum == 15) {
		Features[0] = new Road(this);
		Features[3] = Features[0];

		Features[1] = new City(this);
		Features[2] = Features[1];

		Features[5] = new Field(this);

		Features[4] = new Field(this);
		Features[7] = Features[4];
	}
	else if(tileNum == 16) {
		Features[0] = new Road(this);
		Features[1] = Features[0];

		Features[2] = new Field(this);
		Features[4] = Features[2];
		Features[6] = Features[2];

		Features[3] = new Field(this);
		Features[5] = Features[3];
		Features[7] = Features[3];
	}
	else if(tileNum == 17) {
		Features[0] = new City(this);
		Features[1] = new City(this);

		Features[2] = new Field(this);
		Features[3] = Features[2];
		Features[4] = Features[2];
		Features[5] = Features[2];
		Features[6] = Features[2];
		Features[7] = Features[2];
	}
	else if(tileNum == 18) {
		Features[0] = new Road(this);
		Features[1] = Features[0];

		Features[2] = new City(this);

		Features[3] = new Field(this);
		Features[5] = Features[3];
		Features[7] = Features[3];

		Features[4] = new Field(this);
		Features[6] = Features[4];
	}
	else if(tileNum == 19) {
		Features[0] = new City(this);

		Features[1] = new Road(this);

		Features[2] = new Field(this);
		Features[4] = Features[2];
		Features[6] = Features[2];

		Features[3] = new Field(this);
		Features[5] = Features[3];
		Features[7] = Features[3];
	}
	else if(tileNum == 20) {
		Features[0] = new Road(this);
		Features[3] = Features[0];

		Features[5] = new Field(this);

		Features[1] = new Field(this);
		Features[2] = Features[1];
		Features[4] = Features[1];
		Features[6] = Features[1];
		Features[7] = Features[1];
	}
	else if(tileNum == 21)	{
		Features[0] = new City(this);

		Features[1] = new Field(this);
		Features[2] = Features[1];
		Features[3] = Features[1];
		Features[4] = Features[1];
		Features[5] = Features[1];
		Features[6] = Features[1];
		Features[7] = Features[1];
	}
	else if(tileNum == 22) {
		Features[0] = new Road(this);
		Features[1] = Features[0];

		Features[2] = new City(this);

		Features[3] = new Field(this);
		Features[5] = Features[3];
		Features[7] = Features[3];

		Features[4] = new Field(this);
		Features[6] = Features[4];
	}
	else if(tileNum == 23) {
		Features[0] = new City(this);

		Features[1] = new Road(this);

		Features[2] = new Field(this);
		Features[4] = Features[2];
		Features[6] = Features[2];

		Features[3] = new Field(this);
		Features[5] = Features[3];
		Features[7] = Features[3];

	}
	else if(tileNum == 24) {
		Features[0] = new Road(this);
		Features[1] = new Road(this);
		Features[3] = new Road(this);

		Features[5] = new Field(this);
		Features[7] = new Field(this);

		Features[2] = new Field(this);
		Features[4] = Features[2];
		Features[6] = Features[2];
	}
	else if(tileNum == 25) 	{
		Features[0] = new Field(this);
		Features[3] = Features[0];
		Features[4] = Features[0];
		Features[5] = Features[0];
		Features[6] = Features[0];
		Features[7] = Features[0];

		Features[1] = new City(this);
		Features[2] = new City(this);
	}
	else if(tileNum == 26) {
		Features[0] = new Road(this);

		Features[4] = new Field(this);
		Features[5] = Features[6];

		Features[1] = new City(this);
		Features[2] = Features[1];
		Features[3] = Features[1];

	}
	else if(tileNum == 27) {
		Features[0] = new Road(this);

		Features[4] = new Field(this);
		Features[5] = Features[6];

		Features[1] = new City(this);
		Features[2] = Features[1];
		Features[3] = Features[1];
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
	Feature* tmp;

	tmp = Features[0];
	//Rotating Faces
	Features[0] = Features[3];
	Features[3] = Features[1];
	Features[1] = Features[2];
	Features[2] = tmp;

	tmp = Features[4];
	//Rotating Corners
	Features[4] = Features[5];
	Features[5] = Features[7];
	Features[7] = Features[6];
	Features[6] = tmp;
}

void Tile::rotateL(){
	Feature* tmp;

	//Rotating Faces
	tmp = Features[0];
	Features[0] = Features[2];
	Features[2] = Features[1];
	Features[1] = Features[3];
	Features[3] = tmp;

	//Rotating corners
	tmp = Features[4];
	Features[4] = Features[6];
	Features[6] = Features[7];
	Features[7] = Features[5];
	Features[5] = tmp;
	rotations++;
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
		Features[featureNum]->addTile(tileToAdd);//<-this line
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

//	for(int i = 0; i < 9; i++){
//		if(Features[i] != NULL && Features[i] == Features[index] && i != index){
//			Features[i] = featureInput;
//		}
//
//	}

	Feature* oldPointer = Features[index];
	Feature* newPointer = featureInput;
	if(oldPointer != NULL && newPointer != NULL){
		Features[index]->changePointers(oldPointer,newPointer);
	}

////	delete Features[index]; //huge memory leak if you comment this
//
//	Features[index] = featureInput;



}

void Tile::repointPointers(Feature* origPointer, Feature* newPointer){

	for(int i = 0; i < 9; i++){
		if(Features[i] != NULL && Features[i] == origPointer){
			Features[i] = newPointer;
		}
	}
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







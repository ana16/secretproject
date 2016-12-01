/*
 * Tile.h
 *
 *  Created on: Nov 25, 2016
 *      Author: Matthew
 */

#ifndef TILE_H_
#define TILE_H_

#include <string>
#include "Feature.h"

class Feature;

class Tile{

private:
	//consider making this an array of Features
	//[regions,center,amt,animal]

	//   Feature* northEntity;
	//   Feature* southEntity;
	//   Feature* eastEntity;
	//   Feature* westEntity;
	// Feature* neEntity;
	// Feature* nwEntity;
	// Feature* seEntity;
	// Feature* swEntity;
	// Feature* centerEntity;
	Feature* Features[9] = {NULL};
	int animalCount[5];

    int rotations;



	int animal;


public:

	int tileNum;
	//make these private asap, make access functions
	Tile* North;
    Tile* South;
    Tile* East;
    Tile* West;
	int isEmpty;
	int xPos;
    int yPos;

	Tile();
	Tile(int featureInput[]);

	int addToFeature(int featureNum,Tile* tileToAdd);
	void repointFeature(Feature* featureInput,int index);

	void repointPointers(Feature* origPointer, Feature* newPointer);

	Feature* getFeature(int index);
	
	int getRotations();

	void rotateR();
	void rotateL();

	std::string exportTileInfo();

	void printTileFeatures();
	
	int determineMeeple();


};





#endif /* TILE_H_ */

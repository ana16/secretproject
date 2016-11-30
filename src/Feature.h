/*
 * Feature.h
 *
 *  Created on: Nov 25, 2016
 *      Author: Matthew
 */

#ifndef FEATURE_H_
#define FEATURE_H_

#include <string>
#include <vector>
#include "Tile.h"

//using namespace std;
using std::vector;
using std::string;

class Tile;

class Feature{

private:

	vector<Tile*> tileList;
	std::string name;
	int tileCoordsX[80];
	bool isComplete;
	int scoringInt;
	int owner;
	int potentialPoints;
	//add meeple array here


public:

	Feature();
	Feature(Tile* firstTile);
	virtual std::string getName();

	//make tile class then put tileList here

	bool getComplete();

	int addTile(Tile* tileToAdd);

	int getPotential();

	void releaseMeeples();

	void changePointers(Feature* origPointer, Feature* newPointer);

	int getTileListSize();

};


class Field : public Feature{
private:

	std::string name;



public:

Field();
Field(Tile* startingTile);
std::string getName();

};

class Road : public Feature{
private:


	std::string name;


public:

Road();
std::string getName();
Road(Tile* startingTile);

};
class City : public Feature{
private:

	std::string name;



public:

City();
City(Tile* startingTile);
std::string getName();

};
class Monastery : public Feature{
private:


	std::string name;


public:

Monastery();
Monastery(Tile* startingTile);
std::string getName();

};




#endif /* FEATURE_H_ */

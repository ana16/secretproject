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

using namespace std;

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
	virtual std::string getName();

	//make tile class then put tileList here

	bool getComplete();

	int addTile(Tile* tileToAdd);

	int getPotential();

	void releaseMeeples();

};


class Field : public Feature{
private:

	std::string name;



public:

Field();
std::string getName();

};

class Road : public Feature{
private:


	std::string name;


public:

Road();
std::string getName();

};
class City : public Feature{
private:

	std::string name;



public:

City();
std::string getName();

};
class Monastery : public Feature{
private:


	std::string name;


public:

Monastery();
std::string getName();

};




#endif /* FEATURE_H_ */

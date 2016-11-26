/*
 * Feature.h
 *
 *  Created on: Nov 25, 2016
 *      Author: Matthew
 */

#ifndef FEATURE_H_
#define FEATURE_H_

#include <string>

class Feature{

private:

	std::string name;
	int tileCoordsX[80];
	bool isComplete;
	int scoringInt;
	int owner;
	int potentialPoints;
	//add meeple array here


public:
	Feature();
	std::string getName();

	//make tile class then put tileList here

	bool getComplete();

	int addTile();

	int getPotential();

	void releaseMeeples();

};


class Field : public Feature{
private:





public:




};

class Road : public Feature{
private:





public:




};
class City : public Feature{
private:





public:




};
class Monastery : public Feature{
private:





public:




};




#endif /* FEATURE_H_ */

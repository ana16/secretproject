#ifndef FEATURE_H
#define FEATURE_H

#include <iostream>
// #include <string>


using namespace std;



class Feature{
	
private:

	string name;
	int tileCoordsX[];
	bool isComplete;
	int scoringInt;
	int owner;
	int potentialPoints;
	//add meeple array here
	

public:
	
	string getName(){
		return name;
	}
	
	//make tile class then put tileList here
	
	bool getComplete(){
		//check if feature is bounded
		return 0;
	}
	
	int addTile(){
		//was void, but I want to return a legality int
	}
	
	int getPotential(){
		//very basic point potential
	}
	
	void releaseMeeples(){
		//return meeples to the players
	}
	
	
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


/*
int main(){
	
	Field hello;
	Road fd;
	City jdkfljs;
	Monastery mojdfls;
	
	return 0;
};
*/




#endif






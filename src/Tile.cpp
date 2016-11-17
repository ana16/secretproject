#include <iostream>
#include "Feature.cpp"


using namespace std;

class Tile{
	
private:
	//consider making this an array of Features
	//[regions,center,amt,animal]
	
	// Feature* northEntity;
	// Feature* southEntity;
	// Feature* eastEntity;
	// Feature* westEntity;
	// Feature* neEntity;
	// Feature* nwEntity;
	// Feature* seEntity;
	// Feature* swEntity;
	// Feature* centerEntity;
	Feature* Features[];
	int animal;
	
public:
	
	Tile(int featureInput[]){
		Features[] = new Features[15];
		Features* toBeAdded;
		for(int i = 0; i < 12; i++){
			if(featureInput[i] == 0){
				toBeAdded = new Field;
			}
			else if(featureInput[i] == 1){
				toBeAdded = new City;
			}
			else if(featureInput[i] == 2){
				toBeAdded = new Road;
			}
			else if(featureInput[i] == 3){
				toBeAdded = new Monastery;
			}
			Features[i] = toBeAdded;
		}
		
		animal = featureInput[14];
		
		toBeAdded = NULL;//not sure if necessary
		delete toBeAdded; //Not sure if this removes last pointer or deleted pointer variable.
	}
	
	void rotateR(){
		//
	}
	void rotateL(){
		
	}
	
	
	
	
};

















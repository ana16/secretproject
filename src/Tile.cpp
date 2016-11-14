#include <iostream>
#include "Feature.cpp"


using namespace std;

class Tile{
	
private:
	//consider making this an array of Strings
	//[north,south,east,west,ne,nw,se,sw,center]
	
	Feature* northEntity;
	Feature* southEntity;
	Feature* eastEntity;
	Feature* westEntity;
	Feature* neEntity;
	Feature* nwEntity;
	Feature* seEntity;
	Feature* swEntity;
	Feature* centerEntity;
	Feature* Features[];
	
public:
	
	Tile(int featureInput[],string options){
		Features[] = new Features[9];
		Features* toBeAdded;
		for(int i = 0; i < 9; i++){
			if(featureInput == 0){
				toBeAdded = new Feature;
			}
			else if(featureInput == 1){
				toBeAdded = new Feature;
			}
			else if(featureInput == 2){
				toBeAdded = new Feature;
			}
			else if(featureInput == 3){
				toBeAdded = new Feature;
			}
			Features[i] = toBeAdded;
		}
		toBeAdded = NULL;//not sure if necessary
		delete toBeAdded; //Not sure if this removes last pointer or deleted pointer variable.
	}
	
	void rotateR(){
		//
	}
	void rotateL(){
		
	}
	
	
	
	
};

















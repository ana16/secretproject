#ifndef TILE_HEADER
#define TILE_HEADER

#include <iostream>
#include <sstream>
#include <string>
#include "Feature.cpp"


using namespace std;

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
	Feature* Features[9];
	int animalCount[5];
	int tileNum;
    int rotations;


    
	int animal;

	
public:
	
	//make these private asap, make access functions
	Tile* North;
    Tile* South;
    Tile* East;
    Tile* West;
	int isEmpty;
	int xPos;
    int yPos;
    
	Tile() {
        North = South = East = West = 0;
        xPos = 1;
        yPos = 1;
        isEmpty=1;
        rotations = 0;
           
    };
	Tile(int featureInput[]){
        isEmpty=0;
		North = South = East = West = 0;
		Feature positionArr [15];
		Feature* toBeAdded;
        
        toBeAdded = positionArr;
        
		for(int i = 0; i < 9; i++){
			if(featureInput[i] == 0){
				toBeAdded = new Field();
                cout << "added field\n";
			}
			else if(featureInput[i] == 1){
				toBeAdded = new City;
                cout <<"added city\n";
			}
			else if(featureInput[i] == 2){
				toBeAdded = new Road;
                cout <<"added road\n";
			}
			else if(featureInput[i] == 3){
				toBeAdded = new Monastery;
                cout <<"added monastery\n";
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
	};
	
	void rotateR(){
		//
	};
	void rotateL(){
		//
	};
	
	string exportTileInfo(){
		
		string outputString;
		string tempString;
		ostringstream conversion;

//		if(tileNum < 10){
//			conversion << 0;
//		}
		conversion << tileNum;
		outputString.append(conversion.str());
		conversion.str("");

		conversion << ",";
		outputString.append(conversion.str());
		conversion.str("");

		conversion << rotations;
		outputString.append(conversion.str());
//		cout << outputString << endl;

		return outputString;
	}
    
	
	
	
};

#endif
















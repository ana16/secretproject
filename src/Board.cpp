
#include <vector>
#include <iostream>
#include "Board.h"
#include <typeinfo>
#include "Deck.h"

#include <fstream>

//using namespace std;
using std::cout;
using std::endl;
using std::ofstream;



// int main(){
// //    Board myBoard;
// //    myBoard.addTile();
// //    // myBoard.printBoard();
// //
// //    myBoard.exportBoardState();

// //	cout << "main in board\n";
// 	Deck myDeck;

// 	//main problem is if a tile connects two separate fields, one of the fields gets overwritten without adding the other field, need to find a way to add the two fields together


// 	Board myBoard;

// 	Tile* tempTile = myDeck.pop();

// 	myBoard.addTile(tempTile,40,40);


// 	while(myDeck.getSize() > 0){

// 		tempTile = myDeck.pop();
// 		cout << "tileNum: " << tempTile->tileNum << endl;
// 		myBoard.makeRandomMove(tempTile);

// 	}

// //	this runs
// //	in constructor
// //	tile: 18 added to  (40,40)
// //	tileNum: 16
// //	tile: 16 added to  (40,39)
// //	tileNum: 4
// //	tile: 4 added to  (39,40)
// //	tileNum: 20
// //	tile: 20 added to  (40,41)
// //	tileNum: 16
// //	tile: 16 added to  (40,38)
// //	tileNum: 4
// //	tile: 4 added to  (41,39)
// //	tileNum: 21
// //	tile: 21 added to  (39,39)
// //	tileNum: 4
// //	tile: 4 added to  (38,40)
// //	tileNum: 20
// //	tile: 20 added to  (41,38)
// //	tileNum: 20
// //	tile: 20 added to  (38,39)
// //	tileNum: 16
// //	tile: 16 added to  (41,41)


// //	//debug with this test
// //	int t16[12] = {2, 2, 0, 0, 0, 0, 0, 0, 2, 8, 0, 16};
// //	int t20[12] = {2, 0, 0, 2, 0, 0, 0, 0, 2, 9, 0, 20};
// //	int t1[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1};
// //	int t21[12] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 21};
// //	int t5[12] = {0, 1, 1, 1, 0, 0, 1, 1, 0, 4, 0, 5};
// //	int t4[12] = {0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 0, 4};
// //
// //	tempTile = new Tile(t16);
// //
// //	myBoard.makeRandomMove(tempTile);
// //
// //	tempTile = new Tile(t4);
// //
// //	myBoard.makeRandomMove(tempTile);
// //
// //	tempTile = new Tile(t20);
// //
// //	myBoard.makeRandomMove(tempTile);
// //
// //	tempTile = new Tile(t16);
// //
// //	myBoard.makeRandomMove(tempTile);
// //
// //	tempTile = new Tile(t4);
// //
// //	myBoard.makeRandomMove(tempTile);
// //
// //	tempTile = new Tile(t21);
// //
// //	myBoard.makeRandomMove(tempTile);
// //
// //	tempTile = new Tile(t4);
// //
// //	myBoard.makeRandomMove(tempTile);
// //
// //	tempTile = new Tile(t20);
// //
// //	myBoard.makeRandomMove(tempTile);

// //	tempTile = new Tile(t20);
// //
// //	myBoard.makeRandomMove(tempTile);

// //	tempTile = new Tile(t16);
// //
// //	myBoard.makeRandomMove(tempTile);



// 	//original testing code
// //	int t0[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0};
// //	int t1[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1};
// //	int t5[12] = {0, 1, 1, 1, 0, 0, 1, 1, 0, 4, 0, 5};
// //	int t4[12] = {0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 0, 4};
// //	int t13[12] = {0, 0, 1, 1, 0, 0, 0, 0, 1, 3, 0, 13};
// //	int t17[12] = {1, 1, 0, 0, 0, 0, 0, 0, 0, 3, 0, 17};
// //
// //	Tile* tempTile = new Tile(t1);
// ////	tempTile->printTileFeatures();
// //
// //	myBoard.addTile(tempTile,40,40);
// //
// //	tempTile = new Tile(t5);
// //
// //	myBoard.addTile(tempTile,41,40);
// //
// //	tempTile = new Tile(t4);
// //
// //	myBoard.addTile(tempTile,41,39);
// //
// //	tempTile = new Tile(t13);
// //
// //	myBoard.addTile(tempTile,42,40);
// //
// //	tempTile = new Tile(t17);
// //
// //	myBoard.addTile(tempTile,41,41);
// //
// //	myBoard.getTile(40,40)->printTileFeatures();
// //	cout << endl;
// //	myBoard.getTile(41,40)->printTileFeatures();
// //	cout << endl;
// //	myBoard.getTile(41,41)->printTileFeatures();
// //	cout << endl;
// //	myBoard.getTile(42,40)->printTileFeatures();
// //	cout << endl;
// //	myBoard.getTile(41,39)->printTileFeatures();
// //	cout << endl;
// //
// //	myBoard.printAvailPos();






// //	Tile* tempTile = myDeck.pop();
// //
// //	myBoard.addTile(tempTile,40,40);
// //
// //	tempTile = myDeck.pop();
// //
// //	myBoard.addTile(tempTile,40,41);
// //
// //	tempTile = myDeck.pop();
// //
// //	myBoard.addTile(tempTile,40,42);

// 	myBoard.exportBoardState();


//    return 0;
// }

Board::Board(){

    sizeX=80;
    sizeY=80;
	int t18[12] = {2, 2, 1, 0, 0, 0, 0, 0, 2, 3, 0, 18};
	Tile* newTile = new Tile(t18);

	addTile(newTile,40,40);


}

Tile* Board::getTile(int x, int y){

	return gameGraph[x][y];


}

int Board::makeRandomMove(Tile* tileToAdd){

	//get tile as input
	//for loop through availPosList
	//do checklegal move for each position
	//if none is found, rotate tile
	//repeat

	//*eventually will want to iterate through features from 0-8 in tile to check for legal meeple placement

	int checker = 0;
	for(int j = 0; j < 4; j++){
//		std::cout << openLocVector.size();
		for(int i = 0; i < openLocVector.size(); i++){

			if(checkLegalMove(tileToAdd,openLocVector[i].x,openLocVector[i].y) == true){ //look in here

				addTile(tileToAdd,openLocVector[i].x,openLocVector[i].y); //stops here
				checker = 1;
				return 0;
				break;
			}



		}
		if(checker == 1){
			break;
			return 0;
		}

		tileToAdd->rotateL();

	}

	return 9999;


}

void Board::addTile(Tile* tileToAdd,int x,int y){


	gameGraph[x][y] = tileToAdd;
	updateAvailPos(x,y);
	cout << "tile: " << tileToAdd->tileNum << " added to  (" << x << "," << y << ")" << endl;

	tileToAdd->xPos = x;
	tileToAdd->yPos = y;

	int checker = 0;

	//check west
	if(gameGraph[x-1][y] != NULL){

		//for the tiles with cities on the corner, make the corner null. These corners always get completed or extended by another city and won't have an effect on computation.

		//ne
		//add this new tile to west tile
		checker = gameGraph[x-1][y]->addToFeature(4,tileToAdd);
		if(checker == 1 && gameGraph[x-1][y]->getFeature(4) != tileToAdd->getFeature(5)){
			tileToAdd->repointFeature(gameGraph[x-1][y]->getFeature(4),5);
		}


		checker = 0;

		//E
		checker = gameGraph[x-1][y]->addToFeature(2,tileToAdd);
		if(checker == 1 && gameGraph[x-1][y]->getFeature(2) != tileToAdd->getFeature(3)){
			tileToAdd->repointFeature(gameGraph[x-1][y]->getFeature(2),3);
		}



		checker = 0;

		//se
		checker = gameGraph[x-1][y]->addToFeature(6,tileToAdd);
		if(checker == 1 && gameGraph[x-1][y]->getFeature(6) != tileToAdd->getFeature(7)){
			tileToAdd->repointFeature(gameGraph[x-1][y]->getFeature(6),7);//this line
		}

		checker = 0;

	}

	//for reference
	//N, S, E, W, ne, nw, se, sw, center, tile amount, animal, tile #

	//check north
	if(gameGraph[x][y-1] != NULL){

		//for the tiles with cities on the corner, make the corner null. These corners always get completed or extended by another city and won't have an effect on computation.

		//se
		//add this new tile to west tile
		checker = gameGraph[x][y-1]->addToFeature(6,tileToAdd);
		if(checker == 1 && gameGraph[x][y-1]->getFeature(6) != tileToAdd->getFeature(4)){
			tileToAdd->repointFeature(gameGraph[x][y-1]->getFeature(6),4);
		}


		checker = 0;

		//S
		checker = gameGraph[x][y-1]->addToFeature(1,tileToAdd);
		if(checker == 1 && gameGraph[x][y-1]->getFeature(1) != tileToAdd->getFeature(0)){
			tileToAdd->repointFeature(gameGraph[x][y-1]->getFeature(1),0);
		}



		checker = 0;

		//sw
		checker = gameGraph[x][y-1]->addToFeature(7,tileToAdd);
		if(checker == 1 && gameGraph[x][y-1]->getFeature(7) != tileToAdd->getFeature(5)){
			tileToAdd->repointFeature(gameGraph[x][y-1]->getFeature(7),5);
		}

		checker = 0;

	}

	//for reference
	//N, S, E, W, ne, nw, se, sw, center, tile amount, animal, tile #

	//check south
	if(gameGraph[x][y+1] != NULL){

		//for the tiles with cities on the corner, make the corner null. These corners always get completed or extended by another city and won't have an effect on computation.

		//ne
		//add this new tile to west tile
		checker = gameGraph[x][y+1]->addToFeature(4,tileToAdd);
		if(checker == 1 && gameGraph[x][y+1]->getFeature(4) != tileToAdd->getFeature(6)){
			tileToAdd->repointFeature(gameGraph[x][y+1]->getFeature(4),6);
		}


		checker = 0;

		//N
		checker = gameGraph[x][y+1]->addToFeature(0,tileToAdd);
		if(checker == 1 && gameGraph[x][y+1]->getFeature(0) != tileToAdd->getFeature(1)){
			tileToAdd->repointFeature(gameGraph[x][y+1]->getFeature(0),1);
		}



		checker = 0;

		//nw
		checker = gameGraph[x][y+1]->addToFeature(5,tileToAdd);
		if(checker == 1 && gameGraph[x][y+1]->getFeature(5) != tileToAdd->getFeature(7)){
			tileToAdd->repointFeature(gameGraph[x][y+1]->getFeature(5),7);
		}

		checker = 0;

	}
	//for reference
	//N, S, E, W, ne, nw, se, sw, center, tile amount, animal, tile #

	//check East
	if(gameGraph[x+1][y] != NULL){

		//for the tiles with cities on the corner, make the corner null. These corners always get completed or extended by another city and won't have an effect on computation.

		//nw
		//add this new tile to west tile
		checker = gameGraph[x+1][y]->addToFeature(5,tileToAdd);
		if(checker == 1 && gameGraph[x+1][y]->getFeature(5) != tileToAdd->getFeature(4)){
			tileToAdd->repointFeature(gameGraph[x+1][y]->getFeature(5),4);
		}


		checker = 0;

		//W found ITTTTTTTTTTTTTTTTTTTTTTTTTT!!!!!
		checker = gameGraph[x+1][y]->addToFeature(3,tileToAdd);
		if(checker == 1 && gameGraph[x+1][y]->getFeature(3) != tileToAdd->getFeature(2)){
			tileToAdd->repointFeature(gameGraph[x+1][y]->getFeature(3),2);
		}



		checker = 0;

		//sw
		checker = gameGraph[x+1][y]->addToFeature(7,tileToAdd); //stops here
		if(checker == 1 && gameGraph[x+1][y]->getFeature(7) != tileToAdd->getFeature(6)){
			tileToAdd->repointFeature(gameGraph[x+1][y]->getFeature(7),6);
		}

		checker = 0;

	}



//        if(turn){
//        //ai will rotate for us, we just need to place it, keeps api simple
//        int test1 [15] = {2, 2, 1, 2, 0, 0, 0, 0, 2, 1, 0, 3};
//        int test2 [15] = {0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 0, 4};
//		//pop tile from stack
//
//        Tile firstTile = Tile(test1);
//        Tile secondTile = Tile(test2);
//        cout << "Tile has been accessed\n";
//
//        gameGraph[40][40] = firstTile;
//        gameGraph[40][41] = secondTile;
//        cout << "Tile has been placed\n";
//        firstTile.xPos = 40;
//        firstTile.yPos = 40;
//        secondTile.xPos = 40;
//        secondTile.yPos = 41;
//
//        //check available positions on board from array
//        // availPosAroundTile(firstTile);
//
//        //check if placement is legal
//
//        //place tile and connect the sides
//
//        //check which meeple placements are legal
//
//        //if it is city/road connect it to a feature
//
//        }

	return;	
	
}

void Board::printBoard(){
		//print rows one by one
    cout << "made it into printboard\n";
        for (int i = 0; i<sizeX; i++){
            
            for(int j = 0; j < sizeY; j++){
                
                if(gameGraph[i][j]->isEmpty==0){
                    
                    cout<< i << ","<< j << "is full";
                    
                }
            }
        }
	}

	string Board::exportBoardState(){
		//need to find best format for exporting, needs to be quick to deliver to ai
		
//		cout << "1\n";
		ofstream myFile;
		myFile.open("exportBoard.txt");
//		myFile << "what what";
		// myFile.close();
		
//		cout << "2\n";
		
		for(int i = 0; i < 80; i++){
			for(int j = 0; j < 80; j++){
				
//				cout << "3\n";
				
				if(gameGraph[j][i] == NULL){
					
					 myFile << "0;";
					
					
				}
				else{
					
					myFile << gameGraph[j][i]->exportTileInfo() << ";";
					
					
				}
				
				
			}
			myFile << "\n";
			
			
			
		}
		
		
		
		
		
		return "";
	}
	
	int Board::calcScore(){

		return 0;
	}

	void Board::updateAvailPos(int x, int y){
		int checker = 0;

		for(int i = 0; i < openLocVector.size(); i++){
			if(openLocVector[i].x == x && openLocVector[i].y == y){
				openLocVector.erase(openLocVector.begin()+i);
				break;
			}
		}

		if(checker == 0){

			//add north
			if(gameGraph[x][y-1] == NULL){

				for(int i = 0; i < openLocVector.size(); i++){
					if(openLocVector[i].x == x && openLocVector[i].y == (y-1)){
						openLocVector.erase(openLocVector.begin()+i);
						break;
					}
				}
				loc temp;
				temp.x = x;
				temp.y = y-1;
				openLocVector.push_back(temp);

			}
			//add south
			if(gameGraph[x][y+1] == NULL){

				for(int i = 0; i < openLocVector.size(); i++){
					if(openLocVector[i].x == x && openLocVector[i].y == (y+1)){
						openLocVector.erase(openLocVector.begin()+i);
						break;
					}
				}
				loc temp;
				temp.x = x;
				temp.y = y+1;
				openLocVector.push_back(temp);

			}
			//add east
			if(gameGraph[x+1][y] == NULL){

				for(int i = 0; i < openLocVector.size(); i++){
					if(openLocVector[i].x == (x+1) && openLocVector[i].y == y){
						openLocVector.erase(openLocVector.begin()+i);
						break;
					}
				}
				loc temp;
				temp.x = x+1;
				temp.y = y;
				openLocVector.push_back(temp);

			}
			if(gameGraph[x-1][y] == NULL){

				for(int i = 0; i < openLocVector.size(); i++){
					if(openLocVector[i].x == (x-1) && openLocVector[i].y == y){
						openLocVector.erase(openLocVector.begin()+i);
						break;
					}
				}
				loc temp;
				temp.x = x-1;
				temp.y = y;
				openLocVector.push_back(temp);

			}

		}
//		printAvailPos();

	}

	void Board::printAvailPos(){

		for(int i = 0; i < openLocVector.size(); i++){
			cout << "open: " << "x: " << openLocVector[i].x << " y: " << openLocVector[i].y << endl;
		}

	}
    
    void Board::availPosAroundTile(Tile tile){

		if (tile.North == NULL) {
			int x = tile.xPos;
			int y = tile.yPos;

			loc mypoint;
			mypoint.x = x-1;
			mypoint.y = y;

			openLocVector.push_back(mypoint);

		}
		if (tile.East == NULL) {
			int x = tile.xPos;
			int y = tile.yPos;

			loc mypoint;
			mypoint.x = x;
			mypoint.y = y+1;

			openLocVector.push_back(mypoint);

		}
		if (tile.South == NULL) {
			int x = tile.xPos;
			int y = tile.yPos;

			loc mypoint;
			mypoint.x = x+1;
			mypoint.y = y;

			openLocVector.push_back(mypoint);

		}
		if (tile.West == NULL) {
			int x = tile.xPos;
			int y = tile.yPos;

			loc mypoint;
			mypoint.x = x;
			mypoint.y = y-1;

			openLocVector.push_back(mypoint);

		}
    
		cout << "Board has :" << openLocVector.size() << " elements\n";

    }

    bool Board::checkLegalMove(Tile* tile, int x, int y) {

//    	cout << "trying to place tile at:" << x << "," << y;
    	//N, S, E, W

    	//check to the north
    	if (gameGraph[x][y-1] != NULL) {
    		if (tile->getFeature(0)->getName() != (gameGraph[x][y-1])->getFeature(1)->getName()) {
    			return false;
    		}
    	}
    	//check to the south
    	if (gameGraph[x][y+1] != NULL) {
    		if (tile->getFeature(1)->getName() != (gameGraph[x][y+1])->getFeature(0)->getName()) {
    			return false;
    		}
    	}
    	//check to the east
    	if (gameGraph[x+1][y] != NULL) {
    		if (tile->getFeature(2)->getName() != (gameGraph[x+1][y])->getFeature(3)->getName()) {
    			return false;
    		}
    	}
    	//check to the west
    	if (gameGraph[x-1][y] != NULL) {
    		if (tile->getFeature(3)->getName() != (gameGraph[x-1][y])->getFeature(2)->getName()) {
    			return false;
    		}
    	}
//    	else addTile(tile,x,y);
    	return true;

    }












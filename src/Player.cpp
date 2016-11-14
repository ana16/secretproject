#include <iostream>


using namespace std;



class Player{
	
private:
	//consider making this an array of Strings
	int score;
	int meepleCount;
	
public:
	
	void updateScore(int num){
		score += num;
	}
	
	void incMeeple(){
		//probably will take a number as parameter
		meepleCount++;
	}
	
	void decMeeple(){
		//same as above
		meepleCount--;
	}
	
};

















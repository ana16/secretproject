  // This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <stdio.h>
#include <vector>
#include <iostream>
#include "Board.h"
#include <typeinfo>
#include "Deck.h"
#include "Tile.h"
#include "Feature.h"

using namespace std;


int conv(string x){

	if(x == "JJJJ-")
		return 0;
	else if(x =="LLLL-")
		return 1;
	else if(x == "TLJT-")
		return 2;
	else if(x == "TLTT-")
		return 3;
	else if(x == "JJJJX")
		return 4;
	else if(x == "JLLL-")
		return 5;
	else if(x == "TLJTP")
		return 6;
	else if(x == "TLTTP")
		return 7;
	else if(x == "JJTJX")
		return 8;
	else if(x == "LLJJ-")
		return 9;
	else if(x == "JLTT-")
		return 10;
	else if(x == "TLLT-")
		return 11;
	else if(x == "TTTT-")
		return 12;
	else if(x == "JLJL-")
		return 13;
	else if(x == "JLTTB")
		return 14;
	else if(x == "TLLTB")
		return 15;
	else if(x == "TJTJ-")
		return 16;
	else if(x == "LJLJ-")
		return 17;
	else if(x == "TLTJ-")
		return 18;
	else if(x == "LJTJ-")
		return 19;
	else if(x == "TJJT-")
		return 20;
	else if(x == "LJJJ-")
		return 21;
	else if(x == "TLTJD")
		return 22;
	else if(x == "LJTJD")
		return 23;
	else if(x == "TJTT-")
		return 24;
	else if(x == "JLLJ-")
		return 25;
	else if(x == "TLLL-")
		return 26;
	else if(x == "TLLLC")
		return 27;

}




int main( int argc, char* const argv[] )
{
  // global setup...

  int result = Catch::Session().run( argc, argv );
    
 //   myBoard5 = new Board();
 //    myDeck5 = new Deck();
    


  // global clean-up...

  return result;
}
TEST_CASE( "Functions are computed", "[conv]" ) {
    REQUIRE( conv("JJJJ-") == 0 );
    REQUIRE( conv("LLLL-") == 1 );
    REQUIRE( conv("TLJT-") == 2 );
    REQUIRE( conv("TLTT-") == 3 );
    
}

TEST_CASE( "Tile has been obtained", "[getTile]" ) {
   
    //Board* myBoard5 = new Board();
   // Deck* myDeck5 = new Deck();
   // Tile* tile = myDeck5->pop();
    
    //REQUIRE( tile != NULL );
    //REQUIRE(getTile(18) !=NULL  );

    
}

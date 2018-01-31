#include <iostream>
#include <list>
using namespace std;
#include "Configuration.h"
#include "Placement.h"
#include "Filler.h"

int main( )
{
   Configuration C("nine.txt");
   C.forbid(4,2);
   list<Placement> canDo = C.getPossiblePlacements(2);
   int count = 1;
   for( Placement P : canDo ) {
       cout << count++ << " " << P << endl;
   }
   // C.placeTileAt( 2, 3 , true, 2 );
   // Square::setChars('-','+');
   C.dumpToScreen( );
   Filler F("nine.txt");
   // F.greedyFill(3);
   F.betterFill(2);
   // Square::setChars('-','+');
   F.dumpToScreen( );
}

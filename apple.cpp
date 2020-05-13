/* Contains all “apple” class member function definitions */

// Include header files
#include "init.hpp"
#include "apple.hpp"

//// Function definitions
/// Apple member function definitions
// Default Constructor
 Apple::Apple()
 {
     // Generate and initialize apple position
    appleRow = rand()%(NROWS-2)+1;
    appleCol = rand()%(NCOLS-2)+1;
    
    // Generate Apple
    gameInfo.board[appleRow][appleCol] = -1;
    
    // Exit function
    return;
 }

 // Constructor with color initialization
 Apple::Apple(int c)
 {
    // REVISIT FOR COLOR

    // Initialize apple position
   appleRow = rand()%(NROWS-2)+1;
   appleCol = rand()%(NCOLS-2)+1;

   // Generate Apple
   gameInfo.board[appleRow][appleCol] = -1;

   // Exit function
   return;

 }

 // Function to help create a new apple
 void Apple::newApple(int c)
 {
     // Generate and initialize apple position
    appleRow = rand()%(NROWS-2)+1;
    appleCol = rand()%(NCOLS-2)+1;
    
    // Generate Apple
    gameInfo.board[appleRow][appleCol] = -1;

     // Exit function
     return;
 }

 // Accessor function to determine apple position
 void Apple::getApplePos(int &Y, int &X)
 {
     // Return head position
    Y = appleRow;
    X = appleCol;
    
    // Exit function
    return;
     // Exit function
     return;
 }
 
 // Increments number of apples eaten
     void Apple::incrementApplesEaten()
     {
         applesEaten++;
     }

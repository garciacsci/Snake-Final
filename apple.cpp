/* Snake apple.cpp */

/* 
 * File:    apple.cpp
 * Author:  Christopher Garcia
 * Purpose: Contains all “apple” class member function definitions
 * Date:    14 May 2020
 */

// Include header files
#include "init.hpp"
#include "apple.hpp"

//// Function definitions
/// Apple member function definitions
// Default Constructor
 Apple::Apple()
 {     
    while(TRUE)
    {
        // Generate and initialize apple position
        appleRow = rand()%(NROWS-2)+1;
        appleCol = rand()%(NCOLS-2)+1;

        // Make sure taget is empty
        if (gameInfo.board[appleRow][appleCol] == 0)
        {    
            // Generate Apple if it is
            gameInfo.board[appleRow][appleCol] = -1;
            
            // Exit function
            return;
        }    
    }             
 }

 // Constructor with color initialization
 Apple::Apple(int c)
 {
    while(TRUE)
    {
        // Initialize apple position
        appleRow = rand()%(NROWS-2)+1;
        appleCol = rand()%(NCOLS-2)+1;

        // Check that target is empty
        if (gameInfo.board[appleRow][appleCol] == 0)
        {
            // Generate Apple if it is
            gameInfo.board[appleRow][appleCol] = c*-1;

            // Exit function
            return;
        }
    }
 }

 // Function to help create a new apple
 void Apple::newApple(int c)
 {
    while(TRUE)
    {
        // Initialize apple position
        appleRow = rand()%(NROWS-2)+1;
        appleCol = rand()%(NCOLS-2)+1;

        // Check that target is empty
        if (gameInfo.board[appleRow][appleCol] == 0)
        {
            // Generate Apple if it is
            gameInfo.board[appleRow][appleCol] = c*-1;

            // Exit function
            return;
        }
    }
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
     
// Returns number of apples eaten
     int Apple::eaten()
     {
         return(applesEaten);
     }

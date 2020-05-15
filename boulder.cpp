/* Snake boulder.cpp */

/* 
 * File:    boulder.cpp
 * Author:  Christopher Garcia
 * Purpose: Contains all “boulder” class member function definitions
 * Date:    14 May 2020
 */

// Include header files
#include "init.hpp"
#include "boulder.hpp"

//// Function definitions
/// Boulder member function definitions
// Default Constructor
 Boulder::Boulder()
 {        
    while(true)
    {
        // Declare Variables
        int bRow = rand()%(NROWS-2)+1, bCol = rand()%(NCOLS-2)+1;
        
        // Make sure target is empty
        if (gameInfo.board[bRow][bCol] == 0)
        {
            // Generate Boulder
            gameInfo.board[bRow][bCol] = -4;

            // Exit function
            return;
        }
    }
 }

 // Constructor with color initialization
 Boulder::Boulder(int c)
 {        
    while(true)
    {
        // Declare Variables
        int bRow = rand()%(NROWS-2)+1, bCol = rand()%(NCOLS-2)+1;
        
        // Make sure target is empty
        if (gameInfo.board[bRow][bCol] == 0)
        {
            // Generate Boulder
            gameInfo.board[bRow][bCol] = c*-1;

            // Exit function
            return;
        }
    }

 }

 // Function to help create a new apple
 void Boulder::newBoulder(int c)
 {        
    while(true)
    {
        // Declare Variables
        int bRow = rand()%(NROWS-2)+1, bCol = rand()%(NCOLS-2)+1;
        
        // Make sure target is empty
        if (gameInfo.board[bRow][bCol] == 0)
        {
            // Generate Boulder
            gameInfo.board[bRow][bCol] = c*-1;

            // Exit function
            return;
        }
    }
 }
 
 // Clears boulders from the board
    void Boulder::clearBoulders()
    {
    // Declare Variables
        int row=0, column=1;
    
    // Parse board array and clear boulders
        while (column<NCOLS-1)
        {
            for (row=1; row<NROWS-1; row++)
            {
                if (gameInfo.board[row][column] == -4)
                    gameInfo.board[row][column] = 0;
            }
        column++;
        }
    }

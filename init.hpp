/* Stores global constants, structure data types, enumerations, 
global data types, and function prototypes for initialization */

#ifndef INIT_HPP
#define INIT_HPP

// Include header files
#include <curses.h>
#include <iostream>

// Name Space
using namespace std;

//// Declare and initialize constants
// Number of Rows in Game Board
const int NROWS = 48; 

// Number of Columns in Game Board
const int NCOLS = 96; 

//// Enumerations and Type Declarations
// Keyboard Directions
enum Dir {UP, DOWN, LEFT, RIGHT}; 

// Game Outcomes
enum Res {WIN, LOSS, GAMEOVER};

//// Function Prototypes
// Initialize the XCurses Library
void initXCurses(int argc, char** argv);

// Initialize gameInfo Structure Data
void initGameInfo(ostream &fout);

// Structure Data Type Declarations
struct info
{
    // Stores Block Placement Game Data
    int board[NROWS][NCOLS]; 
    
    // Stores Game Speed
    int speed; 
    
    // Games outcome
    Res outcome;
    
    // More Variables May Be Added... 
};

// Give gameInfo global scope
extern info gameInfo; 

#endif /* INIT_HPP */

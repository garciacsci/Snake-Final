/* Stores global constants, structure data types, enumerations, 
global data types, and function prototypes for initialization */

#ifndef INIT_H
#define INIT_H

// Number of Rows in Game Board
const int NROWS = 48; 

// Number of Columns in Game Board
const int NCOLS = 96; 

// Keyboard Directions
enum Dir {UP, DOWN, LEFT, RIGHT}; 

struct info
{
    // Stores Block Placement Game Data
    int board[NROWS][NCOLS]; 
    
    // Stores Game Speed
    int speed; 
    // More Variables May Be Added... 
};

extern info gameInfo; 


void initXCurses(int argc, char** argv);

#endif /* INIT_H */

/* Contains all initialization functions */

// Define XCURSES
#define XCURSES

// Include header files
#include <curses.h>
#include "init.hpp"

//----------------------------------------------------------------------------//
// Initialize the XCurses Library
void initXCurses(int argc, char** argv)
{
    // Initialize X Display Screen
    Xinitscr(argc, argv); 

    // Relabel Window Title
    PDC_set_title("ECE 71 SNAKE PROJECT");

    // Retain ^C Behavior
    cbreak(); 

    // Make Cursor Invisible
    curs_set(FALSE); 

    // Turn on Keypad
    keypad(stdscr, TRUE); 
    
    // Don't echo input
    noecho(); 

    // Start NCURSES Color
    start_color(); 

    // Do not wait for input
    nodelay(stdscr, TRUE);         
 
    // Exit Function
    return;
}

// Initialize game info structure data
void initGameInfo(ostream &fout)
{
    
    // Declare Variables
    int row=0, column=0;
    
    // Initialize board array to 0's
    gameInfo.board[NROWS][NCOLS]={0};
    
    // Initialize borders to -10
    while(column<NCOLS)
    {
    for (int row=0; row<NROWS; row++)
        {
            gameInfo.board[row][0] = -10;
            gameInfo.board[row][NCOLS-1] = -10;
            gameInfo.board[0][column] = -10;
            gameInfo.board[NROWS-1][column] = -10;
        }
    column++;
    }        
    
    // Initialize game speed to 1
    gameInfo.speed = 10;
    
    
    // Maybe do some formatting for the output file????
    
    
    // Exit Function
    return;
}
//----------------------------------------------------------------------------//

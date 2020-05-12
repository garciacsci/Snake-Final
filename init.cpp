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

    // Match screen to current
    if (getch()==KEY_RESIZE) 

    // terminal size
    resize_term(0,0); 

    // Don't echo input
    noecho(); 

    // Start NCURSES Color
    start_color(); 

    // Do not wait for input
    nodelay(stdscr, TRUE); 
    
    /*
    // Match screen to current terminal size
    if (getch() == KEY_RESIZE)
        resize_term(0,0);
    */
 
    // Exit Function
    return;
}

// Initialize game info structure data
void initGameInfo(ostream &fout)
{
    // Initialize board array to 0's
    boardInfo.board[NROWS][NCOLS]={0};
    
    // Initialize game speed to 1
    boardInfo.speed = 1;
    
    // Exit Function
    return;
}
//----------------------------------------------------------------------------//

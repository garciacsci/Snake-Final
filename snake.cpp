/* Contains all “snake” class member function definitions */

// Define XCurses
#define XCURSES

// Include libraries
#include <curses.h>
#include <iostream>

// Include header files
#include "snake.hpp"
#include "init.hpp"

//// Function prototypes
/// Snake member function definitions
// Default Constructor
Snake::Snake()
{
    // Initialize snake starting position
    gameInfo.board[(NROWS-1)/2][(NCOLS-1)/2] = 1;
}

// Constructor with length initialization
Snake::Snake(int l)
{
    // Declare Variables
    int row=1, column=1, snek=1;
    
    // Start from the top left and 
    while(row<NROWS && l>0)
    {    
        {
            if (row%2==0)
            {
                for (int column=NCOLS-2; column>0 && l>0; column--)
                {
                    gameInfo.board[row][column] = snek;
                    snek++;
                    l--;
                }
            }

            else
            {
                for (int column=1; column<NCOLS-1 && l>0; column++)
                {
                    gameInfo.board[row][column] = snek;
                    snek++;
                    l--;
                }
            }
        }
    row++;
    }   
}

// Move member function
void Snake::move()
{
 /* 
    int row = (LINES-1)/2, row2 = ((LINES-1)/2) + 1, row3 = ((LINES-1)/2) + 2, prevR;
    int col = (COLS-1)/2, col2 = (COLS-1)/2, col3 = (COLS-1)/2, prevC;
    
    mvaddch(row, col, ACS_BLOCK);
    //mvaddch(row2, col2, ACS_BLOCK);
    //mvaddch(row3, col3, ACS_BLOCK);
    
    int ch='\0';
    
    while(1)
    {        
        ch = getch();
          
        if(ch == KEY_RIGHT)
        {
            do
            {
                //prevR = row3;
                //prevC = col3;
                //row3 = row2;
                //col3 = col2;
                //row2 = row;
                //col2 = col;
                //mvaddch(prevR, prevC, ' ');
                mvaddch(row, col, ' ');
                col++;
                mvaddch(row, col, ACS_BLOCK);
                //mvaddch(row2, col2, ACS_BLOCK);
                //mvaddch(row3, col3, ACS_BLOCK);
            } while(ch == KEY_RIGHT || ch == KEY_LEFT);
            
        }
        else if(ch == KEY_LEFT)
        {
            prevR = row3;
            prevC = col3;
            row3 = row2;
            col3 = col2;
            row2 = row;
            col2 = col;
            mvaddch(prevR, prevC, ' ');
            col--;
            mvaddch(row, col, ACS_BLOCK);
            mvaddch(row2, col2, ACS_BLOCK);
            mvaddch(row3, col3, ACS_BLOCK);
        }
        else if(ch == KEY_UP)
        {
            prevR = row3;
            prevC = col3;
            row3 = row2;
            col3 = col2;
            row2 = row;
            col2 = col;
            mvaddch(prevR, prevC, ' ');
            row--;
            mvaddch(row, col, ACS_BLOCK);
            mvaddch(row2, col2, ACS_BLOCK);
            mvaddch(row3, col3, ACS_BLOCK);
        }    
        else if (ch == KEY_DOWN)
        {
            prevR = row3;
            prevC = col3;
            row3 = row2;
            col3 = col2;
            row2 = row;
            col2 = col;
            mvaddch(prevR, prevC, ' ');
            row++;
            mvaddch(row, col, ACS_BLOCK);
            mvaddch(row2, col2, ACS_BLOCK);
            mvaddch(row3, col3, ACS_BLOCK);
        }
    }      
    
    nodelay(stdscr, FALSE);
    getch();
    endwin();    
*/        
    // Exit function
    return;
}

// Accessor function to determine head snake position
void Snake::getHeadPos(int &Y, int &X)
{
    // Declare Variables
    int row=0, column=0, max=0;
    
    // Find snake head (greatest integer on board)
    while (row<NROWS)
    {
        for (column=0; column<NCOLS; column++)
        {
            if (gameInfo.board[row][column] > max);
            {
                y = row;
                x = column;
            }
        }
        fout << "\n";
        row++;    
    }
    
    // Exit function
    return;
}

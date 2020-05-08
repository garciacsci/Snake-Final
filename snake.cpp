/* Contains all “snake” class member function definitions */
#define XCURSES
#include <curses.h>
#include <iostream>
#include "snake.hpp"
#include "init.hpp"

void moveSnake()
{

    int row = (LINES-1)/2, row2 = ((LINES-1)/2) + 1, row3 = ((LINES-1)/2) + 2, prevR;
    int col = (COLS-1)/2, col2 = (COLS-1)/2, col3 = (COLS-1)/2, prevC;
    
    mvaddch(row, col, ACS_BLOCK);
    mvaddch(row2, col2, ACS_BLOCK);
    mvaddch(row3, col3, ACS_BLOCK);
    

    
    while(1)
    {
        int ch;
        ch = getch();
          
        if(ch == KEY_RIGHT)
        {
            prevR = row3;
            prevC = col3;
            row3 = row2;
            col3 = col2;
            row2 = row;
            col2 = col;
            mvaddch(prevR, prevC, ' ');
            col++;
            mvaddch(row, col, ACS_BLOCK);
            mvaddch(row2, col2, ACS_BLOCK);
            mvaddch(row3, col3, ACS_BLOCK);
            
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
    
}



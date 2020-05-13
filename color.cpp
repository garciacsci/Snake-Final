/* Contains all color functions */
#define XCURSES
#include <curses.h>
#include <cstdlib>

//include header files
#include "init.hpp"
#include "color.hpp"
#include "apple.hpp"
#include "display.hpp"

using namespace std;

// Initialize Color Attributes
 void initColors(void)
 {
    
    start_color();
    
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLACK, COLOR_BLACK);
    init_pair(5, COLOR_BLUE, COLOR_BLACK);
    
    
   
 }
 
// Set Color Function used to Set the Color of an Object
//int x is the value of the gameboard(-1, 0, -10, x>0)
//row and col is position of object
void color(int row, int col, int x)
{    
    gameInfo.board[row][col];
    
    if (x > 0)
    {
        attron(COLOR_PAIR(2));
        mvprintw(row, col, "S");
        attroff(COLOR_PAIR(2));
    }
    else if(x == -10)
    {
        attron(COLOR_PAIR(5));
        mvaddch(row, col, ACS_BLOCK);
        attroff(COLOR_PAIR(5));
    }
    else if(x == -1)
    {
        int chance;
        chance = (rand() % 3)+1;
        
        if(chance = 1)
        {
        attron(COLOR_PAIR(1));
        mvprintw(row, col, "A");
        attroff(COLOR_PAIR(1));
        }
        else if(chance = 2)
        {
        attron(COLOR_PAIR(2));
        mvprintw(row, col, "A");
        attroff(COLOR_PAIR(2));
        }
        else if(chance = 3)
        {
        attron(COLOR_PAIR(3));
        mvprintw(row, col, "A");
        attroff(COLOR_PAIR(3));
        }
    }
    else if(x == 0)
    {
        attron(COLOR_PAIR(4));
        mvprintw(row, col, " ");
        attroff(COLOR_PAIR(4));
    }
  
 }
 


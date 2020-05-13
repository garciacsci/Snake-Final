/* Contains all “apple” class member function definitions */

#define XCURSES
#include <curses.h>
#include <iostream>
#include <cstdlib>
#include "init.hpp"
#include "apple.hpp"

using namespace std;

apple::apple()
{
    int row = 0, col = 0;
    int row2 = 0, col2 = 0;
    int row3 = 0, col3 = 0;
    
    row = (rand() % 48)+0;
    col = (rand() % 96)+0;
    row2 = (rand() % 48)+0;
    col2 = (rand() % 96)+0;
    row3 = (rand() % 48)+0;
    col3 = (rand() % 96)+0;
    
    apple1.appleR = row;
    apple1.appleC = col;
    mvprintw(row, col, "A");
    apple2.appleR = row2;
    apple2.appleC = row2; 
    mvprintw(row2, col2, "A");
    apple3.appleR = row3;
    apple3.appleC = col3;
    mvprintw(row3, col3, "A");
    
}

void apple::newApple()
{
    int row = 0, col = 0, prevR, prevC;
    
    prevR = appleR;
    prevC = appleC;
    
    row = (rand() % 48)+0;
    col = (rand() % 96)+0;
    
    appleR = row;
    appleC = col;
    mvprintw(prevR, prevC, " ");
    mvprintw(row, col, "A");
}

void apple::getApplePos(int &apple1Row, int &apple1Col)
{
    appleRow = appleR;
    appleCol = appleC;
}



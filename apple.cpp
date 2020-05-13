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
    apple2.appleR = row2;
    apple2.appleC = row2; 
    apple3.appleR = row3;
    apple3.appleC = col3;
    
}

void apple::newApple1()
{
    int row = 0, col = 0;
    
    row = (rand() % 48)+0;
    col = (rand() % 96)+0;
    
    apple1.appleR = row;
    apple1.appleC = col;
}

void apple::newApple2()
{
    int row2 = 0, col2 = 0;
    
    row2 = (rand() % 48)+0;
    col2 = (rand() % 96)+0;
    
    apple2.appleR = row2;
    apple2.appleC = col2;
}

void apple::newApple3()
{
    int row3 = 0, col3 = 0;
    
    row3 = (rand() % 48)+0;
    col3 = (rand() % 96)+0;
    
    apple3.appleR = row3;
    apple3.appleC = col3;
}


//if this matches snake position call newaApple 1 to generate new apple
void apple::getApplePos1(int &apple1Row, int &apple1Col)
{
    apple1Row = apple1.appleR;
    apple1Col = apple1.appleC;
}
//if this matches snake position call newApple 2 to generate new apple
void apple::getApplePos2(int &apple2Row, int &apple2Col)
{
    apple2Row = apple2.appleR;
    apple2Col = apple2.appleC;
}
//if this matches snake position call newApple 3 to generate new apple
void apple::getApplePos3(int &apple3Row, int &apple3Col)
{
    apple3Row = apple3.appleR;
    apple3Col = apple3.appleC;
}

    



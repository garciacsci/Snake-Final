/* Homework main */

/* 
 * File:    main.cpp
 * Author:  Christopher Garcia
 * Purpose: 
 * Date:    April 30, 2020
 */

// Preprocessor Directives
#define XCURSES

#include <cstdlib> 
#include <curses.h>
#include <cmath> 
#include <iostream>
#include <iomanip>


using namespace std;




using namespace std;

int main(int argc, char **argv)
{
     int ch;

     Xinitscr(argc,argv);
     cbreak();
     keypad(stdscr,TRUE);
     nodelay(stdscr,FALSE);
     noecho();
     printw("Hello World\n");
     refresh();
     while(1)
     {
          ch = getch();
          if (ch == 'Q')
          {
               printw("Q Pressed, Press Any Key to Exit");
               refresh();
               break;
          }
     }
     getch();
     endwin();

     return 0;
}


//----------------------------------------------------------------------------//

// Define User-Defined Functions
/*
{

    // Exit Function
    return;
}
 * */

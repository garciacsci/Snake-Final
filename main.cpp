/* Contains the main function */

// Preprocessor Directives
#include <cstdlib>

using namespace std;

#include "init.h"
#include <curses.h>

// 1. Declare the structure object boardInfo with file scope
info boardInfo;

int main(int argc, char **argv)
{
    initXCurses(argc, argv);
    
    endwin();

     // Exit Program
     exit(EXIT_SUCCESS);
}


//----------------------------------------------------------------------------//

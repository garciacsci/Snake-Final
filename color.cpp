/* Snake color.cpp */

/* 
 * File:    color.cpp
 * Author:  Christopher Garcia
 * Purpose: Contains all color functions
 * Date:    14 May 2020
 */

// Define Xcurses
#define XCURSES

// Include libraries
#include <curses.h>

// Include header files
#include "init.hpp"
#include "color.hpp"

// Name space
using namespace std;

// Initialize Color Attributes
 void initColors(void)
 {
    // Start XCursses Colors 
    start_color();

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);            
    init_pair(4, COLOR_WHITE, COLOR_WHITE);
    init_pair(5, COLOR_BLUE, COLOR_BLUE);
   
 }
 
// Set Color Function used to Set the Color of an Object
 void color(int x)
 {
     
     // Integrated into printboard funciton in display.cpp
     
 }

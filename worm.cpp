/* Snake worm.cpp */

/* 
 * File:    worm.cpp
 * Author:  Christopher Garcia
 * Purpose: Contains all “worm” class member function definitions
 * Date:    14 May 2020
 */

// Define XCurses
#define XCURSES

// Include libraries
#include <curses.h>
#include <iostream>
#include <unistd.h>

// Include header files
#include "init.hpp"
#include "worm.hpp"

//// Function prototypes
/// Worm member function definitions
// Default Constructor
Worm::Worm()
{
    // Initialize worm starting position
    gameInfo.board[(NROWS-1)/2][(NCOLS-1)/2-5] = -15;
    gameInfo.board[(NROWS)-1/2+1][(NCOLS-1)/2-5] = -14;
    gameInfo.board[(NROWS-1)/2+2][(NCOLS-1)/2-5] = -13;
    gameInfo.board[(NROWS-1)/2+3][(NCOLS-1)/2-5] = -12;
    gameInfo.board[(NROWS-1)/2+4][(NCOLS-1)/2-5] = -11;
    
    // Initialize head position
    headRow = (NROWS-1)/2;
    headCol = (NCOLS-1)/2-5;
    
    // Store length of worm
    length=5;    
    cout << "Length of the worm is: " << length << "\n\n";
    
    // Exit function
    return;
}

// Constructor
void Worm::Worm_()
{
    // Initialize worm starting position
    gameInfo.board[(NROWS-1)/2][(NCOLS-1)/2-5] = -15;
    gameInfo.board[(NROWS)-1/2+1][(NCOLS-1)/2-5] = -14;
    gameInfo.board[(NROWS-1)/2+2][(NCOLS-1)/2-5] = -13;
    gameInfo.board[(NROWS-1)/2+3][(NCOLS-1)/2-5] = -12;
    gameInfo.board[(NROWS-1)/2+4][(NCOLS-1)/2-5] = -11;
    
    // Initialize head position
    headRow = (NROWS-1)/2;
    headCol = (NCOLS-1)/2-5;
    
    // Store length of worm
    length=5;    
    cout << "Length of the worm is: " << length << "\n\n";
    
    // Exit function
    return;
}

// Constructor with length initialization
Worm::Worm(int l)
{
    // Declare Variables
    int row=46, column=93, snek=-6;
    
    // Exit if l is 0 or negative
    if (l <= 0)
        return;
    
    // Store length of worm
    length = l;
    cout << "Length of the worm is: " << length << "\n\n";
    
    // Start from the bottom right and 
    while(row>0 && l<-5)
    {    
        {
            if (row%2==0)
            {
                for (int c=NCOLS-2; c>0 && l>0; c--)
                {
                    gameInfo.board[row][c] = snek;
                    snek--;
                    l--;
                    column = c;
                }
            }

            else
            {
                for (int c=1; c<NCOLS-1 && l>0; c++)
                {
                    gameInfo.board[row][c] = snek;
                    snek--;
                    l--;
                    column = c;
                }
            }
        }
    row--;
    }   
    
    // Initialize head position
    headRow = row;
    headCol = column;
    
    // Change direction to down
    direction=DOWN;
        
    // Exit function
    return;
}

// Move member function
void Worm::move()
{
    // Declare variables
    int ch=0;
    
    // Game speed (to help capture inputs)
    usleep(gameInfo.speed*(1000));
    
    //cout << "headrow is: " << headRow << endl;
    //cout << "headcol is: " << headCol << "\n\n";
    
    // Get character from user
    //cout << "Getting character...\n";    
    ch = toupper(getch());
    //cout << "Character is: " << ch << "\n\n";
    
    // Move worm accordingly
    if(ch == 'W' && direction != DOWN)
        { 
            headRow--; 
            direction = UP;
        }
    else if(ch == 'S' && direction != UP)
        {      
            headRow++; 
            direction = DOWN;
        }
    else if(ch == 'A' && direction != RIGHT)
        {
            headCol--;    
            direction = LEFT;
        } 
    else if(ch == 'D' && direction != LEFT)
        {
            headCol++;  
            direction = RIGHT;
        }    
    else if(direction == UP && direction != DOWN)                         
        {
            headRow--;
        }            
    else if(direction == DOWN && direction != UP)
        {  
            headRow++;   
        }
    else if(direction == LEFT && direction != RIGHT)
        {                        
            headCol--;     
        } 
    else if(direction == RIGHT && direction != LEFT)
        {   
            headCol++;     
        }    
        
    // Exit function
        return;
}          

// Accessor function to determine head worm position
void Worm::getHeadPos(int &Y, int &X)
{
    // Return head position
    Y = headRow;
    X = headCol;
    
    // Exit function
    return;
}

// Decrement worm after move
void Worm::decrementWorm()
{
    // Declare Variables
    int row=0, column=0;
    
    while (row<NROWS)
    {
        for (column=0; column<NCOLS; column++)
        {
            if (gameInfo.board[row][column]<-10)
            {                
                ++gameInfo.board[row][column];
            }
        }
        row++;    
    }
    
    // Exit function
    return;
}

// Increment the stored length of the worm
void Worm::incrementWormLength()
{
    length++;
}

// Returns the length of the worm plus one
int Worm::wormLength()
{
    return(length);
}

// Cuts the worm in half
void Worm::cut()
{
    // Declare Variables
    int row=0, column=0;        
    
    // Update head position
    if(direction == UP && direction != DOWN)                         
        {
            headRow++;
        }            
    else if(direction == DOWN && direction != UP)
        {  
            headRow--;   
        }
    else if(direction == LEFT && direction != RIGHT)
        {                        
            headCol++;     
        } 
    else if(direction == RIGHT && direction != LEFT)
        {   
            headCol--;     
        }
    
    // Set the "lower half" of the worm to 0    
    while (row<NROWS)
    {
        for (column=0; column<NCOLS; column++)
        {
            if (gameInfo.board[row][column] < -9 && \
                    gameInfo.board[row][column]> ((length+10)*-1))
            {                
                gameInfo.board[row][column]=0;
            }
        }
        row++;    
    }        
    
    // Reinitialize variables
    row = 0;
    column = 0;
    
    // Set head of snake to -11
    while (row<NROWS)
    {
        for (column=0; column<NCOLS; column++)
        {
            if (gameInfo.board[row][column] < -10)
            {                
                gameInfo.board[row][column]= -11;
            }
        }
        row++;    
    }
    
    // Update worm length
    length = 1;
    
    // Correct the worm offset
    //correct();
                    
    // Exit function
    return;
}

// Correct Worm offset after being cut
/*void Worm::correct()
{
    // Delcare variables
    int row = 0, column = 0; 
    
    // Fix the offset of the remaining worm    
    while (row<NROWS)
    {
        for (column=0; column<NCOLS; column++)
        {
            if (gameInfo.board[row][column]> 0)
            {                
                gameInfo.board[row][column] -= (length/2);
            }
        }
        row++;    
    }
        
    // Update worm length
    if (length%2 == 0)
        length = length/2;
    else
        length = length/2-1;
    
    // Exit function
    return;
}*/

/* Snake snake.cpp */

/* 
 * File:    snake.cpp
 * Author:  Christopher Garcia
 * Purpose: Contains all “snake” class member function definitions
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
#include "snake.hpp"

//// Function prototypes
/// Snake member function definitions
// Default Constructor
Snake::Snake()
{
    // Initialize snake starting position
    gameInfo.board[(NROWS-1)/2][(NCOLS-1)/2] = 5;
    gameInfo.board[(NROWS)-1/2+1][(NCOLS-1)/2] = 4;
    gameInfo.board[(NROWS-1)/2+2][(NCOLS-1)/2] = 3;
    gameInfo.board[(NROWS-1)/2+3][(NCOLS-1)/2] = 2;
    gameInfo.board[(NROWS-1)/2+4][(NCOLS-1)/2] = 1;
    
    // Initialize head position
    headRow = (NROWS-1)/2;
    headCol = (NCOLS-1)/2;
    
    // Store length of snake
    length=5;    
    cout << "Length of the snake is: " << length << "\n\n";
    
    // Exit function
    return;
}
// Constructor
void Snake::Snake_()
{
    // Initialize snake starting position
    gameInfo.board[(NROWS-1)/2][(NCOLS-1)/2] = 5;
    gameInfo.board[(NROWS)-1/2+1][(NCOLS-1)/2] = 4;
    gameInfo.board[(NROWS-1)/2+2][(NCOLS-1)/2] = 3;
    gameInfo.board[(NROWS-1)/2+3][(NCOLS-1)/2] = 2;
    gameInfo.board[(NROWS-1)/2+4][(NCOLS-1)/2] = 1;
    
    // Initialize head position
    headRow = (NROWS-1)/2;
    headCol = (NCOLS-1)/2;
    
    // Store length of snake
    length=5;    
    cout << "Length of the snake is: " << length << "\n\n";
    
    // Exit function
    return;
}

// Constructor with length initialization
Snake::Snake(int l)
{
    // Declare Variables
    int row=1, column=1, snek=1;
    
    // Exit if l is 0 or negative
    if (l <= 0)
        return;
    
    // Store length of snake
    length = l;
    cout << "Length of the snake is: " << length << "\n\n";
    
    // Start from the top left and 
    while(row<NROWS && l>0)
    {    
        {
            if (row%2==0)
            {
                for (int c=NCOLS-2; c>0 && l>0; c--)
                {
                    gameInfo.board[row][c] = snek;
                    snek++;
                    l--;
                    column = c;
                }
            }

            else
            {
                for (int c=1; c<NCOLS-1 && l>0; c++)
                {
                    gameInfo.board[row][c] = snek;
                    snek++;
                    l--;
                    column = c;
                }
            }
        }
    row++;
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
void Snake::move()
{
    // Declare variables
    int ch=0;
    
    // Game speed (to help capture inputs)
    usleep(gameInfo.speed*(1000));
    
    //cout << "headrow is: " << headRow << endl;
    //cout << "headcol is: " << headCol << "\n\n";
    
    // Get character from user
    //cout << "Getting character...\n";    
    ch = getch();
    //cout << "Character is: " << ch << "\n\n";
    
    // Move snake accordingly
    if(ch == KEY_UP && direction != DOWN)
        { 
            headRow--; 
            direction = UP;
        }
    else if(ch == KEY_DOWN && direction != UP)
        {      
            headRow++; 
            direction = DOWN;
        }
    else if(ch == KEY_LEFT && direction != RIGHT)
        {
            headCol--;    
            direction = LEFT;
        } 
    else if(ch == KEY_RIGHT && direction != LEFT)
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

// Accessor function to determine head snake position
void Snake::getHeadPos(int &Y, int &X)
{
    // Return head position
    Y = headRow;
    X = headCol;
    
    // Exit function
    return;
}

// Decrement snake after move
void Snake::decrementSnake()
{
    // Declare Variables
    int row=0, column=0;
    
    while (row<NROWS)
    {
        for (column=0; column<NCOLS; column++)
        {
            if (gameInfo.board[row][column]>0)
            {                
                --gameInfo.board[row][column];
            }
        }
        row++;    
    }
    
    // Exit function
    return;
}

// Increment the stored length of the snake
void Snake::incrementSnakeLength()
{
    length++;
}

// Returns the length of the snake plus one
int Snake::snakeLength()
{
    return(length);
}

// Cuts the snake in half
void Snake::cut()
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
    
    // Set the "lower half" of the snake to 0    
    while (row<NROWS)
    {
        for (column=0; column<NCOLS; column++)
        {
            if (gameInfo.board[row][column] > 0 && \
                    gameInfo.board[row][column]< (length-1))
            {                
                gameInfo.board[row][column]=0;
            }
        }
        row++;    
    }        
    
    // Reinitialize variables
    row = 0;
    column = 0;
    
    while (row<NROWS)
    {
        for (column=0; column<NCOLS; column++)
        {
            if (gameInfo.board[row][column] > 0)
            {                
                gameInfo.board[row][column]=1;
            }
        }
        row++;    
    }
    
    // Update snake length
    length = 1;
    
    // Correct the snake offset
    //correct();
                    
    // Exit function
    return;
}

// Correct Snake offset after being cut
/*void Snake::correct()
{
    // Delcare variables
    int row = 0, column = 0; 
    
    // Fix the offset of the remaining snake    
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
        
    // Update snake length
    if (length%2 == 0)
        length = length/2;
    else
        length = length/2-1;
    
    // Exit function
    return;
}*/

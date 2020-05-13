/* Contains all “snake” class member function definitions */

// Define XCurses
#define XCURSES

// Include libraries
#include <curses.h>
#include <iostream>

// Include header files
#include "init.hpp"
#include "snake.hpp"

//// Function prototypes
/// Snake member function definitions
// Default Constructor
Snake::Snake()
{
    // Initialize snake starting position
    gameInfo.board[(NROWS-1)/2][(NCOLS-1)/2] = 1;
    
    // Store length of snake
    length = 1;
    
    // Exit function
    return;
}

// Constructor with length initialization
Snake::Snake(int l)
{
    // Declare Variables
    int row=1, column=1, snek=1;
    
    // Store length of snake
    length = l;
    
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
    
    // Exit function
    return;
}

// Move member function
void Snake::move()
{
    // Declare variables
    int ch=0;
    
    cout << "headrow is: " << headRow << endl;
    cout << "headcol is: " << headCol << "\n\n";
    
    // Get snake head position
    getHeadPos(headRow, headCol);
    
    cout << "headrow is now: " << headRow << endl;
    cout << "headcol is now: " << headCol << "\n\n";
    
    // Get character
    ch = getch();
    
    // Get input from user
    if( ch != KEY_UP && ch != KEY_DOWN && ch != KEY_LEFT && ch != KEY_RIGHT)
    {
        cout << "No input from user!\n";
        if(direction == UP)                         
            {
                gameInfo.board[headRow-1][headCol] = length+1;                                                
            }            
        else if(direction == DOWN)
            {                                        
                gameInfo.board[headRow+1][headCol] = length+1;          
            }
        else if(direction == LEFT)
            {                                        
                gameInfo.board[headRow][headCol-1] = length+1;          
            } 
        else if(direction == RIGHT)
            {                                        
                gameInfo.board[headRow][headCol+1] = length+1;          
            }
    }
    else
    {
        if(ch == KEY_UP)
            {                                        
                gameInfo.board[headRow-1][headCol] = length+1;  
                direction = UP;
            }
        else if(direction == KEY_DOWN)
            {                                        
                gameInfo.board[headRow+1][headCol] = length+1;    
                direction = DOWN;
            }
     else if(direction == KEY_LEFT)
            {                                        
                gameInfo.board[headRow][headCol-1] = length+1;      
                direction = LEFT;
            } 
        else if(direction == KEY_RIGHT)
            {                                        
                gameInfo.board[headRow][headCol+1] = length+1;      
                direction = RIGHT;
            }
    }
    
    // Decrement the snake
    decrementSnake();
    
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
                Y = row;
                X = column;
            }
        }
        row++;    
    }
    
    // Exit function
    return;
}

// Decrement snake after move
void Snake::decrementSnake()
{
    // Declare Variables
    int row=0, column=0;
    while (row<NROWS && row>0)
    {
        for (column=0; column<NCOLS && column>0; column++)
        {
            if (gameInfo.board[row][column] > 0)
                gameInfo.board[row][column]--;
        }
        row++;    
    }
}

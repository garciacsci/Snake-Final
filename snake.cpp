/* Contains all “snake” class member function definitions */

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
    length = 5;
    
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
    
    
    // Exit function
    return;
}

// Move member function
void Snake::move()
{
    // Declare variables
    int ch=0;
    
    // Game speed
    usleep(gameInfo.speed*(500000/50));
    
    cout << "headrow is: " << headRow << endl;
    cout << "headcol is: " << headCol << "\n\n";
    
    // Get character from user
    cout << "Getting character...\n";    
    ch = getch();
    cout << "Character is: " << ch << "\n\n";
    
    // Move snake accordingly
    if(ch == KEY_UP)
        { 
            if (headRow-1 >=0 && direction != DOWN)
            {
                headRow--; 
                direction = UP;
            }
        }
    else if(ch == KEY_DOWN)
        {                          
            if (headRow+1 < NROWS && direction != UP)
            {
                headRow++; 
                direction = DOWN;
            }
        }
    else if(ch == KEY_LEFT)
        {                             
            if (headCol-1 > 0 && direction != RIGHT)
            {
                headCol--;    
                direction = LEFT;
            }
        } 
    else if(ch == KEY_RIGHT && direction != LEFT)
        {                                
            if (headCol+1 < NCOLS)
            {
                headCol++;  
                direction = RIGHT;
            }
        }    
    else if(direction == UP && direction != DOWN)                         
        {
            if (headRow-1 >0)
            {
                headRow--;
            }
        }            
    else if(direction == DOWN && direction != UP)
        {              
            if (headRow+1 < NROWS)
            {
                headRow++;      
            }
        }
    else if(direction == LEFT && direction != RIGHT)
        {                        
            if (headCol-1 > 0)
            {
                headCol--;     
            }
        } 
    else if(direction == RIGHT)
        {       
            if (headCol+1 < NCOLS && direction != LEFT)
            {
                headCol++;     
            }
        }          
    cout << "Moved Snake\n\n";
        
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
                cout << "Element Decremented!\n";
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
int Snake::tempHead()
{
    return (length+1);
}

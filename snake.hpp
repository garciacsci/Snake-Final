/* Snake snake.hpp */

/* 
 * File:    snake.hpp
 * Author:  Christopher Garcia
 * Purpose: Declares a “snake” class to store relevant snake information
 * Date:    14 May 2020
 */

#ifndef SNAKE_HPP
#define SNAKE_HPP

class Snake
{
public:
// Default Constructor
Snake();

// Constructor
void Snake_();

// Constructor with length initialization
Snake(int l);

// Move member function
void move();

// Accessor function to determine head snake position
void getHeadPos(int &Y, int &X);
 
// Decrement all of the snake parts after a move
void decrementSnake();

// Increment the stored length of the snake
void incrementSnakeLength();

// Returns the length of the snake
int snakeLength();

// Cuts the snake
void cut();

// Correct Snake offset after being cut
//void correct();

private:
    int headRow, headCol, length=0;
    Dir direction=UP;
    
    /*
     * You may add to the class definition, as appropriate. Recall that the 
     * class declaration occurs in snake.hpp, and contains the declarations for 
     * the function prototypes and the data members only. The class member 
     * function definitions are placed in snake.cpp
    */
};

#endif /* SNAKE_HPP */

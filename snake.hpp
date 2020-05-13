/* Declares a “snake” class to store relevant paddle information */

#ifndef SNAKE_HPP
#define SNAKE_HPP

class Snake
{
public:
// Default Constructor
Snake();

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

// Returns the length of the snake plus one
int tempHead();

private:
    int headRow, headCol, length;
    Dir direction=UP;
    
    /*
     * You may add to the class definition, as appropriate. Recall that the 
     * class declaration occurs in snake.hpp, and contains the declarations for 
     * the function prototypes and the data members only. The class member 
     * function definitions are placed in snake.cpp
    */
};

#endif /* SNAKE_HPP */

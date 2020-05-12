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
 
private:
    /*Private members of the class include variables to store the snake’s head 
     * position, the direction the snake is travelling, and the current length 
     * of the snake. If the snake’s direction is LEFT (defined by the  
     * enumeration), the snake should continuously move to the left, etc. 
     * You may add to the class definition, as appropriate. Recall that the 
     * class declaration occurs in snake.hpp, and contains the declarations for 
     * the function prototypes and the data members only. The class member 
     * function definitions are placed in snake.cpp
    */
};

#endif /* SNAKE_HPP */

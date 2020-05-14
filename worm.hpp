/* Snake worm.hpp */

/* 
 * File:    worm.hpp
 * Author:  Christopher Garcia
 * Purpose: Declares a “worm” class to store relevant worm information
 * Date:    14 May 2020
 */

#ifndef WORM_HPP
#define WORM_HPP

class Worm
{
public:
// Default Constructor
Worm();

// Constructor
void Worm_();

// Constructor with length initialization
Worm(int l);

// Move member function
void move();

// Accessor function to determine head worm position
void getHeadPos(int &Y, int &X);
 
// Decrement all of the worm parts after a move
void decrementWorm();

// Increment the stored length of the worm
void incrementWormLength();

// Returns the length of the worm
int wormLength();

// Cuts the worm
void cut();

// Correct Worm offset after being cut
//void correct();

private:
    int headRow, headCol, length=0;
    Dir direction=UP;
    
    /*
     * You may add to the class definition, as appropriate. Recall that the 
     * class declaration occurs in worm.hpp, and contains the declarations for 
     * the function prototypes and the data members only. The class member 
     * function definitions are placed in worm.cpp
    */
};

#endif /* WORM_HPP */

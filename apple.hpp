/* Declares an “apple” class to store relevant apple information */

#ifndef APPLE_HPP
#define APPLE_HPP

class Apple
{
public:
    // Default Constructor
     Apple();

     // Constructor with color initialization
     Apple(int c);

     // Function to help create a new apple
     void newApple(int c);

     // Accessor function to determine apple position
     void getApplePos(int &Y, int &X);
     
     // Increments number of apples eaten
     void incrementApplesEaten();
     
     // Returns number of apples eaten
     int eaten();
     
private:
    int appleRow, appleCol, applesEaten=0, color;    
    
    
    /*
     * You may add data members and 
     * member functions to the class, as appropriate. Recall that the class 
     * declaration occurs in apple.hpp, and contains the declarations for the 
     * function prototypes and the data members only. The class member function 
     * definitions are placed in apple.cpp
     */
};

#endif /* APPLE_HPP */

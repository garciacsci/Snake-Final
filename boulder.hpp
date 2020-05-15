/* Snake boulder.cpp */

/* 
 * File:    boulder.cpp
 * Author:  Christopher Garcia
 * Purpose: Declares a “boulder” class to store relevant boulder information
 * Date:    14 May 2020
 */

#ifndef BOULDER_HPP
#define BOULDER_HPP

class Boulder
{
    
public:
    // Default Constructor
     Boulder();

     // Constructor with color initialization
     Boulder(int c);

     // Function to help create a new apple
     void newBoulder(int c);
     
     // Clears boulders from the board
     void clearBoulders();
     
};


#endif /* BOULDER_HPP */

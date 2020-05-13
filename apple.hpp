/* Declares an “apple” class to store relevant apple information */

#ifndef APPLE_HPP
#define APPLE_HPP

using namespace std;

class apple
{
public:
            
    int appleR;
    int appleC;
    apple();
    void newApple();
    void getApplePos(int &appleRow, int &appleCol);
    
};
//objects
apple apple1, apple2,  apple3;




#endif /* APPLE_HPP */



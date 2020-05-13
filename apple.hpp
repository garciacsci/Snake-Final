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
    void newApple1();
    void newApple2();
    void newApple3();
    void getApplePos1(int &apple1Row, int &apple1Col);
    void getApplePos2(int &apple2Row, int &apple2Col);
    void getApplePos3(int &apple2Row, int &apple2Col);
    
};
//objects
apple apple1, apple2,  apple3;




#endif /* APPLE_HPP */



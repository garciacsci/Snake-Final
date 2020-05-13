/* Contains the main function */

//// Preprocessor Directives

// Libraries
#include <cstdlib>
#include <curses.h>
#include <fstream>
#include <time.h>
#include <unistd.h>

// Inclusion of additional header files
#include "init.hpp"
#include "display.hpp"
#include "apple.hpp"
#include "snake.hpp"
#include "color.hpp"

// Name Space
using namespace std;

// 1. Declare the structure object boardInfo with file scope
info gameInfo;


//----------------------------------------------------------------------------//


// Define main function
int main(int argc, char **argv)
{
    // Declare variables
    //ifstream fin;
    ofstream fout;
    
    /* 2. Declare positional variables (if needed) to determine 
          if the snake has eaten an apple.*/
    int snakeRow, snakeCol, apple1Row, apple1Col, apple2Row, apple2Col, apple3Row, apple3Col;
    
    // 3. Open a file for saving relevant game information.
    fout.open("gameData.txt");
    
    // Make sure input file opened sucessfully
    if(fout.fail())
    {
        cout << "'gameData.txt' failed to open...";
        exit(EXIT_FAILURE);
    }   
    
    // 4. Initialize the XCurses library using a function
    cout << "calling on initXcurses...\n";    
    
    initXCurses(argc, argv);
    
    // 5. Initialize the colors using a function (if needed)
    
                 // DO THIS LATER
    
    
    // 6. Initialize the random number generator using srand()
    srand(clock());
    
    // 7. Initialize the gameInfo object using a function. 
    cout << "\ncalling on initGameInfo...\n";
    
    initGameInfo(fout);                
    
    // 8. Print a Welcome Screen using a function       
    welcome();
    
    // 9. Declare snake and apple class objects
    Snake snake();
    Apple apple;
    
    
    // GET RID OF THIS LATER
    nodelay(stdscr, FALSE);
    
    // 10. Create a loop to play the game:
    while(TRUE)
    {                
        // a. Print the game board.
        printBoard();
                                                
        // b. Move the snake with a class member function.
        snake.move();        
        
        /* c. Change the speed of the game up or down, 
              or quit the game, if necessary. */
        
                // RESEARCH CODE FOR THIS LATER
        
        
        // d. Get the snake head position with a class member function.
        snake.getHeadPos(snakeRow, snakeCol);                
        
        
        //  GET RID OF THIS LATER
        getch();
        
        
        /* e. Compare the snake position with the walls, tail, 
              and apple locations to determine appropriate action 
              (use functions, as necessary) */
        
        
            // f. End the game if the snake collides with itself or a wall
        
        
            // g. Grow the snake and generate a new apple if necessary
        
        
        // h. Update the number of apples eaten, length of the snake, etc
        
        
        /* i. Sleep for a certain number of microseconds 
              before the next iteration begins. */
        
    }
    
    // 11. Print the results of the game to the screen using a function
    
    
    // 12. Print the game information to a file (if needed)
    
    
    // Close the game window
    endwin();
    
    // Close file
    fout.close();
    
    // 13. End the program. 
    exit(EXIT_SUCCESS);                
}
//----------------------------------------------------------------------------//

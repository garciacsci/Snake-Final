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

// Define main function
int main(int argc, char **argv)
{         
    // Declare variables
    cout << "Declaring variables...\n";   
    ofstream fout;
    char ch('\0');    
    /* 2. Declare positional variables (if needed) to determine 
          if the snake has eaten an apple.*/
    int snakeRow, snakeCol, appleRow, appleCol;    
    cout << "Declared variables!\n\n";
    
    
    // 3. Open a file for saving relevant game information.
    cout << "opening gameData...\n";
    fout.open("gameData.txt");            
    // Make sure input file opened sucessfully
    if(fout.fail())
    {
        cout << "'gameData.txt' failed to open...";
        exit(EXIT_FAILURE);
    }
    else
        cout << "gameData opened successfully!\n\n";
    
    
    // 4. Initialize the XCurses library using a function
    cout << "Calling on initXcurses...\n\n";        
    initXCurses(argc, argv);    
    cout << "\nInitialized the xcurses library with initXCurses!\n\n\n";
    
    
    // 5. Initialize the colors using a function (if needed)
    
                 // DO THIS LATER
    
    
    // 6. Initialize the random number generator using srand()
    cout << "Seeding srand...\n";
    srand(clock());    
    cout << "Seeded srand with time!\n\n";
    
    
    // 7. Initialize the gameInfo object using a function. 
    cout << "\nCalling on initGameInfo...\n";    
    initGameInfo(fout);                    
    cout << "Initialized gameInfo with initGameInfo function!\n\n";
    
    
    // 8. Print a Welcome Screen using a function    
    cout << "Calling welcome function\n";    
    welcome();    
    cout << "User welcomed!\n\n";
    
    
    // 9. Declare snake and apple class objects
    cout << "Declaring snake object...\n";
    Snake snake;
    cout << "Declared snake object!\n";
    cout << "Declaring apple object...\n";
    Apple apple1;
    Apple apple2;
    Apple apple3;
    cout << "Declared apple object!\n\n";    
    
    
    cout << "\nEntering main game loop...\n\n\n";        
    // 10. Create a loop to play the game:
    while(TRUE)
    {                
        // Get character for changing game speed or quitting game
        ch = toupper(getch());
        
        // a. Print the game board.
        cout << "Calling print board function...\n";
        printBoard();
        cout << "Printed board to screen!\n\n";      
        
        // b. Move the snake with a class member function.
        cout << "Calling snake move member function...\n";
        snake.move();
        cout << "Called snake move member function!\n\n";
        
        nodelay(stdscr, TRUE);
        
        /* c. Change the speed of the game up or down, 
              or quit the game, if necessary. */        
        if (ch == 'P')
            keypress();
        else if (ch == '-')
            gameInfo.speed++;
        else if (ch == '+')
        {
            if (gameInfo.speed > 1)
                gameInfo.speed--;   
        }            
        else if (ch == 'Q')
        {
            gameInfo.outcome = GAMEOVER;
            break;
        }
        
        
        // d. Get the snake head position with a class member function.
        cout << "Calling snake get head position function...\n";
        snake.getHeadPos(snakeRow, snakeCol);
        cout << "Called snake get head position function!";
        
        
        /* e. Compare the snake position with the walls, tail, 
              and apple locations to determine appropriate action 
              (use functions, as necessary) */
        if (gameInfo.board[snakeRow][snakeCol] == -10 || \
                gameInfo.board[snakeRow][snakeCol] > 0)
        {
            // f. End the game if the snake collides with itself or a wall
            gameInfo.outcome = GAMEOVER;
            break;            
        }
        else if ((gameInfo.board[snakeRow][snakeCol] > -10 && \
                gameInfo.board[snakeRow][snakeCol] < 0))
        {
            // g. Grow the snake and generate a new apple if necessary
            gameInfo.board[snakeRow][snakeCol] = snake.tempHead();
            apple1.getApplePos(appleRow, appleCol);
            if (gameInfo.board[appleRow][appleCol] > 0)
            {
                apple1.newApple(rand()%8+24);
            }
            apple2.getApplePos(appleRow, appleCol);
            if (gameInfo.board[appleRow][appleCol] > 0)
            {
                apple2.newApple(rand()%8+24);
            }
            apple3.getApplePos(appleRow, appleCol);
            if (gameInfo.board[appleRow][appleCol] > 0)
            {
                apple3.newApple(rand()%8+24);
            }
            
            // h. Update the number of apples eaten, length of the snake, etc
            snake.incrementSnakeLength();
            apple1.incrementApplesEaten();
        }
        else
        {
            // Add in snake head
            gameInfo.board[snakeRow][snakeCol] = snake.tempHead();
            
            // Decrement the snake
            cout << "Calling decrement function...\n";
            snake.decrementSnake();
            cout << "Snake decremented!\n\n";

        }                                            
        
        /* i. Sleep for a certain number of microseconds 
              before the next iteration begins. */
        cout << "calling on usleep function...\n";
        usleep(100);
        cout << "Speed is " << gameInfo.speed << "!\n\n";
            
            
        cout << "\n\n\n";
        
    }
    
    cout << "Exited main game loop!\n\n";
    
    // 11. Print the results of the game to the screen using a function
    postGame(gameInfo.outcome);
    
    
    // 12. Print the game information to a file (if needed)
        // DON'T FORGET THIS
    
    // Close the game window
    cout << "Closing game window...\n";
    endwin();
    cout << "Closed game window!\n\n";
    
    // Close file
    cout << "Closing gameData...\n";
    fout.close();
    cout << "gameData closed!\n\n";
    
    // 13. End the program. 
    cout << "Exiting program...";
    exit(EXIT_SUCCESS);                
}
//----------------------------------------------------------------------------//

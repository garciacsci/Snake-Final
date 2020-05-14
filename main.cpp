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
#include "boulder.hpp"
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
    ifstream fin;
    char ch('\0'); 
    int bestLength, bestEaten;
    /* 2. Declare positional variables (if needed) to determine 
          if the snake has eaten an apple.*/
    int snakeRow, snakeCol, appleRow, appleCol;   
    cout << "Declared variables!\n\n";
    
    // Open gamedata to pull in high score
    cout << "opening gameData to pull in high score...\n";
    fin.open("gameData.txt");
    // Make sure input opened sucessfully
    if (fin.fail())
    {
        cout << "'gameData.txt' input failed to open...\n";
        exit(EXIT_FAILURE);
    }
    else
        cout << "gameData input opened sucessfully!\n\n";
    
    // Store best length and apples eaten
    cout << "Reading in best length and apples eaten...\n";
    fin >> bestLength >> bestEaten;
    cout << "Read in best length and apples eaten!\n";
    cout << "Best length is: " << bestLength << endl;
    cout << "Best apples eaten is: " << bestEaten << "\n\n";
    
    // Close gamedata input
    cout << "Closing gamedata input...\n";
    fin.close();
    cout << "Closed gamedata input!\n\n";
    
    // 3. Open a file for saving relevant game information.
    cout << "opening gameData...\n";
    fout.open("gameData.txt");            
    // Make sure output file opened sucessfully
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
    
    
    // 5. Initialize the colors using a function
    cout << "Initializing colors...\n";
    initColors();
    if (!has_colors())
    {
        cout << "Failed to initialize colors- " << endl << "exiting program...";
        exit(EXIT_FAILURE);
    }
    else
        cout << "Initialized colors sucessfully!\n\n";
        
    
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
    cout << "Declared snake object!\n\n";
    cout << "Declaring apple object...\n";
    Apple redApple(1);
    Apple greenApple(2);
    Apple yellowApple(3);
    cout << "Declared apple object!\n\n";    
    // Create boulder objects
    cout << "Declaring Boulders...\n";
    Boulder boulder[5];
    cout << "Declared Boulder Objects!\n\n";        
    
    
    cout << "\nEntering main game loop...\n\n\n";        
    // 10. Create a loop to play the game:
    while(TRUE)
    {                
        // Get character for changing game speed or quitting game
        ch = toupper(getch());
        
        // a. Print the game board.        
        printBoard();        
        
        // b. Move the snake with a class member function.        
        snake.move();        
                
        
        /* c. Change the speed of the game up or down, 
              or quit the game, if necessary. */        
        if (ch == 'P')
            keypress();
        else if (ch == '-' && gameInfo.speed+1 < 11)
            gameInfo.speed++;
        else if (ch == '+' && gameInfo.speed-1 > -1)
        {
            gameInfo.speed--;   
        }            
        else if (ch == 'Q')
        {
            gameInfo.outcome = GAMEOVER;
            break;
        }
        
        
        // d. Get the snake head position with a class member function.
        cout << "Calling snake get head position...\n";
        snake.getHeadPos(snakeRow, snakeCol);
        cout << "Row is: " << snakeRow << endl;
        cout << "Column is: " << snakeCol << "\n\n";
        
        
        /* e. Compare the snake position with the walls, tail, 
              and apple locations to determine appropriate action 
              (use functions, as necessary) */
        // Check if the snake hit itself or a wall
        if (gameInfo.board[snakeRow][snakeCol] == -5 || \
                gameInfo.board[snakeRow][snakeCol] > 0)
        {
            /* f. End the game if the snake collides with itself or a wall */
            cout << "Wall Collision!\n\n";
            gameInfo.outcome = GAMEOVER;
            break;            
        }
        // Check if the snake hit a boulder
        else if (gameInfo.board[snakeRow][snakeCol] == -4)
        {
            cout << "Boulder Collision!\n\n";
            if (gameInfo.difficulty == 1)
            {
                // Break the boulder
                gameInfo.board[snakeRow][snakeCol] = 0;
    
                // Cut the snake in half if it did
                snake.cut();                                
                
                // Check if snake died at boulder
                if (snake.snakeLength() <= 0)
                {                    
                    gameInfo.outcome = GAMEOVER;
                    break;
                }               
                
                // Generate new boulder
                boulder[0].newBoulder(4);
            }
            else 
            {
                gameInfo.outcome = GAMEOVER;
                break;
            }
        }
        // g. Grow the snake and generate a new apple if necessary
        // Check if the snake ate an apple
        else if ((gameInfo.board[snakeRow][snakeCol] > -4 && \
                gameInfo.board[snakeRow][snakeCol] < 0))
        {   
            // Grow the snake head
            gameInfo.board[snakeRow][snakeCol] = (snake.snakeLength()+1);
            
            // Check if a red apple was eaten
            redApple.getApplePos(appleRow, appleCol);
            if (gameInfo.board[appleRow][appleCol] > 0)
            {
                cout << "Red Apple Eaten!\n";
                redApple.newApple(1);
                gameInfo.snakeColor = 1;
            }
            
            // Check if a green apple was eaten
            greenApple.getApplePos(appleRow, appleCol);
            if (gameInfo.board[appleRow][appleCol] > 0)
            {
                cout << "Green Apple Eaten!\n";
                greenApple.newApple(2);
                gameInfo.snakeColor = 2;
            }
            
            // Check if a yellow apple was eaten
            yellowApple.getApplePos(appleRow, appleCol);
            if (gameInfo.board[appleRow][appleCol] > 0)
            {
                cout << "Yellow Apple Eaten!\n";
                yellowApple.newApple(3);
                gameInfo.snakeColor = 3;
            }
            
            // h. Update the number of apples eaten, length of the snake, etc            
            snake.incrementSnakeLength();
            redApple.incrementApplesEaten();
            cout << "Snake Length is: " << snake.snakeLength() << endl;
            cout << "Apples Eaten: " << redApple.eaten() << "\n\n";
            
            // Regenerate Boulders if difficulty is 3
            if (gameInfo.difficulty == 3)
            {
                boulder[0].clearBoulders();
                for (int i=0; i<5; i++)
                {
                    boulder[i].newBoulder(4);
                }            
            }
        }
        else
        {
            // Add in snake head
            gameInfo.board[snakeRow][snakeCol] = (snake.snakeLength()+1);
            
            // Decrement the snake
            snake.decrementSnake();
        }                                            
        
        /* i. Sleep for a certain number of microseconds 
              before the next iteration begins. */
        usleep(gameInfo.speed*(5000));
        cout << "Speed is " << gameInfo.speed << "!\n\n";
            
            
        cout << "\n\n\n";
        
    }
    
    cout << "Exited main game loop!\n\n";
    
    // 11. Print the results of the game to the screen using a function    
    // Print Results to screen
    cout << "Printing results of game to screen..\n";    
    results(bestLength, bestEaten, snake.snakeLength(), redApple.eaten());
    cout << "Results Printed!\n\n";
    
    // 12. Print the game information to a file
    cout << "Saving high scores...\n";
    fout << bestLength << endl << bestEaten;
    cout << "Wrote '" << bestLength << "' and '" << bestEaten << "' to file\n";
    cout << "High scores saved!\n\n";
    
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

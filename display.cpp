/* Snake display.cpp */

/* 
 * File:    display.cpp
 * Author:  Christopher Garcia
 * Purpose: Contains all display functions
 * Date:    14 May 2020
 */

// Include header files
#include "init.hpp"
#include "display.hpp"

// Name Space
using namespace std;

// Welcome Screen
void welcome(void)
{                           
    // Print welcome message
    mvprintw(((NROWS-1)/2-5), ((NCOLS-1)/2-9), "Welcome to Snake");    
    
    // Key press
    keypress();
    
    // Wipe the Screen
    clear();
    refresh();
    
    // Call on Player Menu
    playerMenu();
    cout << "Player preference set to " << gameInfo.preference << "!\n\n"; 
    
    // Wipe the Screen
    clear();
    refresh();
    
    // Call on game difficulty menu function
    difficultyMenu();        
    cout << "Game difficulty set to " << gameInfo.difficulty << "!\n\n";  
    
    // Wipe the Screen
    clear();
    refresh();
    
    // Set number of boulders equal to diffculty
    gameInfo.boulder = gameInfo.difficulty;        
    
    // Exit function
    return;
}

// Print Board Function
void printBoard()
{
    // Declare Variables
    int row=0, column;
    
    // Print array to window
    while (row<NROWS)
    {
        for (column=0; column<NCOLS; column++)
        {
            if (gameInfo.board[row][column] == 0 || \
                    gameInfo.board[row][column] == -10)
                mvaddch(row, column, ' ');
            else if (gameInfo.board[row][column] <0)
            {
                if (gameInfo.board[row][column] == -5)
                {
                    attron(COLOR_PAIR(5));
                    mvaddch(row, column, ACS_BLOCK);
                    attroff(COLOR_PAIR(5));
                }
                else if (gameInfo.board[row][column] == -4)
                {
                    attron(COLOR_PAIR(4));
                    mvaddch(row, column, ACS_BLOCK);
                    attroff(COLOR_PAIR(4));
                }
                else if (gameInfo.board[row][column] == -3)
                {
                    attron(COLOR_PAIR(3));
                    mvaddch(row, column, 'A');
                    attroff(COLOR_PAIR(3));
                }
                else if (gameInfo.board[row][column] == -2)
                {
                    attron(COLOR_PAIR(2));
                    mvaddch(row, column, 'A');
                    attroff(COLOR_PAIR(2));
                }
                else if (gameInfo.board[row][column] == -1)
                {
                    attron(COLOR_PAIR(1));
                    mvaddch(row, column, 'A');
                    attroff(COLOR_PAIR(1));                    
                }
                else if (gameInfo.board[row][column] < -10)
                {
                    attron(COLOR_PAIR(gameInfo.wormColor));
                    mvaddch(row, column, 'W');
                    attroff(COLOR_PAIR(gameInfo.wormColor));
                }
            }
            else 
            {
                attron(COLOR_PAIR(gameInfo.snakeColor));
                mvaddch(row, column, 'S');
                attroff(COLOR_PAIR(gameInfo.snakeColor));
            }
        }
    row++;
    }
    
    // Refresh
    refresh();
    
    // Exit function
    return;
}

// Win Screen
void win(void)
{
    // Print win message
    mvprintw(((NROWS-1)/2-1), ((NCOLS-1)/2-4), "You Win!");
    
    // Call on keypress function
    keypress();
    
    // Exit function
    return;
}

// Loss or End Screen
void loss(void)
{
    // Print loss message
    mvprintw(((NROWS-1)/2-1), ((NCOLS-1)/2-4), "You Lose");
    
    // Call on keypress function
    keypress();
    
    // Exit function
    return;
}

// Game Over 
void gameOver()
{
    // Print game over message
    mvprintw(((NROWS-1)/2-1), ((NCOLS-1)/2-4), "Game Over");
    
    // Call on keypress function
    keypress();
    
    // Exit function
    return;
}

// “Press any Key” Function
void keypress()
{    
    char c; 
    
    // Print "Press any Key" message
    mvprintw(((NROWS-1)/2), ((NCOLS-1)/2-14), "Press Any Key To Continue...");
    
    // Turn on delay
    nodelay(stdscr, FALSE);
    
    // Get a character 
    cout << "Waiting for user to press key...\n";
    c = getch();    
    cout << "Character '" << c << "' read in from user!\n";  
    
    
    // Turn on delay
    nodelay(stdscr, TRUE);
    
    // Exit function
    return;
}

// Post Difficulty Menu
void difficultyMenu()
{
    char c;
    
    while(TRUE)
    {
        // Print difficulty Message
        mvprintw(((NROWS-1)/2-1), ((NCOLS-1)/2-9), "Choose Difficulty");
        
        attron(COLOR_PAIR(2));
        mvprintw(((NROWS-1)/2+1), ((NCOLS-1)/2-9), "1.");                
        mvprintw(((NROWS-1)/2+2), ((NCOLS-1)/2-10), "Easy");
        attroff(COLOR_PAIR(2));
        
        attron(COLOR_PAIR(3));
        mvprintw(((NROWS-1)/2+2), ((NCOLS-1)/2-4), "Medium");
        mvprintw(((NROWS-1)/2+1), ((NCOLS-1)/2-2), "2.");
        attroff(COLOR_PAIR(3));
        
        attron(COLOR_PAIR(1));
        mvprintw(((NROWS-1)/2+2), ((NCOLS-1)/2+4), "Hard");
        mvprintw(((NROWS-1)/2+1), ((NCOLS-1)/2+5), "3.");
        attroff(COLOR_PAIR(1));

        // Turn on delay
        nodelay(stdscr, FALSE);

        // Get a character
        cout << "Waiting for difficulty...\n";
        c = getch();
        cout << "Difficulty " << c << " received!\n\n";

        // Turn off delay
            nodelay(stdscr, TRUE);
            
        // Make sure character is a valid difficulty
        if (c == '1')
        {
            // Update game difficulty
            gameInfo.difficulty = 1;
           
            // Exit function
            return;        
        }
        else if (c == '2')
        {
            // Update game difficulty
            gameInfo.difficulty = 2;

            // Exit function
            return;        
        }
        else if (c == '3')
        {
            // Update game difficulty
            gameInfo.difficulty = 3;

            // Exit function
            return;        
        }
    }    
}

void playerMenu()
{
    char c;
    
    while(TRUE)
    {
        // Print player menu Message
        mvprintw(((NROWS-1)/2-1), ((NCOLS-1)/2-7), "Choose Player");
        
        attron(COLOR_PAIR(2));
        mvprintw(((NROWS-1)/2+1), ((NCOLS-1)/2-9), "1.");                
        mvprintw(((NROWS-1)/2+2), ((NCOLS-1)/2-11), "Snake");
        attroff(COLOR_PAIR(2));
        
        attron(COLOR_PAIR(1));
        mvprintw(((NROWS-1)/2+2), ((NCOLS-1)/2-3), "Worm");
        mvprintw(((NROWS-1)/2+1), ((NCOLS-1)/2-2), "2.");
        attroff(COLOR_PAIR(1));
        
        attron(COLOR_PAIR(3));
        mvprintw(((NROWS-1)/2+2), ((NCOLS-1)/2+4), "Both");
        mvprintw(((NROWS-1)/2+1), ((NCOLS-1)/2+5), "3.");
        attroff(COLOR_PAIR(3));

        // Turn on delay
        nodelay(stdscr, FALSE);

        // Get a character
        cout << "Waiting for difficulty...\n";
        c = getch();
        cout << "Difficulty " << c << " received!\n\n";

        // Turn off delay
            nodelay(stdscr, TRUE);
            
        // Make sure character is a valid difficulty
        if (c == '1')
        {
            // Update player preference
            gameInfo.preference = SNAKE;
           
            // Exit function
            return;        
        }
        else if (c == '2')
        {
            // Update player preference
            gameInfo.preference = WORM;

            // Exit function
            return;        
        }
        else if (c == '3')
        {
            // Update player preference
            gameInfo.preference = BOTH;

            // Exit function
            return;        
        }
    }
}

// Call appropriate post game screen
void postGame(Res x)
{
    // Wipe the Screen
    clear();
    refresh();
    
    // Print appropriate screen based on result
    if (x == GAMEOVER)
        gameOver();
    else if (x == LOSS)
        loss();
    else if (x == WIN)
        win();    
    
    // Exit Function
    return;
}

// Print the results of the game
void results(int &bestLength, int &bestEaten, int snakeLength, int wormLength, \
        int userEaten)
{
    // Debug output variable
    int c;
    
    // Length to be displayed
    int userLength;
    
    // Add user's lengths
    userLength = snakeLength + wormLength;
    
    // Print appropriate end screen
    cout << "Starting post game display...\n";
    postGame(gameInfo.outcome);
    cout << "Post game display complete!\n\n";
    
    // Wipe Screen
    clear();
    refresh();
    
    // Print labeling
    mvprintw(((NROWS-1)/3+2), ((NCOLS-1)/2-8), "You");
    mvprintw(((NROWS-1)/3+2), (((NCOLS-1)/2)+4), "Best");    
    mvprintw((((NROWS-1)/3)+4), ((NCOLS-1)/2-22), "Length: ");
    mvprintw((((NROWS-1)/3)+6), ((NCOLS-1)/2-22), "Apples: ");
    
    // Print User scores
    mvprintw((((NROWS-1)/3)+4), ((NCOLS-1)/2-8), "%d", userLength);
    mvprintw((((NROWS-1)/3)+6), ((NCOLS-1)/2-8), "%d", userEaten);
    
    // Print Best scores
    mvprintw((((NROWS-1)/3)+4), (((NCOLS-1)/2)+4), "%d", bestLength); 
    mvprintw((((NROWS-1)/3)+6), (((NCOLS-1)/2)+4), "%d", bestEaten);        
    
    // Print Press to exit message
    mvprintw(((NROWS-1)/2), ((NCOLS-1)/2-12), "Press Any Key To Exit...");
    
    // Refresh the screen
    refresh();
    
    // Update high scores if necessary
    if (userEaten > bestEaten)
    {
        cout << "New high score!\n";
        mvprintw(((NROWS-1)/3-2), ((NCOLS-1)/2-8), "New High Score!");
        bestLength = userLength;
        cout << "Best Length: " << bestLength << endl;
        bestEaten = userEaten;
        cout << "Best Apples Eaten: " << bestEaten << "\n\n";
    }
    
    // Turn on delay
    nodelay(stdscr, FALSE);
    
    // Get a character 
    cout << "Waiting for user to press key to exit...\n";
    c = getch();    
    cout << "Character '" << c << "' read in from user!\n";  
        
    // Turn on delay
    nodelay(stdscr, TRUE);
    
    // Exit function
    return;
}

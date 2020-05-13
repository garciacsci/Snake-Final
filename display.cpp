/* Contains all display functions */

// Include header files
#include "init.hpp"
#include "display.hpp"

// Name Space
using namespace std;

// Welcome Screen
void welcome(void)
{                           
    // Print welcome message
    mvprintw(((NROWS-1)/2-1), ((NCOLS-1)/2-8), "Welcome to Snake");
    
    // Call on keypress function
    keypress();
                     
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
            if (gameInfo.board[row][column] == 0)
                mvaddch(row, column, ' ');
            else if (gameInfo.board[row][column] <0)
            {
                if (gameInfo.board[row][column] == -10)
                    color(row, column, -10);
                else
                    color(row, column, -1);
            }
            else
                color(row, column, 1);
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

// Call appropriate post game screen
void postGame(Res x)
{
    if (x == GAMEOVER)
        gameOver();
    else if (x == LOSS)
        loss();
    else if (x == WIN)
        win();
    results();
}

// Print the results of the game
void results()
{
    
    // DON'T FORGET TO FINISH THIS
    mvprintw(((NROWS-1)/2-5), ((NCOLS-1)/2-14), "Press Any Key To Continue...");
}

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
        
    cout << "Welcome message printed\n";            
    
    
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
                    mvaddch(row, column, ACS_BLOCK);
                else
                    mvaddch(row, column, 'A');
            }
            else
                mvaddch(row, column, 'S');
        }
    row++;
    }    
    
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
    // Print "Press any Key" message
    mvprintw(((NROWS-1)/2), ((NCOLS-1)/2-14), "Press Any Key To Continue...");
    
    // Turn on delay
    nodelay(stdscr, FALSE);    
    
    // Turn on delay
    nodelay(stdscr, TRUE);
    
    // Exit function
    return;
}

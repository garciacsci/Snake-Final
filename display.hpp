/* Stores display function prototypes */

#ifndef DISPLAY_HPP
#define DISPLAY_HPP

// Welcome Screen
void welcome(void);

// Print Board Function
void printBoard();

// Win Screen
void win(void);

// Loss or End Screen
void loss(void);

// Game Over 
void gameOver();

// “Press any Key” Function
void keypress();

// Post Difficulty Menu
void difficultyMenu();

// Call appropriate post game screen
void postGame(Res x);

// Print the results of the game
void results(int &bestLength, int &bestEaten, int userLength, int userEaten);

#endif /* DISPLAY_HPP */

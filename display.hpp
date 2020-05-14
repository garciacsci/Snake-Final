/* Snake display.hpp */

/* 
 * File:    display.hpp
 * Author:  Christopher Garcia
 * Purpose: Stores display function prototypes
 * Date:    14 May 2020
 */

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

// Posts player menu (worm, snake, or both);
void playerMenu();

// Call appropriate post game screen
void postGame(Res x);

// Print the results of the game
void results(int &bestLength, int &bestEaten, int snakeLength, int wormLength, \
        int userEaten);

#endif /* DISPLAY_HPP */

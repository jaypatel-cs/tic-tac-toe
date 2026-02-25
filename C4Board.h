// C4Board.h
// Defines the C4Board class, which represents the Connect Four game board.
// The board is composed of multiple C4Col objects and manages gameplay logic.

#ifndef C4BOARD_H
#define C4BOARD_H

#include "C4Col.h"

class C4Board {

public:
	C4Board(); //constructor
	void display(); //prints board
	void play(); //runs game
	void playComputer();
	bool isBoardFull(); //checks if board is full and nobody has won yet

private:
	int numCols; //always 7
	C4Col board[7]; //array of columns
	int checkWin(char d); //helper function
};

#endif
// C4Board.cpp
// Implements the Connect Four game logic, including board display,
// player turns, move validation, and win/tie detection.

#include <iostream>
#include "C4Board.h"
using namespace std;

C4Board::C4Board() {
	numCols = 7; 
}

void C4Board::display() {
	//print from top row to bottom row
	for (int row = board[0].getMaxDiscs() - 1; row >=0; row--){
		cout << "| ";
		for (int col = 0; col < numCols; col++) {
			cout << board[col].getDisc(row) << " | ";
		}

		cout << endl;
	}

	cout << "------------------------------" << endl;
	cout << "  ";
	for (int i = 0; i < numCols; i++){
		cout << i << "   ";
	}
	cout << endl;
}


int C4Board::checkWin(char d) {
	//horizontal
	for (int r = 0; r < 6; r++) {
		for (int c = 0; c < 4; c++) {
			if (board[c].getDisc(r) == d && board[c+1].getDisc(r) == d && board[c+2].getDisc(r) == d && board[c+3].getDisc(r) == d) {
				return 1;
			}
		}
	}

	//vertical
	for (int c = 0; c < 7; c++) {
		for (int r = 0; r < 3; r++) {
			if (board[c].getDisc(r) == d && board[c].getDisc(r+1) == d && board[c].getDisc(r+2) == d && board[c].getDisc(r+3) == d) {
				return 1;
			}
		}
	}

	//diagonal up and to the right
	for (int c = 0; c < 4; c++) {
		for (int r = 0; r < 3; r++) {
			if (board[c].getDisc(r) == d && board[c+1].getDisc(r+1) == d && board[c+2].getDisc(r+2) == d && board[c+3].getDisc(r+3) == d) {
				return 1;
			}
		}
	}

	//diagonal down and to the right
	for (int c = 0; c < 4; c++) {
		for (int r = 3; r < 6; r++) {
			if (board[c].getDisc(r) == d && board[c+1].getDisc(r-1) == d && board[c+2].getDisc(r-2) == d && board[c+3].getDisc(r-3) == d) {
				return 1;
			}
		}
	}

	return 0;

}

void C4Board::play() {
	int colChoice;
	int turn = 0;

	while (true) {
		display();

		char disc;
		int player;
		
		if (turn % 2 == 0) { //if its an even number then its player 1's turn otherwise it's player 2's turn
			disc = 'X';
			player = 1;
		} else {
			disc = 'O';
			player = 2;
		}

		cout << "Player " << player << " (" << disc << "), choose column (-1 to quit): "; //get column choice from user
		cin >> colChoice;

		if (colChoice == -1) {
			cout << "Game ended." << endl; //exit the game loop
			break;
		}

		if (colChoice < 0 || colChoice >= numCols){
			cout << "Invalid column." << endl; //invalid column input if its below 0 or above max columns
			continue;
		}

		if (board[colChoice].isFull()) {
			cout << "Column is full. " << endl; //checks if column is already full
			continue;
		}

		board[colChoice].addDisc(disc);

		if(checkWin(disc)) {
			display();
			cout << "Player " << player << " Wins!" << endl; // print the board and announce the winner and break the loop
			break;
		}

		turn++;

		if (isBoardFull()) {
		    display();
		    cout << "The game is a tie!" << endl; //if the board is full and nobody has won yet, it's a tie
		    break;
		}

	}	
}

void C4Board::playComputer() { //human vs computer
    int colChoice;
    int turn = 0;

    while (true) {

        display();

        char disc;
        int player;

        if (turn % 2 == 0) { //player one stuff is the same as human vs human
			// Human (Player 1)
            disc = 'X';
            player = 1;

            cout << "Player " << player << " (" << disc
                 << "), choose column (-1 to quit): ";
            cin >> colChoice;

            if (colChoice == -1) {
                cout << "Game ended." << endl;
                break;
            }

            if (colChoice < 0 || colChoice >= numCols) {
                cout << "Invalid column." << endl;
                continue;
            }

            if (board[colChoice].isFull()) {
                cout << "Column is full." << endl;
                continue;
            }

        } else { //different from human vs human. now computer automatically picks the first available column and places its disc there
            // Computer (Player 2)
            disc = 'O';
            player = 2;

            // first available column
            for (int c = 0; c < numCols; c++) {
                if (!board[c].isFull()) {
                    colChoice = c;
                    break;
                }
            }

            cout << "Computer chooses column " << colChoice << endl;

        }

        board[colChoice].addDisc(disc);

        if (checkWin(disc)) {
            display();

            if (player == 2)
                cout << "Computer wins!" << endl;
            else
                cout << "Player " << player << " wins!" << endl;
            break;
        }

		if (isBoardFull()) {
			display();
    		cout << "The game is a tie!" << endl;  //if the board is full and nobody has won yet, it's a tie
    		break;
		}


        turn++;

    }
}

bool C4Board::isBoardFull() {
	for (int c = 0; c < numCols; c++) {
		if (!board[c].isFull()) {
			return false; // Found at least one column that is not full
		}
	}
	return true; // All columns are full
}







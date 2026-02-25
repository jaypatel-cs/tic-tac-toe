#include <iostream>
using namespace std;

//function to check all rows, columns, and both diagonals of the board to determine who won or if its a tie
//has two inputs. the board after its been cin'ed and the size of the board
char checkWinner(char board[5][5], int N) {

    char first; //to store the first cell in a row, column, or diagonal

    // Check rows
    for (int i = 0; i < N; i++) {
        first = board[i][0];
        if (first == '-') continue; //can't win if it starts with an empty cell so we skip this iteration

        bool win = true;
        for (int j = 1; j < N; j++) {
            if (board[i][j] != first) { //if any cell in the row doesn't match no win
                win = false;
                break;
            }
        }
        if (win) return first;
    }

    // Check columns
	// basically the same thing as checking the rows but just flipping i and j
    for (int j = 0; j < N; j++) {
        first = board[0][j];
        if (first == '-') continue;

        bool win = true;
        for (int i = 1; i < N; i++) {
            if (board[i][j] != first) {
                win = false;
                break;
            }
        }
        if (win) return first;
    }

    // Check top left to bottom right diagonal
    first = board[0][0];
    if (first != '-') {
        bool win = true;
        for (int i = 1; i < N; i++) {
            if (board[i][i] != first) { //compares all diagonal cells to the first diagonal cell
                win = false;
                break;
            }
        }
        if (win) return first;
    }

    // Check top right to bottom left diagonal
    first = board[0][N - 1]; 
    if (first != '-') {
        bool win = true;
        for (int i = 1; i < N; i++) {
            if (board[i][N - 1 - i] != first) { //move down rows while moving left across columns
                win = false;
                break;
            }
        }
        if (win) return first;
    }

    // No winner
    return '-';
}


int main(int argc, char* argv[]) {
	int N;
	char board[5][5];

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	
	char winner = checkWinner(board, N);

	if (winner == 'X') {
		cout << "X wins" << endl;
	}else if (winner == 'O') {
		cout << "O wins" << endl;
	}else {
		cout << "Tie" << endl;
	}
	
	return 0;
}

// Lab 1:  Tic-tac-toe solver
#include <iostream>
using namespace std;

//kept the same function to check if theres a winner from toecheck.cpp
char checkWinner(char board[5][5], int N) {

    // Check rows
    for (int r = 0; r < N; r++) {
        if (board[r][0] == '-') continue;

        int count = 1;
        for (int c = 1; c < N; c++) {
            if (board[r][c] == board[r][0]) {
                count++;
            }
        }

        if (count == N) return board[r][0];
    }

    // Check columns
    for (int c = 0; c < N; c++) {
        if (board[0][c] == '-') continue;

        int count = 1;
        for (int r = 1; r < N; r++) {
            if (board[r][c] == board[0][c]) {
                count++;
            }
        }

        if (count == N) return board[0][c];
    }

    // Diagonal topleft to bottom right
    if (board[0][0] != '-') {
        int count = 1;
        for (int i = 1; i < N; i++) {
            if (board[i][i] == board[0][0]) {
                count++;
            }
        }

        if (count == N) return board[0][0];
    }

    // Diagonal top right to bottom left
    if (board[0][N - 1] != '-') {
        int count = 1;
        for (int i = 1; i < N; i++) {
            if (board[i][N - 1 - i] == board[0][N - 1]) {
                count++;
            }
        }

        if (count == N) return board[0][N - 1];
    }

    return '-';
}


int main(int argc, char *argv[]) {
	int N;
	char board[5][5];

	cout << "Enter board size (3-5): ";
	cin >> N;
	while (N < 3 || N > 5) {
		cout << "Invalid board size. Please enter a number between 3 and 5: ";
		cin >> N;
	}

	//initialize board to '-' so checkWinner function can skip over these values if they are empty 
	//and to know later when the player inputs to see if that spot they chose is empty or not
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = '-';
		}
	}

	int turns = 0;
	int maxTurns = N*N;
	int row;
	int column;
	while (turns < maxTurns && checkWinner(board, N) == '-') {
	
		if (turns % 2 == 0) {
			cout << "Player X's Turn" << endl;
			cout << "Enter row and column: ";
			cin >> row;
			cin >> column;
			while (row > N || row < 1 || column > N || column < 1 || board[row-1][column-1] != '-'){
				cout << "Invalid move. Please re-enter row and column: ";
				cin >> row;
				cin >> column;
			}
			board[row-1][column-1] = 'X';
			char winner = checkWinner(board, N);
			if (winner != '-') {
				cout << winner << " wins!" << endl;
				break;
			}
			turns++;
		}
		if (turns % 2 == 1) {
			cout << "Player O's Turn" << endl;
			cout << "Enter row and column: ";
			cin >> row;
			cin >> column;
			while (row > N || row < 1 || column > N || column < 1 || board[row-1][column-1] != '-'){
				cout << "Invalid move. Please re-enter row and column: ";
                cin >> row;
                cin >> column;
            }
            board[row-1][column-1] = 'O';
			char winner = checkWinner(board, N);
			if (winner != '-') {
				cout << winner << " wins!" << endl;
				break;
			}
			turns++;
		}

	}

	return 0;
}


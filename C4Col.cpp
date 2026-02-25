// C4Col.cpp
// Implements the C4Col class member functions, including disc storage,
// boundary checking, and column capacity logic.

#include "C4Col.h"
#include <iostream>

using namespace std;

C4Col::C4Col() {
	numDiscs = 0;
	maxDiscs = 6;

	//fill column with empty spaces
	for (int i = 0; i < maxDiscs; i++) {
		discs[i] = ' ';
	}

}

int C4Col::isFull() {
	return numDiscs == maxDiscs; //returns if number of discs is equal to max discs
}

char C4Col::getDisc(int i) {
	if (i < 0 || i >= maxDiscs) {
		cout << "Invalid disc index." << endl;
		return ' ';
	}
	if (i >= numDiscs) return ' ';
	return discs[i];
}

int C4Col::getMaxDiscs() {
	return maxDiscs;
}

void C4Col::addDisc(char d) {
	if (isFull()) {
		cout << "Column is full." << endl;
		return;
	}

	discs[numDiscs] = d;
	numDiscs++;
}

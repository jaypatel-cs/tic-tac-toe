# Tic-Tac-Toe (C++)

## Overview
A command-line Tic-Tac-Toe game written in C++.  
Supports both two-player mode and a player vs computer mode.

## Features
- Two-player turn-based gameplay
- Player vs Computer mode
- Board display after each move
- Input validation (prevents selecting occupied positions)
- Win detection (rows, columns, diagonals)
- Draw detection when board is full

## Computer Logic
- Basic AI that selects valid moves automatically
- Separates game logic from computer decision logic
- Demonstrates conditional decision-making and game-state evaluation

## Concepts Used
- Arrays for board representation
- Functions for modular design
- Conditionals and loops
- Game-state management
- Basic AI logic implementation

## How to Run
Compile:
```bash
g++ -std=c++17 -O2 -Wall -Wextra main.cpp -o tictactoe

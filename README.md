# sudoku
A simple command-line Sudoku solver in C for educational purposes. It usages Backtracking Algorithm to find solution.

This is a simple command-line Sudoku solver written in C for mere educational
purposes. It expects a partially solved Sudoku board as input, that will be
read from standard input or the file given as the first program argument, if
given. Then, it will try to solve the board and print it solved on standard
output.

The input format is simple. The board must be given as cells from top to bottom
and left to right, with empty cells represented by 0 and other cells
represented by its value. Example:

5 3 0 0 7 0 0 0 0 
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9

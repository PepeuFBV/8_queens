#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 8 // chessboard size (NxN)

bool board[N][N]; // either true (occupied) or false (empty)

typedef struct Position {
    int row;
    int col;
} Position;

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

void addToBoard(Position *positions) {
    for (int i = 0; i < N; i++) {
        board[positions[i].row][positions[i].col] = true;
    }
}

void resetBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = false;
        }
    }
}

bool isValidSolution(Position *positions) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (positions[i].row == positions[j].row) return false; // same row
            if (positions[i].col == positions[j].col) return false; // same column
            if (abs(positions[i].row - positions[j].row) == abs(positions[i].col - positions[j].col)) return false; // same diagonal
        }
    }
    return true;
}

void generateCombinations(Position *positions, int *columns, int index, int *solutionCount) {
    if (index == N) { // all queens are placed
        if (isValidSolution(positions)) {
            (*solutionCount)++;
            printf("Solution %d:\n", *solutionCount);
            resetBoard();
            addToBoard(positions);
            printBoard();
        }
        return;
    }
    
    for (int col = 0; col < N; col++) { // try placing queen in each column
        positions[index].row = index;
        positions[index].col = col;
        generateCombinations(positions, columns, index + 1, solutionCount);
    }
}

void bruteForce() {
    Position positions[N];
    int columns[N];
    int solutionCount = 0;
    
    printf("Starting brute force search for 8 Queens solutions...\n\n");
    
    generateCombinations(positions, columns, 0, &solutionCount);
    
    printf("Total solutions found: %d\n", solutionCount);
}

void main() {
    resetBoard();
    bruteForce();
    printf("Brute force search completed.\n");
}

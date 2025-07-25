#include "solver.h"
#include <stdio.h>
#include <stdlib.h>

bool isValidSolution(Position *positions) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (positions[i].row == positions[j].row) return false;
            if (positions[i].col == positions[j].col) return false;
            if (abs(positions[i].row - positions[j].row) == abs(positions[i].col - positions[j].col)) return false;
        }
    }
    return true;
}

void bruteForceHelper(Position *positions, int placed, int *solutionCount, int start) {
    if (placed == N) {
        if (isValidSolution(positions)) {
            (*solutionCount)++;
            printf("Solution %d:\n", *solutionCount);
            resetBoard();
            addToBoard(positions);
            printBoard();
        }
        return;
    }
    for (int i = start; i < N * N; i++) {
        positions[placed].row = i / N;
        positions[placed].col = i % N;
        bruteForceHelper(positions, placed + 1, solutionCount, i + 1);
    }
}

void bruteForce(int *solutionCount) {
    Position positions[N];
    bruteForceHelper(positions, 0, solutionCount, 0);
}

bool isSafe(Position *positions, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (positions[i].col == col || abs(positions[i].row - row) == abs(positions[i].col - col)) { // checks if the position is "under attack"
            return false;
        }
    }
    return true;
}

void backtracking(Position *positions, int row, int *solutionCount) {
    if (row == N) {
        (*solutionCount)++;
        printf("Solution %d:\n", *solutionCount);
        resetBoard();
        addToBoard(positions);
        printBoard();
        return;
    }
    for (int col = 0; col < N; col++) {
        if (isSafe(positions, row, col)) {
            positions[row].row = row;
            positions[row].col = col;
            backtracking(positions, row + 1, solutionCount);
        }
    }
}

void solveQueens(SolverApproach approach) {
    Position positions[N];
    int solutionCount = 0;

    if (approach == BACKTRACKING) {
        printf("Starting backtracking search for 8 Queens solutions...\n\n");
        backtracking(positions, 0, &solutionCount);
        printf("Total solutions for backtracking: %d\n", solutionCount);
    } else {
        printf("Starting brute force search for 8 Queens solutions...\n\n");
        bruteForce(&solutionCount);
        printf("Total solutions for brute force: %d\n", solutionCount);
    }
}

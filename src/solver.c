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

void generateCombinations(Position *positions, int index, int *solutionCount) {
    if (index == N) {
        if (isValidSolution(positions)) {
            (*solutionCount)++;
            printf("Solution %d:\n", *solutionCount);
            resetBoard();
            addToBoard(positions);
            printBoard();
        }
        return;
    }
    for (int col = 0; col < N; col++) {
        positions[index].row = index;
        positions[index].col = col;
        generateCombinations(positions, index + 1, solutionCount);
    }
}

void bruteForce(int *solutionCount) {
    Position positions[N];
    generateCombinations(positions, 0, solutionCount);
}

bool isSafe(Position *positions, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (positions[i].col == col ||
            abs(positions[i].row - row) == abs(positions[i].col - col)) {
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

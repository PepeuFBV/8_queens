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

void bruteForce() {
    Position positions[N];
    int solutionCount = 0;
    printf("Starting brute force search for 8 Queens solutions...\n\n");
    generateCombinations(positions, 0, &solutionCount);
    printf("Total solutions found: %d\n", solutionCount);
}

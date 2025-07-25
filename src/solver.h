#ifndef SOLVER_H
#define SOLVER_H

#include "board.h"

typedef enum {
    BRUTE_FORCE,
    BACKTRACKING
} SolverApproach;

void solveQueens(SolverApproach approach);

bool isValidSolution(Position *positions);
void bruteForceHelper(Position *positions, int placed, int *solutionCount, int start);
void bruteForce(int *solutionCount);
bool isSafe(Position *positions, int row, int col);
void backtracking(Position *positions, int row, int *solutionCount);

#endif // SOLVER_H

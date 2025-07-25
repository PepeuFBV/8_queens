#ifndef SOLVER_H
#define SOLVER_H

#include "board.h"

typedef enum {
    BRUTE_FORCE,
    BACKTRACKING
} SolverApproach;

void solveQueens(SolverApproach approach);

bool isValidSolution(Position *positions);
void bruteForce();
void backtracking();

#endif // SOLVER_H

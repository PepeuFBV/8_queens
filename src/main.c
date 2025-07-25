#include <stdio.h>
#include <string.h>
#include <time.h>
#include "board.h"
#include "solver.h"

int main(int argc, char *argv[]) {
    clock_t start, end;
    double cpu_time;
    SolverApproach approach = BRUTE_FORCE; // default

    if (argc > 1) {
        if (strcmp(argv[1], "BRUTE_FORCE") == 0) {
            approach = BRUTE_FORCE;
        } else if (strcmp(argv[1], "BACKTRACKING") == 0) {
            approach = BACKTRACKING;
        }
    }

    start = clock();

    resetBoard();
    solveQueens(approach);

    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %.5f seconds\n", cpu_time);

    return 0;
}

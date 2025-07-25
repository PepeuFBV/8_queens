#include <stdio.h>
#include <time.h>
#include "board.h"
#include "solver.h"

int main() {
    clock_t start, end;
    double cpu_time;

    start = clock();

    resetBoard();
    bruteForce();
    printf("Brute force search completed.\n");

    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %.5f seconds\n", cpu_time);

    return 0;
}

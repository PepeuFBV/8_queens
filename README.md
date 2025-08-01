# 8 Queens

This repository contains solutions to the classic 8 Queens problem using both brute force and backtracking algorithms. The objective is to place 8 queens on an 8x8 chessboard so that no two queens threaten each other (i.e., no two queens share the same row, column, or diagonal).

## Problem Description

The 8 Queens problem is a well-known combinatorial puzzle. The challenge is to find all possible arrangements of 8 queens on a chessboard such that no queen can attack another. This means no two queens can be in the same row, column, or diagonal.

## Requirements

- C compiler (e.g., `gcc`)
- Shell (e.g., `bash`)

> [!WARNING]
> You may need to adjust the permissions of the `build-and-run.sh` script to make it executable. You can do this by running:
> ```bash
> chmod +x build-and-run.sh
> ```

## How to Build and Run

You can build and run the project using the provided script. By default (no args call), the script will use the brute force approach. If you want to use the backtracking approach, you can specify it as an argument:

```bash
./build-and-run.sh BACKTRACKING
```

You can also specify for the brute force approach too if you want:

```bash
./build-and-run.sh BRUTE_FORCE
```
## Algorithms

### Brute Force

The brute force approach generates all possible placements of 8 queens on the board and checks each arrangement for validity. This method is computationally expensive because it explores every combination, but it guarantees finding all solutions.

**How it works:**

- It tries every possible way to place 8 queens on the 8x8 board (without reusing squares).
- For each arrangement, it checks if any two queens threaten each other (same row, column, or diagonal).
- If the arrangement is valid, it is counted as a solution.

**Relevant code:**
```c
void bruteForceHelper(Position *positions, int placed, int *solutionCount, int start) {
    if (placed == N) {
        if (isValidSolution(positions)) {
            (*solutionCount)++;
            // ... print solution ...
        }
        return;
    }
    for (int i = start; i < N * N; i++) {
        positions[placed].row = i / N;
        positions[placed].col = i % N;
        bruteForceHelper(positions, placed + 1, solutionCount, i + 1);
    }
}
```

### Backtracking

The backtracking approach places queens one by one in each row, only in positions that are not under attack. If a conflict is found, it backtracks to try a different position. This method is much more efficient and is the standard approach for the N-Queens problem.

**How it works:**

- Place a queen in the first row, then move to the next row.
- For each row, try placing a queen in each column, checking if it is safe.
- If a safe position is found, move to the next row; otherwise, backtrack.
- Continue until all queens are placed.

**Relevant code:**
```c
void backtracking(Position *positions, int row, int *solutionCount) {
    if (row == N) {
        (*solutionCount)++;
        // ... print solution ...
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
```

Both approaches are implemented in `src/solver.c`. The brute force method is useful for educational purposes, while backtracking is preferred for efficiency.

## License
This project is licensed under the [MIT License](LICENSE). Feel free to use and modify the code as you wish.

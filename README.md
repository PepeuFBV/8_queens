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

- Brute Force:
Generates all possible placements of queens and checks each for validity. This approach is computationally expensive but guarantees all solutions.

- Backtracking:
Places queens one by one, only in safe positions, and backtracks when a conflict is found. This is much more efficient and is the standard approach for this problem.


## License
This project is licensed under the [MIT License](LICENSE). Feel free to use and modify the code as you wish.

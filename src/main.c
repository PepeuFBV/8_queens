// 8 queens problem solution in C

#include <stdio.h>
#include <stdbool.h>

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

void main() {
    Position positions[N] = {
        {0, 0}
    };
    addToBoard(positions);
    printBoard();
}

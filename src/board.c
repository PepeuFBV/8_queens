#include "board.h"
#include <stdio.h>

bool board[N][N];

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

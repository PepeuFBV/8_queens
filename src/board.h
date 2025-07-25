#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>

#define N 8

typedef struct Position {
    int row;
    int col;
} Position;

extern bool board[N][N];

void printBoard();
void addToBoard(Position *positions);
void resetBoard();

#endif // BOARD_H

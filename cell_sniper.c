
#include <stdio.h>
#include <stdlib.h>

#include "game_state.h"

int main()
{
  Board* board = (Board*) malloc(sizeof(Board));

  clearBoard(board);

  setBoardCell(board, 2, 4, ALPHA);
  setBoardCell(board, 5, 2, EPSILON);
  setBoardCell(board, 1, 1, GAMMA);

  printf("cell 1: %d\n", getBoardCell(board, 5, 2));
  printf("cell 2: %d\n", getBoardCell(board, 2, 4));
  printf("cell 3: %d\n", getBoardCell(board, 1, 1));
  printf("cell 4: %d\n", getBoardCell(board, 4, 2));

  free(board);
}
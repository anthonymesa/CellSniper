
#include <stdio.h>
#include <stdlib.h>

enum variant
{
  ALPHA = 1,
  BETA,
  DELTA,
  GAMMA,
  EPSILON,
  END
};

typedef struct row 
{
  unsigned char cell_01 : 3;
  unsigned char cell_02 : 3;
  unsigned char cell_03a : 2;
  unsigned char cell_03b : 1;
  unsigned char cell_04 : 3; 
  unsigned char cell_05 : 3;
  unsigned char cell_06a : 1;
  unsigned char cell_06b : 2;
  unsigned char cell_07 : 3;
  unsigned char cell_08 : 3; 
} Row;

typedef struct board
{
  Row row_1;
  Row row_2;
  Row row_3;
  Row row_4;
  Row row_5;
  Row row_6;
  Row row_7;
} Board;

void setRowCell(Row* _row, int _index, enum variant _value)
{
  switch(_index)
  {
    case 1:
      _row->cell_01 = _value;
      break;
    case 2:
      _row->cell_02 = _value;
      break;
    case 3:
      _row->cell_03b = _value & 1;
      _row->cell_03a = _value >> 1;
      break;
    case 4:
      _row->cell_04 = _value;
      break;
    case 5:
      _row->cell_05 = _value;
      break;
    case 6:
      _row->cell_06b = _value & 2;
      _row->cell_06a = _value >> 2;
      break;
    case 7:
      _row->cell_07 = _value;
      break;
    case 8:
      _row->cell_08 = _value;
      break;
  }
}

enum variant getRowCell(Row* _row, int _index)
{
  int temp_value = 0;
  switch(_index)
  {
    case 1:
      temp_value = _row->cell_01;
      return (enum variant) temp_value;
    case 2:
      temp_value = _row->cell_02;
      return (enum variant) temp_value;
    case 3:
      temp_value += _row->cell_03a << 1;
      temp_value += _row->cell_03b;
      return (enum variant) temp_value;
    case 4:
      temp_value = _row->cell_04;
      return (enum variant) temp_value;
    case 5:
      temp_value = _row->cell_05;
      return (enum variant) temp_value;
    case 6:
      temp_value += _row->cell_06a << 2;
      temp_value += _row->cell_06b;
      return (enum variant) temp_value;
    case 7:
      temp_value = _row->cell_07;
      return (enum variant) temp_value;
    case 8:
      temp_value = _row->cell_08;
      return (enum variant) temp_value;
  }
}

void setBoardCell(Board* _board, int _xindex, int _yindex, enum variant _value)
{
  switch(_yindex)
  {
    case 1:
      setRowCell(&_board->row_1, _xindex, _value);
      return;
    case 2:
      setRowCell(&_board->row_2, _xindex, _value);
      return;
    case 3:
      setRowCell(&_board->row_3, _xindex, _value);
      return;
    case 4:
      setRowCell(&_board->row_4, _xindex, _value);
      return;
    case 5:
      setRowCell(&_board->row_5, _xindex, _value);
      return;
    case 6:
      setRowCell(&_board->row_6, _xindex, _value);
      return;
    case 7:
      setRowCell(&_board->row_7, _xindex, _value);
      return;
  }
}

enum variant getBoardCell(Board* _board, int _xindex, int _yindex)
{
  switch(_yindex)
  {
    case 1:
      return getRowCell(&_board->row_1, _xindex);
    case 2:
      return getRowCell(&_board->row_2, _xindex);
    case 3:
      return getRowCell(&_board->row_3, _xindex);
    case 4:
      return getRowCell(&_board->row_4, _xindex);
    case 5:
      return getRowCell(&_board->row_5, _xindex);
    case 6:
      return getRowCell(&_board->row_6, _xindex);
    case 7:
      return getRowCell(&_board->row_7, _xindex);
  }
}

void clearRow(Row* _row)
{
  setRowCell(_row, 1, 0);
  setRowCell(_row, 2, 0);
  setRowCell(_row, 3, 0);
  setRowCell(_row, 4, 0);
  setRowCell(_row, 5, 0);
  setRowCell(_row, 6, 0);
  setRowCell(_row, 7, 0);
  setRowCell(_row, 8, 0);
}

void clearBoard(Board* _board)
{
  clearRow(&_board->row_1);
  clearRow(&_board->row_2);
  clearRow(&_board->row_3);
  clearRow(&_board->row_4);
  clearRow(&_board->row_5);
  clearRow(&_board->row_6);
  clearRow(&_board->row_7);
}

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

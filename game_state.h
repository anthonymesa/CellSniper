
enum variant
{
  EMPTY = 0,
  ALPHA,
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

void setRowCell(Row* _row, int _index, enum variant _value);
enum variant getRowCell(Row* _row, int _index);
void setBoardCell(Board* _board, int _xindex, int _yindex, enum variant _value);
enum variant getBoardCell(Board* _board, int _xindex, int _yindex);
void clearRow(Row* _row);
void clearBoard(Board* _board);
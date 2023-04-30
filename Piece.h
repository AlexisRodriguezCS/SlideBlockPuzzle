//  Author Information

//  File Information
#include <fstream>
#include <iostream>
#include <sstream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Piece {
private:
  int row;
  int column;
  int height;
  int width;
  char name;
  char movement;
  bool goalPiece;

public:
  /**
   * constructor and destructor
   */
  Piece(int row, int column, int height, int width, char movement) {
    this->row = row;
    this->column = column;
    this->height = height;
    this->width = width;
    this->movement = movement;
    this->goalPiece = false;
  }

  /*
   * function: setLocation
   * description:  sets the row and column of the piece
   *
   * return:  void
   */
  void setLocation(int row, int column) {
    this->row = row;
    this->column = column;
  }

  /*
   * function: setRow
   * description:  sets the row of the piece
   *
   * return:  void
   */
  void setRow(int row) { this->row = row; }

  /*
   * function: setColumn
   * description:  sets the column of the piece
   *
   * return:  void
   */
  void setColumn(int column) { this->column = column; }

  /*
   * function: setName
   * description:  sets the name of the piece
   *
   * return:  void
   */
  void setName(char name) { this->name = name; }

  /*
   * function: setGoalPiece
   * description: sets the value of goalPiece to true
   *
   * return:  void
   */
  void setGoalPiece() { goalPiece = true; }

  /*
   * function: getName
   * description: return the name of the piece
   *
   * return:  a character that represents the piece name
   */
  char getName() { return name; }

  /*
   * function: getX
   * description: return the index of the row
   *
   * return:  an integer containing the row value
   */
  int getRow() { return row; }

  /*
   * function: getY
   * description: return the index of the column
   *
   * return:  an integer containing the column value
   */
  int getColumn() { return column; }

  /*
   * function: isGoalPiece
   * description: return the value of goalPiece
   *
   * return:  an boolean containing the goalPiece value
   */
  bool isGoalPiece() { return goalPiece; }

  /*
   * function: getMovement
   * description: return the value of movement
   *
   * return:  an char containing the movement value
   */
  char getMovement() { return movement; }

  /*
   * function: getHeight
   * description: return the value of height
   *
   * return:  an integer containing the height value
   */
  int getHeight() { return height; }

  /*
   * function: getWidth
   * description: return the value of width
   *
   * return:  an integer containing the width value
   */
  int getWidth() { return width; }

  /*
   * function: stats
   * description:
   *
   * return:
   */
  void stats() {
    cout << "Piece " << name << " stats: "
         << "Row: " << row << ", Column: " << column << ", Width: " << width
         << ", Height: " << height << endl;
  }
};
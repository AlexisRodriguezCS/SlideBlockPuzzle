//  Author Information
//  Alexis Rodriguez
//  Jonah Covarrubias
//  File Information

#include "Movement.h"

class Grid {
 private:
  int rows;
  int columns;
  int numberOfPieces;
  char upper;
  char lower;
  vector<vector<char>> grid;
  vector<Piece> Pieces;

 public:
  /*
   * function: Grid
   * description:  sets the rows,columns, height of the Grid
   *
   * return:  void
   */
  Grid(int row, int column) {
    setRows(row);
    setColumns(column);
    grid = vector<vector<char>>(row, vector<char>(column, '.'));
    numberOfPieces = 0;
    upper = 65;
    lower = 97;
  }

  /*
   * function: printGrid
   * description: Goes through the grid and prints the grid
   *
   * return:  void
   */
  void print() {
    // Top row of stars
    cout << string(columns + 2, '*') << endl;
    // Prints all the values
    for (int row = 0; row < rows; row++) {
      cout << "*";
      for (int col = 0; col < columns; col++) {
        cout << grid[row][col];
      }
      cout << "*" << endl;
    }
    // Bottom row of stars
    cout << string(columns + 2, '*') << endl;
  }

  /*
   * function: setRows
   * description: Sets the number of rows for the Grid
   *
   * return:  void
   */
  void setRows(int rows) {
    if (rows <= 0) {
      cout << "Error: Number of rows must be greater than zero" << endl;
      exit(0);
    } else {
      this->rows = rows;
    }
  }

  /*
   * function: setColumns
   * description:	Sets the columns of rows for the Grid
   *
   * return:  void
   */
  void setColumns(int columns) {
    if (columns <= 0) {
      cout << "Error: Number of columns must be greater than zero" << endl;
      exit(0);
    } else {
      this->columns = columns;
    }
  }

  /*
   * function: getRows
   * description: returns the number of rows of the grid.
   *
   * return: an integer containing the number of rows
   */
  int getRows() { return rows; }

  /*
   * function: getColumns
   * description: returns the number of columns of the grid.
   *
   * return:	an integer containing the number of columns
   */
  int getColumns() { return columns; }

  /*
   * function: overlaps
   * description: determines if the row, col overlaps another piece by using
	 * 		 the width, and height and checking the location at row, col.
   *
   * return:	indicates success/failure
   */
  bool overlaps(int row, int col, int width, int height) {
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        if (grid[row - 1 + i][col - 1 + j] != '.') {
          return true;
        }
      }
    }
    return false;
  }

  /*
   * function: addPiece
   * description: Adds the piece to the vector and grid after
	 *		doing a series of checks.
   *
   * return: void
   */
  void addPiece(int row, int col, int width, int height, char movement) {
    // Check if the piece would fall outside of the puzzle grid
    bool error = false;
    Movement move;
    if (move.outOfBounds(rows, columns, row, col, height, width)) {
      cout << "Warning: Piece with starting position of " << row << "," << col
           << " falls outside of grid" << endl;
      error = true;
    }

    // have an invalid direction of movement
    else if (movement != 'b' && movement != 'h' && movement != 'v' &&
        movement != 'n') {
      cout << "Warning: Piece with starting position of " << row << "," << col
           << " has invalid movement" << endl;
      error = true;
    }

    // or overlap with another piece
    else if (overlaps(row, col, width, height)) {
      cout << "Warning: Piece with starting position of " << row << "," << col
           << " overlaps with other piece" << endl;
      error = true;
    }

    // Only 61 valid pieces are allowed
    else if (numberOfPieces >= 60) {
      cout << "Warning: Piece with starting position of " << row << "," << col
           << " will not be added since there is already 61 valid pieces"
           << endl;
      error = true;
    }

    // No error, add piece to Grid
    if (!error) {
      // Make a new Piece
      Piece newPiece = Piece(row, col, height, width, movement);
      setPieceName(newPiece);
      // cout << "getName: " << newPiece.getName() << endl;
      numberOfPieces++;
      Pieces.push_back(newPiece);
      // cout << "numberOfPieces: " << numberOfPieces << endl;
      // cout << "row: " << row << endl;
      // cout << "col: " << col << endl;
      //   Make the indexes in Pieces vector have the name of Piece
      for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
          grid[row - 1 + i][col - 1 + j] = newPiece.getName();
        }
      }
    }
  }

  /*
   * function: setPieceName
   * description: Sets the piece's name
   *
   * return:	void
   */
  void setPieceName(Piece &currentPiece) {
    if (numberOfPieces == 0) {
      // set name to Z
      currentPiece.setName('Z');
      // update goalPiece to true
      currentPiece.setGoalPiece();
    } else if (numberOfPieces <= 9) {
      // name can be 1-9
      char name = '0' + numberOfPieces;
      // cout << "name: " << id << endl;
      currentPiece.setName(name);
    } else if (numberOfPieces >= 10 && numberOfPieces < 36) {
      // name can be a-z
      // cout << "name: " << lower << endl;
      currentPiece.setName(lower);
      lower++;
    } else {
      // name can be A-Z
      // cout << "name: " << upper << endl;
      currentPiece.setName(upper);
      upper++;
    }
  }

  /*
   * function: getGrid
   * description: returns the 2d char grid 
   *
   * return:  a vector containing the current grid 
   */
  vector<vector<char>> &getGrid() { return grid; }

  /*
   * function: getPieces
   * description:
   *
   * return:  a vector containing all the pieces
   */
  vector<Piece> getPieces() const { return Pieces; }
};

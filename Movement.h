//  Author Information
//  Alexis Rodriguez
// 	Jonah Covarrubias
//  File Information

#include "Piece.h"

class Movement {
 public:
  /*
   * function: canMove
   * description: determines if the piece can move
   *
   * return:  indicates success/failure
   */
  bool canMove(Piece piece) {
    // "n" for no movement (the piece cannot move, it must stay in that space).
    if (piece.getMovement() == 'n') {
      return false;
    }
    return true;
  }

  /*
   * function: canMoveVertically
   * description: determines if the piece can move up or down
   *
   * return:  indicates success/failure
   */
  static bool canMoveVertically(char direction) {
    // "v" for vertical movement (up or down)
    // "b" for both horizontal and vertical movement
    if (direction == 'b' || direction == 'v') {
      return true;
    }
    return false;
  }

  /*
   * function: canMoveHorizontally
   * description: determines if the piece can move left or right
   *
   * return:  indicates success/failure
   */
  static bool canMoveHorizontally(char direction) {
    // "h" for horizontal movement (left or right)
    // "b" for both horizontal and vertical movement
    if (direction == 'b' || direction == 'h') {
      return true;
    }
    return false;
  }

  /*
   * function: outOfBounds
   * description: determines if the row, col  will fall out of bounds 
	 *		by using the rows, columns as the boundaries, and will use
	 *		the height and width to help calculate.
   *
   * return:  indicates success/failure
   */
  static bool outOfBounds(int rows, int columns, int row, int col, int height,
                   int width) {
    // Check if starting position is out of bounds
    if (row <= 0 || row > rows || col <= 0 || col > columns) {
      return true;
    }

    // Check if height makes the piece fall out of bounds
    if ((row + height) - 1 > rows) {
      return true;
    }

    // Check if width makes the piece fall out of bounds
    if ((col + width) - 1 > columns) {
      return true;
    }

    return false;
  }

  /*
   * function: overlapsUp
   * description:  determines if moving the piece up will overlap
	 * 		with another piece.
   *
   * return:  indicates success/failure
   */
  static bool overlapsUp(string pieceLayout, Piece piece, int columns) {
    int startingCol = piece.getColumn();
    int endingCol = startingCol + piece.getWidth() - 1;
    // loop through width of piece and check the spot above
    for (int col = startingCol; col <= endingCol; col++) {
      int upIndex = ((piece.getRow() - 2) * columns) + col - 1;
      if (pieceLayout[upIndex] != '.'){
        return true;
      }
    }
    return false;
  }

  /*
   * function: canMoveUp
   * description:	determines if we can move the piece up
   *
   * return:	indicates success/failure
   */
  static bool canMoveUp(int rows, int columns, Piece piece, string pieceLayout){
    if (!canMoveVertically(piece.getMovement())) {
      return false;
    }
    // Check if moving the piece up goes out of bounds
    if (outOfBounds(rows, columns, piece.getRow() - 1, piece.getColumn(),
                    piece.getHeight(), piece.getWidth())) {
      return false;
    }

    // Check if moving the piece up overlaps with another piece
    if (overlapsUp(pieceLayout, piece, columns)) {
      return false;
    }
    return true;
  }

  /*
   * function: moveUp
   * description:	moves the piece up and returns a string of the layout
   *
   * return: a string of the layout after the move
   */
  static string moveUp(int columns, Piece &piece, string pieceLayout) {
    int startingCol = piece.getColumn();
    int endingCol = startingCol + piece.getWidth() - 1;
    string returnString = pieceLayout;

    // loop along the width of the piece
    for (int col = startingCol; col <= endingCol; col++) {
      // Set bottomIndex to default
      int bottomIndex = ((piece.getRow() + piece.getHeight() - 2) * columns) + col - 1;
      returnString[bottomIndex] = '.';

      // Move the piece up to aboveIndex
      int aboveIndex = ((piece.getRow() - 2) * columns) + col - 1;
      returnString[aboveIndex] = piece.getName();
    }

    // Update the location
    piece.setRow(piece.getRow() - 1);
    return returnString;
  }

  /*
   * function: overlapsDown
   * description:	determines if moving the piece down will overlap
	 * 		with another piece.
   *
   * return:	indicates success/failure
   */
  static bool overlapsDown(string pieceLayout, Piece piece, int columns) {
    int startingCol = piece.getColumn();
    int endingCol = startingCol + piece.getWidth() - 1;
    // loop through width of piece and check the spot below
    for (int col = startingCol; col <= endingCol; col++) {
      int belowIndex = ((piece.getRow() + piece.getHeight() - 1) * columns) + col - 1;
      if (pieceLayout[belowIndex] != '.'){
        return true;
      }
    }
    return false;
  }

  /*
   * function: canMoveDown
   * description:	determines if we can move the piece down
   *
   * return:	indicates success/failure
   */
  static bool canMoveDown(int rows, int columns, Piece piece, string pieceLayout){
    if (!canMoveVertically(piece.getMovement())) {
      return false;
    }

    // Check if moving the piece down goes out of bounds
    if (outOfBounds(rows, columns, piece.getRow() + 1, piece.getColumn(),
                    piece.getHeight(), piece.getWidth())) {
      return false;
    }

    // Check if moving the piece down overlaps with another piece
    if (overlapsDown(pieceLayout, piece, columns)) {
      return false;
    }
    return true;
  }

  /*
   * function: moveDown
   * description:	moves the piece down and returns a string of the layout
   *
   * return: a string of the layout after the move
   */
  static string moveDown(int columns, Piece &piece, string pieceLayout) {
    int startingCol = piece.getColumn();
    int endingCol = startingCol + piece.getWidth() - 1;
    string returnString = pieceLayout;

    // loop along the width of the piece
    for (int col = startingCol; col <= endingCol; col++) {
      // Set topIndex to default
      int topIndex = ((piece.getRow() - 1) * columns) + col - 1;
      returnString[topIndex] = '.';
    
      // Move the piece down to belowIndex
      int belowIndex = ((piece.getRow() + piece.getHeight() - 1) * columns) + col - 1;
      returnString[belowIndex] = piece.getName();
    }
    // Update the location
    piece.setRow(piece.getRow() + 1);

    return returnString;
  }

  /*
   * function: overlapsLeft
   * description: determines if moving the piece to the left will overlap
	 * 		with another piece.
   *
   * return:	indicates success/failure
   */
  static bool overlapsLeft(string pieceLayout, Piece piece, int columns) {
    int startingRow = piece.getRow();
    int endingRow = startingRow + piece.getHeight() - 1;
    // loop through height of piece and check the spot to left
    for (int row = startingRow; row <= endingRow; row++) {
      int leftIndex = ((row - 1) * columns + piece.getColumn() - 2);
      if (pieceLayout[leftIndex] != '.') {
        return true;
      }
    }
    return false;
  }

  /*
   * function: canMoveLeft
   * description:	determines if we can move the piece to the left
   *
   * return:	indicates success/failure
   */
  static bool canMoveLeft(int rows, int columns, Piece piece, string pieceLayout){
    if (!canMoveHorizontally(piece.getMovement())) {
      return false;
    }

    // Check if moving the piece to the left goes out of bounds
    if (outOfBounds(rows, columns, piece.getRow(), piece.getColumn() - 1,
                    piece.getHeight(), piece.getWidth())) {
      return false;
    }

    // Check if moving the piece left overlaps with another piece
    if (overlapsLeft(pieceLayout, piece, columns)) {
      return false;
    }
    return true;
  }

  /*
   * function: moveLeft
   * description:	moves the piece to the left and returns a string of the layout
   *
   * return: 	a string of the layout after the move
   */
  static string moveLeft(int columns, Piece &piece, string pieceLayout) {
    int startingRow = piece.getRow();
    int endingRow = startingRow + piece.getHeight() - 1;
    string returnString = pieceLayout;

    // loop along the height of the piece
    for (int row = startingRow; row <= endingRow; row++) {
      // Set rightSideIndex to default
      int rightSideIndex = (row - 1) * columns + piece.getColumn() + piece.getWidth() - 2;
      returnString[rightSideIndex] = '.';
    
      // Move the piece to the left to leftIndex
      int leftIndex = ((row - 1) * columns + piece.getColumn() - 2);
      returnString[leftIndex] = piece.getName();
    }

    // Update the location
    piece.setColumn(piece.getColumn() - 1);
    return returnString;
  }

  /*
   * function: overlapsRight
   * description:	determines if moving the piece to the right will overlap
	 * 		with another piece.
   *
   * return:	indicates success/failure
   */
  static bool overlapsRight(string pieceLayout, Piece piece, int columns) {
    int startingRow = piece.getRow();
    int endingRow = startingRow + piece.getHeight() - 1;
    // loop through height of piece and check the spot to right
    for (int row = startingRow; row <= endingRow; row++) {
      int rightIndex = ((row - 1) * columns + piece.getColumn() + piece.getWidth() - 1);
      if (pieceLayout[rightIndex] != '.') {
        return true;
      }
    }
    return false;
  }

  /*
   * function: canMoveRight
   * description:	determines if we can move the piece to the right
   *
   * return:	indicates success/failure
   */
  static bool canMoveRight(int rows, int columns, Piece piece, string pieceLayout){
    if (!canMoveHorizontally(piece.getMovement())) {
      return false;
    }

    // Check if moving the piece to the left goes out of bounds
    if (outOfBounds(rows, columns, piece.getRow(), piece.getColumn() + 1,
                    piece.getHeight(), piece.getWidth())) {
      return false;
    }

    // Check if moving the piece left overlaps with another piece
    if (overlapsRight(pieceLayout, piece, columns)) {
      return false;
    }
    return true;
  }

  /*
   * function: moveRight
   * description: moves the piece to the right and returns a string of the layout
   *
   * return:	a string of the layout after the move
   */
  static string moveRight(int columns, Piece &piece, string pieceLayout) {
    int startingRow = piece.getRow();
    int endingRow = startingRow + piece.getHeight() - 1;
    string returnString = pieceLayout;

    // loop along the height of the piece
    for (int row = startingRow; row <= endingRow; row++) {
      // Set leftSideIndex to default
      int leftSideIndex = ((row - 1) * columns + piece.getColumn() - 1);
      returnString[leftSideIndex] = '.';
    
      // Move the piece to the right to rightIndex
      int rightIndex = (row - 1) * columns + piece.getColumn() + piece.getWidth() - 1;
      returnString[rightIndex] = piece.getName();
    }

    // Update location
    piece.setColumn(piece.getColumn() + 1);
    return returnString;
  }
};
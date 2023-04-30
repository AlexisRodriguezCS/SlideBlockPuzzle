//  Alexis Rodriguez
// 	Jonah Covarrubias
#include "Grid.h"

class Snapshot {

private:
  // list of pieces
  vector<Piece> pieces;
  // List of moves
  vector<string> Moves;
  // current configuration of the pieces
  string pieceLayout;
  // Total amount of Moves
  int totalAmount;

public:
  // make new snapshot based on grid and initial values
  Snapshot(Grid grid) {
    for (int row = 0; row < grid.getRows(); row++) {
      for (int col = 0; col < grid.getColumns(); col++) {
        pieceLayout += grid.getGrid()[row][col];
      }
    }
    pieces      = grid.getPieces();
    Moves       = vector<string>();
    totalAmount = 0;
  }
  
  // make new snapshot from "ss"
  Snapshot(Snapshot ss, int pieceIndex, string direction, int n, int cols) {
    // copy over information from ss
    pieces      = ss.getPieces();
    Moves       = ss.getMoves();
    pieceLayout = ss.getPieceLayout();
    totalAmount = ss.getTotalAmount();

    // perform the move n times in the specific direction
    for (int i = 0; i<n;i++) {
      if (direction == "up") {
        pieceLayout = Movement::moveUp(cols, pieces[pieceIndex], pieceLayout);
      } else if (direction == "down") {
        pieceLayout = Movement::moveDown(cols, pieces[pieceIndex], pieceLayout);
      } else if (direction == "left") {
        pieceLayout = Movement::moveLeft(cols, pieces[pieceIndex], pieceLayout);
      } else if (direction == "right") {
        pieceLayout = Movement::moveRight(cols, pieces[pieceIndex], pieceLayout);
      }
    }
    
    addMove(pieces[pieceIndex], n, direction);
    totalAmount++;
  }

  vector<Piece> &getPieces() { return pieces; }
  /*
   * function: getPieceLayout
   * description:  returns a string that has the piece layout
   *
   * return:  a string containing the current piece layout
   */
  string getPieceLayout() { return pieceLayout; }
  /*
   * function: getMoves
   * description:  returns the vector of moves
   *
   * return:  a vector of all the moves
   */
  vector<string> getMoves() { return Moves; }

  int getTotalAmount() { return totalAmount; }

  /*
   * function: addMove
   * description: Adds the move to the vector of moves
   *
   * return:  void
   */
  void addMove(Piece piece, int n, string direction) {
    string currentMove = "Piece ";
    currentMove.push_back(piece.getName());
    currentMove += " moves ";
    currentMove += to_string(n);
    currentMove += " space(s) ";
    currentMove += direction;
    Moves.push_back(currentMove);
  }
};
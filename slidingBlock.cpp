//    Author Information
//  	Alexis Rodriguez
// 		Jonah Covarrubias

#include "Snapshot.h"
using namespace std;
/*
 * function: printLayout
 * description:  Prints out the ascii representation of the grid
 *
 * return:  void
 */
void printLayout(int rows, int cols, string pieceLayout) {
  for (int i = 0; i < cols + 2; i++) {
    cout << '*';
  }
  cout << endl;
  for (int row = 0; row < rows; row++) {
    cout << '*';
    for (int col = 0; col < cols; col++) {
      cout << pieceLayout[row * cols + col];
    }
    cout << '*' << endl;
  }
  for (int i = 0; i < cols + 2; i++) {
    cout << '*';
  }
  cout << endl;
}
/*
 * function: checkSuccess
 * description:  Checks if the goal piece is in the last column(right side)
 *
 * return:  indicates success/failure
 */
bool checkSuccess(int rows, int cols, string pieceLayout) {
  for (int row = 1; row <= rows; row++) {
    if (pieceLayout[row * cols - 1] == 'Z') {
      return true;
    }
  }
  return false;
}
/*
 * function: validDirection
 * description:  Checks if the piece in snapshot can move in direction dir
 *
 * return:  indicates success/failure
 */
bool validDirection(Snapshot ss, int rows, int cols, int pieceIndex,
                    string dir) {
  Piece p = ss.getPieces()[pieceIndex];
  if (dir == "up") {
    return Movement::canMoveUp(rows, cols, p, ss.getPieceLayout());
  }
  if (dir == "down") {
    return Movement::canMoveDown(rows, cols, p, ss.getPieceLayout());
  }
  if (dir == "left") {
    return Movement::canMoveLeft(rows, cols, p, ss.getPieceLayout());
  }
  if (dir == "right") {
    return Movement::canMoveRight(rows, cols, p, ss.getPieceLayout());
  }
  return false;
}
/*
 * function: getPossibleMoves
 * description:  loops through directions and gets all un-seen snapshots
 *      from different length moves and returns the list
 *
 * return:  vector of new snapshots
 */
vector<Snapshot> getPossibleMoves(set<string>& seen, Snapshot currSS, int rows,
                                  int cols, int pieceIndex) {
  vector<Snapshot> returnVector = vector<Snapshot>();
  vector<string> dirs = {"up", "down", "left", "right"};

  for (string dir : dirs) {
    // check if dir is a valid direction for piece to move
    if (validDirection(currSS, rows, cols, pieceIndex, dir)) {
      int n = 1;
      Snapshot newSS = Snapshot(currSS, pieceIndex, dir, n, cols);

      // check if newSS is a snapshot we havent seen yet
      if (seen.find(newSS.getPieceLayout()) == seen.end()) {
        returnVector.push_back(newSS);
        seen.insert(newSS.getPieceLayout());
      }

      // see if we can make longer moves
      while (validDirection(newSS, rows, cols, pieceIndex, dir)) {
        n++;
        newSS = Snapshot(currSS, pieceIndex, dir, n, cols);

        // check if this further snapshot hasn't been seen yet
        if (seen.find(newSS.getPieceLayout()) == seen.end()) {
          returnVector.push_back(newSS);
          seen.insert(newSS.getPieceLayout());
        }
      }
    }
  }
  return returnVector;
}
/*
 * function: BFS
 * description:  Uses breadth-first-search to find the solution
 *      with the least amount of moves and returns the solution
 *
 * return:  snapshot representing the solved grid
 */
Snapshot BFS(Grid grid) {
  int rows = grid.getRows();
  int cols = grid.getColumns();
  Snapshot initialSS = Snapshot(grid);

  // check if initial snapshot is the solution
  if (checkSuccess(rows, cols, initialSS.getPieceLayout())) {
    return initialSS;
  }
  // initialize queue of next snapshots and set of seen snapshots
  queue<Snapshot> frontier = queue<Snapshot>();
  set<string> seen = set<string>();
  seen.insert(initialSS.getPieceLayout());
  frontier.push(initialSS);

  // loop through queue until there are no more next snapshots
  while (!frontier.empty()) {
    Snapshot currSS = frontier.front();

    // loop through all the pieces
    for (int pieceIndex = 0; pieceIndex < currSS.getPieces().size();
         pieceIndex++) {
      // get an ordered list of valid moves for this piece
      vector<Snapshot> validMoves =
          getPossibleMoves(seen, currSS, rows, cols, pieceIndex);

      // check if any of the moves result in success else push it to queue
      for (Snapshot ss : validMoves) {
        if (checkSuccess(rows, cols, ss.getPieceLayout())) {
          return ss;
        }
        frontier.push(ss);
      }
    }
    frontier.pop();
  }
  return initialSS;
}

int main(int argc, char** argv) {
  if (argc != 2) {   // argc should be 2 for correct execution
    // We print argv[0] assuming it is the program name
    cout << "usage: " << argv[0] << " <filename>\n";
    exit(0);
  }

  // We assume argv[1] is a filename to open
  ifstream the_file(argv[1]);
  // Always check to see if file opening succeeded
  if (!the_file.is_open()) {
    cout << "Could not open file: " << argv[1] << "\n";
    exit(0);
  }

  cout << "\nWelcome to Sliding Block Puzzle\n";
  cout << "Using data from puzzle: " << argv[1] << endl;

  bool done = false;
  string line;
  string input;
  int rows;
  int columns;
  int startingRow;
  int startingColumn;
  int width;
  int height;
  char movement;
  std::getline(the_file, line);
  std::istringstream iss(line);
  iss >> rows;
  iss >> columns;
  Grid grid(rows, columns);

  // read in input file and set up initial puzzle configuration
  while (std::getline(the_file, line)) {
    std::istringstream iss(line);

    iss >> startingRow;
    iss >> startingColumn;
    iss >> width;
    iss >> height;
    iss >> movement;

    grid.addPiece(startingRow, startingColumn, width, height, movement);
  }

  //  print out initial puzzle configuration
  cout << endl;
  grid.printGrid();
  cout << endl;
  //  find solution if one exists
  Snapshot solution = BFS(grid);
  int i = 1;
  if (checkSuccess(rows, columns, solution.getPieceLayout())) {
    cout << "This puzzle is solvable in " << solution.getTotalAmount()
         << " steps" << endl;
    for (auto str : solution.getMoves()) {
      cout << i << ". " << str << endl;
      i++;
    }
    cout << endl;
    printLayout(rows, columns, solution.getPieceLayout());
  } else {
    cout << "This puzzle has no solution" << endl;
  }

  return 0;
}

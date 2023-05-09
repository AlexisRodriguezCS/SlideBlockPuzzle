<a name="readme-top"></a>

<p align="center">
  <img src="https://raw.githubusercontent.com/AlexisRodriguezCS/SlideBlockPuzzle/main/Images/Puzzle.jpg" alt="Grid" style="display:block;margin:auto;" height="500">
</p>
<h1 align="center">Slide Block Puzzle</h1>

<!-- TABLE OF CONTENTS -->
<p align="center">
  <a href="#about">About The Project</a> •
  <a href="#getting-started">Getting Started</a> •
  <a href="#usage">Usage</a> •
  <a href="#Contact">Contact</a>
</p>

<!-- ABOUT THE PROJECT -->
<a name="about"></a>
## About The Project

A sliding block puzzle is a type of game that involves a set of different-shaped pieces that can be moved around within a confined space. The objective of the game is to move a particular piece, called the "goal piece," to a predetermined location within the game grid. In this specific puzzle, there are eight different pieces, with the goal piece being labeled as "Z." The goal of this puzzle is to move the Z piece to the right-hand edge of the grid.

In order to solve the puzzle, all of the pieces must be moved in a specific order of moves. All pieces in this puzzle can be moved in any direction, either left/right or up/down. The ultimate aim of the game is to find the shortest solution to the puzzle that will move the goal piece to the right-hand side of the game grid, specifically the last column.

To achieve this, a program has been developed that takes a command-line argument, which is the name of a data file that contains all of the necessary information about the puzzle. The program will then output a sequence of moves that give the shortest possible solution to the puzzle. The program is designed to be efficient and fast, using algorithms and strategies that have been optimized to solve the sliding block puzzle as quickly as possible.

Here's an online demo of the project hosted on [repl.it](https://replit.com/@Alexisrz/SlideBlockPuzzle) for you to try out.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- GETTING STARTED -->
<a name="getting-started"></a>
## Getting Started

To set up a project locally, follow these simple steps.

### Prerequisites

_Software used to run the program._
* [Visusal Studio Code](https://code.visualstudio.com/)

* [MinGW](https://sourceforge.net/projects/mingw/)

* [Git](https://git-scm.com/)

### Installation
_Here's how to install and set up the program._

From your command line:

```bash
# Clone this repository
$ git clone https://github.com/AlexisRodriguezCS/SlideBlockPuzzle.git

# Go into the repository
$ cd SlideBlockPuzzle

# Compile code into an executable
$ make build

# Run the program
$ make run
```

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- USAGE -->
<a name="usage"></a>
## Usage

By default, when executing the command "make run" in the command line, the sliding block puzzle program utilizes the puzzle specified in the data file named "proj3a.data". This data file contains a predefined set of puzzle configurations to be used by the program. Upon successful execution, the program will output the solution to the specified puzzle configuration, along with various metrics such as the number of moves taken to reach the solution, the execution time, and the path taken by the puzzle pieces to reach the solution.

`Welcome to Sliding Block Puzzle`

`Using data from puzzle: .\Data Files\proj3a.data`

<br>

`******`

`*12..*`

`*3.44*`

`*ZZ5.*`

`*6657*`

`******`

<br>

`This puzzle is solvable in 5 steps`

`1. Piece 4 moves 1 space(s) up`

`2. Piece 3 moves 3 space(s) right`

`3. Piece Z moves 1 space(s) up`

`4. Piece 3 moves 1 space(s) down`

`5. Piece Z moves 2 space(s) right`

<br>

`******`

`*1244*`

`*..ZZ*`

`*..53*`

`*6657*`

`******`


If you wish to use a different data file to run the sliding block puzzle program, you must specify the desired file name in the command prompt after calling the program executable, which is located in the same directory as the data files. Specifically, you would enter the following command into the terminal: `.\slidingBlock.exe '.\Data Files\<filename>'`. This will allow the program to read and execute the puzzle configuration instructions provided in the new data file, providing a new and unique challenge for the user to solve.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTACT -->
<a name="contact"></a>
## Contact

Alexis Rodriguez - [LinkedIn](https://www.linkedin.com/in/alexisrodriguezcs/) - alexisrodriguezdev@gmail.com

Project Link: [https://github.com/AlexisRodriguezCS/SlideBlockPuzzle](https://github.com/AlexisRodriguezCS/SlideBlockPuzzle)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

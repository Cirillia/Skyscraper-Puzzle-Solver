# Skyscraper-Puzzle-Solver
This Skyscraper Puzzle Solver is a coding challenge from my bootcamp, designed to showcase my recent learnings in the C programming language and adherence to coding standards. The project involves solving a 4x4 Skyscraper puzzle, which is a type of logic game that combines elements of Sudoku with additional visibility constraints.

The puzzle uses a backtracking approach to explore possible configurations, ensuring each row and column contains unique heights of skyscrapers while satisfying the visibility criteria provided by the input clues.

## Background
In the Skyscraper puzzle, each number in the grid represents the height of a building. The clues around the grid indicate how many buildings are visible from that vantage point, considering that taller buildings block the view of shorter ones behind them. Each row and column must contain unique heights without any repetitions, and the arrangement must adhere to the visibility hints provided from different perspectives: left, right, top, and bottom of the grid.
  
For a more detailed introduction, please refer to the RUSH01 document which provides comprehensive insights into the project requirements and constraints.

## Example
Run the program with the specific input format as follows:
./ "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"

The input string represents the number of visible skyscrapers from each perspective in a sequence of: col1up col2up col3up col4up col1down col2down col3down col4down row1left row2left row3left row4left row1right row2right row3right row4right.

The expected output might be:

1 2 3 4  
2 3 4 1  
3 4 1 2  
4 1 2 3  

## Learning Objectives
### C Programming: 
This project is implemented entirely in C, which has allowed me to deepen my understanding of fundamental programming constructs, memory management, and efficient data structure usage.
### Coding Standards: 
Throughout the development, I adhered to strict coding standards that are part of my bootcamp training, ensuring that the code is not only functional but also clean, well-documented, and maintainable.
### Algorithm Design: 
The solution involves designing an algorithm capable of considering multiple constraints simultaneously, a valuable skill in any software development scenario.

# Skyscraper-Puzzle-Solver

This project implements a puzzle solver for a specific 4x4 skyscraper puzzle, where each cell represents the height of a skyscraper (from 1 to 4). The objective is to fill the grid such that the number of visible skyscrapers from each direction matches provided clues. These clues indicate how many skyscrapers are visible from a particular vantage point (left, right, top, bottom).


## Project Description
The skyscraper puzzle solver is designed to determine the arrangement of skyscrapers on a 4x4 grid based on clues provided for each row and column from different perspectives (left, right, up, down). The puzzle uses a backtracking approach to explore possible configurations, ensuring each row and column contains unique heights of skyscrapers while satisfying the visibility criteria provided by the input clues.

## Example
Run the program with the specific input format as follows:
./ "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"

The input string represents the number of visible skyscrapers from each perspective in a sequence of: col1up col2up col3up col4up col1down col2down col3down col4down row1left row2left row3left row4left row1right row2right row3right row4right.

The expected output might be:

1 2 3 4  
2 3 4 1  
3 4 1 2  
4 1 2 3  

# BFS & DFS algorithms

## What's the project about?

 - Find the way out from maze
 - Practice & understand algorithms

## Difference between BFS & DFS

 - **BFS** (Breadth-First Search) explores all neighbors at the present depth before moving to nodes at the next depth level
 - **DFS** (Depth-First Search) explores as far as possible along each branch before backtracking.

## What's the maze?

I wil assume that the maze is a matrix MxN (M rows & N colums).
In program is a *vector* of *bytes* (data type), where:
 - 0 is empty space hwhere I can move
 - 1 is wall I can't get through
 - 2 is me 
And coordinates where we start (column_start, row_end) and whre we end (column_end, row_end)

#### For Example:

**C++**:
> std::vector<std::vector<unsigned short>> maze = {
> {0, 1, 0, 0, 1},
> {0, 1, 0, 0, 0},
> {0, 0, 0, 1, 1}
> };
> int column_start = 0, row_start = 0;
> int column_end = 1, row_end = 4;

**Golang**:
> maze := [][]int {
> {83, 1, 0, 0, 1},
> {0, 1, 0, 0, 69},
> {0, 0, 0, 1, 1}
> };
> column_start, row_start := 0, 0;
> column_end, row_end := 1, 4;

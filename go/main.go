package main

import (
	"fmt"
	"BFS-DFS-maze/utils"
)

func print(maze [][]uint) {
	for _, row := range maze {
		fmt.Println(row)
	}
	fmt.Println()
}

func main() {
	maze := [][]uint{
		{1, 0, 1, 1, 0},
		{0, 0, 0, 1, 0},
		{0, 1, 0, 0, 0},
		{0, 0, 0, 0, 0},
	}

	fmt.Println("Maze is:")
	print(maze)

	maze1 := make([][]uint, len(maze))
	for i := range maze {
		maze1[i] = make([]uint, len(maze[i]))
		copy(maze1[i], maze[i])
	}

	start := [2]uint{0, 1}
	end := [2]uint{1, 4}

	utils.BFS(start, end, &maze)
	utils.DFS(start, end, &maze1)
	
	fmt.Println("Result for BFS algorithm")
	print(maze)

	fmt.Println("Result for DFS algorithm")
	print(maze1)
}

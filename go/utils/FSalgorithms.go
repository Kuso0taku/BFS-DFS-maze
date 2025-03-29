package FSalgorithms

func Neighbours(current [2]uint, maze [][]uint) [][2]uint {
    var neighbours [][2]uint
    rows := len(maze)
    if rows == 0 {
        return neighbours
    }
    cols := len(maze[0])
    i, j := current[0], current[1]

    if i > 0 && maze[i-1][j] == 0 {
        neighbours = append(neighbours, [2]uint{i - 1, j})
    }
    if i < rows-1 && maze[i+1][j] == 0 {
        neighbours = append(neighbours, [2]uint{i + 1, j})
    }
    if j > 0 && maze[i][j-1] == 0 {
        neighbours = append(neighbours, [2]uint{i, j - 1})
    }
    if j < cols-1 && maze[i][j+1] == 0 {
        neighbours = append(neighbours, [2]uint{i, j + 1})
    }
    return neighbours
}

func BFS(start, end [2]uint, maze *[][]uint) int {
    if len(*maze) == 0 || len((*maze)[0]) == 0 {
        return 0
    }

    var queue [][2]uint
    parent := make([][][2]uint, len(*maze))
    for i := range parent {
        parent[i] = make([][2]uint, len((*maze)[0]))
    }
    visited := make([][]bool, len(*maze))
    for i := range visited {
        visited[i] = make([]bool, len((*maze)[0]))
    }

    queue = append(queue, start)
    visited[start[0]][start[1]] = true
    parent[start[0]][start[1]] = start

    for len(queue) > 0 {
        current := queue[0]
        queue = queue[1:]

        if current == end {
            at := end
            for at != start {
                (*maze)[at[0]][at[1]] = 2
                at = parent[at[0]][at[1]]
            }
            (*maze)[at[0]][at[1]] = 2
            return 1
        }

        for _, neighbour := range Neighbours(current, *maze) {
            if !visited[neighbour[0]][neighbour[1]] {
                visited[neighbour[0]][neighbour[1]] = true
                queue = append(queue, neighbour)
                parent[neighbour[0]][neighbour[1]] = current
            }
        }
    }
    return 0
}

func DFS(start, end [2]uint, maze *[][]uint) int {
    if len(*maze) == 0 || len((*maze)[0]) == 0 {
        return 0
    }

    var stack [][2]uint
    visited := make([][]bool, len(*maze))
    for i := range visited {
        visited[i] = make([]bool, len((*maze)[0]))
    }
    parent := make([][][2]uint, len(*maze))
    for i := range parent {
        parent[i] = make([][2]uint, len((*maze)[0]))
    }

    stack = append(stack, start)
    visited[start[0]][start[1]] = true
    parent[start[0]][start[1]] = start

    for len(stack) > 0 {
        current := stack[len(stack)-1]
        stack = stack[:len(stack)-1] // Исправлено: было stack = stack[len(stack)-1]

        if current == end {
            at := end
            for at != start {
                (*maze)[at[0]][at[1]] = 2
                at = parent[at[0]][at[1]]
            }
            (*maze)[at[0]][at[1]] = 2
            return 1
        }

        for _, neighbour := range Neighbours(current, *maze) {
            if !visited[neighbour[0]][neighbour[1]] {
                stack = append(stack, neighbour)
                visited[neighbour[0]][neighbour[1]] = true
                parent[neighbour[0]][neighbour[1]] = current
            }
        }
    }
    return 0
}

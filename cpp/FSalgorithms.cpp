#include "FSalgorithms.h"
#include <queue>
#include <vector>
#include <utility> // для std::pair
#include <stack>
using namespace std;

vector<pair<unsigned int, unsigned int>> Neighbours(pair<unsigned int, unsigned int> current, vector<vector<unsigned short>> &maze) {
  vector<pair<unsigned int, unsigned int>> neighbours;
  unsigned int rows = maze.size(); 
  unsigned int cols = maze[0].size();
  auto i = current.first, j = current.second;
  
  if (i > 0 && maze[i-1][j] == 0) {neighbours.push_back({i-1, j});}
  if (i < rows - 1 && maze[i+1][j] == 0) {neighbours.push_back({i+1, j});}
  if (j > 0 && maze[i][j-1] == 0) {neighbours.push_back({i, j-1});}
  if (j < cols - 1 && maze[i][j+1] == 0) {neighbours.push_back({i, j+1});}

  return neighbours;
}

int BFS(pair<unsigned int, unsigned int> start, pair<unsigned int, unsigned int> end, vector<vector<unsigned short>> &maze) {
  if (maze.empty() || maze[0].empty()) {return 0;}
  queue<pair<unsigned int, unsigned int>> queue;
  vector<vector<pair<unsigned int, unsigned int>>> parent;
  vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false)); // с помощью конструктора передаем в visited значения: для maze.size() столбцов в каждую клетку передаем вектор булевых значений размером maze[0].size() колонок со значениями false;
  queue.push(start);
  visited[start.first][start.second] = true;

  parent.resize(maze.size());
  for (auto &row : parent) {row.resize(maze[0].size());}
  parent[start.first][start.second] = start;

  while (!queue.empty()) {
    auto current = queue.front();
    queue.pop();

    if (current == end) {
      pair<unsigned int, unsigned int> at = end;
      while (at != start) {
        maze[at.first][at.second] = 2;
        at = parent[at.first][at.second];
      }
      maze[start.first][start.second] = 2;
      return 1;
    }

    for (auto neighbour : Neighbours(current, maze)) {
      if (!visited[neighbour.first][neighbour.second]) {
        visited[neighbour.first][neighbour.second] = true;
        queue.push(neighbour);
        parent[neighbour.first][neighbour.second] = current;
      }
    }
  }
  
  return 0;
}

int DFS(pair<unsigned int, unsigned int> start, pair<unsigned int, unsigned int> end, vector<std::vector<unsigned short>> &maze) {
  if (maze.empty() || maze[0].empty()) {return 0;}
  stack<pair<unsigned int, unsigned int>> dots;
  vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
  vector<vector<pair<unsigned int, unsigned int>>> parent;
  
  dots.push(start);
  visited[start.first][start.second] = true;

  parent.resize(maze.size());
  for (auto &row : parent) {row.resize(maze[0].size());}
  parent[start.first][start.second] = start;

  while (!dots.empty()) {
    auto current = dots.top();
    dots.pop();

    if (current == end) {
      auto at = end;
      while (at != start) {
        maze[at.first][at.second] = 2;
        at = parent[at.first][at.second];
      }
      maze[start.first][start.second] = 2;
      return 1;
    }
    
    for (auto neighbour : Neighbours(current, maze)) {
      if (!visited[neighbour.first][neighbour.second]) {
        dots.push(neighbour);
        visited[neighbour.first][neighbour.second] = true;
        parent[neighbour.first][neighbour.second] = current;
      }
    }
  }

  return 0;
}


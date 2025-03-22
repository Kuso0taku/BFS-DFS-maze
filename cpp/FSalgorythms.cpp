#include "FSalgorythms.h"
#include <queue>
#include <vector>
#include <set>
#include <utility> // для std::pair
using namespace std;

vector<pair<unsigned int, unsigned int>> Neighbours(pair<unsigned int, unsigned int> current, vector<vector<unsigned short>> &maze) {
  vector<pair<unsigned int, unsigned int>> neighbours;
  unsigned int columns = static_cast<unsigned int>(maze.size());
  unsigned int rows = static_cast<unsigned int>(maze[0].size());
  auto i = current.first, j = current.second;
  if (i != 0 && j != 0) {neighbours.insert(neighbours.end(),{{i-1, j-1}, {i-1, j}, {i, j-1}});}
  if (i < columns - 1 && j < rows - 1) {neighbours.insert(neighbours.end(), {{i+1, j+1}, {i+1, j}, {i, j+1}});}
  if (i != 0 && j < rows - 1) {neighbours.insert(neighbours.end(), {{i-1, j+1}});}
  if (i < columns - 1 && j != 0) {neighbours.insert(neighbours.end(), {{i+1, j-1}});}
  return neighbours;
}

int BFS(pair<unsigned int, unsigned int> start, pair<unsigned int, unsigned int> end, vector<vector<unsigned short>> &maze) {
  queue<pair<unsigned int, unsigned int>> queue;
  set<pair<unsigned int, unsigned int>> visited; // уникальные точки, которые были уже посещены
  set<pair<unsigned int, unsigned int>> inQueue; // сет для проверки, есть ли в очереди точки
  
  queue.push(start);
  inQueue.insert(start);

  while (!queue.empty()) {
    pair<unsigned int, unsigned int> current = queue.front();
    if (current == end) {return 1;}
    queue.pop();
    inQueue.erase(current);
    visited.insert(current);
    maze[current.first][current.second] = 2;

    for (auto neighbour : Neighbours(current, maze)) {
      if (visited.find(neighbour) == visited.end() && inQueue.find(neighbour) == inQueue.end()) {
        queue.push(neighbour);
        inQueue.insert(neighbour);
      }
    }
  }
  
  return 0;
}


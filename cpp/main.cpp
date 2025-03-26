#include "FSalgorithms.h"
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

void print(vector<vector<unsigned short>> maze) {
  for (auto i : maze) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
}

int main(void) {
  vector<vector<unsigned short>> maze = {
    {1, 0, 1, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0}
  };
  cout << "Mazes is: " << endl;
  print(maze);
  auto maze1 = maze;
  pair<unsigned int, unsigned int> start = {0, 1};
  pair<unsigned int, unsigned int> end = {1, 4};
  int result_bfs = BFS(start, end, maze);
  int result_bdfs = DFS(start, end, maze1);
  cout << "Result for BFS algorithm:" << endl;
  print(maze);
  cout << endl << "Result for DFS algorithm" << endl;
  print(maze1);
  return 0;
}


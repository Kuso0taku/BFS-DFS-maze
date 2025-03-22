#ifndef FSALGORITHMS_H //protect against from repeated include
#define FSALGORITHMS_H

#include <utility> // для std::pair
#include <vector>
using byte = unsigned char;

std::vector<std::pair<unsigned int, unsigned int>> Neighbours(std::pair<unsigned int, unsigned int> current, std::vector<std::vector<unsigned short>> &maze); 
int BFS(std::pair<unsigned int, unsigned int> start, std::pair<unsigned int, unsigned int> end, std::vector<std::vector<unsigned short>> &maze);
int DFS(std::pair<unsigned int, unsigned int> start, std::pair<unsigned int, unsigned int> end, std::vector<std::vector<unsigned short>> &maze);

#endif // FSALGORITHMS_H

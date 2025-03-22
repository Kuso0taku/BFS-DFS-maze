#ifdef FSALGORYTHMS_H //protect against from repeated include
#define FSALGORYTHMS_H

#include <utility> // для std::pair
#include <vector>
using byte = unsigned char;

std::vector<std::pair<unsigned int, unsigned int>> Neighbours(std::pair<unsigned int, unsigned int> current, std::vector<std::vector<unsigned short>> &maze); 
int BFS(std::pair<unsigned int, unsigned int> start, std::pair<unsigned int, unsigned int> end, std::vector<std::vector<unsigned short>> &maze);
int DFS(std::pair<unsigned int, unsigned int> start, std::pair<unsigned int, unsigned int> end, std::vector<std::vector<unsigned short>> &maze);

#endif // FSALGORYTHMS_H

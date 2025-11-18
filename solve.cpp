#include <chrono>
#include <iostream>
#include <random>
#include <stack>
#include <utility>
#include <vector>

int x, h;

int main() {
  std::cout << "input maze size:";
  std::cin >> x >> h;
  std::vector<std::vector<char>> maze(x, std::vector<char>(h));
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < h; j++) {
      std::cin >> maze[i][j];
    }
  }
  return 0;
}

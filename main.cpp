#include <chrono>
#include <iostream>
#include <random>
#include <stack>
#include <utility>
#include <vector>

int main() {
  int x, h;
  std::cout << "maze size(x h):";
  std::cin >> x >> h;
  if (x < 5 || h < 5 || x % 2 == 0 || h % 2 == 0) {
    std::cerr << "maze size is odd numbers greater than or equal to five"
              << std::endl;
    return 0;
  }
  x += 2;
  h += 2;
  std::vector<std::vector<char>> maze(x, std::vector<char>(h, ' '));
  std::vector<std::pair<int, int>> target;
  std::stack<std::pair<int, int>> currentWall;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> forward(0, 3);
  {
    std::pair<int, int> ax;
    for (int i = 0; i < x; i++) { // initialize field
      for (int j = 0; j < h; j++) {
        if (i == 0 || i == x - 1 || j == 0 || j == h - 1)
          maze[i][j] = '#';
        else {
          ax.first = i;
          ax.second = j;
          currentWall.push(ax);
        }
      }
    }
  }

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < h; j++) {
      std::cout << maze[i][j];
    }
    std::cout << std::endl;
  }
}

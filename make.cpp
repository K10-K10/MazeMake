#include <chrono>
#include <iostream>
#include <random>
#include <stack>
#include <utility>
#include <vector>

int x, h;
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> forward(0, 3);

int wall(std::vector<std::vector<char>> &maze, int i, int j) {
  int rand_f = forward(gen);
  switch (rand_f) {
  case 0:
    if (i - 2 >= 0 && maze[i - 2][j] == ' ') {
      maze[i - 1][j] = '#';
      maze[i - 2][j] = '#';
      wall(maze, i - 2, j);
    } else {
      maze[i - 1][j] = '#';
      return 0;
    }
    break;

  case 1:
    if (j + 2 <= h && maze[i][j + 2] == ' ') {
      maze[i][j + 1] = '#';
      maze[i][j + 2] = '#';
      wall(maze, i, j + 2);
    } else {
      maze[i][j + 1] = '#';
      return 0;
    }
    break;

  case 2:
    if (i + 2 <= x && maze[i + 2][j] == ' ') {
      maze[i + 1][j] = '#';
      maze[i + 2][j] = '#';
      wall(maze, i + 2, j);
    } else {
      maze[i + 1][j] = '#';
      return 0;
    }
    break;

  case 3:
    if (j - 2 >= 0 && maze[i][j - 2] == ' ') {
      maze[i][j - 1] = '#';
      maze[i][j - 2] = '#';
      wall(maze, i, j - 2);
    } else {
      maze[i][j - 1] = '#';
      return 0;
    }
    break;

  default:
    break;
  }
  return 0;
}

int main() {
  std::cout << "maze size(x h):";
  std::cin >> x >> h;
  if (x < 5 || h < 5 || x % 2 == 0 || h % 2 == 0) {
    std::cerr << "maze size is odd numbers greater than or equal to five"
              << std::endl;
    return 0;
  }
  std::vector<std::vector<char>> maze(x, std::vector<char>(h, ' '));
  std::vector<std::pair<int, int>> cw;
  {
    std::pair<int, int> ax;
    for (int i = 0; i < x; i++) { // initialize field
      for (int j = 0; j < h; j++) {
        if (i == 0 || i == x - 1 || j == 0 || j == h - 1)
          maze[i][j] = '#';
        if (i == 1 && j == 1)
          maze[i][j] = 'S';
        if (i == x - 2 && j == h - 2)
          maze[i][j] = 'G';
        else if (i % 2 == 0 && j % 2 == 0) {
          ax.first = i;
          ax.second = j;
          cw.push_back(ax);
        }
      }
    }
  }
  {
    while (cw.size() > 0) {
      std::uniform_int_distribution<> dist(0, cw.size() - 1);
      int rand = dist(gen) % cw.size();
      if (maze[cw[rand].first][cw[rand].second] != '#') {
        maze[cw[rand].first][cw[rand].second] = '#';
        wall(maze, cw[rand].first, cw[rand].second);
      }
      cw.erase(cw.begin() + rand);
    }
  }
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < h; j++) {
      std::cout << maze[i][j];
    }
    std::cout << std::endl;
  }
}

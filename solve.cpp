#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

int x, h;
int cnt = 0;

using coordinate = std::pair<int, std::pair<int, int>>;
std::priority_queue<coordinate, std::vector<coordinate>,
                    std::greater<coordinate>>
    oq;
std::priority_queue<coordinate, std::vector<coordinate>,
                    std::greater<coordinate>>
    cq;

auto a_star(std::vector<std::vector<int>> &maze, std::pair<int, int> &gore) {
  coordinate top = oq.top();
  if (top.second == gore) {
    return 0;
  } else {
    int x = top.second.first, y = top.second.second;
  }
}

int main() {
  std::cout << "input maze size:";
  std::cin >> x >> h;
  std::vector<std::vector<char>> maze(x, std::vector<char>(h));
  std::vector<std ::vector<int>> maze_map(x, std::vector<int>(h, 0));
  std::pair<int, int> start, gore;
  {
    char c;
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < h; j++) {
        std::cin.get(c);
        if (c == 'S' || c == 's') {
          start.first = i;
          start.second = j;
          maze_map[i][j] = 0;
        }
        if (c == 'G' || c == 'g') {
          gore.first = i;
          gore.second = j;
        }
        if (c == '#')
          maze_map[i][j] = -1;
        maze[i][j] = c;
      }
    }
  }
  // std::pair<int, int> curent = start;
  coordinate current;
  current.first = 0;
  current.second = start;
  cq.push(current);
  bool is_gore = false;

  return 0;
}

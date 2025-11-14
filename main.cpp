#include <iostream>
#include <utility>
#include <vector>

int main()
{
  int x, h;
  std::cout << "maze size(x h):";
  std::cin >> x >> h;
  if (x < 5 || h < 5 || x % 2 == 0 || h % 2 == 0)
  {
    std::cout << "maze size big or to 5,%2 == 1" << std::endl;
    return 0;
  }
  std::vector<std::vector<char>> maze(x, std::vector<char>(h));
  std::vector<std::pair<int, int>> target;
  for (int i = 0; i < x; i++)
  {
    for (int j = 0; j < h; j++)
    {
      if (i == 0 || i == x - 1 || j == 0 || j == h - 1)
        maze[i][j] = '#';
      else
        maze[i][j] = ' ';
    }
  }
  for (int i = 0; i < x; i++)
  {
    for (int j = 0; j < h; j++)
    {
      std::cout << maze[i][j];
    }
    std::cout << std::endl;
  }
}

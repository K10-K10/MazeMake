#include <chrono>
#include <iostream>
#include <random>
#include <stack>
#include <utility>
#include <vector>

int x, h;
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> fw(0, 12);
std::stack<std::pair<int, int>> cw;

int wall(std::vector<std::vector<char>> &maze)
{
  int i = cw.top().first;
  int j = cw.top().second;
  if (maze[i][j] == '#')
  {
    cw.pop();
    return 0;
  }
  cw.pop();
  int cnt = 0;
  bool wallFlag = false;
  std::vector<int> forward;
  maze[i][j] = '-';
  while (!wallFlag)
  {
    cnt = 0;
    if (maze[i - 2][j] != '-')
    {
      cnt++;
      forward.push_back(0);
    }
    if (maze[i][j + 2] != '-')
    {
      cnt++;
      forward.push_back(1);
    }
    if (maze[i + 2][j] != '-')
    {
      cnt++;
      forward.push_back(2);
    }
    if (maze[i][j - 2] != '-')
    {
      cnt++;
      forward.push_back(3);
    }
    int f = forward[fw(gen) % cnt];

    switch (f)
    {
    case 0:
      maze[i - 1][j] = '-';
      if (maze[i - 2][j] == '#')
      {
        wallFlag = true;
      }
      else
      {
        maze[i - 2][j] = '-';
        i -= 2;
      }
      break;
    case 1:
      maze[i][j + 1] = '-';
      if (maze[i][j + 2] == '#')
      {
        wallFlag = true;
      }
      else
      {
        maze[i][j + 2] = '-';
        j += 2;
      }
      break;
    case 2:
      maze[i + 1][j] = '-';
      if (maze[i + 2][j] == '#')
        wallFlag = true;
      else
      {
        maze[i + 2][j] = '-';
        i += 2;
      }
      break;
    case 3:
      maze[i][j - 1] = '-';
      if (maze[i][j - 2] == '#')
        wallFlag = true;
      else
      {
        maze[i][j - 2] = '-';
        j -= 2;
      }
      break;
    default:
      return -1;
      break;
    }
  }
  return 0;
}

int main()
{
  std::cout << "maze size(x h):";
  std::cin >> x >> h;
  if (x < 5 || h < 5 || x % 2 == 0 || h % 2 == 0)
  {
    std::cerr << "maze size is odd numbers greater than or equal to five"
              << std::endl;
    return -1;
  }
  std::vector<std::vector<char>> maze(x, std::vector<char>(h, ' '));
  std::vector<std::pair<int, int>> plist;
  int cnt = 0;
  {
    std::pair<int, int> ax;
    for (int i = 0; i < x; i++)
    {
      for (int j = 0; j < h; j++)
      {
        if (i == 1 && j == 1)
          maze[i][j] = 'S';
        if (i == x - 2 && j == h - 2)
          maze[i][j] = 'G';
        if (i == 0 || i == x - 1 || j == 0 || j == h - 1)
          maze[i][j] = '#';
        else if (i % 2 == 0 && j % 2 == 0)
        {
          plist.push_back({i, j});
          cnt++;
        }
      }
    }
  }
  std::uniform_int_distribution<> pl(0, --cnt);
  int rand = 0;
  while (plist.size() > 0)
  {
    rand = pl(gen);
    cw.push(plist[rand % plist.size()]);
    plist.erase(plist.begin() + rand % plist.size());
  }
  while (cw.size() > 0)
  {
    wall(maze);
    for (int i = 0; i < x; i++)
    {
      for (int j = 0; j < h; j++)
      {
        if (maze[i][j] == '-')
          maze[i][j] = '#';
      }
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
  return 0;
}

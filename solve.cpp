#include <iostream>
#include <queue>
#include <string>
#include <vector>

int main()
{
  std::vector<std::string> maze;
  std::string line;

  std::cout << "Input maze (empty line to finish):" << std::endl;
  while (std::getline(std::cin, line))
  {
    if (line.empty())
      break;
    maze.push_back(line);
  }

  if (maze.empty())
  {
    std::cerr << "No maze input provided" << std::endl;
    return -1;
  }

  int rows = maze.size();
  int cols = maze[0].size();

  int startX = -1, startY = -1;
  int goalX = -1, goalY = -1;

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < (int)maze[i].size(); j++)
    {
      if (maze[i][j] == 'S')
      {
        startX = i;
        startY = j;
      }
      else if (maze[i][j] == 'G')
      {
        goalX = i;
        goalY = j;
      }
    }
  }

  if (startX == -1 || goalX == -1)
  {
    std::cerr << "Start (S) or Goal (G) not found" << std::endl;
    return -1;
  }

  std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
  std::vector<std::vector<std::pair<int, int>>> parent(
      rows, std::vector<std::pair<int, int>>(cols, {-1, -1}));

  std::queue<std::pair<int, int>> q;
  q.push({startX, startY});
  visited[startX][startY] = true;

  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};

  bool found = false;

  while (!q.empty())
  {
    auto [cx, cy] = q.front();
    q.pop();

    if (cx == goalX && cy == goalY)
    {
      found = true;
      break;
    }

    for (int i = 0; i < 4; i++)
    {
      int nx = cx + dx[i];
      int ny = cy + dy[i];

      if (nx >= 0 && nx < rows && ny >= 0 && ny < (int)maze[nx].size() &&
          !visited[nx][ny] && maze[nx][ny] != '#')
      {
        visited[nx][ny] = true;
        parent[nx][ny] = {cx, cy};
        q.push({nx, ny});
      }
    }
  }

  if (!found)
  {
    std::cerr << "No solution found" << std::endl;
    return -1;
  }

  int px = goalX, py = goalY;
  while (px != startX || py != startY)
  {
    if (maze[px][py] != 'S' && maze[px][py] != 'G')
    {
      maze[px][py] = '*';
    }
    auto [npx, npy] = parent[px][py];
    px = npx;
    py = npy;
  }

  std::cout << "\nSolved maze:" << std::endl;
  for (const auto &row : maze)
  {
    std::cout << row << std::endl;
  }

  return 0;
}

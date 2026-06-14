#include "make.h"
#include <K10-K10/terminal.h>
#include <K10-K10/utils/base.h>
#include <iostream>
#include <string>
#include <vector>

int main() {
  terminal::app.init();
  auto [x, h] = terminal::utils::getTerminalSize();
  if (x % 2 == 0)
    --x;
  if (h % 2 == 0)
    --h;
  std::vector<std::vector<char>> c_maze = make(h, x);
  std::vector<std::string> maze;
  for (const auto &l : c_maze) {
    maze.push_back(std::string(l.begin(), l.end()));
  }

  terminal::TextField field;

  field.contents(maze)
      .position({0, 0, x, h})
      .text_style(terminal::style::Default())
      .move_cursor(1, 1)
      .cursor_style(
          terminal::style::Default().bg(terminal::style::Color(0, 0, 150)));
  int c_x = 1, c_y = 1;
  terminal::app.loop([&]() {
    field.draw();
    terminal::input::key.read();
    if (field[c_y][c_x] == 'G') {
      terminal::app.stop();
    }
    switch (terminal::input::key.getKeyCode()) {
    case terminal::input::KeyCode::LEFT:
      if (field[c_y][c_x - 1] != '#') {
        field.delete_char();
        --c_x;
        field.move_cursor(c_x, c_y);
        field.insert_char('*');
      }
      break;
    case terminal::input::KeyCode::RIGHT:
      if (field[c_y][c_x + 1] != '#') {
        field.delete_char();
        ++c_x;
        field.move_cursor(c_x, c_y);
        field.insert_char('*');
      }
      break;
    case terminal::input::KeyCode::UP:
      if (field[c_y - 1][c_x] != '#') {
        field.delete_char();
        --c_y;
        field.move_cursor(c_x, c_y);
        field.insert_char('*');
      }
      break;
    case terminal::input::KeyCode::DOWN:
      if (field[c_y + 1][c_x] != '#') {
        field.delete_char();
        ++c_y;
        field.move_cursor(c_x, c_y);
        field.insert_char('*');
      }

      break;
    case terminal::input::KeyCode::CHAR:
      char c = terminal::input::key.getCurrentChar();
      switch (c) {
      case 'r':
        field.delete_char();
        c_x = 1;
        c_y = 1;
        field.move_cursor(c_x, c_y);
        field.insert_char('S');
        break;
      }
    }
  });
}

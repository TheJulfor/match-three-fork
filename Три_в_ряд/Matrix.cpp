#include <windows.h>

#include <ctime>
#include <iostream>
#include <vector>

#include "Management_Header.h"
std::vector<char> symbols = {'X', 'O', '#'};

void Generate_Board(std::vector<std::vector<char>>& board) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      int idx = rand() % 3;
      board[i][j] = symbols[idx];
    }
  }
}
// просто вывод c небольшим дизайном
void Show_Board(std::vector<std::vector<char>> board) {
  std::cout << "=== ТРИ В РЯД ===" << '\n';
  std::cout << "Счет: пока нет" << '\n' << '\n' << "     ";  // потом добавим
  for (int i = 1; i < 9; i++) {
    std::cout << i << "  ";
  }
  std::cout << '\n' << "   ";
  for (int i = 0; i < 13; i++) {
    std::cout << "--";
  }
  std::cout << '\n';
  for (int i = 0; i < 8; i++) {
    std::cout << i + 1 << " " << '|' << "  ";
    for (int j = 0; j < 8; j++) {
      PrintColoredSymbol(board[i][j]);
      std::cout << "  ";
    }
    std::cout << '|';
    std::cout << '\n';
  }
  std::cout << "   ";
  for (int i = 0; i < 13; i++) {
    std::cout << "--";
  }
}
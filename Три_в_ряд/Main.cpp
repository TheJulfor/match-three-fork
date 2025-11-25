#include <windows.h>
#include <ctime>
#include <iostream>
#include <vector>
#include "Matrix_Header2.h"
const int BOARD_SIZE = 8;

int main() { 
  std::vector<std::vector<int>> board(6, std::vector<int>(10));
  Generate_Board(board);
  Show_Board(board);

}
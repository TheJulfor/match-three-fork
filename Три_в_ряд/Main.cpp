#include <Windows.h>
#include <windows.h>

#include <ctime>
#include <iostream>
#include <vector>

#include "Matrix_Header2.h"

const int BOARD_SIZE = 8;

int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  std::srand(std::time(nullptr));
  std::vector<std::vector<char>> board(BOARD_SIZE,
                                       std::vector<char>(BOARD_SIZE));
  Generate_Board(board);
  Show_Board(board);

  std::cout << '\n' << '\n';
  std::cout << "1. Выберите номер ряда (слева от 1 до 8): ";
  // польвозатель вводит
  std::cout << "\n2. Выберите номер элемента ряда (сверху от 1 до 8)";
  // польвозатель вводит
  std::cout << "\n\nСейчас вы выбираете с каким элементом вы хотите поменяться"
            << '\n';

  std::cout << "\n1. Выберите номер ряда(слева от 1 до 8)";
  // польвозатель вводит
  std::cout << "\n2. Выберите номер элемента ряда (сверху от 1 до 8)";
  // польвозатель вводит
  std::cout << '\n';
}
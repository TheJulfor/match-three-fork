#include <windows.h>
#include <ctime>
#include <iostream>
#include <vector>
//просто генериует матрицу от min до max
void Generate_Board(std::vector<std::vector<int>>& board, int Min_Val = 1, int Max_Val = 9) {
    std::srand(static_cast<unsigned int>(std::time(0)));
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 10; j++) {
            board[i][j] = Min_Val + std::rand() % (Max_Val - Min_Val + 1);
        }
    }
}
//просто вывод
void Show_Board(std::vector<std::vector<int>> board) {
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 10; j++) {
      std::cout << board[i][j] << ' ';
    }
    std::cout << '\n' << '\n';
  }

}
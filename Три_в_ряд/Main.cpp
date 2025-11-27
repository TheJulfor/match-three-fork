#include <windows.h>
#include <ctime>
#include <iostream>
#include <vector>
#include "Matrix_Header2.h"

int main() {
    std::srand(std::time(nullptr));
    std::vector<std::vector<char>> board(8, std::vector<char>(8));

    Generate_Board(board);
    Show_Board(board);
}
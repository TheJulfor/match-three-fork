#include <windows.h>
#include <ctime>
#include <iostream>
#include <vector>

std::vector<char> symbols = {'X', 'O', '#'};

void Generate_Board(std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int idx = rand() % 3;
            board[i][j] = symbols[idx];
        }
    }
}

void Show_Board(std::vector<std::vector<char>> board) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << '\n';
    }
}
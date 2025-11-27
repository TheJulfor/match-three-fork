#include <iostream>
#include <random>
#include <thread>
#include <vector>

#include "Management_Header.h"
#include "Matrix_Header2.h"

void win_comb(std::vector<std::vector<char>>& board) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (j > 1) {
        if ((board[i][j] == 'X' || board[i][j] == '1') &&
            (board[i][j - 1] == 'X' || board[i][j - 1] == '1') &&
            (board[i][j - 2] == 'X' || board[i][j - 2] == '1')) {
          board[i][j] = '1';
          board[i][j - 1] = '1';
          board[i][j - 2] = '1';
        }
        if ((board[i][j] == 'O' || board[i][j] == '2') &&
            (board[i][j - 1] == 'O' || board[i][j - 1] == '2') &&
            (board[i][j - 2] == 'O' || board[i][j - 2] == '2')) {
          board[i][j] = '2';
          board[i][j - 1] = '2';
          board[i][j - 2] = '2';
        }
        if ((board[i][j] == '#' || board[i][j] == '3') &&
            (board[i][j - 1] == '#' || board[i][j - 1] == '3') &&
            (board[i][j - 2] == '#' || board[i][j - 2] == '3')) {
          board[i][j] = '3';
          board[i][j - 1] = '3';
          board[i][j - 2] = '3';
        }
        if ((board[i][j] == '$' || board[i][j] == '4') &&
            (board[i][j - 1] == '$' || board[i][j - 1] == '4') &&
            (board[i][j - 2] == '$' || board[i][j - 2] == '4')) {
          board[i][j] = '4';
          board[i][j - 1] = '4';
          board[i][j - 2] = '4';
        }
      }
      if (i > 1) {
        if ((board[i][j] == 'X' || board[i][j] == '1') &&
            (board[i - 1][j] == 'X' || board[i - 1][j] == '1') &&
            (board[i - 2][j] == 'X' || board[i - 2][j] == '1')) {
          board[i][j] = '1';
          board[i - 1][j] = '1';
          board[i - 2][j] = '1';
        }
        if ((board[i][j] == 'O' || board[i][j] == '2') &&
            (board[i - 1][j] == 'O' || board[i - 1][j] == '2') &&
            (board[i - 2][j] == 'O' || board[i - 2][j] == '2')) {
          board[i][j] = '2';
          board[i - 1][j] = '2';
          board[i - 2][j] = '2';
        }
        if ((board[i][j] == '#' || board[i][j] == '3') &&
            (board[i - 1][j] == '#' || board[i - 1][j] == '3') &&
            (board[i - 2][j] == '#' || board[i - 2][j] == '3')) {
          board[i][j] = '3';
          board[i - 1][j] = '3';
          board[i - 2][j] = '3';
        }
        if ((board[i][j] == '$' || board[i][j] == '4') &&
            (board[i - 1][j] == '$' || board[i - 1][j] == '4') &&
            (board[i - 2][j] == '$' || board[i - 2][j] == '4')) {
          board[i][j] = '4';
          board[i - 1][j] = '4';
          board[i - 2][j] = '4';
        }
      }
    }
  }
}

int number_of_winning_cells(std::vector<std::vector<char>> board) {
  int count = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board[i][j] == '1' || board[i][j] == '2' || board[i][j] == '3' ||
          board[i][j] == '4') {
        count++;
      }
    }
  }
  return count;
}

void generation_of_new_cells(std::vector<std::vector<char>>& board, bool& gen) {
  while (number_of_winning_cells(board) != 0) {
    std::vector<char> symbols2 = {'X', 'O', '#', '$'};
    for (int i = 7; i >= 0; i--) {
      for (int j = 7; j >= 0; j--) {
        if (board[i][j] == '1' || board[i][j] == '2' || board[i][j] == '3' ||
            board[i][j] == '4') {
          gen = 0;
          if (i == 0) {
            int tmp_ind = rand() % 4;
            board[i][j] = symbols2[tmp_ind];

          } else {
            std::swap(board[i][j], board[i - 1][j]);
          }
        }
      }
    }
  }
}

void Start_Game(std::vector<std::vector<char>>& board, int& total_score) {
  bool running = true;
  while (running) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    system("cls");
    Show_Board(board, total_score);

    int r1, c1, r2, c2;
    std::cout << "\nВведите координаты первой клетки (строка столбец) или 0 "
                 "для окончания игры: ";
    if (!(std::cin >> r1) || r1 == 0) {
      break;
    }
    std::cin >> c1;

    std::cout << "Введите координаты второй клетки (строка столбец): ";
    std::cin >> r2 >> c2;

    // получаем индексы из координат
    r1--;
    c1--;
    r2--;
    c2--;

    if (r1 < 0 || r1 > 7 || c1 < 0 || c1 > 7 || r2 < 0 || r2 > 7 || c2 < 0 ||
        c2 > 7) {
      std::cout << "Ошибка: Координаты должны быть от 1 до 8!\n";
      continue;
    }
    if ((std::abs(r1 + c1 - r2 - c2)) != 1) {
      std::cout << "Невозможное действие!\n";
      continue;
    }

    std::vector<std::vector<char>> saved_board = board;
    std::swap(board[r1][c1], board[r2][c2]);

    int win = 0;
    int turn_score = 0;
    bool gen = true;

    while (true) {
      win_comb(board);
      int matches = number_of_winning_cells(board);

      if (matches > 0) {
        win = 1;
        turn_score += matches;

        if (gen) gen = false;

        generation_of_new_cells(board, gen);
      } else {
        break;
      }
    }

    if (win == 1) {
      total_score += turn_score;
      std::cout << "Ход выполнен! Вы заработали " << turn_score << " очков.\n";
    } else {
      board = saved_board;
      std::cout
          << "Комбинаций нет. Элементы возвращены в исходное состояние.\n";
    }
  }

  std::cout << "Игра окончена. Ваш итоговый счет: " << total_score << "\n";
}

void Clear_Board(std::vector<std::vector<char>>& board) {
  bool gen = true;

  while (true) {
    win_comb(board);
    int matches = number_of_winning_cells(board);

    if (matches > 0) {
      if (gen) gen = false;
      generation_of_new_cells(board, gen);
    } else {
      break;
    }
  }
}
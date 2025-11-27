#include <windows.h>

#include <iostream>
#include <vector>

std::vector<char> symbols = {'X', 'O', '#', '$'};

// ставит цвет
void SetColor(int colorCode) {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, colorCode);
}
// функция для сброса цвета текста
void ResetColor() {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(
      hConsole, 7);  // делает белый цвет по дефолту, что другое не было цветным
}

// функция для вывода цветных символов
void PrintColoredSymbol(char symbol) {
  switch (symbol) {
    case 'X':
      SetColor(14);  // желтый
      break;
    case 'O':
      SetColor(12);  // красный
      break;
    case '#':
      SetColor(10);  // зеленый
      break;
    case '$':
      SetColor(9);
      break;
    default:
      SetColor(7);  // белый для других символов
      break;
  }
  std::cout << symbol;
  ResetColor();
}

void Generate_Board(std::vector<std::vector<char>>& board) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      int idx = rand() % 4;
      board[i][j] = symbols[idx];
    }
  }
}
// просто вывод c небольшим дизайном
void Show_Board(std::vector<std::vector<char>> board, int score) {
  std::cout << "\n=== ТРИ В РЯД ===" << '\n';
  std::cout << "--- Текущий счет: " << score << " ---" << '\n'
            << '\n'
            << "     ";
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

void MurMiau() {
  int flag = 1;
  int tmp = 1;
  while (flag == 1) {
    if (tmp == 1) {
      SetConsoleOutputCP(65001);
      std::cout << ">^˶ω˶^<" << std::endl;
      tmp++;
      std::cout << "Ещё один? (1 - да, 0 - нет)" << std::endl;
      std::cin >> flag;
    } else if (tmp == 2) {
      std::cout << "\xE2\x82\x8D\xCB\x84;\xCB\x95;\xCB\x84\xE2\x82\x8E"
                << std::endl;
      tmp++;
      std::cout << "Ещё один? (1 - да, 0 - нет)" << std::endl;
      std::cin >> flag;
    } else if (tmp == 3) {
      std::cout << "\xE2\x82\x8D\xCB\x84\xCB\xB6\xE1\xB5\x94 \xE1\xB5\x95 "
                   "\xE1\xB5\x94\xCB\xB6\xCB\x84\xE2\x82\x8Emeow"
                << std::endl;
      tmp = 1;
      std::cout << "Ещё один? (1 - да, 0 - нет)" << std::endl;
      std::cin >> flag;
    }
  }
}
#include <windows.h>

#include <iostream>
#include <vector>

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
    default:
      SetColor(7);  // белый для других символов
      break;
  }
  std::cout << symbol;
  ResetColor();
}

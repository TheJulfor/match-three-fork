#include <windows.h>
#include <ctime>
#include <iostream>
#include <vector>
#include "Matrix_Header2.h"
#include "Management_Header.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::srand(std::time(nullptr));
    std::vector<std::vector<char>> board(8, std::vector<char>(8));

    setlocale(LC_ALL,"RU");
    int score;
    bool flag_tmp = 1;
    while (flag_tmp == 1) {
        std::cout << "Приветствуем вас в нашей игре!" << std::endl << "Цель игры - набрать максимальное количество очков" << std::endl;
        std::cout << "Вы получаете очки выждый раз когда на доске оказывается 3 или более одинаковых элементов в ряд" << std::endl;
        std::cout << "Выберите нужное действие с помощью ввода в консоль номера пункта" << std::endl;
        std::cout << "1 - Начать игру" << std::endl;
        std::cout << "2 - Текущий рекорд" << std::endl;
        std::cout << "3 - Кнопка для вывода котика <3" << std::endl;
        std::cout << "4 - Выйти из игры" << std::endl;
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                //вставьте сюда игровую функцию
                break;
            case 2:
                std::cout << score << std::endl;
                break;
            case 3:
                MurMiau();
                break;
            case 4:
                flag_tmp=0;
                break;
            default:
                std::cout << "Неправильный номер" << std::endl;
        }
    }
}
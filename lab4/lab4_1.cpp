#include <iostream>
#include <algorithm>


int main() {

    setlocale(LC_ALL, "Russian"); //#include <windows.h> SetConsoleOutputCP(CP_UTF8);

    // Инициализация

    int temp  = 1;
    int countr = 0;

    
    std::cout << "Введите числовую последовательность для определения суммы всех введенных чисел. (Последовательность должна оканчиваться числом 0) " << std::endl;

   // Цикл для нахождения суммы

    while (temp != 0) {

        if (std::cin >> temp) {

        }
        else
        {
            std::cin.ignore(100, '\n');
            std::cin.clear();
            std::cout << "Можно использовать только целые числа - Вы ввели символы";
            return 1;

        }
        countr += temp; 
    }
    std::cout << countr;

    return 0;
}
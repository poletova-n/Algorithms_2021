#include <iostream>
#include <algorithm>


int main() {

    setlocale(LC_ALL, "Russian"); //#include <windows.h> SetConsoleOutputCP(CP_UTF8);

    // Инициализация

    int f_el = 0;
    int s_el = 0;
    int th_el = 0;
    int temp  = 0;
    int countr = 0;

    
    std::cout << "Введите числовую последовательность для определения локальных максимумов. (Последовательность должна оканчиваться числом 0) " << std::endl;

    // Первичная проверка чисел
    
    if (std::cin >> f_el >> s_el >> th_el >> temp) {

    }
    else
    {
        std::cin.ignore(100, '\n');
        std::cin.clear();
        std::cout << "Можно использовать только целые числа - Вы ввели символы";
        return 1;

    }

   // Хватает ли чисел

    if ((f_el == 0) or (s_el == 0) or (th_el == 0)) {
        std::cout << "Недостаточно чисел для определения локальных максимумов";
        return 1;
    }

   // Первичная проверка на мусор для запуска цикла

    if ((s_el > f_el) and (s_el > th_el)) {
        countr++;
    }

   // Цикл для нахождения кол-ва

    while (temp != 0) {

        f_el = s_el;
        s_el = th_el;
        th_el = temp;

        if ((s_el > f_el) and (s_el > th_el)) {
            countr++;
        }

        // Проверка потока на мусор

        if (std::cin >> temp) {

        }
        else
        {
            std::cin.ignore(100, '\n');
            std::cin.clear();
            std::cout << "Можно использовать только целые числа - Вы ввели символы";
            return 1;

        }
    }
    std::cout << countr;

    return 0;
}
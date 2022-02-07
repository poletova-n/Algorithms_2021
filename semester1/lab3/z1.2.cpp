#include <iostream>
#include <Windows.h>

std::string setCorrectEnd( int n);

const char* ERROR_NOT_VALID_INPUT = "Ошибка: количество ворон должно быть задано целым числом больше нуля, завершение программы.";

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    try
    {
        int n = 0; // Инициализация переменной
        std::cout << "Введите количесто ворон: ";
        std::cin >> n;
        if (std::cin.fail() || n < 1 || std::cin.peek() != 10) // Проверка на корректность ввода
        {
            throw ERROR_NOT_VALID_INPUT;
        }
        else
        {
            std::cout << "В стае " << n << " ворон" << setCorrectEnd(n); // Вывод количества ворон с правильным окончанием слова
            return 0;
        }
    }
    catch(const char* error)
    {
        std::cerr << std::endl << error << std::endl;
        return -1;
    }
}

std::string setCorrectEnd( int n) // Функция, вычисляющая правильное окончание
{
    if(n%10 == 1 && n%100 != 11) // Если число оканчивается на 1, но не на 11, то следуюет добавить окончание "a"
    {
        return "а";
    }
    if(n%10 > 1 && n%10 < 5) // Если число оканчивается на 2, 3, 4 , то следуюет добавить окончание "ы"
    {
        return "ы";
    }
    else // Во всех остальных случаях доп символ не нужен
    {
        return "";
    }
}
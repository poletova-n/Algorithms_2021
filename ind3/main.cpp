#include <iostream>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <limits>
void duplicateFinder(int* mass, int n)
{
    int z=0; //счетчик повторов
    for (int i = 0;i < n;i++)
    {
        if ((*(mass + i) >= 0))//проверка чисел на положительные
        {
            for (int k=i+1;k<n;k++)
               if (*(mass + i) == *(mass + k)) //проверка чисел на эквивалентность
                z+=1;
        }
    }
    if (z==0)
        std::cout << "there are NO duplicate elements in the array\n";
    else
        std::cout << "there are duplicate elements in the array\n";
}
void init(int* mass, int n, int min, int max)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        mass[i] = (min + (rand() % (max - min + 1)));
    }
}
void output(int* mass, int n)
{
    std::cout << "Array elements:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "  " << *(mass + i) << "\n";
    }
}
int main()
{
    const int n = 5;
    int arr1[n] = {25, 25, 50, 4, 150};
    std::cout << "EX.1\n";
    output(arr1, n);
    duplicateFinder(arr1, n);
    int n2=0, min = 0, max = 0;
    std::cout << "EX.2\n";
    std::cout << " Enter the number  of elements of the array (((koli4estvo)))\n";
    while (!(std::cin >> n2) || (n2 < 1))
    {
        std::cout << "  The number of array elements must be an INTEGER from 1 to 2 147 483 647\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
        n2 = 0;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
    int* arr2 = new int[n2];
    std::cout << " Enter the borders of the interval from which random values will be taken\n";
    while (!(std::cin >> min) || !(std::cin >> max) || (min>max)) {
    std::cout << " Borders should be set as an INTEGER NUMBER from -2 147 483 648 to 2 147 483 647, and the left border must be less than the right one\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
        min = 0;
        max = 0;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
    init(arr2, n2, min, max);
    output(arr2, n2);
    duplicateFinder(arr2, n2);
    delete[] arr2;
    int n3 = 0;
    std::cout << "Ex.3\n";
        std::ifstream file("../Igor.txt");
    while (!file.eof())
    {
        file >> n3;
        if (file.fail())
        {
            std::cout << " Invalid value for the number of cells in the array"; //Неверное значение для количества ячеек массива
            n3 = 0;
            return 2;
        }
        int* arr = new int[n3];
        for (int i = 0;i < n3;i++)
        {
            if (file.good())
            {
                file >> *(arr + i);
            }
            if (file.fail())
            {
                std::cout << " Invalid value to write to array"; //Неверное значение для записи в массив
                return 2;
            }
        }
        output(arr, n3);
        duplicateFinder(arr, n3);
        delete[] arr;
    }
    return 0;
}
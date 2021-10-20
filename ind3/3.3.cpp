#include <iostream>
#include <fstream>
#include <string>
#include "counter.h"


int main()
{
    int n;
    std::string line;
    std::ifstream file("C:\\Users\\01\\CLionProjects\\Algorithms_2021\\ind3\\array.txt");
    if (file.is_open())
    {
        file >> n;
    }
    int *array = new int[n];
    if (file.is_open())
    {
        for (int i = 0; i < n; i++)
        {
            file >> array[i];
            std::cout << array[i] << std::endl;
        }
    }
    std::cout << "Number of positive elements of the first array:" << counter(n,array);
    file.close();
    delete[] array;
}




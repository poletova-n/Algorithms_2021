#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

int Count (int size, int array[]);

int main()
{
    int size;
    int *array = new int[size];
    std::string line;
    std::ifstream file("C:\\Users\\01\\CLionProjects\\Algorithms_2021\\ind3\\array.txt");
    if (file.is_open())
    {
        file >> size;
        for (int i = 0; i < size; i++)
        {
            file >> array[i];
            std::cout << array[i] << std::endl;
        }
    }
    int result = Count(size,array);
    std::cout << "Number of positive elements of the first array:" << result;
    file.close();
    delete[] array;
}
int Count (int size, int array[])
{
    size = 10;
    int count = 0;
    int min = INT_MAX;
    array[size] = {};
    int index = 0;
    for (int j = 0; j < size; j++)
    {
        if (array[j] < min)
        {
            min = array[j];
            index = j;
        }
    }
    for (int i = 0; i <=  index; i++)
    {
        if(array[i] > 0)
        {
            count ++;
        }
    }
    return count;
}



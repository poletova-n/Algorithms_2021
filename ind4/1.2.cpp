#include <iostream>
#include <fstream>
#include <string>

const char* file_not_open = "File not open.";

char* DelNum(const char* arr, char* finArr);

int main()
{
    try
    {
        int size = 0;
        std::ifstream file("C:\\Users\\01\\CLionProjects\\Algorithms_2021\\ind4\\text.txt");
        if (!file.is_open())
        {
            throw file_not_open;
        }
        else
        {
            while (!file.eof())
            {
                file >> size;
                int count = 0;
                char symbol = 'k';
                char *arr = new char[size];
                char *finArr = new char[size];
                while ((symbol != '\0') and (count < size))
                {
                    symbol = file.get();
                    arr[count] = symbol;
                    count++;
                }
                arr[size+1] = '\0';
                DelNum(arr, finArr);
                delete[] arr;
                delete[] finArr;
                file.close();
                return 0;
            }

        }
    }
    catch (const char* error)
    {
        std::cerr << error;
        return -1;
    }
}
char* DelNum(const char* arr, char* finArr)
{
    for (int i = 0; arr[i]; i++)
    {
        for (int k = 0; arr[k]; k++)
        {
            if (arr[i] <= '9' and arr[i] >= '0')
            {
                i++;
            }
            finArr[k] = arr[i];
        }
        std::cout << finArr[i];
    }
    return finArr;
}

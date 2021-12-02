#include <iostream>
#include <fstream>

const char* file_not_open = "File not open.";

const int line = 4;
const int column = 5;

int Check(int (&array)[line][column]);

int main()
{
    try
    {
        std::fstream res("C:\\Users\\01\\CLionProjects\\Algorithms_2021\\ind5\\res1");
        int arr[line][column] = { {0, 8, 9, 13, 987}, {8, 4, 0, 0, 98}, {95, 70, 2, 1, 707}, {10, 20, 30, 77, 3} };
        if (!res.is_open())
        {
            throw file_not_open;
        }
        else
        {
            res << Check(arr);
            res.close();
        }
    }
    catch (const char* error)
    {
        std::cerr << error;
        return -1;
    }
}

int Check(int (&array)[line][column])
{
    int count = 0;
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (array[i][j] == 0)
            {
                count ++;
                break;
            }
        }
    }
    return count;
}
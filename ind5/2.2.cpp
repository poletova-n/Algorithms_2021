#include <iostream>
#include <fstream>

const char* file_not_open = "File not open.";

int Check(int** array, int n);
int** CreateArr(int n);
void Input(std::ifstream& input,int** array, int n);

int main()
{

    try
    {
        int n = 4;
        std::ifstream input("C:\\Users\\01\\CLionProjects\\Algorithms_2021\\ind5\\data2");
        std::ofstream out("C:\\Users\\01\\CLionProjects\\Algorithms_2021\\ind5\\res2");
        if (!out.is_open() or !input.is_open())
        {
            throw file_not_open;
        }
        else
        {
            int** arr = CreateArr(n);
            Input(input,arr,n);
            out << Check(arr,n);
            out.close();
            input.close();
            for (int i = 0; i < n; i++)
            {
                delete[] arr[i];
            }
            delete[] arr;
        }
    }
    catch (const char* error)
    {
        std::cerr << error;
        return -1;
    }
}

int Check(int** array, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i == 0 or j == 0 or array[i][j] < array[i-1][j-1]) and
                (i == 0 or array[i][j] < array[i-1][j]) and
                (i == 0 or j == n - 1 or array[i][j] < array[i-1][j+1]) and
                (j == 0 or array[i][j] < array[i][j-1]) and
                (j == n - 1 or array[i][j] < array[i][j+1]) and
                (i == n - 1 or j == 0 or array[i][j] < array[i+1][j-1]) and
                (i == n - 1 or array[i][j] < array[i+1][j]) and
                (i == n - 1 or j == n - 1 or array[i][j] < array[i+1][j+1]))
            {
                count ++;
            }
        }
    }
    return count;
}
int** CreateArr(int n)
{
    int** array  = new int*[n];
    for (int i = 0; i<n; i++)
    {
        array[i] = new int[n];
    }
    return array;
}
void Input(std::ifstream& input,int** array, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            input >> array[i][j];
        }
    }
}
void Print(int** array, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << array[i][j];
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

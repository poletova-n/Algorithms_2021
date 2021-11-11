#include <iostream>
#include <fstream>

const char* ERROR_FILE_NOT_OPEN = "The file was not open!";

bool Comparison(char array1[], char array2[], int count1, int count2)
{
    for (int i = 0; i < count1; i++)
    {
        for (int j = 0; j < count2; j++)
        {
            if (array1[i] == array2[j])
                return 1;
        }
    }
    return 0;
}
int main()
{
    int max_size = 0;
    std::ifstream input("C:/Users/PetrK/Documents/Visual Studio Files/ConsoleApplication15/input.txt");
    try
    {
        if (!input.is_open())
        {
            throw ERROR_FILE_NOT_OPEN;
        }
    }
    catch (const char* error)
    {
        std::cerr << error;
        return -1;
    }
    while (!input.eof())
    {
        char object = 'a';
        input >> max_size;
        char* array1 = new char[max_size];
        char* array2 = new char[max_size];

        int i = 0;
        while ((i < max_size) && (object != '\0'))
        {
            input >> object;
            //std::cout << object;
            array1[i] = object;
            i++;
        }
        //std::cout << std::endl;
        int count1 = i;
        i = 0;
        object = 'a';
        while ((i < max_size) && (object != '\0'))
        {
            input >> object;
            //std::cout << object;
            array2[i] = object;
            i++;
        }
        //std::cout << std::endl;
        int count2 = i;
        if (Comparison(array1, array2, count1, count2) == 1)
        {
            std::cout << "true" << std::endl;
        }
        else
        {
            std::cout << "false" << std::endl;
        }
        delete[] array1;
        delete[] array2;
        return 0;

    }
}
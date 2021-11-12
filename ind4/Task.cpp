#include <iostream>
#include <fstream>

const char* ERROR_FILE_NOT_OPEN = "The file was not open!";

bool Comparison(char const* array1, char const* array2)
{
    int i = 0, j = 0;
    while (array1[i] != '\0')
    {
        while (array2[j] != '\0')
        {
            if (array1[i] == array2[j])
                return 1;
            j++;
        }
        j = 0;
        i++;
    }
    return 0;
}
int main()
{
    int max_size = 0;
    std::ifstream input("C:/Users/PetrK/Documents/Visual Studio Files/ConsoleApplication15/input.txt");
    std::ofstream output("C:/Users/PetrK/Documents/Visual Studio Files/ConsoleApplication15/output.txt");
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
        char* array1 = new char[max_size + 1];
        char* array2 = new char[max_size + 1];

        int i = 0;
        while ((i < max_size) && (object != '\0'))
        {
            input >> object;
            //std::cout << object;
            array1[i] = object;
            i++;
        }
        array1[i] = '\0';
        i = 0;
        object = 'a';
        while ((i < max_size) && (object != '\0'))
        {
            input >> object;
            //std::cout << object;
            array2[i] = object;
            i++;
        }
        array2[i] = '\0';

        //std::cout << std::endl;
        if (Comparison(array1, array2) == 1)
        {
            output << "true" << std::endl;
        }
        else
        {
            output << "false" << std::endl;
        }
        delete[] array1;
        delete[] array2;
        return 0;

    }
}
#include <iostream>
#include <fstream>

const char* ERROR_INPUT_FILE_NOT_FOUND = "Error: input file not found.";

const char* ERROR_OUTPUT_FILE_NOT_FOUND = "Error: output file not found.";

void setArray(int** &array, int sizeX, int sizeY, std::ifstream &input);

int getDuplNumber( int** &array, int sizeX, int sizeY);

bool isColumnNumsUniq( int** &array, int sizeY, int &columnNumber);

int main()
{
    try
    {
        std::ifstream input("D:\\PTcodes\\c++\\GitPull\\Algorithms_2021\\ind5\\input\\input_2.txt");

        if (!input.is_open())
        {
            throw ERROR_INPUT_FILE_NOT_FOUND;
        }

        int sizeX = 0;
        int sizeY = 0;

        int** array;

        input >> sizeX;
        input >> sizeY;

        setArray(array, sizeX, sizeY, input);

        input.close();

        int answer = getDuplNumber(array, sizeX, sizeY);

        std::ofstream output("D:\\PTcodes\\c++\\GitPull\\Algorithms_2021\\ind5\\output\\output_2.txt");

        if (!output.is_open())
        {
            throw ERROR_OUTPUT_FILE_NOT_FOUND;
        }

        output << answer;

        output.close();

        for (int i = 0; i < sizeX; ++i)
        {
            delete [] array[i];
        }
        delete [] array;
        
    }
    catch(const char* error)
    {
        system("cls");
        std::cerr << std::endl << error << std::endl;
        exit(1);
    }
}

void setArray(int** &array, int sizeX, int sizeY, std::ifstream &input)
{
    array = new int* [sizeX];

    for (int i = 0; i < sizeX; ++i)
    {
        int* line = new int[sizeY];
        for (int j = 0; j < sizeY; ++j)
        {
            input >> line[j];
        }
        array[i] = line;
    }
}

int getDuplNumber( int**& array, int sizeX, int sizeY)
{
    int ans = 0;

    for (int i = 0; i < 3; ++i)
    {
        if(isColumnNumsUniq(array, sizeY, i)) ans++;
    }
    return ans;
}

bool isColumnNumsUniq( int**& array, int sizeY, int &columnNumber)
{
    for (int i = 0; i < sizeY; ++i)
    {
        for (int j = 0; j < sizeY; ++j)
        {
            if(j != i && array[j][columnNumber] == array[i][columnNumber])
            {
                return false;
            }
        }
    }
    return true;
}
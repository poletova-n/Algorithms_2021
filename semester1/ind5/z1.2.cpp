#include <iostream>
#include <fstream>

const char* ERROR_INPUT_FILE_NOT_FOUND = "Error: input.txt file not found.";

const char* ERROR_OUTPUT_FILE_NOT_FOUND = "Error: output.txt file not found.";

const char* ERROR_INVALID_ARRAY_INPUT = "Error: invalid array input.txt.";

const char* ERROR_X_NOT_FOUND = "Error: array x size not found.";

const char* ERROR_Y_NOT_FOUND = "Error: array y size not found.";

const char* ERROR_INVALID_X_INPUT = "Error: x must be integer greater then 0.";

const char* ERROR_INVALID_Y_INPUT = "Error: y must be integer greater then 0.";

void setArray(int** &array, int sizeX, int sizeY, std::ifstream &input);

int getDuplNumber( int** &array, int sizeX, int sizeY);

bool isColumnNumsUniq( int** &array, int sizeY, int &columnNumber);

int main()
{
    try
    {
        std::ifstream input("D:\\PTcodes\\c++\\GitPull\\Algorithms_2021\\ind5\\input.txt\\input_2.txt");

        if (!input.is_open())
        {
            throw ERROR_INPUT_FILE_NOT_FOUND;
        }

        int sizeX = -5;
        int sizeY = -5;

        int** array;

        if(!input.eof())
        {
            input >> sizeX;
            if(input.fail() || sizeX < 1 || (input.peek() != 10 && input.peek() != 32))
            {
                throw ERROR_INVALID_X_INPUT;
            }
        } else
        {
            throw ERROR_X_NOT_FOUND;
        }

        if(!input.eof())
        {
            input >> sizeY;
            if(input.fail() || sizeY < 1 || (input.peek() != 10 && input.peek() != 32))
            {
                throw ERROR_INVALID_Y_INPUT;
            }
        } else
        {
            throw ERROR_Y_NOT_FOUND;
        }

        setArray(array, sizeX, sizeY, input);

        input.close();

        int answer = getDuplNumber(array, sizeX, sizeY);

        std::ofstream output("D:\\PTcodes\\c++\\GitPull\\Algorithms_2021\\ind5\\output.txt\\output_2.txt");

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
            if(!input.eof()) {
                input >> line[j];
                if(input.fail() || (input.peek() != 10 && input.peek() != 32))
                {
                    throw ERROR_INVALID_ARRAY_INPUT;
                }
            } else
            {
                throw ERROR_INVALID_ARRAY_INPUT;
            }
        }
        array[i] = line;
        if(!input.eof()){
            throw ERROR_INVALID_ARRAY_INPUT;
        }
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
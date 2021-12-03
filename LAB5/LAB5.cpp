#include <iostream>
#include <fstream>

const char* ERROR_INPUT_FILE_NOT_FOUND = "Error: input.txt file not found.";

const char* ERROR_OUTPUT_FILE_NOT_FOUND = "Error: output.txt file not found.";

const char* ERROR_INVALID_ARRAY_INPUT = "Error: invalid array input.txt.";

const int sizeX = 3;

const int sizeY = 3;

void setArray(int(&array)[sizeX][sizeY], std::ifstream& input);

int getDuplNumber(int(&array)[sizeX][sizeY]);

bool isColumnNumsUniq(int(&array)[sizeX][sizeY], int& columnNumber);

int main()
{
    try {
        int array[sizeX][sizeY];

        std::ifstream input(R"(C:\Users\orcva\source\repos\LAB1\LAB5\input.txt)");
        if (!input.is_open())
        {
            throw ERROR_INPUT_FILE_NOT_FOUND;
        }

        setArray(array, input);

        input.close();

        int answer = getDuplNumber(array);

        std::ofstream output(R"(C:\Users\orcva\source\repos\LAB1\LAB5\output.txt)");
        if (!output.is_open())
        {
            throw ERROR_OUTPUT_FILE_NOT_FOUND;
        }

        output << answer;

        output.close();
    }
    catch (const char* error)
    {
        system("cls");

        std::cerr << std::endl << error << std::endl;
        exit(1);
    }
}

void setArray(int(&array)[sizeX][sizeY], std::ifstream& input)
{
    for (int i = 0; i < sizeX; ++i)
    {
        for (int j = 0; j < sizeY; ++j)
        {
            if (!input.eof()) {
                input >> array[i][j];
                /*if (input.fail() || (input.peek() != 10 && input.peek() != 32))
                {
                    throw ERROR_INVALID_ARRAY_INPUT;
                }*/
            }
            else
            {
                throw ERROR_INVALID_ARRAY_INPUT;
            }
            
            /*if (!input.eof()) {
                throw ERROR_INVALID_ARRAY_INPUT;
            }*/
        }
    }
}

int getDuplNumber(int(&array)[sizeX][sizeY])
{
    int ans = 0;

    for (int i = 0; i < sizeX; ++i)
    {
        if (!isColumnNumsUniq(array, i)) ans++;
    }

    return ans;
}

bool isColumnNumsUniq(int(&array)[sizeX][sizeY], int& columnNumber)
{
    for (int i = 0; i < sizeX; ++i)
    {
        for (int j = 0; j < sizeY; ++j)
        {
            if (j != i && array[j][columnNumber] == array[i][columnNumber])
            {
                return false;
            }
        }
    }
    return true;
}

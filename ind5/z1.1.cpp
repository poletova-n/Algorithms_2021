#include <iostream>
#include <fstream>

const char* ERROR_FILE_NOT_FOUND = "Error: file not found.";

const int sizeX = 3;

const int sizeY = 3;

void setArray(int (&array)[sizeX][sizeY], std::ifstream &input);

int getDuplNumber(int (&array)[sizeX][sizeY]);

bool isColumnNumsUniq(int (&array)[sizeX][sizeY], int &columnNumber);

int main()
{
    try {
        int array[sizeX][sizeY];

        std::ifstream input("D:\\PTcodes\\c++\\GitPull\\Algorithms_2021\\ind5\\input\\input_1.txt");
        if (!input.is_open())
        {
            throw ERROR_FILE_NOT_FOUND;
        }

        setArray(array, input);

        input.close();

        int answer = getDuplNumber(array);

        std::ofstream output("D:\\PTcodes\\c++\\GitPull\\Algorithms_2021\\ind5\\output\\output_1.txt");
        if (!output.is_open()) {
            throw ERROR_FILE_NOT_FOUND;
        }

        output << answer;

        output.close();
    }
    catch(const char* error)
    {
        system("cls");

        std::cerr << std::endl << error << std::endl;
        exit(1);
    }
}

void setArray(int (&array)[sizeX][sizeY], std::ifstream &input)
{
    for (int i = 0; i < sizeX; ++i)
    {
        for (int j = 0; j < sizeY; ++j)
        {
            input >> array[i][j];
        }
    }
}

int getDuplNumber(int (&array)[sizeX][sizeY])
{
    int ans = 0;

    for (int i = 0; i < sizeX; ++i)
    {
        if(isColumnNumsUniq(array,i)) ans++;
    }

    return ans;
}

bool isColumnNumsUniq(int (&array)[sizeX][sizeY], int &columnNumber)
{
    for (int i = 0; i < sizeX; ++i)
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
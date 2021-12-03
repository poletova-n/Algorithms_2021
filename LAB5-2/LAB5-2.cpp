#include <iostream>
#include <fstream>

const char* ERROR_INPUT_FILE_NOT_FOUND = "Error: input.txt file not found.";

const char* ERROR_OUTPUT_FILE_NOT_FOUND = "Error: output.txt file not found.";

const char* ERROR_INVALID_ARRAY_INPUT = "Error: invalid array input.txt.";

const char* ERROR_X_NOT_FOUND = "Error: array x size not found.";

const char* ERROR_Y_NOT_FOUND = "Error: array y size not found.";

const char* ERROR_INVALID_X_INPUT = "Error: x must be integer greater then 0.";

const char* ERROR_INVALID_Y_INPUT = "Error: y must be integer greater then 0.";

void setArray(int**& array, int sizeX, int sizeY, std::ifstream& input);

int getDuplNumber(int**& array, int sizeX, int sizeY);

bool isColumnNumsUniq(int**& array, int sizeY, int& columnNumber);

int main()
{
    try
    {
        std::ifstream input(R"(C:\Users\orcva\source\repos\LAB1\LAB5-2\input.txt)");

        if (!input.is_open())
        {
            throw ERROR_INPUT_FILE_NOT_FOUND;
        }

        int sizeX = -5;
        int sizeY = -5;

        int** array;

        if (!input.eof())
        {
            input >> sizeX;
            if (input.fail() || sizeX < 1 || (input.peek() != 10 && input.peek() != 32))
            {
                throw ERROR_INVALID_X_INPUT;
            }
        }
        else
        {
            throw ERROR_X_NOT_FOUND;
        }

        if (!input.eof())
        {
            input >> sizeY;
            if (input.fail() || sizeY < 1 || (input.peek() != 10 && input.peek() != 32))
            {
                throw ERROR_INVALID_Y_INPUT;
            }
        }
        else
        {
            throw ERROR_Y_NOT_FOUND;
        }

        setArray(array, sizeX, sizeY, input);

        input.close();

        int answer = getColWithMaxRepeats(array, sizeX, sizeY);

        std::ofstream output(R"(C:\Users\orcva\source\repos\LAB1\LAB5-2\output.txt)");
        if (!output.is_open()){
            throw ERROR_OUTPUT_FILE_NOT_FOUND;
        }
        output << answer;
        output.close();

        for (int i = 0; i < sizeX; ++i)
        {
            delete[] array[i];
        }
        delete[] array;

    }
    catch (const char* error)
    {
        system("cls");
        std::cerr << std::endl << error << std::endl;
        exit(1);
    }
}

void setArray(int**& array, int sizeX, int sizeY, std::ifstream& input)
{
    array = new int* [sizeX];

    for (int i = 0; i < sizeX; ++i)
    {
        int* line = new int[sizeY];
        for (int j = 0; j < sizeY; ++j)
        {
            if (!input.eof()) {
                input >> line[j];
            }
            else
            {
                throw ERROR_INVALID_ARRAY_INPUT;
            }
        }
        array[i] = line;
    }
}

int getColumnNumsRepeats(int**& array, int sizeY, int& columnNumber)
{
    int maxReps = 0;
    int curReps = 0;
    for (int i = 1; i < sizeY; ++i)
    {
        if (array[i-1][columnNumber] == array[i][columnNumber]) {
            curReps++;
            if (curReps > maxReps) {
                maxReps = curReps;
            }
        }
        else {
            curReps = 0;
        }
    }
    return maxReps;
}

int getColWithMaxRepeats(int**& array, int sizeX, int sizeY)
{
    int ans = -1;
    int prevReps = 0;

    for (int i = 0; i < 3; ++i)
    {
        int reps = getColumnNumsRepeats(array, sizeY, i);
        if (reps > prevReps) {
            ans = i;
            prevReps = reps;
        }
    }
    return ans;
}


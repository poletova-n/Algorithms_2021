#include <iostream>
#include <fstream>
const char* ERROR_INPUT_FILE_NOT_FOUND = "Error: input.txt file not found.";
const char* ERROR_OUTPUT_FILE_NOT_FOUND = "Error: output.txt file not found.";
const char* ERROR_X_NOT_FOUND = "Error: array x size not found.";
const char* ERROR_Y_NOT_FOUND = "Error: array y size not found.";
const char* ERROR_INVALID_X_INPUT = "Error: x must be integer greater then 0.";
const char* ERROR_INVALID_Y_INPUT = "Error: y must be integer greater then 0.";
const char* ERROR_INVALID_ARRAY_INPUT = "invalid array";
void setArray(int** &array, int sizeX, int sizeY, std::ifstream &input);
int KolvoDupl( int** &array, int sizeX, int sizeY);
bool RowUniq( int** &array, int sizeX, int &rowNumber);
int main()
{
    try
    {
        std::ifstream input("C:\\Users\\User\\CLionProjects\\ind3\\input.txt");
        if (!input.is_open())
        {
            throw ERROR_INPUT_FILE_NOT_FOUND;
        }
        int sizeX;
        int sizeY;
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
        int answer = KolvoDupl(array, sizeX, sizeY);
        std::ofstream output("C:\\Users\\User\\CLionProjects\\ind3\\output.txt");
        if (!output.is_open())
        {
            throw ERROR_OUTPUT_FILE_NOT_FOUND;
        }
        \

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
        std::cerr << std::endl << error << std::endl;
        exit(1);
    }
}

void setArray(int** &array, int sizeX, int sizeY, std::ifstream &input) {
    array = new int *[sizeX];
    for (int i = 0; i < sizeX; ++i) {
        int *line = new int[sizeX];
        for (int j = 0; j < sizeX; ++j) {
            if (!input.eof()) {
                input >> line[j];
                if (input.fail()) {
                    throw ERROR_INVALID_ARRAY_INPUT;
                }
            }
        }
        array[i] = line;
        }
    }

int KolvoDupl( int**& array, int sizeX, int sizeY)
{
    int ans = 0;

    for (int i = 0; i < 3; ++i)
    {
        if(RowUniq(array, sizeX, i)) ans++;
    }
    return ans;
}

bool RowUniq( int**& array, int sizeX, int &rowNumber)
{
    for (int i = 0; i < sizeX; ++i)
    {
        for (int j = 0; j < sizeX; ++j)
        {
            if(j != i && array[rowNumber][j] == array[rowNumber][i])
            {
                return false;
            }
        }
    }
    return true;
}
#include <iostream>
#include <fstream>
#include <string>

const char* ERROR_FILE_NOT_FOUND = "Error: file not found";

const char* ERROR_INVALID_FILE_INPUT = "Error: invalid file input.txt structure";

const char* ERROR_INVALID_ARRAY_INPUT = "Error: array must contain only integers";

const char* ERROR_INVALID_ARRAY_SIZE_INPUT = "Error: array size must be integer greater then 0 and placed on new line";

void readAndWorkWithFile(std::string &filename);

int main()
{
    std::string filename = R"(C:\Users\orcva\source\repos\LAB1\LAB3\input.txt)";
    readAndWorkWithFile(filename);
}

void readAndWorkWithFile(std::string &filename){
    try {

        int n = 0;
        int curPos = 3;

        std::cout << "Answers: " << std::endl;

        std::ifstream input(filename);
        if (!input.is_open())
        {
            throw ERROR_FILE_NOT_FOUND;
        }
        else
        {
            while(!input.eof())
            {
                int curN = 0;
                input >> curN;
                if(curN < 1 || input.fail() || input.peek() != 10 || input.peek() == 32)
                {
                    throw ERROR_INVALID_ARRAY_SIZE_INPUT;
                }

                int *array = new int[curN];
                int count = 0;
                for (int j = 0; j < curN; ++j)
                {
                    input >> array[j];
                    if(input.fail())
                    {
                        throw ERROR_INVALID_ARRAY_INPUT;
                    }
                }

                for (int i = 2; i < curN; ++i) {
                    if (array[i - 2] < array[i - 1] && array[i - 1] < array[i]) {
                        ++count;
                    }
                }


                char check = ' ';
                input.get(check);

                if(check != 10 && !input.eof())
                {
                    throw ERROR_INVALID_FILE_INPUT;
                }

                std::cout << count << std::endl;

                delete [] array;
            }
        }

        input.close();
    }
    catch(const char* error)
    {
        system("cls");

        std::cerr << std::endl << error << std::endl;
        exit(-1);
    }
}
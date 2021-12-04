#include <iostream>
#include <fstream>

const char* ERROR_FILE_NOT_FOUND = "Error: file not found";

const char* TRUE = "True";

const char* FALSE = "False";

const char* & DuplicatesInRow(char* &array);

int main()
{
    try {
        std::ifstream in("../input.txt");

        if (!in.is_open()) {
            throw ERROR_FILE_NOT_FOUND;
        }

        int currentPos = 0;
        bool isEnd = false;

        while (!isEnd) {

            in.seekg(currentPos);
            char currentSumbol = '1';
            int move = 0;

            while (true) {
                in.get(currentSumbol);
                if (currentSumbol != 10 && !in.eof()) {
                    move++;
                } else {
                    break;
                }
            }

            if (in.eof()) {
                isEnd = true;
            }

            in.clear();
            in.seekg(currentPos);

            char *array = new char[move + 1];

            for (int i = 0; i < move; ++i) {
                in >> array[i];
            }

            array[move] = '\0';

            currentPos += move + 2;

            std::cout << DuplicatesInRow(array) << std::endl;

            delete [] array;
        }
    }
    catch(const char* error)
    {
        std::cerr << std::endl << error << std::endl;
        exit(1);
    }
}
const char* & DuplicatesInRow(char* &array)
{
    for (int i = 0; array[i]; ++i)
    {
        if (array[i] == array[i + 1])
        {
            return TRUE;
        }
    }
    return FALSE;
}
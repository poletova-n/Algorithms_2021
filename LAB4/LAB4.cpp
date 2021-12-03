#include <iostream>
#include <fstream>

const char* ERROR_FILE_NOT_FOUND = "Error: file not found";

const char S1 = 'w';
const char S2 = 'W';

int main()
{
    try {
        std::ifstream in("C:\\Users\\orcva\\source\\repos\\LAB1\\LAB4\\input.txt");

        if (!in.is_open()) {
            throw ERROR_FILE_NOT_FOUND;
        }

        int curPos = 0;
        bool isEnd = false;

        while (!isEnd) {

            in.seekg(curPos);
            char curSumbol = '1';
            int moveN = 0;

            while (true) {
                in.get(curSumbol);
                if (curSumbol != 10 && !in.eof()) {
                    moveN++;
                }
                else {
                    break;
                }
            }

            if (in.eof()) {
                isEnd = true;
            }

            in.clear();
            in.seekg(curPos);

            char* array = new char[moveN + 1];

            for (int i = 0; i < moveN; ++i) {
                char curC;
                in >> curC;
                if (curC == S1)
                    array[i] = S2;
                else
                    array[i] = curC;
            }

            array[moveN] = '\0';
            curPos += moveN + 2;
            std::cout << array << std::endl;
            delete[] array;
        }
    }
    catch (const char* error)
    {
        system("cls");
        std::cerr << std::endl << error << std::endl;
        exit(1);
    }
}


#include <iostream>
#include <fstream>

const char* ERROR_FILE_NOT_FOUND = "Error: file not found";

const char* KEY_YES = "Yes";

const char* KEY_NO = "No";

const char* & hasDuplicates(char* &array);

int main()
{
    try {
        std::ifstream in("D:\\PTcodes\\c++\\GitPull\\Algorithms_2021\\ind4\\input.txt");

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
                } else {
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
                in >> array[i];
            }

            array[moveN] = '\0';

            curPos += moveN + 2;

            std::cout << hasDuplicates(array) << std::endl;

            delete [] array;
        }
    }
    catch(const char* error)
    {
        system("cls");

        std::cerr << std::endl << error << std::endl;
        exit(1);
    }
}

const char* & hasDuplicates(char* &array)
{
    for (int i = 0; array[i]; ++i)
    {
        for (int j = 0; array[j]; ++j)
        {
            if(array[i] == array[j] && i != j)
            {
                return KEY_YES;
            }
        }
    }
    return KEY_NO;
}
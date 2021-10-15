#include <iostream>
#include <fstream>
#include <string>

const char* ERROR_FILE_NOT_FOUND = "Error: file not found";

int main()
{
    std::ifstream in("D:\\PTcodes\\c++\\GitPull\\Algorithms_2021\\ind4\\input.txt");
    if (!in.is_open())
    {
        throw ERROR_FILE_NOT_FOUND;
    }
    int curPos = 0;
    while (!in.eof())
    {
        in.seekg(curPos);
        char curSumbol = '1';
        int moveN = 0;
        bool isEnd = false;

        while (curSumbol != 10 && !in.eof())
        {
            in.get(curSumbol);
            moveN++;
        }

        if(in.eof())
        {
            moveN--;
            isEnd = true;
        }


        in.clear();
        in.seekg(curPos);

        char *array = new char[moveN];
        bool hasDupl = false;

        for (int i = 0; i < moveN; ++i) {
            in >> array[i];
            for (int j = 0; j < i; ++j) {
                if(array[i] == array[j])
                {
                    hasDupl = true;
                    break;
                }
            }
        }

        curPos += moveN + 1;

        std::cout << hasDupl << std::endl;
        if(isEnd) break;
    }
}
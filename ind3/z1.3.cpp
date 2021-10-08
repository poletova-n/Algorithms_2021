#include <iostream>
#include <fstream>
#include <string>

const char* ERROR_FILE_NOT_FOUND = "Error: file not found";

const char* ERROR_INVALID_FILE_INPUT = "Error: invalid file input";

int main()
{
    try {
        int n = 0;
        int curPos = 3;
        std::ifstream in("D:\\PTcodes\\c++\\GitPull\\Algorithms_2021\\ind3\\input.txt");
        if (!in.is_open())
        {
            throw ERROR_FILE_NOT_FOUND;
        }
        else
        {
            in >> n;
            if(n < 1)
            {
                throw ERROR_INVALID_FILE_INPUT;
            }
            for (int i = 0; i < n; ++i)
            {
                in.seekg(curPos);
                char curSumbol = '1';
                int curN = 0;
                int moveN = 0;
                while (!in.eof()) {
                    in.get(curSumbol);
                    if (curSumbol == ' ')
                    {
                        curN++;
                    }
                    if (curSumbol == '\n')
                    {
                        moveN++;
                        break;
                    }
                    moveN++;
                }
                if (moveN > 1) curN++;

                int *array = new int[curN];
                int max = std::numeric_limits<int>::min();
                int count = 0;

                in.clear();
                in.seekg(curPos);

                for (int j = 0; j < curN; j++)
                {
                    in >> array[j];
                }
                curPos += moveN + 1;
                for (int j = 0; j < curN; j++)
                {
                    if (max < array[j])
                    {
                        max = array[j];
                        count = 0;
                    } else {
                        if (array[j] < 0)
                        {
                            count++;
                        }
                    }
                }
                std::cout << count << std::endl;
            }
        }
    }
    catch(const char* error)
    {
        std::cerr << std::endl << error << std::endl;
        return -1;
    }
}




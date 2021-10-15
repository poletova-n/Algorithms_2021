#include <iostream>
#include <string>
#include <fstream>

const char* ERROR_FILE_NOT_OPENED = "File didn't open!";

const char* ERROR_NUMBER_NOT_POSITIVE = "The first symbol in your file isn't positive!";

void swap(int& a, int& b)
{
    int term = a;
    a = b;
    b = term;
}

int main()
{
    try {
        int firstNumber;
        int position = 3;
        std::ifstream fin("C:\\Users\\anush\\Algorithms_2021\\ind3\\myText.txt");
        if (!fin.is_open())
        {
            throw ERROR_FILE_NOT_OPENED;
        }
        else
        {
            fin >> firstNumber;
            if(firstNumber < 1)
            {
                throw ERROR_NUMBER_NOT_POSITIVE;
            }
            for (int i = 0; i < firstNumber; ++i)
            {
                fin.seekg(position);
                char nextSymbol;
                int sizeArray = 0;
                int movePosition = 0;
                while (!fin.eof()) {
                    fin.get(nextSymbol);
                    if (nextSymbol == ' ')
                    {
                        sizeArray++;
                    }
                    if (nextSymbol == '\n')
                    {
                        movePosition++;
                        break;
                    }
                    movePosition++;
                }
                if (movePosition > 1)
                {
                    sizeArray++;
                }

                int *arr = new int[sizeArray];

                fin.clear();
                fin.seekg(position);

                for (int j = 0; j < sizeArray; j++)
                {
                    fin >> arr[j];
                }
                position += movePosition + 1;
                for(int i = 0; i < sizeArray; ++i)
                {
                    int smaller = i;
                    for(int current = 0; current < sizeArray; ++current)
                    {
                        if(arr[smaller] < arr[current])
                        {
                            swap(arr[smaller], arr[current]);
                        }
                    }
                }
                std::cout << std::endl;
                for(int i = 0; i < sizeArray; ++i)
                {
                    std::cout << arr[i] << " ";
                }
                delete [] arr;
            }
        }
        fin.close();
        return 0;
    }
    catch(const char* error)
    {
        std::cerr << std::endl << error << std::endl;
        return -1;
    }
}
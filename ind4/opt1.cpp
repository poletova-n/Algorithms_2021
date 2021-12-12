#include <iostream>
#include <fstream>

const char* ERROR_FILE_NOT_OPENED = "File didn't open!";

char * removeSpace(const char * input, char * inputCopy);

int main()
{
    try
    {
        int position = 0;
        int sizeOfString;
        std::ifstream fin("C:\\Users\\anush\\Algorithms_2021\\ind4\\myText.txt");
        if (!fin.is_open()) {
            throw ERROR_FILE_NOT_OPENED;
        }
        else
        {
            while (!fin.eof())
            {
                fin.seekg(position);
                fin >> sizeOfString;

                char * arr = new char[sizeOfString];
                char * arrCopy = new char[sizeOfString];

                fin.seekg(position+3);
                char currentSymbol;
                int i = 0;

                while(fin.get(currentSymbol) && i < sizeOfString)
                {
                    arr[i] = currentSymbol;
                    i++;
                }

                arr[sizeOfString] = '\0';

                position += sizeOfString+5;

                removeSpace(arr, arrCopy);

                std::cout << " ";
            }
        }
        fin.close();
        return 0;
    }
    catch(const char * error)
    {
        std::cerr << std::endl << error << std::endl;
        return -1;
    }
}

char * removeSpace(const char * input, char * inputCopy)
{
    for (int i = 0; input[i]; i++)
    {
        for (int j = 0; input[j]; j++)
        {
            if(input[i] == ' ')
            {
                i++;
            }
            inputCopy[j] = input[i];
        }
        std::cout << inputCopy[i];
    }
    return inputCopy;
}



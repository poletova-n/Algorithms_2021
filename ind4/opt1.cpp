#include <iostream>
#include <fstream>
#include <string>


const char* ERROR_FILE_NOT_OPENED = "File didn't open!";

std::string removeSpace(std::string input);

int main()
{
    try {
        std::string input;
        int position = 0;
        std::ifstream fin("C:\\Users\\anush\\Algorithms_2021\\ind4\\myText.txt");
        if (!fin.is_open())
        {
            throw ERROR_FILE_NOT_OPENED;
        }
        else
        {
            while(true)
            {
                fin.seekg(position);
                if(getline(fin, input))
                {
                    fin.clear();
                    fin.seekg(position);

                    std::cout << std::endl;

                    position += input.length()+2;

                    std::cout << removeSpace(input);
                }
                else
                {
                    break;
                }

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


std::string removeSpace(std::string input)
{
    int length = input.length();
    for(int i = length-1; i >= 0; --i)
    {
        if(input[i] == ' ')
        {
            input.erase(i,1);
        }
    }
    return input;
}


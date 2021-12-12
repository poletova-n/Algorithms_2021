#include <iostream>
#include <fstream>

const char* ERROR_FILE_NOT_OPENED = "File didn't open!";

const int size1 = 5;
const int size2 = 4;

void readFile(int (&input)[size1][size2], std::ifstream &fin, std::ofstream &fout);

int main()
{
    try
    {
        int arr[size1][size2];

        std::ifstream fin("C:\\Users\\anush\\Algorithms_2021\\ind5\\inputFile1.1.txt");
        std::ofstream fout("C:\\Users\\anush\\Algorithms_2021\\ind5\\outputFile1.1.txt");
        if (!fin.is_open() || !fout.is_open())
        {
            throw ERROR_FILE_NOT_OPENED;
        }
        else
        {
            readFile(arr, fin, fout);
            fin.close();
        }
        return 0;
    }
    catch(const char * error)
    {
        std::cerr << std::endl << error << std::endl;
        return -1;
    }
}

void readFile(int (&input)[size1][size2], std::ifstream &fin, std::ofstream &fout)
{
    for(int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++) {
            fin >> input[i][j];
            if(input[i][j] != 0)
            {
                fout << input[i][j] << " ";
            }
        }
        fout << std::endl;
    }
}
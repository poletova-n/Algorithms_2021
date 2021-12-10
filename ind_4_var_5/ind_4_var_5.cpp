#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

const char* ERROR_FILE_IS_NOT_OPENED = "file is not opened!";

char* findsym(const char* arr1, int size1, const char* arr2, int size2);

int main() 
{

    try 
    {
        bool flag = false;
        int position(0), size(0), size1(0), size2(0);
        char* arr1 = new char[size];
        char* arr2 = new char[size];
        ifstream fin("C:\\Users\\Ольга\\Documents\\учеба\\поликек\\c++\\Algorithms_2021\\ind_4_var_5\\input.txt");
        ofstream fout("C:\\Users\\Ольга\\Documents\\учеба\\поликек\\c++\\Algorithms_2021\\ind_4_var_5\\output.txt");
        if (!fin.is_open()) 
        
        {
            throw ERROR_FILE_IS_NOT_OPENED;
        }
        else 
        {
            while (!fin.eof()) 
            {
                fin.seekg(position);
                fin >> size;

                char* arr = new char[size];

                fin.seekg(position + 3);
                char cursym;
                int i(0);

                while (fin.get(cursym) && i < size) 
                {
                    arr[i] = cursym;
                    i++;
                }

                arr[size] = '\0';

                position += size + 5;
                if (flag == false) 
                {
                    arr1 = arr;
                    size1 = size;
                }
                else 
                {
                    arr2 = arr;
                    size2 = size;
                }
                flag = true;
            }
            findsym(arr1, size1, arr2, size2);
        }
        fin.close();
        fout.close();
        return 0;
    }
    catch (const char* error)
    {
        cerr << endl << error << endl;
        return -1;
    }
}

char* findsym(const char* arr1, int size1, const char* arr2, int size2)
{
    for (int i = 0; i < size1; ++i) 
    {
        for (int j = 0; j < size2; ++j) 
        {
            if (arr1[i] != arr2[j]) 
            {
                сout << arr2[j];
            }
        }
    }
}
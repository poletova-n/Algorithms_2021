#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

const char* ERROR_FILE_NOT_OPENED = "Файл не открывается!";

char * findSym(const char * arr1, int size1, const char * arr2, int size2);

int main() {
    SetConsoleOutputCP(CP_UTF8);
    try {
        bool flag = false;
        int position(0);
        int size(0);
        char * arr1 = new char[size];
        char * arr2 = new char[size];
        int size1(0);
        int size2(0);
        ifstream fin("C:\\Users\\miha1\\CLionProjects\\Algorithms_2021\\ind4\\input");
        if (!fin.is_open()) {
            throw ERROR_FILE_NOT_OPENED;
        }
        else {
            while (!fin.eof()) {
                fin.seekg(position);
                fin >> size;

                char * arr = new char[size];

                fin.seekg(position + 3);
                char currentSymbol;
                int i(0);

                while(fin.get(currentSymbol) && i < size) {
                    arr[i] = currentSymbol;
                    i++;
                }

                arr[size] = '\0';

                position += size + 5;
                if (flag == false) {
                    arr1 = arr;
                    size1 = size;
                }
                else {
                    arr2 = arr;
                    size2 = size;
                }
                flag = true;
            }
            findSym(arr1, size1, arr2, size2);
        }
        fin.close();
        return 0;
    }
    catch(const char * error)
    {
        cerr << endl << error << endl;
        return -1;
    }
}

char * findSym(const char * arr1, int size1, const char * arr2, int size2) {
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            if (arr1[i] == arr2[j]) {
                cout << arr2[j];
            }
        }
    }
}

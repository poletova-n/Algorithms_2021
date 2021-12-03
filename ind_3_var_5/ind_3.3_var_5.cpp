#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    cout << "raw array: " << endl;
    int n;
    string line;
    ifstream file("C:\\Users\\Ольга\\Documents\\учеба\\поликек\\c++\\Algorithms_2021\\ind_3_var_5\\array.txt");
    {
        file >> n;
    }
    int* array = new int[n];
    if (file.is_open())
    {
        for (int i = 0; i < n; i++)
        {
            file >> array[i];
            cout << array[i] << endl;
        }
        cout << "ready array: " << endl;
        for (int i = 0; i < n; i++)
        {
                    if (array[i] % 2 == 0)
            {
                cout << array[i] << endl;
            }

        }
        for (int j = 0; j < n; j++)
        {

            if (array[j] % 2 == 1)
            {
                cout << array[j] << endl;
            }

        }
    }
   
    file.close();
    delete[] array;
}



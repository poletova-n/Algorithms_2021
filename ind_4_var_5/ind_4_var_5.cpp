#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char string1[] = { "12345" };
    char string2[] = { "92348" };
    char string3[20] = {};
    char string4[20] = {};
    for (int z = 0; z < 20; z++)
    {
        for (int j = 0; j < 20; j++)
        {
            char temp, temp2;
            for (int i = 0; i < sizeof(string1); i++)
            {

                for (int k = 0; k < sizeof(string2); k++)
                {
                    if (string1[i] != string2[k])
                    {
                        temp2 = string2[k];
                        temp = string1[i];
                    }
                    else
                    {
                        temp = NULL; temp2 = NULL;
                        break;
                    }
                }

                string3[j] = temp;
                string4[z] = temp2;
                if (string3[j] != NULL)
                {
                    j++;
                }
                if (string4[z] != NULL)
                {
                    z++;
                }
            }
        }

    }
    for (int a = 0; a < 20; a++)
    {
        for (int b = 0; b < 20; b++)
        {
            char temp, temp2;
            for (int k = 0; k < sizeof(string2); k++)
            {

                for (int i = 0; i < sizeof(string1); i++)
                {
                    if (string2[k] != string1[i])
                    {
                        temp2 = string2[k];
                        temp = string1[i];
                    }
                    else
                    {
                        temp = NULL; temp2 = NULL;
                        break;
                    }
                }


                string4[b] = temp2;

                if (string4[b] != NULL)
                {
                    b++;
                }
            }
        }

    }
    cout << string3;
    cout << string4;

    cout << endl;
    _getch();
    return 0;
}

#include <iostream>

int main()
{
    char* p = "аоа";
    int pos = 0;
    for(int i = 0; i < size; i++)
    {
        if(i < sizeof(p))
        {
            res[pos] = p[i];
            pos++;
        }
        if(i < sizeof(q))
        {
            res[pos] = p[i];
            pos++;
        }
    }
}

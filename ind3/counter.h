#ifndef MAIN_CPP_COUNTER_H
#define MAIN_CPP_COUNTER_H
#pragma once

int counter(int size, int* x)
{
    int count = 0;
    int min = INT_MAX;
    int* array = new int[size];
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if(x[i] < min)
        {
            min = x[i];
            index = i;
        }
    }
    for (int j = 0; j < index; j++)
    {
        if (x[j] > 0)
        {
            count++;
        }
    }
    delete [] array;
    return count;
}
#endif

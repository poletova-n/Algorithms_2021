#ifndef ALGORITHMS_2021_COUNTER_H
#define ALGORITHMS_2021_COUNTER_H

using namespace std;

int counter(int size, int* array) {
    int count(1);
    int myMax = INT_MIN;
    for (int i = 0; i < size; ++i) {
        if (myMax == array[i]) {
            count += 1;
        }
        if (myMax < array[i]) {
            count = 1;
        }
        myMax = max(array[i], myMax);
    }
    return count;
}
#endif //ALGORITHMS_2021_COUNTER_H

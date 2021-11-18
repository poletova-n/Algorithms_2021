#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    const int size(5);
    int array[size] = {1, 2, 3, 2, 3};
    int myMax = INT_MIN;
    int count(0);
    for (int i = 0; i < size; ++i) {
        if (myMax == array[i]) {
            count += 1;
        }
        myMax = max(array[i], myMax);
    }
    cout << "Ответ: " << count;
}

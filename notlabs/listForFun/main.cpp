#include "List.h"

#include <iostream>

int main()
{
    List<int> list;
    List<int> list1;
    for (int i = 0; i < 5; ++i) {
        list.add(i);
    }
    list.print();
    if(list != list1)
    std::cout << list.size();
    return 0;
}

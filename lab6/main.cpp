#pragma ide diagnostic ignored "hicpp-exception-baseclass"
#include <iostream>
#include "DoubleLinkedList.h"

int main () {
    DoubleLinkedList list;
    for (int i = 0; i < 10; i++) {
        list.insertTail(i);
    }


    list.deleteHead();

    list.deleteTail();

    list.deleteItem(5);

    list.headItem() = 10;

    list.replaceItem(3, 15);

    list.insertHead(91);

    list.tailItem() = 87;

    std::cout << list << "\n";

    std::cout << list.headItem() << (list.searchItem(list.headItem()) ? "1" : "0")
              << list.tailItem() << (list.searchItem(list.tailItem()) ? "1" : "0") << "\n";

    DoubleLinkedList another_list;
    for (int i = 0; i < 10; i++) {
        another_list.insertTail(10 - i);
    }
    std::cout << another_list << "\n";

    std::cout << (list == another_list ? "1" : "0") << "\n";

    list.add(another_list);

    std::cout << list.deleteItem(4345, true) << "\n";
    std::cout << list.deleteItem(6, true) << "\n";

    std::cout << list.replaceItem(478389, 1001, true) << "\n";

    std::cout << list << "\n";

    std::cout  << (list == another_list ? "1" : "0") << "\n";

    return 0;
}
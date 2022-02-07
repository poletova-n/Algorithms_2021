//
// Примеры использования класса DoubleLinkedList
//
#include "DoubleLinkedList.h"
#include <iostream>

int main() {

	DoubleLinkedList list;

	std::cout << ((list.searchItem(1)) ? "1 find" : "1 not find") << std::endl;
	std::cout << ((list.searchItem(8)) ? "8 find" : "8 not find") << std::endl;

	DoubleLinkedList list1(list);

    std::cout << (list == list1 ? "Yes" : "No") << std::endl;

    std::cout << list1;

    list1.deleteHead();
    list1.insertTail(5);

    std::cout << list1;

    list1.deleteTail();
    list1.deleteTail();

    std::cout << list1;

    std::cout << list;
    list1.add(list);

    std::cout << list1;

    list1.insertHead(1);
    list1.insertHead(7);

    std::cout << list1;

    std::cout << (list1.deleteItem(3) ? "Deleted" : "Not found") << std::endl;
    std::cout << (list1.deleteItem(2, true) ? "Deleted" : "Not found") << std::endl;

    std::cout << list1;

    std::cout << (list1.replaceItem(7, 5) ? "Replaced" : "Not found") << std::endl;
    std::cout << (list1.replaceItem(1, 5, true) ? "Replaced" : "Not found") << std::endl;

    std::cout << list1;

    std::cout << (list1.deleteItem(2) ? "Deleted" : "Not found" ) << std::endl;

    std::cout << list1;

    return 0;
}
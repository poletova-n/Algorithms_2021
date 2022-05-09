
#include "DoubleLinkedList.h"
#include <iostream>

int main() {
	DoubleLinkedList list;   // Создание пустого списка
	//std::cout << list.deleteTail() << "\n";
	list.insertHead(2);  // Добавление элементов
	list.insertHead(3);
	list.insertHead(1);
	std::cout << "list: ";
	list.outAll();           // Печать элементов

	std::cout << ((list.searchItem(1)) ? "1 find" : "1 not find") << std::endl;
	std::cout << ((list.searchItem(8)) ? "8 find" : "8 not find") << std::endl;

	DoubleLinkedList  list1(list); 	// Копирование списка
	if (list1 == list)
		std::cout << "true\n";
	else std::cout << "false\n";
	list1.insertHead(4);         // Добавление элемента
	list1.insertHead(5);         // Добавление элемента
	list1.deleteHead();          // Удаление головного
	std::cout << "list1: ";
	list1.outAll();
	list1.insertHead(6);
	list1.deleteTail();
	std::cout << "list1: ";
	list1.outAll();
	list1.add(list);
	list1.replaceItem(1, 9);
	std::cout << "list1: ";
	list1.outAll();
	list1.deleteHead();
	list1.outAll();        // Печать результата

	return 0;
}
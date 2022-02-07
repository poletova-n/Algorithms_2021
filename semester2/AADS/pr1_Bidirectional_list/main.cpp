//
// ������� ������������� ������ DoubleLinkedList
//
#include "DoubleLinkedList.h"
#include <iostream>

int main() {
	DoubleLinkedList list;   // �������� ������� ������
	list.insertHead(2);      // ���������� ���������
	list.insertHead(3);
	list.insertHead(1);
	list.outAll();           // ������ ���������

	std::cout << ((list.searchItem(1)) ? "1 find" : "1 not find") << std::endl;
	std::cout << ((list.searchItem(8)) ? "8 find" : "8 not find") << std::endl;

	DoubleLinkedList  list1; // (list);  // ����������� ������
	list1.insertHead(4);         // ���������� ��������
	list1.insertHead(5);         // ���������� ��������
	list1.deleteHead();          // �������� ���������
	list1.outAll();
	list1.insertHead(6);
	list1.deleteHead();
	list1.outAll();        // ������ ����������

	return 0;
}
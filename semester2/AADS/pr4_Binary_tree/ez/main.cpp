// 
//   ������������ ������� ������: �������� ������ ������  

#include "BinarySearchTree.h"

#include <iostream>
using std::cout;
using std::endl;

template <class T>

void testConstr(BinarySearchTree <T> x)
{
	std::cout << " testConstr constructor &&" << std::endl;
}

int main()
{
	//�������� ������� ������
	BinarySearchTree <int> intTree;
	//BinarySearchTree <int> intTree1 (intTree);
	
	/*BinarySearchTree <int> intTree2;
	intTree2 = std::move(intTree);
	//testConstr(intTree2);
	BinarySearchTree <int> intTree3;
	intTree3 = std::move (intTree + 1);
    if(intTree == intTree2)*/


	//testConstr(intTree + 1);
	// testConstr(std::move (intTree + 1)); // ok: void testConstr(BinarySearchTree <T>  x)
    // ���������� �����
	intTree.insert(10);
	intTree.insert(3);
	intTree.insert(20);
	intTree.insert(15);
	intTree.insert(30);
	intTree.insert(2);
	intTree.insert(5);
    intTree.insert(32);
	intTree.insert(22);

	// ����� ����� ������ � �������� ����� 
	intTree.print(cout);

	// ����� � ������ �� �����

	int  keyFound = intTree.iterativeSearch(15); // ����� ������ ���� ��������
	cout << "Key " << 15 <<
		(keyFound ? " found successfully" : " not found") <<
		" in the tree" << endl;

	keyFound = intTree.iterativeSearch(23);      // ����� ������ ���� ���������
	cout << "Key " << 23 <<
		(keyFound ? " found successfully" : " not found") <<
		" in the tree" << endl;

	// ����������� ������ � ���������� ����� ������
	cout << "height = " << intTree.getHeight() << endl;
	cout << "count =  " << intTree.getCount() << endl;

	// . . .
	return 0;
}

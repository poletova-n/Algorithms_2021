#include "DoubleList.h"



int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	//  1 �����
	// 
	// 1 �������
	DoubleList<int> list;
	list.push_back(1);
	list.push_back(1);
	list.push_back(2);
	list.insertTail(new Node<int>(3));

	// 2 �������
	list.deleteTail();

	// 3 ������� 
	list.deleteItem(1);

	// 4 ������� 
	DoubleList<int> replaceList;
	/*replaceList.push_back(1);*/
	/*replaceList.push_back(1);
	replaceList.push_back(1);
	if (replaceList.replaceItem(1, 2)) {
		std::cout << "����� ������� c REPLACE: " << replaceList;
	}   else std::cout << "���� ������!" << std::endl;*/

	replaceList.replaceNode(replaceList.getHead(), 99);
	std::cout << "����� ������� c REPLACE_NODE: " << replaceList;



	// 5 ������� 
	DoubleList<int> listBeginn;
	/*listBeginn.push_back(1);*/
	listBeginn.push_back(2);
	DoubleList<int> listEnd;
	listEnd.push_back(3);
	//listEnd.push_back(4);
	listBeginn.add(listEnd); // �������� � ��������
	std::cout << "����� ������������ �������: " << listBeginn;

	// 6 ������� 
	DoubleList<int> listOne;
	listOne.push_back(1);
	listOne.push_back(1);
	listOne.push_back(1);

	DoubleList<int> listTwo;
	listTwo.push_back(1);
	listTwo.push_back(1);
	listTwo.push_back(2);

	if (listOne == listTwo) {
		std::cout << "������ �����!" << std::endl;
	}
	else std::cout << "������ �� �����!" << std::endl;

	// 2 �����
	std::cout << "����� �������: " << list;


	// 3 �����

	return 0;

}


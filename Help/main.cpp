#include "DoubleList.h"



int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	//  1 часть
	// 
	// 1 задание
	DoubleList<int> list;
	list.push_back(1);
	list.push_back(1);
	list.push_back(2);
	list.insertTail(new Node<int>(3));

	// 2 задание
	list.deleteTail();

	// 3 задание 
	list.deleteItem(1);

	// 4 задание 
	DoubleList<int> replaceList;
	/*replaceList.push_back(1);*/
	/*replaceList.push_back(1);
	replaceList.push_back(1);
	if (replaceList.replaceItem(1, 2)) {
		std::cout << "Вывод массива c REPLACE: " << replaceList;
	}   else std::cout << "Лист пустой!" << std::endl;*/

	replaceList.replaceNode(replaceList.getHead(), 99);
	std::cout << "Вывод массива c REPLACE_NODE: " << replaceList;



	// 5 задание 
	DoubleList<int> listBeginn;
	/*listBeginn.push_back(1);*/
	listBeginn.push_back(2);
	DoubleList<int> listEnd;
	listEnd.push_back(3);
	//listEnd.push_back(4);
	listBeginn.add(listEnd); // проблемы с размером
	std::cout << "Вывод соединенного массива: " << listBeginn;

	// 6 задание 
	DoubleList<int> listOne;
	listOne.push_back(1);
	listOne.push_back(1);
	listOne.push_back(1);

	DoubleList<int> listTwo;
	listTwo.push_back(1);
	listTwo.push_back(1);
	listTwo.push_back(2);

	if (listOne == listTwo) {
		std::cout << "Списки равны!" << std::endl;
	}
	else std::cout << "Списки не равны!" << std::endl;

	// 2 часть
	std::cout << "Вывод массива: " << list;


	// 3 часть

	return 0;

}


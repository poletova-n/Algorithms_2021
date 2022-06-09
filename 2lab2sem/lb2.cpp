#include "Dictionary.h"
#include <iostream>
#include <string>

int main()
{
	Dictionary list;
	list.insert("999");
	list.insert("1");
	list.insert("2");

	list.outAll();

	std::cout << "Deleting: \n";

	Dictionary list1(list);
	list1.deleteItem("1");
	list1.outAll();

	std::cout << "Searh: \n";

	if (list1.searchItem("1"))
		std::cout << "found\n";
	else
		std::cout << "not found\n";
	if (list1.searchItem("2"))
		std::cout << "found\n";
	else
		std::cout << "not found\n";

	std::cout << "Adding:\n";

	list.insert("5");
	list.insert("6");
	list.insert("7");

	std::cout << "list \n";
	list.outAll();

	std::cout << "\n";

	list1.insert("9");
	list1.insert("17");
	list1.insert("1");
	list1.insert("3");

	std::cout << "list1 \n";
	list1.outAll();

	std::cout << "Result:\n";
	list1.add(list);
	list1.outAll();

	list.insert("1");
	list.insert("5");
	list.insert("6");
	list.insert("7");

	std::cout << "list \n";
	list.outAll();

	std::cout << "list1 \n";
	list1.outAll();

	std::cout << "Crosssing:\n";
	Dictionary crossed;
	crossed = Crossing(list1, list);
	crossed.outAll();

	std::cout << "Remove:\n";
	list1.remove(list);
	list1.outAll();
}
// 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include"BinarySearchTree.h"
#include <iostream>

int main()
{
	setlocale(0, "");
	BinarySearchTree<int> tree1;
	tree1.insert(30);
	tree1.insert(16);
	tree1.insert(14);
	tree1.insert(19);
	tree1.insert(11);
	tree1.insert(61);
	tree1.insert(41);
	tree1.insert(65);
	tree1.insert(67);

	BinarySearchTree<int>tree2;

	tree2.insert(40);
	tree2.insert(15);
	tree2.insert(11);
	tree2.insert(20);
	tree2.insert(55);
	tree2.insert(54);
	tree2.insert(60);
	tree2.insert(70);
	tree2.insert(80);
	tree1.printTree();
		tree1.widthTraversal();
	std::cout << "\n" << '\n';
	if (tree1.isEqualTrees(tree2)) std::cout << "Да";
	else std::cout << "Нет" << std::endl;
	if (tree1.HaveEqualNodes(tree2)) std::cout << "Да";
	else std::cout << "Нет" << std::endl;

}

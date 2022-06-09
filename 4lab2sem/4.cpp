#include <iostream>
#include "BinarySearchTree.h"

int main()
{
    setlocale(0, "");
    BinarySearchTree<int>tree;
    tree.insert(60);
    tree.insert(20);
    tree.insert(62);
    tree.insert(61);
    tree.insert(65);
    tree.insert(63);
    tree.insert(70);
    tree.insert(79);
    tree.printTree();
    std::cout << "\n элементов дерева:" << tree.getCount() << '\n';
    std::cout << "\n высота дерева:" << tree.getHeight() << '\n';
    std::cout << tree.iterativeSearch(20) << '\n';
    tree.iterativeInorderWalk();
    std::cout << '\n';
    tree.recursiveinorderWalk();
    std::cout << '\n';
    tree.deleteKey(79);
    tree.printTree();
    tree.deleteKey(60);
    tree.printTree();
    return 0;
}
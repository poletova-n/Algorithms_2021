//
// Created by Foko on 28.03.2022.
//
#include <iostream>
#include "BinarySearchTree.h"

int main () {
    BinarySearchTree<int> tree(0);

        tree.insert(-92);
    tree.insert(-32);
    tree.insert(-12);
    tree.insert(36);
    tree.insert(-11);
    tree.insert(42);
    tree.insert(-2);
    tree.insert(10);
    tree.insert(-99);
    tree.insert(99);
    tree.insert(76);
    tree.insert(-43);
    tree.insert(26);
    std::cout << tree.print() << "\n";
    tree.deleteNode(0);
    std::cout << tree.print() << "\n";
    return 0;
}
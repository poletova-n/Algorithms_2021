//
// Created by Foko on 28.03.2022.
//
#include <iostream>
#include "BinarySearchTree.h"

int main () {
    BinarySearchTree<int> tree(0);
    tree.insert(-1);
    tree.insert(45);
    tree.insert(23);
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
    int i = tree.search(10);
    int j = tree.deleteNode(10);
    int k = tree.search(10);
    return 0;
}
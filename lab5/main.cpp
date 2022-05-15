//
// Created by Foko on 03.05.2022.
//
#include <iostream>
#include "CircleQueue.h"
#include "BinarySearchTree.h"




int main () {
    BinarySearchTree<int> tree(0);
    BinarySearchTree<int> tree1(0);

    tree.insert(4);
    tree.insert(6);
    tree.insert(7);
    tree.insert(-3);
    tree.insert(1);


    tree.insert(-8);
    tree1.insert(4);
    tree1.insert(-3);

    tree1.insert(5);
    tree1.insert(7);
    tree1.insert(1);
    tree1.insert(-8);

    try {
        CircleQueue<int> queue(4);
        //tree.levelOrder();
        tree.intersection(tree1);
    } catch (const std::exception& error) {
        std::cout << error.what() << '\n';
    }



    return 0;
}
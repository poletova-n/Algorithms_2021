#include "BinarySearchTree.h"
#include <iostream>

int main()
{
    auto intTree = new BinarySearchTree<int>;

    intTree->insert(3);
    intTree->insert(11);

    BinarySearchTree<int>* intTreeCopy(intTree);

    intTree = intTreeCopy;

    intTree->insert(1);
    intTree->insert(9);
    intTree->insert(7);
    intTree->insert(8);
    intTree->insert(6);
    intTree->insert(10);
    intTree->insert(12);

    intTree->print(std::cout);

    intTree->deleteKey(3);

    intTree->print(std::cout);

    intTree->deleteKey(11);

    //intTree->deleteKey(7);

    intTree->print(std::cout);

    intTree->iterativeInorderWalk();

    intTree->inorderWalk();

    int  keyFound = intTree->iterativeSearch(10); // поиск должен быть успешным
    std::cout << "Key " << 10 <<
         (keyFound ? " found successfully" : " not found") <<
         " in the tree" << std::endl;

    keyFound = intTree->iterativeSearch(23);      // поиск должен быть неудачным
    std::cout << "Key " << 23 <<
         (keyFound ? " found successfully" : " not found") <<
         " in the tree" << std::endl;

    // определение высоты и количества узлов дерева*/
    std::cout << "height = " << intTree->getHeight() << std::endl;
    std::cout << "count =  " << intTree->getCount() << std::endl;

    return 0;
}
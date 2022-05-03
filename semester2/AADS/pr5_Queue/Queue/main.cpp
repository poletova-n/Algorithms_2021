#include <iostream>
#include "CircleQueue.h"
#include "BinarySearchTree.h"

void havingFunWithTrees();

void wrongSize();

void queueOverflow();

void queueUnderflow();

int main()
{
    havingFunWithTrees();
    return 0;
}

void havingFunWithTrees(){
    auto * intTree = new BinarySearchTree<int>;

    auto * intTree1 = new BinarySearchTree<int>;

    intTree1->insert(3);
    intTree1->insert(4);
    intTree1->insert(2);

    intTree->insert(4);
    intTree->insert(3);
    intTree->insert(2);


    intTree1->intersection(intTree);

    std::cout << intTree1->compare(intTree) << std::endl;

    intTree->iterativeWideWalk();

    intTree1->iterativeWideWalk();
}

void wrongSize(){
    CircleQueue<int> circleQueue(245325523525323553);
}

void queueOverflow(){
    CircleQueue<int> circleQueue(2);
    circleQueue.enQueue(1);
    circleQueue.enQueue(2);
    circleQueue.enQueue(3);
}

void queueUnderflow(){
    CircleQueue<int> circleQueue(3);
    circleQueue.enQueue(1);
    circleQueue.deQueue();
    circleQueue.deQueue();
}

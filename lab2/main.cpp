#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-auto"
//
// Created by Foko on 25.02.2022.
//
#include "SinglyOrderedList.h"

int main () {
    SinglyOrderedList list1;
    list1.insert(0);
    list1.insert(1);
    list1.insert(2);
    list1.insert(4);
    list1.insert(5);
    list1.insert(6);

    std::cout << list1;

    SinglyOrderedList list2;
    list2.insert(3);
    list2.insert(4);
    list2.insert(5);
    list2.insert(6);
    list2.insert(7);
    list2.insert(8);

    std::cout << list2;

    SinglyOrderedList list3 = list1;
    SinglyOrderedList list4 = list1;

    SinglyOrderedList list2_copy(list2);

    list3.addition(list2_copy);
    list4.subtraction(list2);
    SinglyOrderedList list5 = intersection(list1, list2);


    std::cout << "\n" << list1 << list2 << list3 << list4 << list5;

    std::cout << "\n";
}
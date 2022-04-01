//
// Created by Foko on 02.04.2022.
//

#ifndef ONE_WAY_LIST_SINGLYORDEREDLIST_H
#define ONE_WAY_LIST_SINGLYORDEREDLIST_H

#include <iostream>

class SinglyOrderedList {
private:
    struct Node {
        Node* next;
        int key;

        explicit Node (int key, Node* next = nullptr);
    };
private:
    Node* head{};
    size_t length;
private:
    Node* search (const int* key) const;
public:
    SinglyOrderedList ();

    SinglyOrderedList (const SinglyOrderedList& list);

    SinglyOrderedList (SinglyOrderedList&& list) noexcept;

    ~SinglyOrderedList ();

    SinglyOrderedList& operator=(const SinglyOrderedList& list);

    SinglyOrderedList& operator=(SinglyOrderedList&& list) noexcept;

    Node* insert (Node* insert_node);

    bool insert (int key);

    bool search (int key) const;

    bool remove (int key);

    void addition (SinglyOrderedList& list);;

    void subtraction (const SinglyOrderedList& list);


    friend SinglyOrderedList& intersection (const SinglyOrderedList& first, const SinglyOrderedList& second);
    friend std::ostream& operator<<(std::ostream& out, const SinglyOrderedList& list);
};

#endif //ONE_WAY_LIST_SINGLYORDEREDLIST_H

//#include "SinglyOrderedList.cpp"
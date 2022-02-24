//
// Created by Foko on 23.02.2022.
//

#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <iostream>

class DoubleLinkedList {
private:
    struct Node { //  приватная структура ноды
        Node *_prev;
        Node *_next;
        int _key;

        explicit Node(int key, Node *prev = nullptr, Node *next = nullptr);
    };
private:
    int length;
    Node* _head;
    Node* _tail;
private:
    void insertHead(Node *item);

    void insertTail(Node *item);

    bool deleteNode(Node *item);

    Node *searchNode(int key);

    static Node *replaceNode(Node *item, int key);

public:
    explicit DoubleLinkedList();

    DoubleLinkedList(const DoubleLinkedList &list);

    DoubleLinkedList(DoubleLinkedList && list) noexcept;

    DoubleLinkedList &operator=(const DoubleLinkedList &list);

    DoubleLinkedList &operator=(DoubleLinkedList &&list) noexcept;

    ~DoubleLinkedList();

    int headItem() const;

    int &headItem();

    int tailItem() const;

    int &tailItem();

    void insertHead(int key);

    void insertTail(int key);

    bool searchItem(int key);

    bool replaceItem(int old_key, int new_key, bool all = false);

    bool deleteItem(int key, bool all = false);

    bool deleteHead();

    bool deleteTail();

    void add(DoubleLinkedList &list);

    bool operator==(DoubleLinkedList &list);

    inline bool operator!=(DoubleLinkedList &list);

    friend std::ostream &operator<<(std::ostream &out, const DoubleLinkedList &list);
};



std::ostream& operator<<(std::ostream& out, const DoubleLinkedList& list);
#endif //DOUBLE_LINKED_LIST_H

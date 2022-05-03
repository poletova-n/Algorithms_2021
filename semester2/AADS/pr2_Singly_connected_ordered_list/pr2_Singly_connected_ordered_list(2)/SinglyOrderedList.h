//
// Created by Администратор on 17.02.2022.
//

#ifndef ALGORITHMS_2021_SINGLYORDEREDLIST_H
#define ALGORITHMS_2021_SINGLYORDEREDLIST_H


#include <xstring>
#include <functional>
#include <algorithm>
#include "SinglyOrderedList.h"


class SinglyOrderedList {

protected:
    struct Node
    {

        std::string item_;
        Node* next_;

        Node(std::string item, Node *next);

        bool hasNext() const;
    };

    int size_;
    Node* head_;

    bool add(Node* node);

    bool insertNode(Node* node, bool isHead = false, Node* previous = nullptr);

    bool deleteNode(Node* node, bool isHead = false, Node* previous = nullptr);

    std::string elementAt(int index);

public:

    bool forEach(const std::function<bool(Node*,bool,Node*)>& function);

    SinglyOrderedList();

    SinglyOrderedList(SinglyOrderedList&& other) noexcept ;

    SinglyOrderedList(SinglyOrderedList* other) noexcept;

    void swap(SinglyOrderedList& other);

    SinglyOrderedList& operator=(SinglyOrderedList& right);

    //SinglyOrderedList* operator=(SinglyOrderedList* right);

    [[maybe_unused]] bool isEmpty();

    [[nodiscard]] int getSize() const;

    virtual bool add(const std::string& key);

    bool add(SinglyOrderedList& list);

    virtual int find(const std::string& key);

    virtual bool deleteWord(const std::string& key);

    virtual bool deleteWord(SinglyOrderedList& list);

    virtual void print();

    void swap(SinglyOrderedList *other);
};



#endif //ALGORITHMS_2021_SINGLYORDEREDLIST_H

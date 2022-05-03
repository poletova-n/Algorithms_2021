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

    SinglyOrderedList();

    bool forEach(const std::function<bool(Node*,bool,Node*)>& function);

    SinglyOrderedList(SinglyOrderedList&& other) noexcept ;

    SinglyOrderedList(SinglyOrderedList* other) noexcept;

    void swap(SinglyOrderedList& other);

    SinglyOrderedList& operator=(SinglyOrderedList& right);

    //SinglyOrderedList* operator=(SinglyOrderedList* right);

    [[maybe_unused]] bool isEmpty();

    [[nodiscard]] int getSize() const;

    bool add(SinglyOrderedList& list);

    virtual bool add(const std::string& key);

    virtual int find(const std::string& key);

    virtual bool deleteWord(const std::string& key);

    virtual bool deleteWord(SinglyOrderedList& list);

    virtual void print();

    ~SinglyOrderedList();

    virtual void clear();
};



#endif //ALGORITHMS_2021_SINGLYORDEREDLIST_H

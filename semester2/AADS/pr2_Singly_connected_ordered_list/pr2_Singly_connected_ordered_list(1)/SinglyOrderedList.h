//
// Created by Администратор on 17.02.2022.
//

#ifndef ALGORITHMS_2021_SINGLYORDEREDLIST_H
#define ALGORITHMS_2021_SINGLYORDEREDLIST_H


#include <xstring>
#include <functional>
#include <algorithm>

struct Node
{
    std::string item_;
    Node* next_;

    Node(const std::string &item, Node *next);

    bool hasNext();
};

class SinglyOrderedList {

private:


    int size_;
    Node* head_;

    bool add(Node* node);

    bool forEach(const std::function<bool(Node*,bool,Node*)>& function);

    bool insertNode(Node* node, bool isHead = false, Node* previous = nullptr);

    bool deleteNode(Node* node, bool isHead = false, Node* previous = nullptr);

    std::string elementAt(int index);

public:

    SinglyOrderedList();

    SinglyOrderedList(SinglyOrderedList&& other) noexcept ;

    void swap(SinglyOrderedList& other);

    SinglyOrderedList& operator=(SinglyOrderedList right);


    [[maybe_unused]] bool isEmpty();

    [[nodiscard]] int getSize() const;

    bool add(const std::string& key);

    bool add(SinglyOrderedList& list);

    int find(const std::string& key);

    bool deleteWord(const std::string& key);

    bool deleteWord(SinglyOrderedList& list);

    void print();

    friend void set_intersection(SinglyOrderedList& l, SinglyOrderedList& l2, SinglyOrderedList& res );
};


#endif //ALGORITHMS_2021_SINGLYORDEREDLIST_H

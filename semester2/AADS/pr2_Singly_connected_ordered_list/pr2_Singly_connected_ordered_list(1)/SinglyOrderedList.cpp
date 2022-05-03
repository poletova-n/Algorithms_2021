#include "SinglyOrderedList.h"

#include <iostream>

SinglyOrderedList::Node::Node(const std::string &item, SinglyOrderedList::Node *next = nullptr) : item_(item), next_(next) {}

bool SinglyOrderedList::Node::hasNext() {
    return this->next_ != nullptr;
}


SinglyOrderedList::SinglyOrderedList() : size_(0), head_(nullptr) {}

SinglyOrderedList::SinglyOrderedList(SinglyOrderedList &&other) noexcept : head_(other.head_), size_(other.size_)
{
    other.head_ = nullptr;
    other.size_ = 0;
}

void SinglyOrderedList::swap(SinglyOrderedList &other) {
    std::swap(head_, other.head_);
    std::swap(size_, other.size_);
}

SinglyOrderedList &SinglyOrderedList::operator=(SinglyOrderedList right) {
    if(this != &right){
        swap(right);
    }
    return *this;
}


int SinglyOrderedList::getSize() const {
    return size_;
}


bool SinglyOrderedList::add(const std::string& key) {
    return add(new Node(key));
}

bool SinglyOrderedList::add(SinglyOrderedList::Node *node) {

    if(head_ == nullptr) return insertNode(node, true);

    if(find(node->item_) != -1){
        delete node;
        return false;
    }

    Node* temp = head_;
    if(head_->item_ > node->item_) return insertNode(node, true, head_);

    while(temp->hasNext()){
        if(temp->next_->item_ > node->item_) break;
        temp = temp->next_;
        if(temp == nullptr) break;
    }

    return insertNode(node, false ,temp);
}

bool SinglyOrderedList::insertNode(SinglyOrderedList::Node *node, bool isHead, SinglyOrderedList::Node *previous) {
    if(isHead){
        head_ = node;
        node->next_ = previous;
    }else{
        node->next_ = previous->next_;
        previous->next_ = node;
    }
    size_++;
    return true;
}

bool SinglyOrderedList::deleteNode(SinglyOrderedList::Node *node, bool isHead, SinglyOrderedList::Node *previous) {
    if(isHead) {
        head_ = node->next_;
    }else{
        previous->next_ = node->next_;
    }
    size_--;
    delete node;
    return true;
}

bool SinglyOrderedList::deleteWord(SinglyOrderedList &list) {

    Node* tempDelete = list.head_;
    if(list.size_ == 0) return true;
    Node* temp = head_;

    for (int i = 0; i < list.size_; ++i) {
        forEach([&tempDelete, this](Node* node, bool isHead, Node* previous){
                    if(node->item_ == tempDelete->item_){
                        return deleteNode(node, isHead, previous);
                    }
                    return false;
                });
        tempDelete = tempDelete->next_;
    }

    return true;
}

bool SinglyOrderedList::deleteWord(const std::string& key) {

    if(this->size_ == 0) return false;

    Node* temp = head_;

    forEach([&key, this](Node* node, bool isHead, Node* previous){
        //if(node == nullptr)return false;
        if(node->item_ == key){
            return deleteNode(node, isHead, previous);
        }
        return false;
    });

    return false;
}

bool SinglyOrderedList::forEach(const std::function<bool(Node*,bool,Node*)>& function) {

    Node* temp = head_;

    function(temp, true, nullptr);

    if(size_ < 2) return true;

    temp = head_;
    for (int i = 1; i < size_-1; ++i) {
        function(temp->next_, false, temp);
        temp = temp->next_;
    }

    function(temp->next_, false, temp);

    return true;
}

int SinglyOrderedList::find(const std::string& key) {

    int index = 0;

    if(head_ == nullptr) return -1;

    Node* temp = head_;

    for (int i = 0; i < size_; ++i) {
        if(temp->item_ == key) return index;
        index++;
        temp = temp->next_;
    }

    return -1;
}


void SinglyOrderedList::print() {

    if(this->isEmpty()) { std::cout << "List is empty" << std::endl; return; }

    forEach([](Node* node, bool isHead, Node* current){
        std::cout << node->item_ << " ";
        return true;
    });

    std::cout << std::endl;
}

[[maybe_unused]] bool SinglyOrderedList::isEmpty() {
    return head_ == nullptr;
}

bool SinglyOrderedList::add(SinglyOrderedList& list) {

    if(list.isEmpty()) return false;

    Node* temp;

    for (int i = 0; i < list.size_; ++i) {
        temp = list.head_;
        for (int j = 1; j < list.size_ - i; ++j) {
            temp = temp->next_;
        }
        add(temp);
    }

    list.head_ = nullptr;
    list.size_ = 0;

    return true;
}

void set_intersection(SinglyOrderedList& l, SinglyOrderedList &l2, SinglyOrderedList &res) {

    for (int i = 0; i < l.size_; ++i) {
        if(l2.find(l.elementAt(i)) != -1){
            res.add(l.elementAt(i));
        }
    }
}

std::string SinglyOrderedList::elementAt(int index) {
    Node* temp = head_;
    for (int i = 1; i < index; ++i) {
        temp = temp->next_;
    }
    return temp->item_;
}
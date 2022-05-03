#include <iostream>
#include "Glossary.h"
#include "SinglyOrderedList.h"

Glossary::GlossaryNode::GlossaryNode(const std::string &item, SinglyOrderedList::Node *next = nullptr) : Node(item, next), wordList_(new SinglyOrderedList) {}

Glossary::GlossaryNode::~GlossaryNode() {
    delete wordList_;
}

bool Glossary::add(const std::string &key) {

    std::string firstLetter;

    firstLetter += key[0];

    if(SinglyOrderedList::find(firstLetter) == -1){
        Node* temp = new GlossaryNode(firstLetter);
        SinglyOrderedList::add(temp);
    }

    auto* temp = static_cast<GlossaryNode *>(head_);

    if(temp->item_ == firstLetter){
        return temp->wordList_->add(key);
    }

    while(temp->hasNext()){
        temp = static_cast<GlossaryNode *>(temp->next_);
        if(temp->item_ == firstLetter){
            return temp->wordList_->add(key);
        }
    }

    return false;
}

void Glossary::print() {

    if(head_ == nullptr){
        std::cout << "Glossary is empty!";
        return;
    }

    auto* temp = static_cast<GlossaryNode *>(head_);

    //std::cout << size_ << std::endl;

    for (int i = 0; i < size_; ++i) {
        std::cout << temp->item_ << " : ";
        temp->wordList_->print();
        temp = static_cast<GlossaryNode *>(temp->next_);
    }
}

bool Glossary::deleteWord(const std::string &key) {

    bool result = false;
    std::string firstLetter;
    firstLetter += key[0];

    if(SinglyOrderedList::find(firstLetter) == -1) return false;

    //SinglyOrderedList::deleteWord(key);

    auto* temp = static_cast<GlossaryNode *>(head_);

    if(temp->item_ == firstLetter){
        result = temp->wordList_->deleteWord(key);
        if(temp->wordList_->isEmpty()) SinglyOrderedList::deleteWord(static_cast<std::string&>(firstLetter));
        return result;
    }


    while(temp->hasNext()){
        temp = static_cast<GlossaryNode *>(temp->next_);
        if(temp->item_ == firstLetter){
            result = temp->wordList_->deleteWord(key);
            if(temp->wordList_->isEmpty()) SinglyOrderedList::deleteWord(static_cast<std::string&>(firstLetter));
            return result;
        }
    }

    return result;
}

bool Glossary::deleteSection(const std::string& key) {
    return SinglyOrderedList::deleteWord(key);
}

bool Glossary::add(Glossary& list){

    auto* temp = static_cast<GlossaryNode *>(list.head_);

    temp->wordList_->forEach([&temp, this](Node* node, bool isHead, Node* previous){
        add(node->item_);
        return true;
    });

    while(temp->hasNext()){
        temp = static_cast<GlossaryNode *>(temp->next_);
        temp->wordList_->forEach([&temp, this](Node* node, bool isHead, Node* previous){
            add(node->item_);
            return true;
        });
    }

    list.head_ = nullptr;
    list.size_ = 0;

    return false;
}

bool Glossary::deleteWord(Glossary &list) {

    auto* temp = static_cast<GlossaryNode *>(list.head_);

    temp->wordList_->forEach([this](Node* node, bool isHead, Node* previous){
        deleteWord(node->item_);
        return true;
    });

    while(temp->hasNext()){
        temp = static_cast<GlossaryNode *>(temp->next_);
        temp->wordList_->forEach([this](Node* node, bool isHead, Node* previous){
            deleteWord(node->item_);
            return true;
        });
    }
    return false;
}

int Glossary::find(const std::string &key) {

    int pos = 0;
    std::string firstLetter;
    firstLetter += key[0];

    if(SinglyOrderedList::find(firstLetter) == -1) return -1;

    auto* temp = static_cast<GlossaryNode *>(head_);

    for (int i = 0; i < size_; ++i) {
        if(temp->item_ == firstLetter){
            int res = temp->wordList_->SinglyOrderedList::find(key);
            return res == -1 ? -1 : pos + res;
        }
        pos += temp->wordList_->getSize();
        temp = static_cast<GlossaryNode *>(temp->next_);
    }

    return -1;
}

 void Glossary::intersection(Glossary &glossary1, Glossary &glossary2, Glossary &result) {

    auto *temp = static_cast<GlossaryNode *>(glossary1.head_);

    for (int i = 0; i < glossary1.size_; ++i) {
        temp->wordList_->forEach([&glossary2, &result](Glossary::Node *node, bool isHead, Glossary::Node *previous) {
            if (glossary2.find(node->item_) != -1) {
                result.add(node->item_);
            }
            return true;
        });
        temp = static_cast<Glossary::GlossaryNode *>(temp->next_);
    }
}

int Glossary::getFullSize() {

    int size = 0;

    auto *temp = static_cast<GlossaryNode *>(head_);
    for (int i = 0; i < size_; ++i)
    {
        size += temp->wordList_->getSize();
        temp = static_cast<GlossaryNode *>(temp->next_);
    }

    return size;
}

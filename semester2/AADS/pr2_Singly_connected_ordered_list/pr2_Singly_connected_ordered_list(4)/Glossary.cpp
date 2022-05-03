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

    return forEach([&firstLetter, key](GlossaryNode* temp){
        if(temp->item_ == firstLetter) return temp->wordList_->add(key);
        return false;
    });
}

void Glossary::print() {

    if(head_ == nullptr){
        std::cout << "Glossary is empty!" << std::endl;
        return;
    }

    auto* temp = static_cast<GlossaryNode *>(head_);

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

    return forEach([this, &firstLetter, &result, key](GlossaryNode* temp){
        if(temp->item_ == firstLetter){
            result = temp->wordList_->deleteWord(key);
            if(temp->wordList_->isEmpty()) SinglyOrderedList::deleteWord(static_cast<std::string&>(firstLetter));
            return result;
        }
        return result;
    });
}

bool Glossary::deleteSection(const std::string& key) {
    return SinglyOrderedList::deleteWord(key);
}

void Glossary::add(Glossary& list){

     list.forEach([this](GlossaryNode* temp){
        return temp->wordList_->forEach([&temp, this](Node* node, bool isHead, Node* previous){
            add(node->item_);
            return true;
        });
    });

    list.clear();
}

void Glossary::deleteWord(Glossary &list) {

    list.forEach([this](GlossaryNode* temp){
        return temp->wordList_->forEach([this](Node* node, bool isHead, Node* previous){
            deleteWord(node->item_);
            return true;
        });
    });
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

bool Glossary::forEach(const std::function<bool(GlossaryNode*)>& function){
    bool ans = false;

    auto* temp = static_cast<GlossaryNode *>(head_);

    for (int i = 0; i < size_; ++i) {
        function(temp) ? ans = true : ans = false;
        temp = static_cast<GlossaryNode *>(temp->next_);
    }

    return ans;
}

void Glossary::clear(){

    auto* temp = static_cast<GlossaryNode *>(head_);;;

    for (int i = 0; i < size_; ++i) {
        temp = static_cast<GlossaryNode *>(head_);;
        for (int j = 0; j < size_-i-1; ++j) {
            temp = static_cast<GlossaryNode *>(temp->next_);
        }
        temp->wordList_->clear();
        delete temp;
    }

    head_ = nullptr;
    size_ = 0;
}

#include "DoubleLinkedList.h"

DoubleLinkedList::Node::Node(int key, Node* prev, Node* next): _prev(prev), // конструктор
                                                               _next(next),
                                                               _key(key)  {
    ;
}

void DoubleLinkedList::insertHead(Node *item) { // вставка ноды в начало
    if (_head != nullptr) {
        _head->_prev = item;
        item->_next = _head;
        _head = item;
    } else {
        _tail = _head = item;
    }
    length++;
}

void DoubleLinkedList::insertTail(Node *item) { // вставка ноды в конец
    if (_tail != nullptr) {
        _tail->_next = item;
        item->_prev = _tail;
        _tail = item;
    } else {
        _head = _tail = item;
    }
    length++;
}

bool DoubleLinkedList::deleteNode(Node *item) { // удаление ноды по адресу
    if (item == nullptr) {
        return false;
    }
    if (item->_prev == nullptr) {
        _head = item->_next;
    } else {
        item->_prev->_next = item->_next;
    }
    if (item->_next == nullptr) {
        _tail = item->_prev;
    } else {
        item->_next->_prev = item->_prev;
    }
    delete item;
    length--;
    return true;
}

DoubleLinkedList::Node* DoubleLinkedList::searchNode(int key) { // поиск ноды по адресу
    Node *item = _head;
    while (item != nullptr && item->_key != key) {
        item = item->_next;
    }
    return item;
}

DoubleLinkedList::Node* DoubleLinkedList::replaceNode(Node *item, int key) { // замена ноды по адресу
    Node *new_item = new Node(key, item->_prev, item->_next);

    if (item->_next != nullptr) {
        item->_next->_prev = new_item;
    }
    if (item->_prev != nullptr) {
        item->_prev->_next = new_item;
    }

    delete item;
    return new_item;
}

DoubleLinkedList::DoubleLinkedList() : _tail(nullptr),
                                       _head(nullptr),
                                       length(0) {
    ;
}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList &list) {
    _head = list._head;
    _tail = list._tail;
    length = list.length;
}

DoubleLinkedList::DoubleLinkedList(DoubleLinkedList && list)  noexcept {
    _head = list._head;
    list._head = nullptr;

    _tail = list._tail;
    list._tail = nullptr;

    length = list.length;
    list.length = 0;
}

DoubleLinkedList& DoubleLinkedList::operator=(const DoubleLinkedList &list) {
    if (this != &list) {
        _head = list._head;
        _tail = list._tail;
        length = list.length;
    }
    return *this;
}

DoubleLinkedList& DoubleLinkedList::operator=(DoubleLinkedList &&list) noexcept {
    if (this != &list) {
        _head = list._head;
        list._head = nullptr;

        _tail = list._tail;
        list._tail = nullptr;

        length = list.length;
        list.length = 0;
    }
    return *this;
}

DoubleLinkedList::~DoubleLinkedList() {
    Node *temp = _head;
    while (temp != nullptr) {
        _head = _head->_next;
        delete temp;
        temp = _head;
    }
}

int DoubleLinkedList::headItem() const {
    if (_head != nullptr) {
        return _head->_key;
    } else {
        throw ("List is empty.");
    }
}

int &DoubleLinkedList::headItem() {
    if (_head != nullptr) {
        return _head->_key;
    } else {
        throw ("List is empty.");
    }
}

int DoubleLinkedList::tailItem() const {
    if (_tail != nullptr) {
        return _tail->_key;
    } else {
        throw ("List is empty.");
    }
}

int &DoubleLinkedList::tailItem() {
    if (_tail != nullptr) {
        return _tail->_key;
    } else {
        throw ("List is empty.");
    }
}

void DoubleLinkedList::insertHead(int key) {
    return insertHead(new Node(key));
}

void DoubleLinkedList::insertTail(int key) {
    return insertTail(new Node(key));
}

bool DoubleLinkedList::searchItem(int key) {
    return searchNode(key) != nullptr;
}

bool DoubleLinkedList::replaceItem(int old_key, int new_key, bool all) {
    Node *item;
    if (!all) {
        item = searchNode(old_key);
        return item != replaceNode(item, new_key);
    } else {
        all = false;
        while ((item = searchNode(old_key)) != nullptr) {
            all = (item != replaceNode(item, new_key));
        }
        return all;
    }
}

bool DoubleLinkedList::deleteItem(int key, bool all) {
    if (!all) {
        return deleteNode(searchNode(key));
    } else {
        all = false;
        Node *item;
        while ((item = searchNode(key)) != nullptr) {
            all = deleteNode(item);
        }
        return all;
    }
}

bool DoubleLinkedList::deleteHead() {
    return deleteNode(_head);
}

bool DoubleLinkedList::deleteTail() {
    return deleteNode(_tail);
}

void DoubleLinkedList::add(DoubleLinkedList &list) {
    _tail->_next = list._head;
    list._head->_prev = _tail;

    length += list.length;

    list._head = nullptr;
    list._tail = nullptr;
    list.length = 0;
}

bool DoubleLinkedList::operator==(DoubleLinkedList &list) {
    Node *item = list._head;
    Node *current = _head;
    while (item != nullptr && current != nullptr) {
        if (item->_key != current->_key) {
            return false;
        }
        item = item->_next;
        current = current->_next;
    }
    return item == current;
}

inline bool DoubleLinkedList::operator!=(DoubleLinkedList &list) {
    return !this->operator==(list);
}

std::ostream& operator<<(std::ostream& out, const DoubleLinkedList& list) {
    DoubleLinkedList::Node* item = list._head;
    while (item != nullptr) {
        out << item->_key << "\n";
        item = item->_next;
    }
    return out;
}
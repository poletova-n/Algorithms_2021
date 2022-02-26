//
// Created by Foko on 25.02.2022.
//
#include <iostream>

class SinglyOrderedList {
private:
    struct Node {
        Node* next;
        int key;

        Node (int key, Node* next = nullptr): key(key),
                                              next(next)
                                              {
           ;
        }

        ~Node () {
            delete next;
        }
    };
private:
    Node* head;
    size_t length;
public:
    SinglyOrderedList (): length(0)
                          {
        head = nullptr;
    }

    SinglyOrderedList (const SinglyOrderedList& list): length(list.length) {
        Node* item = list.head; // item указатель копируемого списка
        Node* current_item;
        // current_item указатель на элемент текущего списка

        if (item != nullptr) {
            head = new Node(item->key);
        }

        while (item != nullptr) {
            current_item = current_item->next = new Node(item->key); //конструктор копирования ноды в новую область памяти
            item = item->next;
        }
    }

    SinglyOrderedList (SinglyOrderedList&& list) noexcept {
        if (this != &list) {
            head = list.head;
            length = list.length;

            list.head = nullptr;
            list.length = 0;
        }
    }

    ~SinglyOrderedList () {
        delete head;
    }

    SinglyOrderedList& operator=(const SinglyOrderedList& list) {
        if (this != &list) {
            delete head;
            head = nullptr;

            Node* item = list.head; // item указатель копируемого списка
            Node* current_item;
            // current_item указатель на элемент текущего списка

            if (item != nullptr) {
                head = new Node(item->key);
            }

            while (item != nullptr) {
                delete current_item->next;
                current_item = current_item->next = new Node(item->key); //конструктор копирования ноды в новую область памяти

                item = item->next;
            }
        }
        return *this;
    }

    SinglyOrderedList& operator=(SinglyOrderedList&& list) noexcept {
        if (this != &list) {
            head = list.head;
            length = list.length;

            list.head = nullptr;
            list.length = 0;
        }
        return *this;
    }

    bool insert (int key) {
        if (head == nullptr) { // проверка на пустой список
            head = new Node(key);
            return true;
        }

        if (key < head->key) { // вставка в начало списка
            head = new Node(key, head);
            return true;
        }

        Node *item = head; // вставка в конец или после элемента
        while (item->next != nullptr && item->next->key < key) {
            item = item->next; // поиск места вставки
        }
        if (item->key != key) { // т.к. следующий элемент точно удовлетворяет условиям, нужно проверить предыдущий
            item->next = new Node(key, item->next); // вставка в конец тоже работает
            return true;
        } else {
            return false;
        }
    }

};


int main () {
    SinglyOrderedList list;
    list.insert(0);
    list.insert(9);
    list.insert(-1);
    list.insert(6);
    list.insert(10);
    list.insert(3);

    std::cout << "\n";
}

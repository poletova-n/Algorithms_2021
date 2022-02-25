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
};


int main () {
    return 0;
}

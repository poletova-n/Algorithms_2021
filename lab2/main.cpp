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
private:
    Node* search (const int* key) {
        Node* item = head;
        while (item != nullptr && item->key < *key) {
            item = item->next;
        }
        if (item != nullptr && item->key == *key) {
            return item;
        } else {
            return nullptr;
        }
    }
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
        Node* item = head;
        while (item->next != nullptr) {
            head = item->next;
            delete item;
            item = head;
        }
        delete item;
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
        if (item->key != key) { // т.к. следующий элемент точно не удовлетворяет ключу, нужно проверить текущий
            item->next = new Node(key, item->next); // вставка в конце
            return true;
        } else {
            return false;
        }
    }

    bool search (int key) {
        return this->search(&key) == nullptr;
    }

    bool remove (int key) {
        if (head == nullptr) {
            return false;
        }

        Node* item = head; // вставка в конец или после элемента
        if (head->key == key) {
            head = head->next;
            delete item;
            return true;
        }

        while (item->next != nullptr && item->next->key < key) {
            item = item->next; // поиск места вставки
        }
        if (item->next != nullptr && item->next->key == key) { // т.к. следующий элемент точно меньше
            Node* temp = item->next->next; // копирование указателя
            delete item->next; // удаление элемента
            item->next = temp; // сшивание списка
            return true;
        } else {
            return false;
        }
    }

    friend std::ostream& operator<<(std::ostream& out, const SinglyOrderedList& list);
};

std::ostream& operator<<(std::ostream& out, const SinglyOrderedList& list) {
    SinglyOrderedList::Node* item = list.head;
    while (item != nullptr) {
        out << item->key << ' ';
        item = item->next;
    }
    out << '\n';
    return out;
}


int main () {
    SinglyOrderedList list;
    list.insert(0);
    list.insert(9);
    list.insert(-1);
    list.insert(6);
    list.insert(10);
    list.insert(3);


    std::cout << list;

    list.remove(-1);
    list.remove(4);
    list.remove(6);
    list.remove(10);

    std::cout << list;
    std::cout << "\n";
}

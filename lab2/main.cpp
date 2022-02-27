#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-auto"
//
// Created by Foko on 25.02.2022.
//
#include <iostream>

class SinglyOrderedList {
private:
    struct Node {
        Node* next;
        int key;

        explicit Node (int key, Node* next = nullptr): key(key),
                                              next(next)
                                              {
           ;
        }
    };
private:
    Node* head{};
    size_t length;
private:
    Node* search (const int* key) const {
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

    SinglyOrderedList (const SinglyOrderedList& list): length(list.length)
                                                       {
        Node* item = list.head;
        while (item != nullptr) {
            this->insert(new Node(item->key));
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

        while (head != nullptr) {
            head = item->next;
            delete item;
            item = head;
        }
        delete item;
    }

    SinglyOrderedList& operator=(const SinglyOrderedList& list) {
        if (this != &list) {
            SinglyOrderedList* copy = this;
            *this = SinglyOrderedList(list);
            delete copy;
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
    
    Node* insert (Node* insert_node) {
        if (head == nullptr) { // проверка на пустой список
            head = insert_node;
            length++;
            return insert_node;
        }

        if (insert_node->key < head->key) { // вставка в начало списка
            insert_node->next = head;
            head = insert_node;
            length++;
            return insert_node;
        }

        Node *item = head; // вставка в конец или после элемента
        while (item->next != nullptr && item->next->key <= insert_node->key) {
            item = item->next; // поиск места вставки
        }
        if (item->key != insert_node->key) { // т.к. следующий элемент точно не удовлетворяет ключу, нужно проверить текущий
            insert_node->next = item->next;
            item->next = insert_node;
            length++;
            return insert_node;
        } else { 
            return nullptr;
        }
    }

    bool insert (int key) {
        return insert(new Node(key, nullptr)) == nullptr;
    }

    bool search (int key) const {
        return this->search(&key) != nullptr;
    }

    bool remove (int key) {
        if (head == nullptr) {
            return false;
        }

        Node* item = head; // вставка в конец или после элемента
        if (head->key == key) {
            head = head->next;
            delete item;
            length--;
            return true;
        }

        while (item->next != nullptr && item->next->key < key) {
            item = item->next; // поиск места
        }
        if (item->next != nullptr && item->next->key == key) { // т.к. следующий элемент точно меньше
            Node* temp = item->next->next; // копирование указателя
            delete item->next; // удаление элемента
            item->next = temp; // сшивание списка
            length--;
            return true;
        } else {
            return false;
        }
    }

    void addiction (SinglyOrderedList& list) {
        if (this == &list) {
            return;
        }

        Node* buffer;

        if (list.head == nullptr) {
            return;
        }

        while (list.head->next != nullptr) {
            buffer = list.head; // копирование текущего указателя item
            list.head = list.head->next; // перемещение к следующему указателю
            this->insert(buffer); // вставка элемента по сохраненному указателю
        }
        this->insert(list.head);
        list.head = nullptr;
    };
    
    void subtraction (const SinglyOrderedList& list) {
        if (this == &list) {
            SinglyOrderedList* copy = this;
            *this = SinglyOrderedList();
            delete copy;
            return;
        }

        Node* item = list.head;
        while (item != nullptr) {
            this->remove(item->key);
            item = item->next;
        }
    }

    friend std::string checkout(SinglyOrderedList& list);
    friend SinglyOrderedList& intersection (const SinglyOrderedList& first, const SinglyOrderedList& second);
    friend std::ostream& operator<<(std::ostream& out, const SinglyOrderedList& list);
};

SinglyOrderedList& intersection (const SinglyOrderedList& first, const SinglyOrderedList& second) {
    SinglyOrderedList* list = new SinglyOrderedList();
    SinglyOrderedList::Node* item = first.head;
    while (item != nullptr) {
        if (second.search(item->key))
            list->insert(item->key);
        item = item->next;
    }
    return *list;
}

std::ostream& operator<<(std::ostream& out, const SinglyOrderedList& list) {
    SinglyOrderedList::Node* item = list.head;
    while (item != nullptr) {
        out << item->key << ' ';
        item = item->next;
    }
    out << '\n';
    return out;
}

std::string checkout (SinglyOrderedList& list) {
    SinglyOrderedList::Node* item = list.head;
    std::string outstring;

    while (item != nullptr) {
        outstring += (std::to_string(item->key) + " ");
        item = item->next;
    }
    return outstring;
}

int main () {
    SinglyOrderedList list1;
    list1.insert(0);
    list1.insert(1);
    list1.insert(2);
    list1.insert(4);
    list1.insert(5);
    list1.insert(6);

    std::cout << list1;

    SinglyOrderedList list2;
    list2.insert(3);
    list2.insert(4);
    list2.insert(5);
    list2.insert(6);
    list2.insert(7);
    list2.insert(8);

    std::cout << list2;

    SinglyOrderedList list3 = list1;
    SinglyOrderedList list4 = list1;

    SinglyOrderedList list2_copy(list2);

    list3.addiction(list2_copy);
    list4.subtraction(list2);
    SinglyOrderedList list5 = intersection(list1, list2);


    std::cout << "\n" << list1 << list2 << list3 << list4 << list5;

    std::cout << "\n";
}
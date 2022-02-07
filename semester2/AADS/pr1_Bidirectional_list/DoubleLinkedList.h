#ifndef __DOUBLE_LINKED_LIST
#define __DOUBLE_LINKED_LIST

#include <fstream>

//  DoubleLinkedList.h - Дважды связный список целых чисел
//
class DoubleLinkedList
{
private:
    // Тип  Node используется для описания элемента списка, связанного со 
    // следующим с помощью поля next_ и предшествующим с помощью поле prev_
    struct Node         // может использоваться  только в классе DoubleLinkedList
    {
        int item_;        // значение элемента списка
        Node* next_;      // указатель на следующий элемент списка
        Node* prev_;      // указатель на предшествующий элемент списка

        // Конструктор для создания нового элемента списка. 
        Node(int item, Node* next = nullptr, Node* prev = nullptr) : item_(item), next_(next), prev_(prev) { }
    };

    int count_;         // счетчик числа элементов
    Node* head_;        // первый элемент списка
    Node* tail_;        // последний элемент списка
 
    void swap(DoubleLinkedList& other) noexcept;
    
    // Доступ к головному узлу списка
    Node* head() const { return head_; }

    // Доступ к хвостовому узлу списка
    Node* tail() const { return tail_; }

    // Добавление сформированного узла в хвост списка
    void insertTail(Node* x);

    // Добавление сформированного узла в начало списка
    void insertHead(Node* x); // (int item);

  // Удаление заданного узла 
    void deleteNode(Node* x);

    // Поиск узла (адрес) с заданным значением  
    Node* searchNode(int item);

    // Замена информации узла на новое 
    Node* replaceNode(Node* x, int item);

public:

    // Конструктор "по умолчанию" - создание пустого списка
    DoubleLinkedList();

    // Конструктор "копирования" – создание копии имеющегося списка
    DoubleLinkedList(const DoubleLinkedList& src);

    // Оператор присваивания (копирующее присваивание)
    DoubleLinkedList& operator=(const DoubleLinkedList& right);

    // Конструктор перемещения 
    DoubleLinkedList(DoubleLinkedList&& other) noexcept;

    // Оператор перемещающего присваивания 
    DoubleLinkedList& operator=(DoubleLinkedList&& right) noexcept;

    bool operator==(DoubleLinkedList& right);

    friend std::ostream& operator<<(std::ostream& output, DoubleLinkedList &doubleLinkedList);
   
    // количество элементов списка
    [[nodiscard]] int count()const { return count_; }

    // Доступ к информации головного узла списка
    [[nodiscard]] int headItem() const;
    int& headItem();

    // Доступ к информации хвостового узла списка
    [[nodiscard]] int tailItem() const;
    int& tailItem();

    // Добавление элемента в голову списка
    void insertHead(int item);

    // Добавление элемента в хвост списка
    void insertTail(int item);

    // Удаление элемента с головы списка
    bool deleteHead();

    // Удаление элемента из хвоста списка
    bool deleteTail();

    // Удаление узла с заданным значением  
    bool deleteItem(const int item, bool all = false);

    // Поиск записи с заданным значением  
    bool searchItem(int item);

    // Замена информации узла на новое 
    bool replaceItem(int itemOld, int itemNew, bool all = false);

    // Вывод элементов списка в текстовом виде в стандартный выходной поток 
    void outAll();

    void add(DoubleLinkedList & list);

    // Деструктор списка	
    virtual ~DoubleLinkedList();

};

/*bool operator==(DoubleLinkedList &right, DoubleLinkedList& left) {
    if(&right == &left) return true;
    if(right.count_ != left.count_) return false;
    right.
    for (int i = 0; i < ; ++i) {

    }
    return false;
}*/


#endif


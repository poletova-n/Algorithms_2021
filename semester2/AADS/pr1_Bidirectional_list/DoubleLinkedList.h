#ifndef __DOUBLE_LINKED_LIST
#define __DOUBLE_LINKED_LIST

#include <fstream>

//  DoubleLinkedList.h - ������ ������� ������ ����� �����
//
class DoubleLinkedList
{
private:
    // ���  Node ������������ ��� �������� �������� ������, ���������� �� 
    // ��������� � ������� ���� next_ � �������������� � ������� ���� prev_
    struct Node         // ����� ��������������  ������ � ������ DoubleLinkedList
    {
        int item_;        // �������� �������� ������
        Node* next_;      // ��������� �� ��������� ������� ������
        Node* prev_;      // ��������� �� �������������� ������� ������

        // ����������� ��� �������� ������ �������� ������. 
        Node(int item, Node* next = nullptr, Node* prev = nullptr) : item_(item), next_(next), prev_(prev) { }
    };

    int count_;         // ������� ����� ���������
    Node* head_;        // ������ ������� ������
    Node* tail_;        // ��������� ������� ������
 
    void swap(DoubleLinkedList& other) noexcept;
    
    // ������ � ��������� ���� ������
    Node* head() const { return head_; }

    // ������ � ���������� ���� ������
    Node* tail() const { return tail_; }

    // ���������� ��������������� ���� � ����� ������
    void insertTail(Node* x);

    // ���������� ��������������� ���� � ������ ������
    void insertHead(Node* x); // (int item);

  // �������� ��������� ���� 
    void deleteNode(Node* x);

    // ����� ���� (�����) � �������� ���������  
    Node* searchNode(int item);

    // ������ ���������� ���� �� ����� 
    Node* replaceNode(Node* x, int item);

public:

    // ����������� "�� ���������" - �������� ������� ������
    DoubleLinkedList();

    // ����������� "�����������" � �������� ����� ���������� ������
    DoubleLinkedList(const DoubleLinkedList& src);

    // �������� ������������ (���������� ������������)
    DoubleLinkedList& operator=(const DoubleLinkedList& right);

    // ����������� ����������� 
    DoubleLinkedList(DoubleLinkedList&& other) noexcept;

    // �������� ������������� ������������ 
    DoubleLinkedList& operator=(DoubleLinkedList&& right) noexcept;

    bool operator==(DoubleLinkedList& right);

    friend std::ostream& operator<<(std::ostream& output, DoubleLinkedList &doubleLinkedList);
   
    // ���������� ��������� ������
    [[nodiscard]] int count()const { return count_; }

    // ������ � ���������� ��������� ���� ������
    [[nodiscard]] int headItem() const;
    int& headItem();

    // ������ � ���������� ���������� ���� ������
    [[nodiscard]] int tailItem() const;
    int& tailItem();

    // ���������� �������� � ������ ������
    void insertHead(int item);

    // ���������� �������� � ����� ������
    void insertTail(int item);

    // �������� �������� � ������ ������
    bool deleteHead();

    // �������� �������� �� ������ ������
    bool deleteTail();

    // �������� ���� � �������� ���������  
    bool deleteItem(const int item, bool all = false);

    // ����� ������ � �������� ���������  
    bool searchItem(int item);

    // ������ ���������� ���� �� ����� 
    bool replaceItem(int itemOld, int itemNew, bool all = false);

    // ����� ��������� ������ � ��������� ���� � ����������� �������� ����� 
    void outAll();

    void add(DoubleLinkedList & list);

    // ���������� ������	
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


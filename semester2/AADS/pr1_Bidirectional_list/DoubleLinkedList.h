#ifndef __DOUBLE_LINKED_LIST
#define __DOUBLE_LINKED_LIST

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
    DoubleLinkedList() : count_(0), head_(nullptr), tail_(nullptr) {  }

    // ����������� "�����������" � �������� ����� ���������� ������
    DoubleLinkedList(const DoubleLinkedList& src);

    // �������� ������������ (���������� ������������)
    DoubleLinkedList& operator=(const DoubleLinkedList& right);

    // ����������� ����������� 
    DoubleLinkedList(DoubleLinkedList&& other) noexcept;

    // �������� ������������� ������������ 
    DoubleLinkedList& operator=(DoubleLinkedList&& right) noexcept;
   
    // ���������� ��������� ������
    int count()const { return count_; }

    // ������ � ���������� ��������� ���� ������
    int headItem() const;
    int& headItem();

    // ������ � ���������� ���������� ���� ������
    int tailItem() const;
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
    bool deleteItem(const int item);

    // ����� ������ � �������� ���������  
    bool searchItem(int item);

    // ������ ���������� ���� �� ����� 
    bool replaceItem(int itemOld, int itemNew);

    // ����� ��������� ������ � ��������� ���� � ����������� �������� ����� 
    void outAll();

    // ���������� ������	
    virtual ~DoubleLinkedList();
};
#endif


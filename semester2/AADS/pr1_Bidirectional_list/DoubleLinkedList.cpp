#include "DoubleLinkedList.h"
#include "DoubleLinkedList.h"
#include <iostream>

// ����������� "�� ���������" - �������� ������� ������ - ��. �������� ������
DoubleLinkedList::DoubleLinkedList(): count_(0), head_(nullptr), tail_(nullptr) {  }

// ����������� "�����������" � �������� ����� ���������� ������
DoubleLinkedList::DoubleLinkedList (const DoubleLinkedList & list) : count_(0), head_(nullptr), tail_(nullptr)  {

    if(list.head_ == nullptr) return;

    this->insertHead(new Node(list.head_->item_));

    if(list.count_ < 2) return;

    Node *temp = list.head_->next_;
    this->insertTail(new Node(temp->item_));

    for (int i = 0; i < list.count_ - 2; ++i) {
        temp = temp->next_;
        this->insertTail(new Node(temp->item_));
    }

}

void DoubleLinkedList::swap(DoubleLinkedList& other) noexcept
{
	std::swap(head_, other.head_);
	std::swap(tail_, other.tail_);
	std::swap(count_, other.count_);
}

// �������� ������������ (���������� ������������)
DoubleLinkedList & DoubleLinkedList ::operator=(const DoubleLinkedList& right)
{
	if (this != &right) {
		DoubleLinkedList temp(right); // temp ����� right ��������
		swap(temp);        // ������ this ����� right, � temp ����� this
	}                    // �������� temp c ������� ������� this
	return *this;
}

// ����������� ����������� 
DoubleLinkedList::DoubleLinkedList(DoubleLinkedList&& other) noexcept:
	head_(other.head_),
	tail_(other.tail_),
	count_(other.count_)
{
	other.head_ = nullptr;
	other.tail_ = nullptr;
	other.count_ = 0;
}

// �������� ������������� ������������ 
DoubleLinkedList& DoubleLinkedList::operator=(DoubleLinkedList&& right) noexcept 
{
	if (this != &right) {
		swap(right);
	}
	return *this;
}


// ���������� ��������������� ���� � ����� ������
void DoubleLinkedList::insertTail(Node* x)
{
	x->prev_ = tail_;
    if(head_ != nullptr){
        tail_->next_ = x;
    }
    else head_ = x;
    tail_ = x;
    count_++;
}

// ���������� ��������������� ���� � ������ ������
void DoubleLinkedList::insertHead(Node* x)
{   // x->prev_ == nullptr,  x->next_ == nullptr  
	x->next_ = head_;
	if (head_ != nullptr) {
		// ������ ��� �� ���� � ����� ������� ����� � ������, � ���������
		head_->prev_ = x;
	}
	else {
		// ������ ��� ���� � ����� ������� ����� � ������, � ���������
		tail_ = x;
	}
	head_ = x;
	count_++;  // ����� ��������� ������ �����������
}

// �������� ��������� ���� 
void DoubleLinkedList::deleteNode(Node* x)
{
	if (x == nullptr) {
		throw ("DoubleLinkedList::deleteNode  - ������� ����� ����� ���������� ����");
	}
	if (x->prev_ != nullptr) {
		(x->prev_)->next_ = x->next_;
	}
	else {
		head_ = x->next_;
	}
	if (x->next_ != nullptr) {
		(x->next_)->prev_ = x->prev_;
	}
	else {
		tail_ = x->prev_;
	}
	delete x;
	count_--;
}

// ����� ���� (�����) � �������� ���������  
DoubleLinkedList::Node* DoubleLinkedList::searchNode(int item)
{
	Node* x = head_;
	while (x != nullptr && x->item_ != item) {
		x = x->next_;
	}
	return x;
}

// ������ ���������� ���� �� ����� 
DoubleLinkedList::Node* DoubleLinkedList::replaceNode(DoubleLinkedList::Node* x, int item)
{
	x->item_ = item;
	return x;
}

// ������ � ���������� ��������� ���� ������
int DoubleLinkedList::headItem() const
{
	if (head_ != nullptr) {
		return head_->item_;
	}
	throw ("headItem - ������ ����!");
}

int& DoubleLinkedList::headItem()
{
	if (head_ != nullptr) {
		return head_->item_;
	}
	throw ("headItem - ������ ����!");
}

// ������ � ���������� ���������� ���� ������
int DoubleLinkedList::tailItem() const
{
	if (tail_ != nullptr) {
		return tail_->item_;
	}
	throw ("tailItem - ������ ����!");
}
int& DoubleLinkedList::tailItem()
{
	if (tail_ != nullptr) {
		return tail_->item_;
	}
	throw ("tailItem - ������ ����!");
}

// ���������� �������� � ������ ������
void DoubleLinkedList::insertHead(int item)
{
	insertHead(new Node(item));
}


// ���������� �������� � ����� ������
void DoubleLinkedList::insertTail(int item)
{
	insertTail(new Node(item));
}

// �������� �������� � ������ ������
bool DoubleLinkedList::deleteHead()
{
	if (head_ == nullptr) return false;
	deleteNode(head_);
	return true;
}

// �������� �������� �� ������ ������
bool DoubleLinkedList::deleteTail()
{
    if(tail_ == nullptr) return false;
    deleteNode(tail_);
	return true;
}

// �������� ���� � �������� ���������  
bool DoubleLinkedList::deleteItem(const int item, bool all)
{

    bool isSuccessful = false;
    Node* current = head_;

    while(current != nullptr)
    {
        if (current->item_ == item)
        {
            current = current->next_;
            deleteNode(current->prev_);
            if(!all) return true;
            isSuccessful = true;
        }
        else current = current->next_;
    }
    return isSuccessful;

}

// ����� ������ � �������� ���������  
bool DoubleLinkedList::searchItem(int item)
{
	return (searchNode(item) != nullptr);
}


// ������ ���������� ���� �� ����� 
bool DoubleLinkedList::replaceItem(int itemOld, int itemNew, bool all)
{
    bool isSuccessful = false;
    Node* current = head_;

    while(current != nullptr)
    {
        if (current->item_ == itemOld)
        {
            current->item_ = itemNew;
            if(!all) return true;
            isSuccessful = true;
        }
        current = current->next_;
    }
    return isSuccessful;
}

// ����� ��������� ������ � ��������� ���� � ����������� �������� ����� 
void DoubleLinkedList::outAll()
{
    if(head_ == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }

	Node* current = head_;
	while (current != nullptr) {
		std::cout << current->item_ << ' ';
		current = current->next_;
	}
	std::cout << std::endl;
}

// ���������� ������	
DoubleLinkedList::~DoubleLinkedList()
{
	Node* current = nullptr;
	Node* next = head_;
	while (next != nullptr) {
		current = next;
		next = next->next_;
		delete current;
	}

}

void DoubleLinkedList::add(DoubleLinkedList &list) {

    if(list.head_ == nullptr) return;

    int count = list.count_;

    this->insertTail(new Node(list.head_->item_));

    if(list.count_ < 2) return;

    Node *temp = list.head_->next_;
    this->insertTail(new Node(temp->item_));

    for (int i = 0; i < count - 2; ++i) {
        temp = temp->next_;
        this->insertTail(new Node(temp->item_));
    }

}

bool DoubleLinkedList::operator==(DoubleLinkedList &right) {

    if(&right == this) return true;

    if(right.count_ != this->count_) return false;

    Node* first = head_;
    Node* second = right.head_;

    for (int i = 0; i < right.count_; ++i) {
        if(first->item_ != second->item_) return false;
        first = first->next_;
        second = second->next_;
    }

    return true;
}

std::ostream &operator<<(std::ostream &output, DoubleLinkedList &doubleLinkedList) {

    doubleLinkedList.outAll();
    return output;
}
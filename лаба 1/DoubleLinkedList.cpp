#include "DoubleLinkedList.h"
#include "DoubleLinkedList.h"
//  DoubleLinkedList.cpp - ������ ������� ������ ����� ����� - ���������� ������� ������  
//
#include <iostream>

// ����������� "�� ���������" - �������� ������� ������ - ��. �������� ������
//DoubleLinkedList::DoubleLinkedList(): count_(0), head_(nullptr), tail_(nullptr) {  }

// ����������� "�����������" � �������� ����� ���������� ������
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& src)
{
	head_ = nullptr;
	tail_ = nullptr;
	Node* x = src.head_;
	for (int i = 1; i <= src.count(); i++)
	{
		insertTail(x->item_);
		x = x->next_;
	}
	count_ = src.count();
}

void DoubleLinkedList::swap(DoubleLinkedList& other) noexcept
{
	std::swap(head_, other.head_);
	std::swap(tail_, other.tail_);
	std::swap(count_, other.count_);
}

// �������� ������������ (���������� ������������)
DoubleLinkedList& DoubleLinkedList::operator=(DoubleLinkedList&& right) noexcept
{
	if (this != &right) {
		 // temp ����� right ��������
		swap(right);        // ������ this ����� right, � temp ����� this
	}                    // �������� temp c ������� ������� this
	return *this;
}

// ����������� ����������� 
DoubleLinkedList::DoubleLinkedList(DoubleLinkedList&& other) noexcept :
	head_(other.head_),
	tail_(other.tail_),
	count_(other.count_)
{
	other.head_ = nullptr;
	other.tail_ = nullptr;
	other.count_ = 0;
}


//-------------------------------------------------------------------

// �������� ��������� �� ���������
bool DoubleLinkedList::operator==(const DoubleLinkedList& list) const noexcept
{
	if (count_ != list.count_) //���������� ����� ���������
	{
		return 0;
	}
	Node* x = head_;
	Node* y = list.head_;

	while (x != nullptr && y != nullptr) //���������� �������� ������� � ������
	{
		if (x->item_ == y->item_)
		{
			x = x->next_;
			y = y->next_;
		}
		else return 0;
	}
	return 1;
}
//------------------------------------------------------------------

//�������� ������
std::ostream& operator<<(std::ostream& out, const DoubleLinkedList& list)
{
	DoubleLinkedList::Node* x = list.head_;
	while (x != nullptr) 
	{
		out << x->item_ << ' ';
		x = x->next_;
	}
	out << "\n";
	return out;
}
//-------------------------------------------------------------------

// ���������� ��������������� ���� � ����� ������
void DoubleLinkedList::insertTail(Node* x)
{
	if (tail_ != nullptr) // ���� ���� ��������� ������, �� ��� ���������� � �������������
	{
		x->prev_ = tail_; 
		tail_->next_ = x; 
	}
	else
		head_ = x; 
	count_++;
	tail_ = x;
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
		// ��������� �� ������ ������
		(x->prev_)->next_ = x->next_;
	}
	else {
		// ��������� ������ ������,  ������ ������� ���������� ������
		head_ = x->next_;
	}
	if (x->next_ != nullptr) {
		// ��������� �� �����
		(x->next_)->prev_ = x->prev_;
	}
	else {
		// ��������� �����
		tail_ = x->prev_;
	}
	delete x;      // 
	count_--;     // ����� ��������� ������ �����������
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

// ���������� ��������� ������
//  int DoubleLinkedList::�ount()const{ return count_; }

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
{   // ������� ����� ������� ������ � ��������� � ������ 
	insertHead(new Node(item));
}


// ���������� �������� � ����� ������
void DoubleLinkedList::insertTail(int item)
{   // ������� ����� ������� ������ � ��������� � ����� 
	insertTail(new Node(item));
}

// �������� �������� � ������ ������
bool DoubleLinkedList::deleteHead()
{
	if (head_ == nullptr) {
		return 0;  // ������ ����, �������� ���
	}
	deleteNode(head_);
	return 1;      // ������ ��� �� ����, �������� ������
}

//----------------------------------------------------------------------------

// �������� �������� �� ������ ������
bool DoubleLinkedList::deleteTail()
{
	if (tail_ == nullptr)
	{
		return 0; // ���� ������ ���� ���������� false
	}
	deleteNode(tail_);
	return 1;  
}

//------------------------------------------------------------------------------

// �������� ���� � �������� ���������  
bool DoubleLinkedList::deleteItem(const int item)
{
	Node* x = searchNode(item);
	if (x != nullptr) 
	{
		deleteNode(x);
		return 1;
	}
	return 0; 
}

// ����� ������ � �������� ���������  
bool DoubleLinkedList::searchItem(int item)
{   // ���������� TRUE, ���� ���� ������ 
	return (searchNode(item) != nullptr);
}

//----------------------------------------------------------------------------

// ������ ���������� ���� �� ����� 
bool DoubleLinkedList::replaceItem(int itemOld, int itemNew)
{
	Node* x = searchNode(itemOld);
	if (x != nullptr)
	{
		replaceNode(x, itemNew);
		return 1;
	}
	return 0;
}

// ����� ��������� ������ � ��������� ���� � ����������� �������� ����� 
void DoubleLinkedList::outAll()
{
	Node* current = head_;       // ��������� �� �������
	while (current != nullptr) {
		std::cout << current->item_ << ' ';
		current = current->next_;  // ������� � ���������� ��������
	}
	std::cout << std::endl;
}

//-----------------------------------------------------------------------------

//���������� � ����� ��������� ������
void DoubleLinkedList::add(DoubleLinkedList& list)
{
	tail_->next_ = list.head_;			
	list.head_->prev_ = tail_;
	tail_ = list.tail_;
	list.head_ = nullptr;
	list.tail_ = nullptr;
}

// ���������� ������	
DoubleLinkedList::~DoubleLinkedList()
{
	Node* current = nullptr;   // ��������� �� �������, ���������� ��������
	Node* next = head_;        // ��������� �� ��������� �������
	while (next != nullptr) {  // ���� ���� ��� �������� � ������
		current = next;
		next = next->next_;    // ������� � ���������� ��������
		delete current;        // ������������ ������
	}
}
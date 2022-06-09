#include "Dictionary.h"
#include <string>
#include <iostream>

// ���������� �����������
Dictionary::Dictionary(const Dictionary& src)
{
	Node* x = src.head_;
	for (int i = 1; i <= src.count(); i++)
	{
		insert(x->value_);
		x = x->next_;
	}
	count_ = src.count();
}

void Dictionary::swap(Dictionary& other) noexcept
{
	std::swap(head_, other.head_);
	std::swap(count_, other.count_);
}

//�������� ������������ (���������� ������������)
Dictionary& Dictionary::operator=(const Dictionary& right)
{
	if (this != &right)
	{
		Dictionary temp(right);  // temp ����� ������ right 
		swap(temp);				//������ this ����� right, temp ����� this
	}							//�������� temp � ������� ������� this
	return *this;
}

//����������� �����������
Dictionary::Dictionary(Dictionary&& other) noexcept :
	head_(other.head_),
	count_(other.count_)
{
	other.head_ = nullptr;
	other.count_ = 0;
}

// �������� ������������� ����������
Dictionary& Dictionary::operator=(Dictionary&& right) noexcept
{
	if (this != &right)
		swap(right);
	return *this;
}

// ���������� ��������������� ����
void Dictionary::insert(Node* x)
{
	if (head_ != nullptr)
	{
		Node* temp = head_;
		Node* prev = nullptr;
		while (temp != nullptr && x->value_ > temp->value_)
		{
			prev = temp;
			temp = temp->next_;
		}
		if (temp != nullptr && x->value_ == temp->value_)
		{
			return;
		}
		if (temp != head_)
		{
			x->next_ = temp;
			prev->next_ = x;
		}
		else
		{
			x->next_ = head_;
			head_ = x;
		}

	}
	else
		head_ = x;
	count_++;
}

// ������ � ���������� ��������� ���� ������
std::string Dictionary::headItem() const
{
	if (head_ != nullptr) {
		return head_->value_;
	}
	throw ("headItem - ������ ����!");
}

std::string& Dictionary::headItem()
{
	if (head_ != nullptr)
	{
		return head_->value_;
	}
	throw ("headItem - ������ ����!");
}

// ���������� ��������
void Dictionary::insert(std::string value)
{
	insert(new Node(value));
}

//�������� �������� � ������ ������
bool Dictionary::deleteHead()
{
	if (head_ == nullptr)
	{
		return 0;
	}
	Node* temp = head_->next_;
	delete head_;
	head_ = temp;
	count_--;
	return 1; //������ ��� �� ����, ������ �������
}

//
bool Dictionary::deleteItem(const std::string value)
{
	Node* x = head_;
	if (x->value_ != value) //���� �� ������ �������
	{
		Node* prev = x;
		x = x->next_;
		while (x != nullptr && x->value_ != value)
		{
			prev = x;
			x = x->next_;
		}
		prev->next_ = x->next_;
		deleteNode(x);
	}
	else
	{
		deleteHead(); //���� ������ �������
	}
	return 1;
}

void Dictionary::deleteNode(Node* x)
{
	delete x;
}

//����� ������ � ������� ���������
bool Dictionary::searchItem(std::string value)
{
	//��� ���� ������ true
	Node* x = head_;
	while (x != nullptr && x->value_ != value)
	{
		x = x->next_;
	}

	return (x != nullptr);
}

// ����� ��������� ������ � ��������� ���� 
void Dictionary::outAll()
{
	Node* current = head_;
	while (current != nullptr)
	{
		std::cout << current->value_ << "\n";
		current = current->next_;
	}
	std::cout << "\n";
}

//����������� ��������
void Dictionary::add(Dictionary& other)
{
	while (other.head_ != nullptr)
	{
		Node* next = other.head_->next_;
		insert(other.head_);
		other.head_ = next;
	}
	other.count_ = 0;
}

//��������� ��������
void Dictionary::remove(const Dictionary& other)
{
	Node* x = other.head_;
	while (x != nullptr)
	{
		Node* temp = head_;
		Node* prev = nullptr;
		while (temp != nullptr && x->value_ > temp->value_)
		{
			prev = temp;
			temp = temp->next_;
		}
		if (temp != nullptr && x->value_ == temp->value_)
		{
			if (head_ != temp)
			{
				prev->next_ = temp->next_;
				delete temp;
			}
			else
			{
				head_ = temp->next_;
				delete temp;
			}
		}
		x = x->next_;
	}
}

//
Dictionary::~Dictionary()
{
	Node* current = nullptr; // ��������� �� ������� ������� �������
	Node* next = head_;		// ��������� �� ��������� 
	while (next != nullptr) // ���� ���� ��� ��������
	{
		current = next;
		next = next->next_; // ������� � ���������� 
		delete current;		// ������������ ������
	}
}

// ����������� ��������
Dictionary Crossing(const Dictionary& list1, const Dictionary& list2)
{
	Dictionary newOne;
	Dictionary::Node* x = list2.head_;
	while (x != nullptr)
	{
		Dictionary::Node* temp = list2.head_;
		Dictionary::Node* prev = nullptr;
		while (temp != nullptr && x->value_ > temp->value_)
		{
			prev = temp;
			temp = temp->next_;
		}
		if (temp != nullptr && x->value_ == temp->value_)
			newOne.insert(x->value_);
		x = x->next_;
	}
	return newOne;
}
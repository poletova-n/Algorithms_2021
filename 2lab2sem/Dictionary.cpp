#include "Dictionary.h"
#include <string>
#include <iostream>

// конструкор копирования
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

//оператор присваивания (копирующее присваивание)
Dictionary& Dictionary::operator=(const Dictionary& right)
{
	if (this != &right)
	{
		Dictionary temp(right);  // temp копия адреса right 
		swap(temp);				//теперь this копия right, temp копия this
	}							//удаление temp с данными сатрого this
	return *this;
}

//конструктор перемещения
Dictionary::Dictionary(Dictionary&& other) noexcept :
	head_(other.head_),
	count_(other.count_)
{
	other.head_ = nullptr;
	other.count_ = 0;
}

// оператор перемещающего присвоения
Dictionary& Dictionary::operator=(Dictionary&& right) noexcept
{
	if (this != &right)
		swap(right);
	return *this;
}

// добавление сформарованного узла
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

// доступ к информации головного узла списка
std::string Dictionary::headItem() const
{
	if (head_ != nullptr) {
		return head_->value_;
	}
	throw ("headItem - список пуст!");
}

std::string& Dictionary::headItem()
{
	if (head_ != nullptr)
	{
		return head_->value_;
	}
	throw ("headItem - список пуст!");
}

// добавление элемента
void Dictionary::insert(std::string value)
{
	insert(new Node(value));
}

//удаление элемента с головы списка
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
	return 1; //список был не пуст, голова удалена
}

//
bool Dictionary::deleteItem(const std::string value)
{
	Node* x = head_;
	if (x->value_ != value) //если не первый элемент
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
		deleteHead(); //если первый элемент
	}
	return 1;
}

void Dictionary::deleteNode(Node* x)
{
	delete x;
}

//поиск записи с заданым значением
bool Dictionary::searchItem(std::string value)
{
	//ели узел найден true
	Node* x = head_;
	while (x != nullptr && x->value_ != value)
	{
		x = x->next_;
	}

	return (x != nullptr);
}

// вывод элементов списка в текстовом виде 
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

//объединение словарей
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

//вычитание словарей
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
	Node* current = nullptr; // указатель на элемент который удаляем
	Node* next = head_;		// указатель на следующий 
	while (next != nullptr) // пока есть еще элементы
	{
		current = next;
		next = next->next_; // переход к следующему 
		delete current;		// освобождение памяти
	}
}

// пересечение словарей
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
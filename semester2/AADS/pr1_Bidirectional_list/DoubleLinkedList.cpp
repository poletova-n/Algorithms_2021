#include "DoubleLinkedList.h"
#include "DoubleLinkedList.h"
#include <iostream>

// Конструктор "по умолчанию" - создание пустого списка - см. Описание класса
DoubleLinkedList::DoubleLinkedList(): count_(0), head_(nullptr), tail_(nullptr) {  }

// Конструктор "копирования" – создание копии имеющегося списка
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

// Оператор присваивания (копирующее присваивание)
DoubleLinkedList & DoubleLinkedList ::operator=(const DoubleLinkedList& right)
{
	if (this != &right) {
		DoubleLinkedList temp(right); // temp копия right операнда
		swap(temp);        // теперь this копия right, а temp копия this
	}                    // удаление temp c данными старого this
	return *this;
}

// Конструктор перемещения 
DoubleLinkedList::DoubleLinkedList(DoubleLinkedList&& other) noexcept:
	head_(other.head_),
	tail_(other.tail_),
	count_(other.count_)
{
	other.head_ = nullptr;
	other.tail_ = nullptr;
	other.count_ = 0;
}

// Оператор перемещающего присваивания 
DoubleLinkedList& DoubleLinkedList::operator=(DoubleLinkedList&& right) noexcept 
{
	if (this != &right) {
		swap(right);
	}
	return *this;
}


// Добавление сформированного узла в хвост списка
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

// Добавление сформированного узла в начало списка
void DoubleLinkedList::insertHead(Node* x)
{   // x->prev_ == nullptr,  x->next_ == nullptr  
	x->next_ = head_;
	if (head_ != nullptr) {
		// список был НЕ пуст – новый элемент будет и первым, и последним
		head_->prev_ = x;
	}
	else {
		// список был пуст – новый элемент будет и первым, и последним
		tail_ = x;
	}
	head_ = x;
	count_++;  // число элементов списка увеличилось
}

// Удаление заданного узла 
void DoubleLinkedList::deleteNode(Node* x)
{
	if (x == nullptr) {
		throw ("DoubleLinkedList::deleteNode  - неверно задан адрес удаляемого узла");
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

// Поиск узла (адрес) с заданным значением  
DoubleLinkedList::Node* DoubleLinkedList::searchNode(int item)
{
	Node* x = head_;
	while (x != nullptr && x->item_ != item) {
		x = x->next_;
	}
	return x;
}

// Замена информации узла на новое 
DoubleLinkedList::Node* DoubleLinkedList::replaceNode(DoubleLinkedList::Node* x, int item)
{
	x->item_ = item;
	return x;
}

// Доступ к информации головного узла списка
int DoubleLinkedList::headItem() const
{
	if (head_ != nullptr) {
		return head_->item_;
	}
	throw ("headItem - список пуст!");
}

int& DoubleLinkedList::headItem()
{
	if (head_ != nullptr) {
		return head_->item_;
	}
	throw ("headItem - список пуст!");
}

// Доступ к информации хвостового узла списка
int DoubleLinkedList::tailItem() const
{
	if (tail_ != nullptr) {
		return tail_->item_;
	}
	throw ("tailItem - список пуст!");
}
int& DoubleLinkedList::tailItem()
{
	if (tail_ != nullptr) {
		return tail_->item_;
	}
	throw ("tailItem - список пуст!");
}

// Добавление элемента в голову списка
void DoubleLinkedList::insertHead(int item)
{
	insertHead(new Node(item));
}


// Добавление элемента в хвост списка
void DoubleLinkedList::insertTail(int item)
{
	insertTail(new Node(item));
}

// Удаление элемента с головы списка
bool DoubleLinkedList::deleteHead()
{
	if (head_ == nullptr) return false;
	deleteNode(head_);
	return true;
}

// Удаление элемента из хвоста списка
bool DoubleLinkedList::deleteTail()
{
    if(tail_ == nullptr) return false;
    deleteNode(tail_);
	return true;
}

// Удаление узла с заданным значением  
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

// Поиск записи с заданным значением  
bool DoubleLinkedList::searchItem(int item)
{
	return (searchNode(item) != nullptr);
}


// Замена информации узла на новое 
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

// Вывод элементов списка в текстовом виде в стандартный выходной поток 
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

// Деструктор списка	
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
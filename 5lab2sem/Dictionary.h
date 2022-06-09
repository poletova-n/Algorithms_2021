#pragma once
#include <string>
#include <iostream>
#pragma once

template <class T>
class Dictionary
{
private:
	struct Node
	{
		Node* m_next; //Следующее слово
		T m_value; //Слово
		Node(Node* next, T value) : m_next(next), m_value(value) {} //Конструктор узла
	};
	Node* m_head;
	int m_count;
public:
	Dictionary() : m_head(nullptr), m_count(0) {} //Создание пустого списка

	Dictionary(Dictionary&& dict) noexcept : m_head(dict.m_head), m_count(dict.m_count)
	{
		dict.m_head = nullptr;
		dict.m_count = 0;
	} //Конструктор перемещения

	Dictionary& operator=(Dictionary&& dict) noexcept
	{
		if (&dict == this)
			return *this;
		else
		{
			Node* next = m_head;
			Node* current = nullptr;
			while (next != nullptr)
			{
				current = next;
				next = next->m_next;
				delete current;
			}

			m_head = dict.m_head;
			m_count = dict.m_count;
			dict.m_count = 0;
			dict.m_head = nullptr;
		}
	} //Оператор перемещающего присваивания

	bool IsEmpty()
	{
		return m_count == 0;
	}

	bool Insert(T value)
	{
		if (Search(value))
			return false;

		if (m_head == nullptr)
		{
			m_head = new Node(nullptr, value);
			m_count++;
			return true;
		}
		else if (value < m_head->m_value)
		{
			m_head = new Node(m_head, value);
			m_count++;
			return true;
		}

		Node* current = nullptr;
		Node* next = m_head;

		while (next != nullptr)
		{
			current = next;
			next = next->m_next;
			if (current->m_value < value)
			{
				if (next == nullptr)
				{
					current->m_next = new Node(nullptr, value);
					m_count++;
					return true;
				}
				else
				{
					if (next->m_value > value)
					{
						current->m_next = new Node(next, value);
						m_count++;
						return true;
					}
				}
			}
		}
	} //Добавить слово

	bool Insert(Node* node)
	{
		if (m_head != nullptr)
		{
			Node* temp = m_head;
			Node* prev = nullptr;
			while (temp != nullptr && node->m_value > temp->m_value)
			{
				prev = temp;
				temp = temp->m_next;
			}
			if (temp != nullptr && node->m_value == temp->m_value)
				return false;

			if (temp != m_head)
			{
				node->m_next = temp;
				prev->m_next = node;
			}
			else
			{
				node->m_next = m_head;
				m_head = node;
			}
		}
		else
		{
			m_head = node;
			node->m_next = nullptr;
		}
		m_count++;
		return true;
	}//Добавить узел

	bool Search(T value)
	{
		if (m_count == 0)
			return false;

		Node* current = m_head;
		while (current != nullptr)
		{
			if (current->m_value == value)
				return true;

			current = current->m_next;
		}

		return false;
	}//Найти слово

	bool Delete(T value)
	{
		if (!Search(value))
			return false;

		if (m_head->m_value == value) //Удаление головы
		{
			Node* head = m_head;
			m_head = m_head->m_next;
			delete head;
			m_count--;
			return true;
		}

		Node* current = nullptr;
		Node* next = m_head;

		while (next != nullptr)
		{
			current = next;
			next = next->m_next;
			if (next != nullptr && next->m_value == value)
			{
				current->m_next = next->m_next;
				delete next;
				m_count--;
				return true;
			}
		}
	}//Удалить слово

	void Add(Dictionary<T>& dict)
	{

		if (m_count == 0)
		{
			m_head = dict.m_head;
			m_count = dict.m_count;
			dict.m_count = 0;
			dict.m_head = nullptr;
			return;
		}

		while (dict.m_head != nullptr) {
			Node* next = dict.m_head->m_next;
			if (!Insert(dict.m_head))
				delete dict.m_head;

			dict.m_head = next;
		}

		dict.m_head = nullptr;
		dict.m_count = 0;
	}//Присоединить словарь

	void Subtract(const Dictionary& dict)
	{
		Node* x = dict.m_head;

		while (x != nullptr) {
			Node* temp = m_head;
			Node* prev = nullptr;
			while (temp != nullptr && x->m_value > temp->m_value) {
				prev = temp;
				temp = temp->m_next;
			}
			if (temp != nullptr && x->m_value == temp->m_value) {
				if (m_head != temp) {
					prev->m_next = temp->m_next;
					delete temp;
					m_count--;
				}
				else {
					m_head = temp->m_next;
					delete temp;
					m_count--;
				}
			}
			x = x->m_next;
		}
	}//Вычести словарь

	friend Dictionary Intersect(const Dictionary& dict1, const Dictionary& dict2)
	{
		Dictionary newDict;
		Dictionary::Node* current = dict2.m_head;

		while (current != nullptr) {
			Dictionary::Node* temp = dict1.m_head;
			Dictionary::Node* prev = nullptr;
			while (temp != nullptr && current->m_value > temp->m_value) {
				prev = temp;
				temp = temp->m_next;
			}
			if (temp != nullptr && current->m_value == temp->m_value) {
				newDict.Insert(current->m_value);
			}
			current = current->m_next;
		}
		return newDict;
	}//Пересечение словарей

	friend std::ostream& operator<<(std::ostream& out, const Dictionary& dict)
	{
		if (dict.m_count == 0)
		{
			out << "\nСловарь пустой.\n";
			return out;
		}
		out << '\n';

		Dictionary::Node* current = dict.m_head;
		while (current != nullptr)
		{
			out << current->m_value << '\n';
			current = current->m_next;
		}

		out << '\n';
		return out;
	}//Оператор вывода

	~Dictionary()
	{
		if (m_count == 0)
			return;

		Node* current = nullptr;
		Node* next = m_head;

		while (next != nullptr)
		{
			current = next;
			next = next->m_next;
			delete current;
		}

		m_head = nullptr;
		m_count = 0;
	}//Деструктор
};

#pragma once

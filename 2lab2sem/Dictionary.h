#include <string>
#include <iostream>
#pragma once
class Dictionary
{
private:
	struct Node
	{
		Node* next_; //��������� �� ��������� �����
		std::string value_; //�����
		Node(std::string value, Node* next = nullptr) : value_(value), next_(next) { }
	};
	int count_; //������� ����
	Node* head_; //������ ����� ������

	void swap(Dictionary& other) noexcept;

	//������ � ��������� ���� ������
	Node* head() const {
		return head_;
	}

	int count() const
	{
		return count_;
	}

	//���������� ���� � ������ ������
	void insert(Node* x);

public:

	Dictionary() {};

	Dictionary(const Dictionary& src);

	Dictionary& operator=(const Dictionary& right);

	Dictionary& operator=(Dictionary&& right) noexcept;

	Dictionary(Dictionary&& other) noexcept;

	std::string headItem() const;

	std::string& headItem();

	void insert(std::string value);

	bool deleteHead();

	bool deleteItem(const std::string value);

	void deleteNode(Node* x);

	bool searchItem(std::string value);

	void outAll();

	void add(Dictionary& other);

	void remove(const Dictionary& other);

	~Dictionary();

	friend Dictionary Crossing(const Dictionary& list1, const Dictionary& list2);

};

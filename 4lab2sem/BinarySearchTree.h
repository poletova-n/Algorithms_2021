#pragma once


#include<iostream>
#include<stack>

template <class T>
class BinarySearchTree
{
private:
	struct Node {
		T key_; // значение ключа, содержащееся в узле
		Node* left_; // указатель на левое поддерево
		Node* right_; // указатель на правое поддерево
		Node* p_; // указатель на родителя !!! не используется
		// Конструктор узла
		Node(T key, Node* left = nullptr, Node* right = nullptr, Node* p = nullptr) :
			key_(key), left_(left), right_(right), p_(p) {}
	};
	Node* root_; // Указатель на корневой узел

	Node* iterativeSearchNode(const T& key) const {
		Node* cur = root_;
		while (cur != nullptr) {
			if (cur->key_ == key)
				return cur;
			if (key < cur->key_)
				cur = cur->left_;
			else
				cur = cur->right_;
		}
		return nullptr;
	}

	int getCount(const Node* node)const {
		if (node == nullptr) {
			return 0;
		}
		return(1+ getCount(node->left_) + getCount(node->right_));
	}

	int getHeight(const Node* node) const {
		int left, right, height = 0;
		if (node != nullptr) {
			left = getHeight(node->left_);
			right = getHeight(node->right_);
			height = ((left > right) ? left : right)+1 ;
		}
		return height ;
	}

	void inorderWalk(Node* node)const {
		if (node) {
			if (node->left_)
				inorderWalk(node->left_);
			std::cout << node->key_ << ' ';
			if (node->right_)
				inorderWalk(node->right_);
		}
	}

	void print(Node* node) const {
		std::cout << node->key_;
		if (!node->left_ && !node->right_)
			return;
		std::cout << '(';
		if (!node->left_)
			std::cout << ' ';
		else
			print(node->left_);
		std::cout << ',';
		if (!node->right_)
			std::cout << ' ';
		else
			print(node->right_);
		std::cout << ')';
	}

	void deleteTree(Node* root) {
		if (root) {
			deleteTree(root->left_);
			deleteTree(root->right_);
			delete root;
		}
	}

	Node* getMinNode(Node* node) {
		Node* cur = node;
		while (cur && cur->left_)
			cur = cur->left_;
		return cur;
	}
public:
	BinarySearchTree() :root_(nullptr) {}// "по умолчанию" создает пустое дерево
	BinarySearchTree(const BinarySearchTree<T>& scr) = delete;
	BinarySearchTree(BinarySearchTree<T>&& src) {
		root_ = src.root_;
		src.root_ = nullptr;
	}
	BinarySearchTree <T>& operator= (const BinarySearchTree <T>& src) = delete;
	BinarySearchTree <T>& operator= (BinarySearchTree <T>&& src) {
		delete(root_);
		root_ = src.root_;
		src.root_ = nullptr;
	}

	virtual ~BinarySearchTree() {
		deleteTree(root_);
		root_ = nullptr;
	}


	// 1.1 Функция поиска по ключу в бинарном дереве поиска
	bool iterativeSearch(const T& key) const {
		Node* cur = root_;
		while (cur != nullptr) {
			if (cur->key_ == key)
				return true;
			if (cur->key_ > key)
				cur = cur->left_;
			else
				cur = cur->right_;
		}
		return false;
	}

	// 2 Вставка нового элемента в дерево: true,если элемент добавлен; 
// false, если элемент уже был
	bool insert(const T& key) {
		if (iterativeSearch(key))
			return false; //если элемент найден false
		if (root_ == nullptr) {
			root_ = new Node(key, nullptr, nullptr, nullptr);
			return true;
		}
		Node* cur = root_;
		while (cur != nullptr) {
			if (key < cur->key_) {
				if (cur->left_)
					cur = cur->left_;
				else {
					cur->left_ = new Node(key, nullptr, nullptr, cur);
					return true;
				}
			}
			else {
				if (cur->right_)
					cur = cur->right_;
				else {
					cur->right_ = new Node(key, nullptr, nullptr, cur);
					return true;
				}
			}
		}
	}
	// 3.1 Удаление элемента из дерева, не нарушающее порядка элементов
// true,если элемент удален; false, если элемента не было
	bool deleteKey(const T& key) {
		Node* nodeToDelete = iterativeSearchNode(key);
		if (!nodeToDelete)//узел не найден
			return false;
		if (!nodeToDelete->left_ && !nodeToDelete->right_) {//если узел листок
			if (nodeToDelete->p_) {
				if (nodeToDelete->p_->left_ == nodeToDelete)
					nodeToDelete->p_->left_ = nullptr;
				else
					nodeToDelete->p_->right_ = nullptr;
			}
			else
				root_ = nullptr;
			delete nodeToDelete;
		}
		else if (nodeToDelete->left_ && !nodeToDelete->right_) {//если один левый наследник
			if (nodeToDelete->p_) {
				if (nodeToDelete->p_->left_ == nodeToDelete)
					nodeToDelete->p_->left_ = nodeToDelete->left_;
				else
					nodeToDelete->p_->right_ = nodeToDelete->left_;
			}
			else
				root_ = nodeToDelete->left_;
			delete nodeToDelete;
		}
		else if (!nodeToDelete->left_ && nodeToDelete->right_) {//если один правый наследник
			if (nodeToDelete->p_) {
				if (nodeToDelete->p_->left_ == nodeToDelete)
					nodeToDelete->p_->left_ = nodeToDelete->right_;
				else
					nodeToDelete->p_->right_ = nodeToDelete->right_;
			}
			else
				root_ = nodeToDelete->right_;
			delete nodeToDelete;
		}
		else {
			T replaceKey = getMinNode(nodeToDelete->right_)->key_;
			deleteKey(replaceKey);
			nodeToDelete->key_ = replaceKey;
		}
		return true;
	}
	// 4.1 Печать строкового изображения дерева в выходной поток out
	void printTree() const {
		if (root_) {
			std::cout << '\n';
			print(root_);
			std::cout << '\n';
		}
		else
			std::cout << "\n пустое дерево \n";
	}
	// 5.1 Определение количества узлов дерева
	int getCount() const {
		if (root_)
			return getCount(root_);
		else
			return 0;
	}
	// 6.1 Определение высоты дерева
	int getHeight() const {
		if (root_) {
		 return getHeight(root_)-1;
		}
		else return 0;
	}
	// 7 Инфиксный обход дерева (итеративный) 
	void iterativeInorderWalk() const {
		std::stack<Node*>stack;
		Node* cur = root_;
		while (stack.size() != 0 || cur) {
			if (cur) {
				stack.push(cur);
				cur = cur->left_;
			}
			else {
				cur = stack.top();
				stack.pop();
				std::cout << cur->key_ << ' ';
				cur = cur->right_;
			}
		}
	}

	// 8.1 Инфиксный обход дерева (рекурсивный) 
	void recursiveinorderWalk() const {
		inorderWalk(root_);
	}
};

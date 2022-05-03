#ifndef __BINARY_SEARCH_TREE_H
#define __BINARY_SEARCH_TREE_H

#include <iostream>

//
// Определение шаблона класса BinarySearchTree
//
template <class T>
class BinarySearchTree
{
public:

	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree<T> & scr) = delete;
	BinarySearchTree(BinarySearchTree<T>&& scr) noexcept;

	BinarySearchTree <T>& operator= (const BinarySearchTree <T>& src) = delete;
	BinarySearchTree <T>& operator= ( BinarySearchTree <T>&& src) noexcept;

	BinarySearchTree <T>& operator+ (int x) noexcept 
	{
		std::cout << "operator+" << std::endl;
		return *this;
	};

	// Деструктор освобождает память, занятую узлами дерева
	virtual ~BinarySearchTree();
	
	// Печать строкового изображения дерева в выходной поток out
	void print(std::ostream& out) const;
	
	// Функция поиска по ключу в бинарном дереве поиска
	bool iterativeSearch(const T& key) const;
	
	// Вставка нового элемента в дерево:
    // true,если элемент добавлен; false, если элемент уже был
	bool insert(const T& key);
	
	// Удаление элемента из дерева, не нарушающее порядка элементов
	// true,если элемент удален; false, если элемента не было
	bool deleteKey(const T& key);
	
	// Определение количества узлов дерева
	int getCount() const;
	
	// Определение высоты дерева
	int getHeight() const;
	
	// Сравнение деревьев: true, если все узлы деревьев одинаковые
	bool operator== (const BinarySearchTree <T>& src);

	// Инфиксный обход дерева (итеративный) 
	void iterativeInorderWalk () const;

	// Инфиксный обход дерева (рекурсивный) 
	void inorderWalk() const;
	

private:

	// Описание структуры узла со ссылками на детей и родителя
	template <class T>
	struct Node {
		T  key_;         // значение ключа, содержащееся в узле
		Node<T>* left_;     // указатель на левое поддерево
		Node<T>* right_;    // указатель на правое поддерево
		Node<T>* p_;        // указатель на  родителя 
						 
		Node(T key, Node* left = nullptr, Node* right = nullptr, Node* p = nullptr) :
			key_(key), left_(left), right_(right), p_(p)
		{  }
	};

	// Дерево реализовано в виде указателя на корневой узел.
	Node<T>* root_;

	void swap(BinarySearchTree <T>& left, BinarySearchTree <T>& right);

	// Функция поиска адреса узла по ключу в бинарном дереве поиска
	Node<T>* iterativeSearchNode(const T& key) const;
	
	// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
	// Рекурсивные функции, представляющие тела основных интерфейсных методов
	// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 

	// Рекурсивная функция для освобождения памяти
	void deleteSubtree(Node<T>* node);
	
	// Рекурсивная функция определения количества узлов дерева
	int getCountSubTree(const Node<T>* node) const;

	// Рекурсивная функция определения высоты дерева
	int getHeightSubTree(Node<T>* node) const;

	// Рекурсивная функция для вывода изображения дерева в выходной поток
	void printNode(std::ostream& out, Node<T>* root) const;

	// Рекурсивная функция для организации обхода узлов дерева.
	void inorderWalk(Node<T>* node) const;

}; // конец шаблона класса TreeBinarySearchTree



    // Конструктор "по умолчанию" создает пустое дерево
	template <class T>
	BinarySearchTree<T>::BinarySearchTree(): root_(nullptr)
	{
		std::cout << "constructor" << std::endl;
	}
	// ---------------------------------------------------------------------------------------------------------------------------------------------------------
	template <class T>
	BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T>&& scr)noexcept: root_(nullptr)
	{
		// ???
		std::cout << "constructor &&" << std::endl;
		swap(*this, scr); // теперь scr - пустое дерево, уничтожается, кк временный объект
	}


	// .........................................................................

	// Деструктор освобождает память, занятую узлами дерева
	template <class T>
	BinarySearchTree<T>::~BinarySearchTree()
	{
		deleteSubtree(root_);
	}
	// Рекурсивная функция для освобождения памяти
	template <class T>
	void BinarySearchTree<T>::deleteSubtree(Node<T>* node)
	{
		if(node->left_ != nullptr) deleteSubtree(node->left_);
        if(node->right_ != nullptr) deleteSubtree(node->right_);
        delete node;
	}
	 
	template <class T>
	void BinarySearchTree<T>::swap(BinarySearchTree <T>& left, BinarySearchTree <T>& right)
	{
		left.root_ == std::move(right.root_);
        right.root_ == std::move(left.root_);
		std::swap(left.root_, right.root_);
	}

	// .........................................................................
	// Печать строкового изображения дерева в выходной поток out +
	template <class T>
	void BinarySearchTree<T>::print(std::ostream& out) const
	{
		printNode(out, root_);
		out << std::endl;
	}
	// Рекурсивная функция для вывода изображения дерева в выходной поток +
	template <class T>
	void BinarySearchTree<T>::printNode(std::ostream& out, Node<T>* root) const
	{
		// Изображение дерева заключается в круглые скобки.
		out << '(';
		if (root != nullptr) {
			// Для узлов дерева должна быть определена (или переопределена)
			// операция вывода в выходной поток <<
			out << root->key_;
			printNode(out, root->left_);
			printNode(out, root->right_);
		}
		out << ')';
	}
	// .........................................................................
	
	// Функция поиска по ключу в бинарном дереве поиска +
	template <class T>
	bool BinarySearchTree<T>::iterativeSearch(const T& key)  const
	{
		return (iterativeSearchNode(key) != nullptr);
	}
	// Функция поиска адреса узла по ключу в бинарном дереве поиска +
	template <class T>
	BinarySearchTree<T>::Node<T>* BinarySearchTree<T>::iterativeSearchNode(const T& key) const
	{
        Node<T>* node = this->root_;
        while(node != nullptr){
            if(node->key_ == key) return node;
            if(node->key_ > key){
                if(node->right_ == nullptr) break;
                node = node->right_;
            }
            else{
                if(node->left_ == nullptr) break;
                node = node->left_;
            }
        }
		return nullptr;
	}
	// .........................................................................
	
	// Вставка нового элемента в дерево:
	// true,если элемент добавлен; false, если элемент уже был

	template <class T>
	bool BinarySearchTree<T>::insert(const T& key)
	{
        Node<T>* node = this->root_;
		while(node != nullptr){
            if(node->key_ == key) return false;
            if(node->key_ > key){
                if(node->right_ == nullptr) {
                    node->right_ = new Node<T>(key, nullptr, nullptr, node);
                    return true;
                }
                else{
                    node = node->right_;
                }
            }
            else{
                if(node->left_ == nullptr) {
                    node->left_ = new Node<T>(key, nullptr, nullptr, node);
                    return true;
                }
                else{
                    node = node->left_;
                }
            }
        }
        this->root_ = new Node<T>(key, node, node, node);
		return true; // ??? заменить при реализации
	}

	// Удаление элемента из дерева, не нарушающее порядка элементов
	template <class T>
	bool BinarySearchTree<T>::deleteKey(const T& key)
	{
		// . . . 
	}
	// .........................................................................
	
	// Определение количества узлов дерева +
	template <class T>
	int BinarySearchTree<T>::getCount() const
	{
		return getCountSubTree(this->root_);
	}
	// Рекурсивная функция определения количества узлов дерева +
	template <class T>
	int BinarySearchTree<T>::getCountSubTree(const Node<T>* node) const
	{
		if (node == nullptr)
			return 0;
		return (1 + getCountSubTree(node->left_) +
			getCountSubTree(node->right_));
	}
	// .........................................................................
	
	// Определение высоты дерева +
	template <class T>
	int BinarySearchTree<T>::getHeight() const
	{
		return getHeightSubTree(this->root_);
	}
	// Рекурсивная функция определения высоты дерева +
	template <class T>
	int BinarySearchTree<T>::getHeightSubTree(Node<T>* node) const
	{
        if(node == nullptr) return 0;
        if(getHeightSubTree(node->left_) > getHeightSubTree(node->right_)) return getHeightSubTree(node->left_) + 1;
		return getHeightSubTree(node->right_) + 1;
	}
	
	// .........................................................................

	// Инфиксный обход дерева (рекурсивный)  +
	template <class T>
	void BinarySearchTree<T>::inorderWalk() const
	{
		inorderWalk(this->root_);
	}
	// Рекурсивная функция для организации обхода узлов дерева. +
	template <class T>
	void BinarySearchTree<T>::inorderWalk(Node<T>* node) const
	{
        if(node != nullptr) {
            inorderWalk(node->left_);
            inorderWalk(node->right_);
        }
	}
	// Инфиксный обход дерева (итеративный) 
	template <class T>
	void BinarySearchTree<T>::iterativeInorderWalk() const
	{
		// ??? 
	}
	// .........................................................................

	// Сравнение деревьев: true, если все узлы деревьев одинаковые
	template <class T>
	bool BinarySearchTree<T>::operator== (const BinarySearchTree <T>& src)
	{
		// ???
	}
	

	template <class T>
	BinarySearchTree <T>& BinarySearchTree<T>:: operator= (BinarySearchTree <T>&& src) noexcept
	{
		std::cout << "operator=&&" << std::endl;
		swap(*this, src);
		return *this;
	}



#endif

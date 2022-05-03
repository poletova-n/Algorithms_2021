#ifndef __BINARY_SEARCH_TREE_H
#define __BINARY_SEARCH_TREE_H

#include <iostream>

//
// ����������� ������� ������ BinarySearchTree
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

	// ���������� ����������� ������, ������� ������ ������
	virtual ~BinarySearchTree();
	
	// ������ ���������� ����������� ������ � �������� ����� out
	void print(std::ostream& out) const;
	
	// ������� ������ �� ����� � �������� ������ ������
	bool iterativeSearch(const T& key) const;
	
	// ������� ������ �������� � ������:
    // true,���� ������� ��������; false, ���� ������� ��� ���
	bool insert(const T& key);
	
	// �������� �������� �� ������, �� ���������� ������� ���������
	// true,���� ������� ������; false, ���� �������� �� ����
	bool deleteKey(const T& key);
	
	// ����������� ���������� ����� ������
	int getCount() const;
	
	// ����������� ������ ������
	int getHeight() const;
	
	// ��������� ��������: true, ���� ��� ���� �������� ����������
	bool operator== (const BinarySearchTree <T>& src);

	// ��������� ����� ������ (�����������) 
	void iterativeInorderWalk () const;

	// ��������� ����� ������ (�����������) 
	void inorderWalk() const;
	

private:

	// �������� ��������� ���� �� �������� �� ����� � ��������
	template <class T>
	struct Node {
		T  key_;         // �������� �����, ������������ � ����
		Node<T>* left_;     // ��������� �� ����� ���������
		Node<T>* right_;    // ��������� �� ������ ���������
		Node<T>* p_;        // ��������� ��  �������� 
						 
		Node(T key, Node* left = nullptr, Node* right = nullptr, Node* p = nullptr) :
			key_(key), left_(left), right_(right), p_(p)
		{  }
	};

	// ������ ����������� � ���� ��������� �� �������� ����.
	Node<T>* root_;

	void swap(BinarySearchTree <T>& left, BinarySearchTree <T>& right);

	// ������� ������ ������ ���� �� ����� � �������� ������ ������
	Node<T>* iterativeSearchNode(const T& key) const;
	
	// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
	// ����������� �������, �������������� ���� �������� ������������ �������
	// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 

	// ����������� ������� ��� ������������ ������
	void deleteSubtree(Node<T>* node);
	
	// ����������� ������� ����������� ���������� ����� ������
	int getCountSubTree(const Node<T>* node) const;

	// ����������� ������� ����������� ������ ������
	int getHeightSubTree(Node<T>* node) const;

	// ����������� ������� ��� ������ ����������� ������ � �������� �����
	void printNode(std::ostream& out, Node<T>* root) const;

	// ����������� ������� ��� ����������� ������ ����� ������.
	void inorderWalk(Node<T>* node) const;

}; // ����� ������� ������ TreeBinarySearchTree



    // ����������� "�� ���������" ������� ������ ������
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
		swap(*this, scr); // ������ scr - ������ ������, ������������, �� ��������� ������
	}


	// .........................................................................

	// ���������� ����������� ������, ������� ������ ������
	template <class T>
	BinarySearchTree<T>::~BinarySearchTree()
	{
		deleteSubtree(root_);
	}
	// ����������� ������� ��� ������������ ������
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
	// ������ ���������� ����������� ������ � �������� ����� out +
	template <class T>
	void BinarySearchTree<T>::print(std::ostream& out) const
	{
		printNode(out, root_);
		out << std::endl;
	}
	// ����������� ������� ��� ������ ����������� ������ � �������� ����� +
	template <class T>
	void BinarySearchTree<T>::printNode(std::ostream& out, Node<T>* root) const
	{
		// ����������� ������ ����������� � ������� ������.
		out << '(';
		if (root != nullptr) {
			// ��� ����� ������ ������ ���� ���������� (��� ��������������)
			// �������� ������ � �������� ����� <<
			out << root->key_;
			printNode(out, root->left_);
			printNode(out, root->right_);
		}
		out << ')';
	}
	// .........................................................................
	
	// ������� ������ �� ����� � �������� ������ ������ +
	template <class T>
	bool BinarySearchTree<T>::iterativeSearch(const T& key)  const
	{
		return (iterativeSearchNode(key) != nullptr);
	}
	// ������� ������ ������ ���� �� ����� � �������� ������ ������ +
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
	
	// ������� ������ �������� � ������:
	// true,���� ������� ��������; false, ���� ������� ��� ���

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
		return true; // ??? �������� ��� ����������
	}

	// �������� �������� �� ������, �� ���������� ������� ���������
	template <class T>
	bool BinarySearchTree<T>::deleteKey(const T& key)
	{
		// . . . 
	}
	// .........................................................................
	
	// ����������� ���������� ����� ������ +
	template <class T>
	int BinarySearchTree<T>::getCount() const
	{
		return getCountSubTree(this->root_);
	}
	// ����������� ������� ����������� ���������� ����� ������ +
	template <class T>
	int BinarySearchTree<T>::getCountSubTree(const Node<T>* node) const
	{
		if (node == nullptr)
			return 0;
		return (1 + getCountSubTree(node->left_) +
			getCountSubTree(node->right_));
	}
	// .........................................................................
	
	// ����������� ������ ������ +
	template <class T>
	int BinarySearchTree<T>::getHeight() const
	{
		return getHeightSubTree(this->root_);
	}
	// ����������� ������� ����������� ������ ������ +
	template <class T>
	int BinarySearchTree<T>::getHeightSubTree(Node<T>* node) const
	{
        if(node == nullptr) return 0;
        if(getHeightSubTree(node->left_) > getHeightSubTree(node->right_)) return getHeightSubTree(node->left_) + 1;
		return getHeightSubTree(node->right_) + 1;
	}
	
	// .........................................................................

	// ��������� ����� ������ (�����������)  +
	template <class T>
	void BinarySearchTree<T>::inorderWalk() const
	{
		inorderWalk(this->root_);
	}
	// ����������� ������� ��� ����������� ������ ����� ������. +
	template <class T>
	void BinarySearchTree<T>::inorderWalk(Node<T>* node) const
	{
        if(node != nullptr) {
            inorderWalk(node->left_);
            inorderWalk(node->right_);
        }
	}
	// ��������� ����� ������ (�����������) 
	template <class T>
	void BinarySearchTree<T>::iterativeInorderWalk() const
	{
		// ??? 
	}
	// .........................................................................

	// ��������� ��������: true, ���� ��� ���� �������� ����������
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

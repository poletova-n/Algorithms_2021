#ifndef ALGORITHMS_2021_BINARYSEARCHTREE_H
#define ALGORITHMS_2021_BINARYSEARCHTREE_H

#include <iostream>
#include "ostream"
#include <stack>

template <class T>
class BinarySearchTree
{
private:

    template <class T>
    struct Node {
        T key_; // значение ключа, содержащееся в узле
        Node<T> *left_; // указатель на левое поддерево
        Node<T> *right_; // указатель на правое поддерево
        Node<T> *p_; // указатель на родителя !!! не используется
        // Конструктор узла
        explicit Node(T key, Node *p =nullptr, Node *left = nullptr, Node *right= nullptr):
                key_(key), p_(p), left_ (left), right_(right)
        { }
    };
    Node<T> *root_;

// 1.2 Функция поиска адреса узла по ключу в бинарном дереве поиска
    Node<T>* iterativeSearchNode(const T& key) const{
        Node<T>* temp = root_;
        while(temp != nullptr){
            if(temp->key_ == key) return temp;
            if(temp->key_ < key){
                if(temp->right_ == nullptr){
                    return nullptr;
                }else{
                    temp = temp->right_;
                }
            }
            else{
                if(temp->left_ == nullptr){
                    return nullptr;
                }else{
                    temp = temp->left_;
                }
            }
        }
        return nullptr;
    };

// 4.2 Рекурсивная функция для вывода изображения дерева в выходной поток
    void printNode(std::ostream& out, Node<T>* root) const{
        out << "(" ;
        out << root->key_;
        if (root->left_ != nullptr) { printNode(out, root->left_); }
        if (root->right_ != nullptr) { printNode(out, root->right_); }
        out << ")";
    };

// 5.2 Рекурсивная функция определения количества узлов дерева
    int getCount(const Node<T>* node) const{
        if(node == nullptr) return 0;
        else{ return getCount(node->right_) + getCount(node->left_) + 1; }
    };

// 6.2 Рекурсивная функция определения высоты дерева
    int getHeight(const Node<T>* node) const{
        if(node == nullptr) return 0;
        return std::max(getHeight(node->right_), getHeight(node->left_)) + 1;
    };

// 8.2 Рекурсивная функция для организации обхода узлов дерева.
    void inorderWalk(Node<T>* node) const{
        if(node == nullptr) return;
        inorderWalk(node->left_);
        std::cout << node->key_ << " ";
        inorderWalk(node->right_);
    };

    void clearTree(Node<T>* node){
        if(node == nullptr) return;
        clearTree(node->right_);
        clearTree(node->left_);
        delete node;
    }


public:
    BinarySearchTree(){
        root_ = nullptr;
    }

    BinarySearchTree(const BinarySearchTree<T> & scr) = delete;

    BinarySearchTree(BinarySearchTree<T>&& src) noexcept : root_(src.root_)   {
        src.root_ = nullptr;
    };

    BinarySearchTree <T>& operator= (const BinarySearchTree <T>& src) = delete;

    BinarySearchTree <T>& operator= (BinarySearchTree <T>&& src) noexcept{
        if(&src == this) return *this;

        clearTree(root_);

        root_ = src.root_;
        src.root_ = nullptr;
        return *this;
    } ;

    virtual ~BinarySearchTree() = default;

// 1.1 Функция поиска по ключу в бинарном дереве поиска
    bool iterativeSearch(const T& key) const{
        return iterativeSearchNode(key) != nullptr;
    }

// 2 Вставка нового элемента в дерево: true,если элемент добавлен;
// false, если элемент уже был
    bool insert(const T& key){
        Node<T>* temp = root_;
        while(temp != nullptr){
            if(temp->key_ == key) return false;
            if(temp->key_ < key){
                if(temp->right_ == nullptr){
                    temp->right_ = new Node<T>(key, temp);
                    return true;
                }else{
                    temp = temp->right_;
                }
            }
            else{
                if(temp->left_ == nullptr){
                    temp->left_ = new Node<T>(key, temp);
                    return true;
                }else{
                    temp = temp->left_;
                }
            }
        }
        this->root_ = new Node<T>(key);
        return true;
    };

// 3.1 Удаление элемента из дерева, не нарушающее порядка элементов
// true,если элемент удален; false, если элемента не было
    bool deleteKey(const T& key){

        Node<T>* nodeToDelete = iterativeSearchNode(key);

        if(nodeToDelete == nullptr) return false;

        if(nodeToDelete->right_ == nullptr && nodeToDelete->left_ == nullptr) {
            if(nodeToDelete->p_->key_ < nodeToDelete->key_){
                nodeToDelete->p_->right_ = nullptr;
            }else{
                nodeToDelete->p_->left_ = nullptr;
            }
            nodeToDelete = nullptr;
            return true;
        }
        if(nodeToDelete->right_ == nullptr && nodeToDelete->left_ != nullptr) {
            if(nodeToDelete->p_->key_ < nodeToDelete->key_){
                nodeToDelete->p_->right_ = nodeToDelete->left_;
            }else{
                nodeToDelete->p_->left_ = nodeToDelete->left_;
            }
            return true;
        }
        if(nodeToDelete->right_ != nullptr && nodeToDelete->left_ == nullptr) {
            if(nodeToDelete->p_->key_ < nodeToDelete->key_){
                nodeToDelete->p_->right_ = nodeToDelete->right_;
            }else{
                nodeToDelete->p_->left_ = nodeToDelete->right_;
            }
            return true;
        }
        else{
            bool isFirst = true;

            Node<T>* temp = nodeToDelete->right_;

            while(temp->left_ != nullptr){
                temp = temp->left_;
                isFirst = false;
            }

            nodeToDelete->key_ = temp->key_;
            if(temp->right_ == nullptr){
                if(isFirst){temp->p_->right_ = nullptr;}
                else{
                    temp->p_->left_ = nullptr;
                }
            }else{
                temp->right_->p_ = temp->p_;
                temp->p_->left_ = temp->right_;
            }


            delete temp;
            return true;
        }
    };

// 4.1 Печать строкового изображения дерева в выходной поток out
    void print(std::ostream& out) const{
        if(root_ == nullptr) std::cout << "Tree is empty" << std::endl;
        else{printNode(out,root_);
        std::cout << std::endl;}
    };

// 5.1 Определение количества узлов дерева
    [[nodiscard]] int getCount() const{
        return getCount(root_);
    };

// 6.1 Определение высоты дерева
    [[nodiscard]] int getHeight() const{
        if(root_ == nullptr) return 0;
        return std::max(getHeight(root_->right_), getHeight(root_->left_)) + 1;
    };

// 7 Инфиксный обход дерева (итеративный)
    void iterativeInorderWalk() const{
        auto * stack = new std::stack<Node<T>*>;
        Node<T>* temp = root_;
        while( temp != nullptr || !stack->empty()){
            if(temp != nullptr){
                stack->push(temp);
                temp = temp->left_;
            } else{
                temp = stack->top();
                stack->pop();
                std::cout << temp->key_ << " ";
                temp = temp->right_;
            }
        }
        delete stack;

        std::cout << std::endl;
    };

// 8.1 Инфиксный обход дерева (рекурсивный)
    void inorderWalk() const{
        inorderWalk(root_);
        std::cout << std::endl;
    };
};

#endif

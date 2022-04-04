//
// Created by Foko on 04.04.2022.
//

#ifndef ONE_WAY_LIST_BINARYSEARCHTREE_H
#define ONE_WAY_LIST_BINARYSEARCHTREE_H

#include <iostream>

template <typename T> class BinarySearchTree {
private:
    struct Node {
        Node* right;
        Node* left;
        Node* parent = nullptr;
        T key;

        explicit Node (T node_key, Node* node_parent = nullptr) {
            key = node_key;
            parent = node_parent;
            left = nullptr;
            right = nullptr;
        }

        ~Node () = default;

        void deleteNode () {
            if (right != nullptr && left != nullptr) {
                Node* item = right;
                while (item->left != nullptr)
                    item = item->left;
                key = item->key;
                if (right == item) // исключительный вариант
                    right = nullptr;
                delete item;
            } else if (right != nullptr && left == nullptr) {
                key = right->key;
                delete right;
                right = nullptr;
            } else if (right == nullptr && left != nullptr) {
                key = left->key;
                delete left;
                left = nullptr;
            } else
                if (parent->left != nullptr && parent->left->key == key) {
                    parent->left == nullptr;
                } else if (parent->left != nullptr && parent->left->key == key) {
                    parent->right == nullptr;
                }
                delete this;
        }

        size_t getDepth(size_t current_depth) {
            if (right != nullptr && left != nullptr) {
                return std::max(right->getDepth(++current_depth), left->getDepth(++current_depth));
            } else if (right != nullptr) {  // здесь видимо существование одного потомка является исключительным случаем
                return right->getDepth(++current_depth);   // возможно стоит сразу возвращать ++current_depth
            } else if (left != nullptr) {
                return left->getDepth(++current_depth);
            } else {
                return current_depth;
            }
        }
    };

    Node* root_;
    size_t size;

    Node* searchNode(T search_key) {
        Node* item = root_;
        while (item != nullptr && item->key != search_key) {
            if (search_key < item->key) {
                item = item->left;
            } else {
                item = item->right;
            }
        }
        return item;
    }

public:
    BinarySearchTree () {
        size = 0;
    }

    explicit BinarySearchTree (T root_key) {
        root_ = new Node(root_key);
        size = 1;
    }

    BinarySearchTree (const BinarySearchTree&) = delete;

    BinarySearchTree (BinarySearchTree&& tree)  noexcept {
        root_ = tree.root_;
        size = tree.size;

        tree.root_ = nullptr;
        size = 0;
    }

    ~BinarySearchTree () {
        delete root_;
    }

    BinarySearchTree& operator=(const BinarySearchTree&) = delete;

    BinarySearchTree& operator=(BinarySearchTree&& tree)  noexcept {
        if (this == &tree) {
            return *this;
        }
        root_ = tree.root_;
        size = tree.size;

        tree.root_ = nullptr;
        tree.size = 0;
    }

    void insert (T new_key) {
        Node *item = root_;
        while (item != nullptr && new_key != item->key) {
            if (new_key < item->key) {
                if (item->left == nullptr) {
                    item->left = new Node(new_key, item);
                    ++size;
                }
                item = item->left;
            } else {
                if (item->right == nullptr) {
                    item->right = new Node(new_key, item);
                    ++size;
                }
                item = item->right;
            }
        }
        if (item == root_)
            root_ = new Node(new_key);
    }

    inline bool search (T search_key) {
        return searchNode(search_key) != nullptr;
    }

    bool deleteNode (T delete_key) {
        Node* item = searchNode(delete_key);
        if (item) {
            item->deleteNode();
            return true;
        } else
            return false;
    }
};


#endif //ONE_WAY_LIST_BINARYSEARCHTREE_H

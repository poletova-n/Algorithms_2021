//
// Created by Foko on 04.04.2022.
//

#ifndef ONE_WAY_LIST_BINARYSEARCHTREE_H
#define ONE_WAY_LIST_BINARYSEARCHTREE_H

#include <iostream>
#include <stack>

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

        }

        std::string print() {
            std::string result = std::to_string(key);
            if (left != nullptr && right != nullptr) {
                result += "(";
                result += left->print();
                result += ",";
                result += right->print();
                result += ")";
            } else if (right == nullptr && left != nullptr) {
                result += "(";
                result += left->print();
                result += ")";
            } else if (right != nullptr && left == nullptr) {
                result += "(";
                result += right->print();
                result += ")";
            }
            return result;
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

        inline size_t getSize () {
            return ((left != nullptr) ? left->getCount : 0) + ((right != nullptr) ? right->getCount : 0) + 1;
        }

        void recursiveInfix () {
            if (left) {
                left->recursiveInfix();
            }
            std::cout << key << "\n";
            if (right) {
                right->recursiveInfix();
            }
        }
    };

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

    Node* root_;
    size_t size;

public:
    BinarySearchTree () {
        size = 0;
    }

    explicit BinarySearchTree (T root_key) {
        root_ = new Node(root_key);
        size = 1;
    }

    ~BinarySearchTree () {
        delete root_->right;
        delete root_->left;
        delete root_;
    }

    BinarySearchTree (const BinarySearchTree&) = delete;

    BinarySearchTree (BinarySearchTree&& tree)  noexcept {
        root_ = tree.root_;
        size = tree.size;

        tree.root_ = nullptr;
        size = 0;
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
        if (item == nullptr)
            root_ = new Node(new_key);
    }

    inline bool search (T search_key) {
        return searchNode(search_key) != nullptr;
    }

    std::string print() {
        if (root_) {
            return root_->print();
        } else {
            return "";
        }
    }

    bool deleteNode (T delete_key) {
        Node* item = searchNode(delete_key);
        Node* parent = item->parent;

        if (item == nullptr) {
            return false;
        }

        if (item->left == nullptr && item->right == nullptr) { //частный случай удаления листа
            if (parent == nullptr) { // удаление корня
                delete root_;
                root_ = nullptr;
            } else { // удаление остальных вариантов
                if (parent->left == item) {
                    parent->left == nullptr;
                } else if (parent->right == item) {
                    parent->right == nullptr;
                }
                delete item;
             }
        } else if (item->left != nullptr && item->right != nullptr) { // удаление центрального
            Node* replacement = item->right; // поиск минимально большего значения
            while (replacement->left != nullptr) { // спуск вниз
                replacement = replacement->left;
            }

            if (replacement->parent->left == replacement) {
                replacement->parent->left = nullptr; // удаление минимально большего
            } else {
                replacement->parent->right = nullptr;
            }

            replacement->left = item->left;
            replacement->right = item->right;
            replacement->parent = parent;

            if (parent != nullptr) {
                if (parent->left == item) {
                    parent->left = replacement;
                } else {
                    parent->right = replacement;
                }
                delete item;
            } else {
                delete root_;
                root_ = replacement;
            }
        } else {
            Node* replacement = item->left != nullptr ? item->left : item->right;
            replacement->parent = parent;
            if (parent != nullptr) {
                if (parent->right == item) {
                    parent->right = replacement;
                } else {
                    parent->left = replacement;
                }
            } else {
                delete root_;
                root_ = replacement;
            }
        }
        return true; // ппц какой-то
    }

    void iterativeInfix() {
        std::stack<Node*> stack;
        Node* item = root_;
        while (!stack.empty() or item != nullptr) {
            if (item) {
                stack.push(item);
                item = item->left;
            } else {
                item = stack.top();
                stack.pop();
                std::cout << item->key << "\n";
                item = item->right;
            }
        }
    }

    void recursiveInfix() {
        root_->recursiveInfix();
    }
};


#endif //ONE_WAY_LIST_BINARYSEARCHTREE_H

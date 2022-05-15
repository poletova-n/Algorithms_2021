//
// Created by Foko on 04.04.2022.
//

#include "BinarySearchTree.h"
#include "CircleQueue.h"

template<typename T>
BinarySearchTree<T>::Node::Node(T node_key, BinarySearchTree::Node *node_parent) {
    key = node_key;
    parent = node_parent;
    left = nullptr;
    right = nullptr;
}

template<typename T>
void BinarySearchTree<T>::Node::deleteNode() {

}

template<typename T>
std::string BinarySearchTree<T>::Node::print() {
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

template<typename T>
size_t BinarySearchTree<T>::Node::getDepth(size_t current_depth) {
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

template<typename T>
size_t BinarySearchTree<T>::Node::getSize() {
    return ((left != nullptr) ? left->getSize() : 0) + ((right != nullptr) ? right->getSize() : 0) + 1;
}

template<typename T>
void BinarySearchTree<T>::Node::recursiveInfix() {
    if (left) {
        left->recursiveInfix();
    }
    std::cout << key << "\n";
    if (right) {
        right->recursiveInfix();
    }
}

template<typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::searchNode(T search_key) {
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

template<typename T>
BinarySearchTree<T>::BinarySearchTree() {
    size = 0;
}

template<typename T>
BinarySearchTree<T>::BinarySearchTree(T root_key) {
    root_ = new Node(root_key);
    size = 1;
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    delete root_->right;
    delete root_->left;
    delete root_;
}

template<typename T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree &&tree) noexcept {
    root_ = tree.root_;
    size = tree.size;

    tree.root_ = nullptr;
    size = 0;
}

template<typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(BinarySearchTree &&tree) noexcept {
    if (this == &tree) {
        return *this;
    }
    root_ = tree.root_;
    size = tree.size;

    tree.root_ = nullptr;
    tree.size = 0;

    return *this;
}

template<typename T>
void BinarySearchTree<T>::insert(T new_key) {
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

template<typename T>
bool BinarySearchTree<T>::search(T search_key) {
    return searchNode(search_key) != nullptr;
}

template<typename T>
std::string BinarySearchTree<T>::print() {
    if (root_) {
        return root_->print();
    } else {
        return "";
    }
}

template<typename T>
bool BinarySearchTree<T>::deleteNode(T delete_key) {
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
                parent->left = nullptr;
            } else if (parent->right == item) {
                parent->right = nullptr;
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

template<typename T>
void BinarySearchTree<T>::iterativeInfix() {
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

template<typename T>
void BinarySearchTree<T>::recursiveInfix() {
    root_->recursiveInfix();
}

template<typename T>
void BinarySearchTree<T>::levelOrder() {
    CircleQueue<Node*> queue(size / 2 + 1);
    queue.enQueue(root_);
    while (!queue.isEmpty()) {
        Node* item = queue.deQueue();
        std::cout << item->key << "\n";
        if (item->left) {
            queue.enQueue(item->left);
        }
        if (item->right) {
            queue.enQueue(item->right);
        }
    }
}

template<typename T>
bool BinarySearchTree<T>::compare(BinarySearchTree<T> &other) {

    if (other.size != size){
        return false;
    }

    CircleQueue<Node*> queue(size);
    std::stack<Node*> stack;

    Node *item = root_;
    while (item != nullptr || !stack.empty()) {
        if (item != nullptr) {
            stack.push(item);
            item = item->left;
        } else {
            item = stack.top();
            stack.pop();
            queue.enQueue(item);
            item = item->right;
        }
    }

    item = other.root_;
    while (item != nullptr || !stack.empty()) {
        if (item != nullptr) {
            stack.push(item);
            item = item->left;
        } else {
            item = stack.top();
            stack.pop();
            if (queue.deQueue()->key != item->key) {
                return false;
            }
            item = item->right;
        }
    }
    return true;
}

template<typename T>
void BinarySearchTree<T>::intersection(BinarySearchTree<T> &other) {
    CircleQueue<Node*> queue(size);
    std::stack<Node*> stack;

    Node *item = root_;
    while (item != nullptr || !stack.empty()) {
        if (item != nullptr) {
            stack.push(item);
            item = item->left;
        } else {
            item = stack.top();
            stack.pop();
            queue.enQueue(item);
            item = item->right;
        }
    }


    item = other.root_;
    while (item != nullptr || !stack.empty()) {
        if (queue.isEmpty()) {
            std::cout << "END";
            break;
        }
        if (item != nullptr) {
            stack.push(item);
            item = item->left;
        } else {
            item = stack.top();
            stack.pop();
            Node* temp = queue.deQueue();
            while(item->key < temp->key && !stack.empty()) {
                item = stack.top();
                stack.pop();
            }
            if (temp->key == item->key) {
                std::cout << item->key << " ";
            }
            item = item->right;
        }
    }

    std::cout << std::endl;
}

template class BinarySearchTree<int>;
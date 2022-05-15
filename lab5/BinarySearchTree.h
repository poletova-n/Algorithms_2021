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

        explicit Node (T node_key, Node* node_parent = nullptr);

        Node () {}

        ~Node () = default;

        void deleteNode ();

        std::string print();

        size_t getDepth(size_t current_depth);

        inline size_t getSize ();

        void recursiveInfix ();
    };

    Node* searchNode(T search_key);

    Node* root_;
    size_t size;

public:
    BinarySearchTree ();

    explicit BinarySearchTree (T root_key);

    ~BinarySearchTree ();

    BinarySearchTree (const BinarySearchTree&) = delete;

    BinarySearchTree (BinarySearchTree&& tree)  noexcept;

    BinarySearchTree& operator=(const BinarySearchTree&) = delete;

    BinarySearchTree& operator=(BinarySearchTree&& tree)  noexcept;

    void insert (T new_key);

    inline bool search (T search_key);

    std::string print();

    bool deleteNode (T delete_key);

    void iterativeInfix();

    void recursiveInfix();

    void levelOrder ();

    bool compare(BinarySearchTree<T> &other);

    void intersection(BinarySearchTree<T> &other);
};



#endif //ONE_WAY_LIST_BINARYSEARCHTREE_H

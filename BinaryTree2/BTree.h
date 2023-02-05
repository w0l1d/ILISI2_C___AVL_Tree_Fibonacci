//
// Created by W0L1D on 1/10/2023.
//

#ifndef ILISI2_C___BINARYTREE2_BTREE_H
#define ILISI2_C___BINARYTREE2_BTREE_H
#include <iostream>

using namespace std;

template<class T>
class BTree {
private:
    struct Node {
        T data;
        int height;
        Node *left, *right;

        Node(T data) : data(data), height(1), left(nullptr), right(nullptr) { }
    };

    Node* root;
    long long _size;

    int getHeight(Node* node) {
        if (!node) {
            return 0;
        }
        return node->height;
    }

    int getBalance(Node* node) {
        if (!node) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    Node* rotateRight(Node* node) {
        Node* left = node->left;
        Node* right = left->right;

        left->right = node;
        node->left = right;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        left->height = max(getHeight(left->left), getHeight(left->right)) + 1;

        return left;
    }

    Node* rotateLeft(Node* node) {
        Node* right = node->right;
        Node* left = right->left;

        right->left = node;
        node->right = left;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        right->height = max(getHeight(right->left), getHeight(right->right)) + 1;

        return right;
    }

    Node* insert(Node* node, T &data) {
        if (!node) {
            return new Node(data);
        }

        if (data < node->data) {
            node->left = insert(node->left, data);
        } else if (data > node->data) {
            node->right = insert(node->right, data);
        } else {
            return node;
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        if (balance > 1 && data < node->left->data) {
            return rotateRight(node);
        }

        if (balance < -1 && data > node->right->data) {
            return rotateLeft(node);
        }

        if (balance > 1 && data > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && data < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }
    Node* search(Node* node, T &key) {
        if (!node) {
            return nullptr;
        }

        if (key == node->data) {
            return node;
        }

        if (key < node->data) {
            return search(node->left, key);
        } else {
            return search(node->right, key);
        }
    }


    void destroy(Node* node) {
        if (!node) {
            return;
        }
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    BTree() : root(nullptr), _size(0) { }
    ~BTree() {
        destroy(root);
    }
    typedef struct Node Node;
    void insert(T &data) {
        _size++;
        root = insert(root, data);
    }
    Node* search(T &key) {
        return search(root, key);
    }
    long long size() {return _size;}
};


#endif //ILISI2_C___BINARYTREE2_BTREE_H


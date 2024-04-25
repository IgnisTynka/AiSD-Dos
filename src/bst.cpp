#include <cmath>
#include <iostream>

#include "../include/bst.h"

BST::BST() : Tree() {}

BST::~BST() {}

void BST::create(std::vector<int> data) {
    removeAll();
    for (int i = 0; i < data.size(); i++) {
        if (_root == nullptr) {
        _root = new Node(data[i]);
        } else {
         _insertValue(_root, data[i]);
        }
    }
}

void BST::_insertValue(Node* node, int data) {
    if (data < node->data) {
        if (node->left == nullptr) {
            node->left = new Node(data);
        } else {
            _insertValue(node->left, data);
        }
    } else {
        if (node->right == nullptr) {
            node->right = new Node(data);
        } else {
            _insertValue(node->right, data);
        }
    }
}

void BST::rebalance(int vineHeight) {
    Node* tempRoot = new Node(0);
    int vh = _vineHeight(_root) ;
    while (vh  != vineHeight) {
        vh = _vineHeight(_root);
    }

    int m =  pow(2, int(log2(vh + 1))) - 1;   

}


void BST::remove(int data) {
    
}

BST::Node* BST::_removeValue(Node* node, int data) {
    if (node == nullptr) {
        return nullptr;
    }
    if (data < node->data) {
        node->left = _removeValue(node->left, data);
        return node;
    } 
    if (data > node->data) {
        node->right = _removeValue(node->right, data);
        return node;
    } 
    if (node->left == nullptr && node->right == nullptr) {
        delete node;
        return nullptr;
    } 
    if (node->left == nullptr) {
        Node* right = node->right;
        delete node;
        return right;
    } 
    if (node->right == nullptr) {
        Node* left = node->left;
        delete node;
        return left;
    } 
    Node* min_right = node->right;
    Node* parent_min = node;
    while (min_right->left != nullptr) {
        parent_min = min_right;
        min_right = min_right->left;
    }
    node->data = min_right->data;
    if (parent_min->left == min_right) {
        parent_min->left = min_right->right;
    } else {
        parent_min->right = min_right->right;
    }
    delete min_right;
    return node;
}

BST::Node* BST::_rotateLeft(Node* node) {
    if (!node || !node->right) return node;
    
    Node* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    return newRoot;
}

BST::Node* BST::_rotateRight(Node* node) {
    if (!node || !node->left) return node;

    Node* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    return newRoot;
}


int BST::_vineHeight(Node*& node) {
    Node* grandParent = nullptr;
    Node* current = node;
    int count = 0;

    while (current != nullptr) {
        if (current->left != nullptr) {
            Node* oldCurrent = current;
            current = _rotateRight(current);
            if (grandParent != nullptr) {
                grandParent->right = current;
            } else {
                node = current;
            }
            current->right = oldCurrent;
        }
        grandParent = current;
        current = current->right;
        count++;
    }
    return count;
}

void BST::_balance(Node* &root, int count) {
    
}
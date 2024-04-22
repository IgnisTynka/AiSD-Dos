#include "../include/tree.h"

#include <iostream>

Tree::~Tree() {
    removeAll();
}

std::vector<int> Tree::preOrder() {
    std::vector<int> result;
    if(_root == nullptr) {
        return result;
    }
    _root->preOrder(&result);
    return result;
}

std::vector<int> Tree::inOrder() {
    std::vector<int> result;
    if(_root == nullptr) {
        return result;
    }
    _root->inOrder(&result);
    return result;
}

std::vector<int> Tree::postOrder() {
    std::vector<int> result;
    if(_root == nullptr) {
        return result;
    }
    _root->postOrder(&result);
    return result;
}

int Tree::min() {
    if (_root == nullptr) {
        throw std::out_of_range("Tree is empty");
    }
    return _root->min();
}

int Tree::max() {
    if (_root == nullptr) {
        throw std::out_of_range("Tree is empty");
    }
    return _root->max();
}

void Tree::removeAll() {
    if (_root != nullptr) {
        _removeSubtree(_root);
        _root = nullptr;
    }
}

void Tree::Node::preOrder(std::vector<int> *result) {
    result->push_back(data);
    if (left != nullptr) {
        left->preOrder(result);
    }
    if (right != nullptr) {
        right->preOrder(result);
    }
}

void Tree::Node::inOrder(std::vector<int> *result) {
    if (left != nullptr) {
        left->inOrder(result);
    }
    result->push_back(data);
    if (right != nullptr) {
        right->inOrder(result);
    }
}

void Tree::Node::postOrder(std::vector<int> *result) {
    if (left != nullptr) {
        left->postOrder(result);
    }
    if (right != nullptr) {
        right->postOrder(result);
    }
    result->push_back(data);
}

int Tree::Node::min() {
    if (left != nullptr) {
        return left->min();
    }
    return data;
}

int Tree::Node::max() {
    if (right != nullptr) {
        return right->max();
    }
    return data;
}

void Tree::_removeSubtree(Node* node) {
    if (node->left != nullptr) {
        _removeSubtree(node->left);
    }
    if (node->right != nullptr) {
        _removeSubtree(node->right);
    }
    delete node;
}

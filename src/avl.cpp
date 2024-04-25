#include <iostream>
#include <vector>

#include "../include/avl.h"
#include "../include/functions.h"

AVL::AVL() : Tree() {}

AVL::~AVL() {}


void AVL::create(std::vector<int> values) {
    removeAll();
    sort(values);
    _root = _createSubtree(values, 0, values.size() - 1);
    
}

AVL::AVLNode* AVL::_createSubtree(const std::vector<int> &values, int left, int right) {
    int mid = (left + right) / 2;
    AVLNode* node = new AVLNode(values[mid]);
    if (left < mid) {
        node->left = _createSubtree(values, left, mid - 1);
        AVLNode* left = (AVLNode*)node->left;
        if (left->height >= node->height) {
            node->height = left->height + 1;
        }
    }
    if (mid < right) {
        node->right = _createSubtree(values, mid + 1, right);
        AVLNode* right = (AVLNode*)node->right;
        if (right->height >= node->height) {
            node->height = right->height + 1;
        }
    }
    return node;
}

void AVL::remove(int value) {

}

AVL::AVLNode* AVL::_rotateRight(AVLNode* node) {
    AVLNode* left = (AVLNode*)node->left;
    node->left = left->right;
    left->right = node;
    return left;
}

AVL::AVLNode* AVL::_rotateLeft(AVLNode* node) {
    AVLNode* right = (AVLNode*)node->right;
    node->right = right->left;
    right->left = node;
    return right;
}


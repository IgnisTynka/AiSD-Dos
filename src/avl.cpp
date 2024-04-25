#include <cmath>
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

void AVL::rebalance() {
    std::vector<int> values = preOrder();
    removeAll();
    create(values);
}

void AVL::remove(int data) {
    _nodeCount--;
    _root = _removeValue((AVLNode*)_root, data);
}


AVL::AVLNode* AVL::_rotateRight(AVLNode* node) {
    if (!node || !node->right) return node;
    
    AVLNode* left = (AVLNode*)node->left;
    node->left = left->right;
    left->right = node;
    return left;
}

AVL::AVLNode* AVL::_rotateLeft(AVLNode* node) {
    if (!node || !node->left) return node;

    AVLNode* right = (AVLNode*)node->right;
    node->right = right->left;
    right->left = node;
    return right;
}

int AVL::_getBalance(AVLNode* node) {
    if (!node) return 0;
    int leftHeight = (node->left != nullptr) ? ((AVLNode*)node->left)->height : 0;
    int rightHeight = (node->right != nullptr) ? ((AVLNode*)node->right)->height : 0;
    return leftHeight - rightHeight;
}

AVL::AVLNode* AVL::_removeValue(AVLNode* node, int data) {
     if (node == nullptr) {
        return nullptr;
    }
    if (data < node->data) {
        node->left = _removeValue((AVLNode*)node->left, data);
        return node;
    } 
    if (data > node->data) {
        node->right = _removeValue((AVLNode*)node->right, data);
        return node;
    } 
    // Node has no children
    if (node->left == nullptr && node->right == nullptr) {
        delete node;
        return nullptr;
    }
    // Node has one child - right
    if (node->left == nullptr) {
        AVLNode* temp = (AVLNode*)node->right;
        delete node;
        return temp;
    }
    // Node has one child - left
    if (node->right == nullptr) {
        AVLNode* temp = (AVLNode*)node->left;
        delete node;
        return temp;
    }
    // Node has two children
    AVLNode* temp = (AVLNode*)node->right;
    while (temp && temp->left != nullptr)
        temp = (AVLNode*)temp->left;
    node->data = temp->data;
    node->right = _removeValue((AVLNode*)node->right, temp->data);
    
    node->height = 1 + std::max(
        node->left ? ((AVLNode*)node->left)->height : 0,
        node->right ? ((AVLNode*)node->right)->height : 0
    );
    int balance = _getBalance(node);

    // Left Left Case
    if (balance > 1 && _getBalance((AVLNode*)node->left) >= 0) {
        return _rotateRight(node);
    }
    // Left Right Case
    if (balance > 1 && _getBalance((AVLNode*)node->left) < 0) {
        node->left = _rotateLeft((AVLNode*)node->left);
        return _rotateRight(node);
    }
    // Right Right Case
    if (balance < -1 && _getBalance((AVLNode*)node->right) <= 0) {
        return _rotateLeft(node);
    }
    // Right Left Case
    if (balance < -1 && _getBalance((AVLNode*)node->right) > 0) {
        node->right = _rotateRight((AVLNode*)node->right);
        return _rotateLeft(node);
    }

    return node;
}
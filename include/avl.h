#pragma once

#include "tree.h"

class AVL : public Tree {    
public:
    AVL();
    ~AVL();

    virtual void create(std::vector<int> data) override;
    /// Rebalance the tree
    virtual void rebalance() override;

    virtual void remove(int data) override;

protected:
    class AVLNode : public Node {
    public:
        int height;
        AVLNode(int data) : Node(data), height(0) {}
        ~AVLNode() {}
    };

private:
    void _insertValue(AVLNode* node, int data);
    AVL::AVLNode* _createSubtree(const std::vector<int> &values, int left, int right);

    AVL::AVLNode* _rotateLeft(AVLNode* node);
    AVL::AVLNode* _rotateRight(AVLNode* node);
    int _getBalance(AVLNode* node);

    AVL::AVLNode* _removeValue(AVLNode* node, int data);
};

#pragma once

#include "tree.h"

class AVL : public Tree {    
public:
    AVL();
    ~AVL();

    virtual void insert(int data) override;
    virtual void insertAll(std::vector<int> data) override;

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
    void _rotateLeft(AVLNode* node);
    void _rotateRight(AVLNode* node);

};

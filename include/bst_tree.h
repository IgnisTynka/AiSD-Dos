#pragma once

#include "tree.h"

class BST : public Tree {    
public:
    BST();
    ~BST();

    virtual void insert(int data) override;
    virtual void insertAll(std::vector<int> data) override;

    virtual void remove(int data) override;

private:
    void _insertValue(Node* node, int data);

};

#pragma once

#include "tree.h"

class BST : public Tree {    
public:
    /// Constructor
    BST();
    /// Destructor
    ~BST();

    /// Insert all elements from the vector data into the tree
    virtual void create(std::vector<int> data) override;
    /// Rebalance the tree
    virtual void rebalance() override;

    /// Remove the node with data from the tree
    virtual void remove(int data) override;

private:
    void _insertValue(Node* node, int data);

    BST::Node* _rotateLeft(Node* node);
    BST::Node* _rotateRight(Node* node);
    /// Return the height of the tree transformed into a vine
    int _vineHeight(Node* &node);
    /// Balance the tree using left rotation
    void _balance(Node* &node, int count);
    
    BST::Node* _removeValue(Node* node, int data);
};
 
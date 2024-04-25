#pragma once

#include <vector>

class Tree{
public:
    /// Constructor
    virtual ~Tree();

    /// Insert all elements from the vector data into the tree
    virtual void create(std::vector<int> data) = 0;
    /// Rebalance the tree
    virtual void rebalance(int vineHeight) = 0;

    /// Return vector with the tree elements in pre-order
    std::vector<int> preOrder();
    /// Return vector with the tree elements in in-order
    std::vector<int> inOrder();
    /// Return vector with the tree elements in post-order
    std::vector<int> postOrder();
    /// Return the minimum value in the tree
    int min();
    /// Return the maximum value in the tree
    int max();

    /// Remove the node with data from the tree
    virtual void remove(int data) = 0;
    /// Remove all nodes from the tree
    void removeAll();

protected:
    class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) : data(data), left(nullptr), right(nullptr) {}
        ~Node() {}

        void preOrder(std::vector<int> *result);
        void inOrder(std::vector<int> *result);
        void postOrder(std::vector<int> *result);
        int min();
        int max();
    };

    Node* _root;

private:
    void _removeSubtree(Node* node);

};


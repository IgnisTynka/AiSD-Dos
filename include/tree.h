#pragma once
#include "node.h"
#include <vector>

class Tree{
    private:
        Node *root;
    public:
        Tree();
        ~Tree();
        Node* getRoot();
        void insert(Node *node, int data);
        // void preOrder(Node* node, std::vector<int> *result);
        // void inOrder(Node* node, std::vector<int> *result);
        // void postOrder(Node* node, std::vector<int> *result);
        // void print(Node *node);
        // void remove(Node *node, int data);
        // void removeAll(Node *node);
        // void findMinMax(Node *node, int data);
};
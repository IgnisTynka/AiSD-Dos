#pragma once
#include "node.h"
#include <vector>

class Tree{
    private:
        Node *root;
        Tree();
        ~Tree();
    public:
        void insert(Node *node, int data);
        void print(Node *node);
        void remove(Node *node, int data);
        void findMinMax(Node *node, int data);
};
#pragma once

#include <vector>

class Tree{
public:
    virtual ~Tree();

    virtual void insert(int data) = 0;
    virtual void insertAll(std::vector<int> data) = 0;

    std::vector<int> preOrder();
    std::vector<int> inOrder();
    std::vector<int> postOrder();
    int min();
    int max();

    virtual void remove(int data) = 0;
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


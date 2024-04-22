#pragma once

class Node {
private:
    int data;
    Node* left;
    Node* right;

public:
    Node(int data);

    int getData();
    void setData(int data);

    Node* getLeft();
    void setLeft(Node* left);

    Node* getRight();
    void setRight(Node* right);
};
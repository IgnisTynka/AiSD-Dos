#include "../include/node.h"

Node::Node(int data){
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

Node::~Node(){
    delete this->left;
    delete this->right;
}

Node* Node::getLeft(){
    return this->left;
}

void Node::setLeft(Node* left){
    this->left = left;
}

Node* Node::getRight(){
    return this->right;
}

void Node::setRight(Node* right){
    this->right = right;
}

#include "../include/tree.h"
#include <iostream>

Tree::Tree(){
    this->root = nullptr;
}

Node* Tree::getRoot(){
    return this->root;
}

void Tree::insert(Node *node, int data){
    if(node == nullptr){
        this->root = new Node(data);
    }else{
        if(data < node->getData()){
            if(node->getLeft() == nullptr){
                node->setLeft(new Node(data));
            }else{
                insert(node->getLeft(), data);
            }
        }else{
            if(node->getRight() == nullptr){
                node->setRight(new Node(data));
            }else{
                insert(node->getRight(), data);
            }
        } 
    }
}

void Tree::preOrder(Node* node, std::vector<int> *result){
    if(node != nullptr){
        result->push_back(node->getData());
        preOrder(node->getLeft(), result);
        preOrder(node->getRight(), result);
    }

}

void Tree::inOrder(Node* node, std::vector<int> *result){
    if(node != nullptr){
        inOrder(node->getLeft(), result);
        result->push_back(node->getData());
        inOrder(node->getRight(), result);
    }
}

void Tree::postOrder(Node* node, std::vector<int> *result){
    if(node != nullptr){
        postOrder(node->getLeft(), result);
        result->push_back(node->getData());
        postOrder(node->getRight(), result);
    }
}

void Tree::print(Node *node){   
}

void Tree::remove(Node *node, int data){
}

void Tree::removeAll(Node *node){
    std::vector<int> order;
    postOrder(node, &order);
    for(int i = 0; i < order.size(); i++){
        remove(node, order[i]);
    }
}

void Tree::findMinMax(Node *node, int data){
}
#include "../include/node.h"
#include "../include/tree.h"

Tree::Tree(){
    this->root = nullptr;
}

void Tree::insert(Node *node, int data){
    if(this->root == nullptr){
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

void Tree::remove(Node *node, int data){
}

void Tree::findMinMax(Node *node, int data){
}
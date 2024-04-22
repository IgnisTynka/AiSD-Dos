#include "avl_tree.h"
#include "node.h"

AVLTree::AVLTree(){
    this->root = nullptr;
}

AVLTree::~AVLTree(){
    delete this->root;
}


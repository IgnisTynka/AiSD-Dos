#include <iostream>
#include "../include/tree.h"
#include "../include/node.h"

int main(){
    Tree *tree = new Tree();
    tree->insert(tree->getRoot(), 10);
    std::cout << "Root: " << tree->getRoot()->getData() << std::endl;
    return 0;
}


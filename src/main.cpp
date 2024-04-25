#include <iostream>
#include <vector>

#include "../include/functions.h"
#include "../include/avl.h"
#include "../include/bst.h"

int main(int argc, const char* argv[]){

    std::string treeType = std::string(argv[2]);

    if (treeType == "BST") {
        Tree* tree = new BST();
        menu(tree);
    } else if (treeType == "AVL") {
        Tree* tree = new AVL();
        menu(tree);
    } else {
        std::cout << "Invalid tree type" << std::endl;
        return 1;
    }
}
 
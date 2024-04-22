#include <iostream>
#include <vector>

#include "../include/tree.h"
#include "../include/bst.h"
#include "../include/avl_tree.h"

int main(int argc, const char* argv[]){
    if (argc != 3 || std::string(argv[1]) != "--tree") {
        std::cout << "Usage: ./executable --tree <tree type>" << std::endl;
        return 1;
    }
    std::string treeType = argv[2];
    if (treeType == "BST") {
        std::cout << "BST tree" << std::endl;
    } else if (treeType == "AVL") {
        std::cout << "AVL tree" << std::endl;
    } else {
        std::cout << "Invalid tree type" << std::endl;
        return 1;
    }
    
    return 0;
}


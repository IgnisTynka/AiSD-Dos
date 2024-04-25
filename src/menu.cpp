#include <iostream>

#include "../include/functions.h"

void menu(Tree* tree) {
    
    int nodes;
    std::cout << "nodes> ";
    std::cin >> nodes;
    std::cout << nodes << std::endl;

    std::vector<int> values;
    std::cout << "insert> ";
    for (int i = 0; i < nodes; i++) {
        int value;
        std::cin >> value;
        values.push_back(value);
        std::cout << value << " ";
    }
    std::cout << std::endl;

    tree->create(values);
    
    while (true) {
        std::cout << "action> ";
        std::string action;
        std::cin >> action;
        std::cout << action << std::endl;

        if (action == "Help" ){
            std::cout << "Help \t\t Show this message" << std::endl;
            std::cout << "Print \t\t Print the tree usin In-order, Pre-order, Post-order" << std::endl;
            std::cout << "FindMinMax \t Find the minimum and maximum values of the tree" << std::endl;
            std::cout << "Remove \t\t Remove elements of the tree" << std::endl;
            std::cout << "Delete \t\t Delete whole tree" << std::endl;
            std::cout << "Rebalance \t Rebalance the tree" << std::endl;
            std::cout << "Exit \t\t Exits the program (same as ctrl+D)" << std::endl;
        } else if (action == "Print") {
            std::vector<int> order;

            std::cout << "Pre-order: ";
            order = tree->preOrder();
            for (int i = 0; i < order.size(); i++) {
                std::cout << order[i] << " ";
            }
            std::cout << std::endl;

            std::cout << "In-order: ";
            order = tree->inOrder();
            for (int i = 0; i < order.size(); i++) {
                std::cout << order[i] << " ";
            }
            std::cout << std::endl;

            std::cout << "Post-order: ";
            order = tree->postOrder();
            for (int i = 0; i < order.size(); i++) {
                std::cout << order[i] << " ";
            }
            std::cout << std::endl;
        } else if (action == "Remove") {
            int rem_nodes;
            std::cout << "nodes> ";
            std::cin >> rem_nodes;
            std::cout << rem_nodes << std::endl;
            std::cout << "delete> ";
            for (int i = 0; i < rem_nodes; i++) {
                int value;
                std::cin >> value;
                tree->remove(value);
                std::cout << value << " ";
            }
            std::cout << "\nNodes succcesfylly removed" << std::endl;
            nodes -= rem_nodes;

        } else if (action == "FindMinMax") {
            int min = tree->min();
            int max = tree->max();
            std::cout << "Minimum: " << min << std::endl;
            std::cout << "Maximum: " << max << std::endl;

        } else if (action == "Delete") {
            tree->removeAll();
            std::cout << "Tree succesfully removed" << std::endl;

        } else if (action == "Rebalance") {
            tree->rebalance(nodes);
            std::cout << "Tree succesfully rebalanced" << std::endl;

        } else if (action == "Exit") {
            std::cout << "Exiting..." << std::endl;
            return;
        } else {
            std::cout << "Invalid action" << std::endl;
        }
    }
}
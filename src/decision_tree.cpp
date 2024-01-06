#include "decision_tree.h"
#include <iostream>

Node* createNode(const std::string& question) {
    Node* newNode = new Node;
    newNode->question = question;
    return newNode;
}

void addBranch(Node* parentNode, const std::string& option, Node* childNode) {
    parentNode->branches[option] = childNode;
}

void traverseDecisionTree(Node* currentNode) {
    std::cout << currentNode->question << std::endl;

    if (currentNode->branches.empty()) {
        // Leaf node reached, make a decision or perform an action
        std::cout << "Decision reached!" << std::endl;
        // You can add specific actions or decisions here
    } else {
        // Internal node, continue traversing based on user input
        std::string userInput;
        std::cout << "Enter your decision (";
        for (const auto& branch : currentNode->branches) {
            std::cout << branch.first << "/";
        }
        std::cout << "): ";
        std::cin >> userInput;

        auto nextNode = currentNode->branches.find(userInput);
        if (nextNode != currentNode->branches.end()) {
            traverseDecisionTree(nextNode->second);
        } else {
            std::cout << "Invalid input. Please try again." << std::endl;
            traverseDecisionTree(currentNode);
        }
    }
}

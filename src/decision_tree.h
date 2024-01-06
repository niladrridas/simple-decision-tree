#ifndef DECISION_TREE_H
#define DECISION_TREE_H

#include <map>
#include <string>

// Define a Node structure for the decision tree
struct Node {
    std::string question;
    std::map<std::string, Node*> branches;
};

// Function to create a new node in the decision tree
Node* createNode(const std::string& question);

// Function to add branches to a node in the decision tree
void addBranch(Node* parentNode, const std::string& option, Node* childNode);

// Function to traverse the decision tree and make decisions
void traverseDecisionTree(Node* currentNode);

#endif // DECISION_TREE_H

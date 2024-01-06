#include <iostream>
#include <map>
#include <string>

// Define a Node structure for the decision tree
struct Node {
    std::string question;
    std::map<std::string, Node*> branches;
};

// Function to create a new node in the decision tree
Node* createNode(const std::string& question) {
    Node* newNode = new Node;
    newNode->question = question;
    return newNode;
}

// Function to add branches to a node in the decision tree
void addBranch(Node* parentNode, const std::string& option, Node* childNode) {
    parentNode->branches[option] = childNode;
}

// Function to traverse the decision tree and make decisions
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

int main() {
    // Creating a simple decision tree
    Node* root = createNode("Is it a mammal?");
    Node* yesNode = createNode("Does it have fur?");
    Node* noNode = createNode("Does it have feathers?");

    addBranch(root, "Yes", yesNode);
    addBranch(root, "No", noNode);

    Node* catNode = createNode("It's a cat!");
    Node* dogNode = createNode("It's a dog!");
    Node* fishNode = createNode("It's a fish!");
    Node* reptileNode = createNode("It's a reptile!");

    addBranch(yesNode, "Yes", catNode);
    addBranch(yesNode, "No", dogNode);
    addBranch(noNode, "Yes", birdNode);
    addBranch(noNode, "No", reptileNode);

    // Traverse the decision tree
    traverseDecisionTree(root);

    // Remember to free memory allocated for nodes
    // ...

    return 0;
}

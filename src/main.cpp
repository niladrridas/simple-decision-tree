#include "decision_tree.h"

int main() {
    // Creating a simple decision tree
    Node* root = createNode("Is it a mammal?");
    Node* yesNode = createNode("Does it have fur?");
    Node* noNode = createNode("Does it have feathers?");

    addBranch(root, "Yes", yesNode);
    addBranch(root, "No", noNode);

    Node* catNode = createNode("It's a cat!");
    Node* dogNode = createNode("It's a dog!");
    Node* birdNode = createNode("It's a bird!");
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

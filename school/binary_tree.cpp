#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node {
    int value;
    Node* childLeft;
    Node* childRight;
};

Node* createLeafs(int currentHeight, int maxHeight, int minValue, int maxValue) {
    if (currentHeight > maxHeight) return nullptr;

    Node* newNode = new Node;

    if (currentHeight == 1) {
        cout << "Enter the value for the root node: ";
        cin >> newNode->value;
    } else {
        if (minValue > maxValue) {
            newNode->value = minValue;
        } else {
            newNode->value = minValue + rand() % (maxValue - minValue + 1);
        }
    }

    if (currentHeight < maxHeight) {
        newNode->childLeft = createLeafs(currentHeight + 1, maxHeight, minValue, newNode->value - 1);
        newNode->childRight = createLeafs(currentHeight + 1, maxHeight, newNode->value + 1, maxValue);
    } else {
        newNode->childLeft = nullptr;
        newNode->childRight = nullptr;
    }

    return newNode;
}

void displayTree(Node* root, string indent = "", bool isLeft = true) {
    if (root == nullptr) {
        return;
    }
    cout << indent;
    if (isLeft) {
        cout << "├──";
        indent += "│   ";
    } else {
        cout << "└──";
        indent += "    ";
    }

    cout << root->value << endl;

    displayTree(root->childLeft, indent, true);
    displayTree(root->childRight, indent, false);
}

int main() {
    srand(time(0));

    int height;
    cout << "Enter the height of the tree: ";
    cin >> height;

    Node* root = createLeafs(1, height, 1, 100);

    cout << "\nThe tree structure (with lines): \n";
    
    displayTree(root);

    return 0;
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node {
private:
    int data;
    Node* left;
    Node* right;

public:
    Node(int value) {
        this->data = value;
        this->left = nullptr;
        this->right = nullptr;
    }
    friend ostream& operator<<(ostream& o,Node &node) {
        o << node.data << endl;
        return o;
    }
    friend istream& operator>>(istream&o2, Node &node) {
        o2 >> node.data;
        return o2;
    }
    int getData() {
        return this->data;
    }

    void setData(int value) {
        this->data = value;
    }

    Node* getLeft() {
        return this->left;
    }

    void setLeft(Node* node) {
        this->left = node;
    }

    Node* getRight() {
        return this->right;
    }

    void setRight(Node* node) {
        this->right = node;
    }

    Node* insertIterative(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        Node* current = node;
        Node* newNode = new Node(value);
        while (true) {
            if (value < current->getData()) {
                if (current->getLeft() == nullptr) {
                    current->setLeft(newNode);
                    break;
                }
                current = current->getLeft();
            } else {
                if (current->getRight() == nullptr) {
                    current->setRight(newNode);
                    break;
                }
                current = current->getRight();
            }
        }
        return node; 
    }

    Node* insertRecursive(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->getData()) {
            node->setLeft(insertRecursive(node->getLeft(), value));
        } else if (value > node->getData()) {
            node->setRight(insertRecursive(node->getRight(), value));
        }
        return node;
    }

    Node* deleteNode(Node* node, int value) {
        if (node == nullptr) {
            return node;
        }
        if (value < node->getData()) {
            node->setLeft(deleteNode(node->getLeft(), value));
        } else if (value > node->getData()) {
            node->setRight(deleteNode(node->getRight(), value));
        } else {
            if (node->getLeft() == nullptr) {
                Node* temp = node->getRight();
                delete node;
                return temp;
            } else if (node->getRight() == nullptr) {
                Node* temp = node->getLeft();
                delete node;
                return temp;
            }
        }
        return node;
    }

        void inOrder(Node* node) {
        if (node != nullptr) {
            inOrder(node->getLeft());
            cout << node->getData() << " ";
            inOrder(node->getRight());
        }
    }

    void preOrder(Node* node) {
        if (node != nullptr) {
            cout << node->getData() << " ";
            preOrder(node->getLeft());
            preOrder(node->getRight());
        }
    }

    void postOrder(Node* node) {
        if (node != nullptr) {
            postOrder(node->getLeft());
            postOrder(node->getRight());
            cout << node->getData() << " ";
        }
    }

    void searchRecursive(Node* node, int value) {
        if (node == nullptr) {
            cout << "Element not found" << endl;
            return;
        }
        if (value == node->getData()) {
            cout << "Element found" << endl;
            return;
        }
        if (value < node->getData()) {
            searchRecursive(node->getLeft(), value);
        } else {
            searchRecursive(node->getRight(), value);
        }
    }

    Node* searchIterative(Node* node, int value) {
        while (node != nullptr) {
            if (value == node->getData()) {
                return node;
            }
            if (value < node->getData()) {
                node = node->getLeft();
            } else {
                node = node->getRight();
            }
        }
        return nullptr;
    }

    bool isBST(Node* value, Node* min = nullptr, Node* max = nullptr) {
        if (value == nullptr) {
            return true;
        }
        if ((min != nullptr && value->getData() <= min->getData()) || (max != nullptr && value->getData() > max->getData())) {
            return false;
        }
        return isBST(value->getLeft(), min, value) && isBST(value->getRight(), max, value);
    }

    bool searchI(int k) { 
        return searchIterative(this, k) != nullptr;
    }

    bool searchR(int k) { 
        Node* result = searchIterative(this, k);
        return result != nullptr;
    }

    Node* insertI(int k) {
        return insertIterative(this, k);
    }
};
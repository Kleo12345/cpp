#include "Node.h"
#include <iostream>

Node::Node(int k, Node* lchild, Node* rchild)
{
    data = k;
    this->lchild = lchild;
    this->rchild = rchild;
}

int Node::getData() { return data; }

Node* Node::getLchild() { return lchild; }

Node* Node::getRchild() { return rchild; }

Node* Node::insertRecursive(int k)
{
    if(this == nullptr) {
        return new Node(k);
    }
    if(this->data == k) {
        return this;
    }
    if(k > this->data) {

        this->rchild = (this->rchild)->insertRecursive(k);
    } else {
        this->lchild = (this->lchild)->insertRecursive(k);
    }
    return this;
}

bool Node::areIdentical(Node* root2) {
    if(root2 == nullptr && this == nullptr) {
        return true;
        }
        else if(root2 == nullptr || this == nullptr) {
            return false;
        }
            if(this->data == root2->data) {
                return (this->lchild->areIdentical(root2->getLchild()) && this->rchild->areIdentical(root2->getRchild()));
            }
            else  {
                return false;
            }
}

Node::~Node() {}

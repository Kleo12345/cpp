#include <iostream>
#include <string>

using namespace std;

class Node{
    private:
    int data; 
    Node* rchild;
    Node* lchild;
    public:
    Node(int d) : data(d), rchild(nullptr), lchild(nullptr) {}
    friend ostream& operator<<(ostream& o, Node* n){
        o << n->data << endl;
        o << n->rchild << endl;
        o << n->lchild << endl;
    } 
    friend istream& operator>>(istream& o2, Node* n){
        o2 >> n->data;
        o2 >> n->rchild;
        o2 >> n->lchild;
    }
    int getData(){
       return this->data; 
    }
    Node* getRightNode(){
        return rchild;
    }
    Node* getLeftNode(){
        return lchild;
    }
    void setData(int d){
        data = d;
    }
    void setRightNode(Node* r){
        rchild = r;
    }
    void setLeftNode(Node* l){
        lchild = l;
    }
    Node* insertIterativo(Node* n, int value){
        if(n == nullptr){
            return n;
        }
        Node* current = n;
        while (true)
        {
            if(value > current->getData()){
                if (current->getLeftNode() == nullptr)
                {
                    current->setLeftNode(new Node(value));
                    break;
                }
                else if(current->getRightNode() == nullptr)
                {
                    current->setRightNode(new Node(value));
                    break;
                }
                current = current->getRightNode();
            }
        }
        return n;
    }

    Node* insertRecursivo(Node* n, int value){
        if(n == nullptr){
            return n;
        }
        Node* current = n;
        if(value > current->getData()){
            current->setRightNode(insertRecursivo(current->getRightNode(), value));
        }else if(value < current->getData()){
            current->setLeftNode(insertRecursivo(current->getLeftNode(), value));
        }
    }
    Node* deleteNode(Node* n, int value){
        if (n== nullptr){
            return n;
        }
        Node* current = n; 
        if(value > current->getData()){
            current->setRightNode(deleteNode(current->getRightNode(), value));
        }else if (value < current->getData()){
            current->setLeftNode(deleteNode(current->getLeftNode(), value));
        }
        else{
            if(current->getLeftNode() == nullptr){
                Node* temp = current->getRightNode();
                delete current;
                return temp;
            }else{
                Node* temp = current->getLeftNode();
                delete current;
                return temp;
            }
        }
        return n;
    }
    Node* searchRecursive(Node* node, int value){
        if(node==nullptr){
        return nullptr;
    }
    Node* current = node;
    if(value< current->getData()){
        return searchRecursive(current->getLeftNode(), value);
    }
    else if(value > current->getData()){
        return searchRecursive(current->getRightNode(), value);
    }
    }
    Node* searchIterative(Node* node, int value){
        if(node == nullptr){
            return nullptr;
        }
        Node* current = node; 
        while(current!= nullptr){
            if(value == current->getData()){
                return current;
            }
            if(value < current->getData()){
                current = current->getLeftNode();
            }else {
                current = current->getRightNode();
            }
        }
        return nullptr;
    }
    bool isBst(Node* n, Node* minvalue=nullptr, Node* maxvalue=nullptr){
        if(n== nullptr){
            return true;
        }

        if((minvalue != nullptr && n->getData() <= minvalue->getData()) || (maxvalue != nullptr && n->getData() >= maxvalue->getData())){
            return false;
        }
        return isBst(n->getLeftNode(), minvalue, n)&& isBst(n->getRightNode(), maxvalue,n);
    }
    int findDepth(Node* n) {
        if (n == nullptr)
            return -1; 

        int leftDepth = findDepth(n->getLeftNode());
        int rightDepth = findDepth(n->getRightNode());

        return 1 + max(leftDepth, rightDepth);
    }

};
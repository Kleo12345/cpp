#ifndef NODE_H
#define NODE_H
#include <vector>

class Node
{
private:
    int data;
    Node* lchild;
    Node* rchild;
public:
    Node(int k, Node* lchild=nullptr, Node* rchild=nullptr);
    int getData();
    Node* getLchild();
    Node* getRchild();
    Node* insertRecursive(int k);
    bool areIdentical(Node* root2);
    ~Node();

};

#endif // NODE_H

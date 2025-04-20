#include "Node.h"
#include "Node.cpp"
#include <iostream>
using namespace std;

int main()
{
    Node* root = new Node(50);
    root->insertRecursive(17)->insertRecursive(53)->insertRecursive(27)->insertRecursive(14)->insertRecursive(21);

    Node* root2 = new Node(50);
    root2->insertRecursive(17)->insertRecursive(23)->insertRecursive(27)->insertRecursive(14)->insertRecursive(21);
    
    cout << root->areIdentical(root2)<< endl;  // it must print 0
    
    Node* root3 = new Node(50);
    root3->insertRecursive(17)->insertRecursive(53)->insertRecursive(27)->insertRecursive(14)->insertRecursive(21);
    
    cout << root->areIdentical(root3)<< endl;  // it must print 1

    return 0;
}
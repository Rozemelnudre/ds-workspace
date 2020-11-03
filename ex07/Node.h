#ifndef DS_NODE
#define DS_NODE

#include <iostream>
#include <vector>
#include <stack>

namespace ds_course{
    class Node{
        public:
            int value;
            Node* leftChild;
            Node* rightChild;
            Node(int vval){
                value = vval;
                leftChild = NULL;
                rightChild = NULL;
            }
            ~Node();
            void addLeftChild(Node* child){
                leftChild = child;
            }
            void addRightChild(Node* child){
                rightChild = child;
            }

    };

using namespace std;

    vector<int> inOrderTraversal(Node* root){
        vector<int> alienData;
        stack<Node*> stc;
        Node* current = root;
        while(current != NULL || stc.empty() == false){
            while (current !=  NULL) {
            
                /* place pointer to a tree node on 
                the stack before traversing 
                the node's left subtree */
                stc.push(current); 
                current = current->leftChild; 
            } 
    
            /* Current must be NULL at this point */
            current = stc.top(); 
            stc.pop(); 
    
            alienData.push_back(current->value);
    
            /* we have visited the node and its 
            left subtree.  Now, it's right 
            subtree's turn */
            current = current->rightChild; 
            }
    }

}

#endif
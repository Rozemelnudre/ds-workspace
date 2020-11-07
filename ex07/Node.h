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
            Node* root;
            bool isRoot;
            Node(int vval){
                value = vval;
                leftChild = NULL;
                rightChild = NULL;
                root = NULL;
                isRoot = false;
            }
            ~Node();
            void addLeftChild(Node* child){
                leftChild = child;
            }
            void addRightChild(Node* child){
                rightChild = child;
            }

    };

}

#endif
#ifndef DS_TREE_NODE
#define DS_TREE_NODE

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

namespace ds_workspace{
    class Node{
        public:
            int baddness;
            string key;
            Node* right;
            Node* left;
            int height;
            Node(string kkey){
                key = kkey;
                left = NULL;
                right = NULL;
                /*or is the height 1?*/
                height = 1;
                baddness = 1;
            }
            ~Node();
    };

}

#endif
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
            Node(string kkey);
            ~Node();
    };
}

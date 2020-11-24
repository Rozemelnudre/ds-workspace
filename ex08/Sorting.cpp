#include "TreeNode.cpp"
#include <string.h>

using namespace std;
using namespace ds_workspace;

void reverseStr(string& str) { 
    int n = str.length(); 
    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
}


Node* compare(Node* first, Node* second, int mode){
    Node* max;
    if(mode == 0){
        /*lex*/
        if(first->key <= second->key){
            return first;
        }else{
           return second;
        }
    }else if(mode == 1){
        /*shortlex*/
        if(first->key.length() < second->key.length()){
            return first;
        }else if(first->key.length() == second->key.length()){
            if(first->key <= second->key){
                return first;
            }else{
                return second;
            }
        }else{
            return second;
        }
    }else if(mode == 2){
        reverseStr(first->key);
        reverseStr(second->key);

        if(first->key <= second->key){
            return first;
        }else{
           return second;
        }
        /*colex*/
    }
}


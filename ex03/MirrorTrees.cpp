#include <iostream>
#include <sstream>
#include <vector>
#include <ctype.h>
#include <string>
#include <algorithm>
#include "MirrorTrees.h"


using namespace std;
using namespace ds_course;

Node::Node(int vv){
    val = vv;
}


int Node::getVal(){
    return this->val;
}

vector<int> Node::getChildren(){
    vector<int> returnVector;
    for (int i = 0; i < (this->children).size(); i++){
        returnVector.push_back(this->children[i].val);
    }

    return returnVector;
}

void Node::addChild(Node child){
    this->children.push_back(child);
}

void Node::reflectChildren(){
    int size = this->children.size();
    Node temp(8);

    if(size % 2 == 0){
        
        for(int i = 0; i < size / 2; i++){
            temp = this->children[i];
            this->children[i] = this->children[size-i];
            this->children[size-i] = temp;
        }

    }else if(size % 2 == 1){
          for(int i = 0; i < (size - 1) / 2; i++){
            temp = this->children[i];
            this->children[i] = this->children[size-i];
            this->children[size-i] = temp;
        }
    }
}

Node Node::getPreorder(Node nade){
    nade.sortArr.push_back(nade.val);
    int count = this->children.size();
    for (int i = 0; i < count; i++){
       nade.sortArr.push_back(getPreorder(nade.children[i]).getVal());
    }
    
}



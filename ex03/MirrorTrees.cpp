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
    for (int i = 0; i < this->children.size(); i++){
        returnVector.push_back(this->children[i]->getVal());
    }

    return returnVector;
}

void Node::addChild(Node* child){
    this->children.push_back(child);
}

void Node::reflectChildren(){
    int size = this->children.size();
    Node* temp = NULL;

    if(size % 2 == 0){
        
        for(int i = 0; i < size / 2; i++){
            temp = this->children.at(i);
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

void Node::getPreorder(){
    cout << this->getVal() << " " ;
    this->printChildren();

    vector<Node*> children = this->getChildNodes();
    int count = children.size();
    for (int i = 0; i < count; i++){
        if(!children[i]->getChildren().empty()){
            children[i]->getPreorder();
        }
    }

    cout << 0 << endl;
    
}

void Node::printChildren(){
    vector<int> children = this->getChildren();
    int size = children.size();

    for (int i = 0; i < size; i++){
        if(i == size -1){
         cout << children[i] << endl;   
        }else{
            cout << children[i] << " ";
        }
        
    }
}

vector<Node*> Node::getChildNodes(){
    return this->children;
}



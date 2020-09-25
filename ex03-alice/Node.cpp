#include <iostream>
#include <sstream>
#include <vector>
#include <ctype.h>
#include <string>
#include <algorithm>
#include "Node.h"


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
        returnVector.push_back(this->children.at(i)->getVal());
    }

    return returnVector;
}

void Node::addChild(Node* child){
    this->children.push_back(child);
}

void Node::reflectChildren(){
    reverse(children.begin(), children.end());

}

void Node::getPreorder(){

    this->reflectChildren();

    cout << this->getVal() << " " ;
    this->printChildren();
    

    vector<Node*> children = this->getChildNodes();
    
    int count = children.size();
    for (int i = 0; i < count; i++){
        if(!children.at(i)->getChildren().empty()){

            children.at(i)->getPreorder();
        }
    }
    
}

void Node::printChildren(){
    vector<int> children = this->getChildren();
    int size = children.size();

    for (int i = 0; i < size; i++){
        if(i == size -1){
         cout << children.at(i) << endl;   
        }else{
            cout << children.at(i) << " ";
        }
        
    }
}

vector<Node*> Node::getChildNodes(){
    return this->children;
}



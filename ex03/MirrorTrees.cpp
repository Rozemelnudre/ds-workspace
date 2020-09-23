#include <iostream>
#include <sstream>
#include <vector>
#include <ctype.h>
#include <string>
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

void Node::reflect(){

}

void Node::printPreorder(){

}



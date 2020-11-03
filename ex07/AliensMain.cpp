#include <iostream>
#include <vector> 
#include <string>
#include <map>
#include <sstream>
#include "Node.h"

using namespace ds_course;
using namespace std;

int main(){

    string line;
    string command;
    int data;
    int parentval;
    vector<int> traversal;
    map<int, Node*> existingNodes;
    Node* current;
    Node* root;
    Node* newNode;
    
    while(getline(cin, line)){
        istringstream inputLine(line);

        inputLine >> command;

        if(command == "T"){
            inputLine >> data;
            current = new Node(data);
            root = current;
            existingNodes.insert({data, current}); 

        }else if(command == "L"){
            
            inputLine >> parentval;
            inputLine >> data;

            if(current->value == parentval){
                newNode = new Node(data);
                current->addLeftChild(newNode);
                current = newNode;
                existingNodes.insert({data,current});
            }else{
                if(existingNodes.find(parentval) != existingNodes.end()){
                    newNode = new Node(data);
                    existingNodes.at(parentval)->addLeftChild(newNode);
                    current = newNode;
                    existingNodes.insert({data,current});
                }
            }
        }else if(command == "R"){

            inputLine >> parentval;
            inputLine >> data;

            if(current->value == parentval){
                newNode = new Node(data);
                current->addRightChild(newNode);
                current = newNode;
                existingNodes.insert({data,current});
            }else{
                if(existingNodes.find(parentval) != existingNodes.end()){
                    newNode = new Node(data);
                    existingNodes.at(parentval)->addRightChild(newNode);
                    current = newNode;
                    existingNodes.insert({data,current});
                }
            }

        }else if(command == "?"){

        }

    }



    return 0;
}
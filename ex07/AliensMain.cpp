#include <iostream>
#include <sstream>
#include "Node.h"

using namespace ds_course;
using namespace std;

int traversal[10000];
int trcount = 0;

void inOrderTraversal(Node* node);


int main(){

    string line;
    string command;
    int data;
    int parentval;
    //Node* current;
    Node* root;
    Node* newNode;
    Node* nodesAdded[10000];
    int counter = 0;
    Node* forest[10000];
    int frstcnt = 0;
   
    
    while(getline(cin, line)){
        istringstream inputLine(line);

        
        

        inputLine >> command;
        //cout << "right now doing " << command << endl;

        if(command == "T"){
           
            inputLine >> data;
            //cout << "Adding ancestor with val " << data << endl;
            bool isUniqueRoot = true;
            for(int i = 0; i < counter; i++){
                if(nodesAdded[i]->value == data){
                    isUniqueRoot = false;
                    break;
                }
            }
            if(!isUniqueRoot){
                cout << "error6\n";
                continue;
            }
            newNode = new Node(data);
            newNode->isRoot = true;
            forest[frstcnt] = newNode;
            frstcnt++;
            nodesAdded[counter] = newNode;
            counter ++;

        }else if(command == "L"){
            

            bool leftChildExists = false;
            bool parentHasChild = false;
            bool leftParentFound = false;
            
            inputLine >> parentval;
            inputLine >> data;
            //cout << "trying to add left "<< data << " to " << parentval << endl;

            if(parentval == data){
                cout << "error1\n";
                continue;
            }

            for(int m = 0; m < counter; m++){
                if(nodesAdded[m]->value == data){
                    leftChildExists = true;
                    break;
                }
            }



            for(int i = 0; i < counter; i++){
                
                if(nodesAdded[i]->value == parentval){

                    leftParentFound = true;

                    if(nodesAdded[i]->leftChild != NULL){
                        parentHasChild = true;
                        break;
                    }
                   

                    if(!leftChildExists && !parentHasChild){
                        newNode = new Node(data);
                        if(nodesAdded[i]->isRoot){
                            newNode->root = nodesAdded[i];
                        }else{
                            newNode->root = nodesAdded[i]->root;
                        }
                       nodesAdded[i]->addLeftChild(newNode); 
                       nodesAdded[counter] = newNode;
                       counter ++;
                        break;
                    }
                   
                }
            }
            if(leftParentFound == false){
                cout << "error2\n";
            }else if(leftChildExists){
                cout << "error3\n";
            }else if(parentHasChild){
                cout << "error4\n";
            }
           

        }else if(command == "R"){
          
            bool rightChildExists = false;
            bool rParentHasChild = false;
            bool rightParentFound = false;

            inputLine >> parentval;
            inputLine >> data;
            //cout << "trying to add "<< data << " to " << parentval << endl;

            if(parentval == data){
                cout << "error1\n";
                continue;
            }

            for(int m = 0; m < counter; m++){
                if(nodesAdded[m]->value == data){
                    rightChildExists = true;
                    break;
                }
            }


            for(int i = 0; i < counter; i++){
                if(nodesAdded[i]->value == parentval){
                    rightParentFound = true;

                    if(nodesAdded[i]->rightChild != NULL){
                        //cout << "rightChild full" << endl;
                        rParentHasChild = true;
                        break;
                    }else{
                        //cout << "found right parent" << endl;
                        rightParentFound = true;
                    }

                    if(!rightChildExists && !rParentHasChild){
                        newNode = new Node(data);
                        if(nodesAdded[i]->isRoot){
                            newNode->root = nodesAdded[i];
                        }else{
                            newNode->root = nodesAdded[i]->root;
                        }
                        nodesAdded[i]->addRightChild(newNode);

                        nodesAdded[counter] = newNode;
                        counter ++;
                        break;
                    }
                }
            }
            if(!rightParentFound){
              cout << "error2\n";  
            }else if(rightChildExists){
                cout << "error3\n";
            }else if(rParentHasChild){
                cout << "error5\n";
            }
            

        }else if(command == "?"){
           
            inputLine >>data;
            //cout << "searching for " << data << endl;
            bool found = false;
            trcount = 0;
            for(int i = 0; i < counter; i++){
                if(nodesAdded[i]->value == data){
                    if(nodesAdded[i]->isRoot){
                        inOrderTraversal(nodesAdded[i]);
                    }else{
                       inOrderTraversal(nodesAdded[i]->root); 
                    }
                    found = true;
                    break;
                    
                }
            }
            if(!found){
                //cout << "did not find " << data << endl;
                cout << "error0\n";
                continue;
            }
            if(trcount == 1){
                if(traversal[0] == data){
                   cout << "0 0\n" ; 
                }else{
                    /*throw some error*/
                }
                
            }else{
               for (int i = 0; i < trcount; i++){
                    if(traversal[i] == data){

                        if(i == 0){
                            cout << "0 ";
                        }else{
                            cout << traversal[i-1] << " ";
                        }

                        if(i == trcount -1){
                            cout << "0\n";
                        }else{
                            cout << traversal[i+1] << "\n";
                        }
                    }
                }  
            }
          
           
        }

    }

    return 0;
}

void inOrderTraversal(Node* root){
    if(root->leftChild != NULL){
        inOrderTraversal(root->leftChild);
    }
    traversal[trcount] = root->value;
    trcount ++;
    if(root->rightChild != NULL){
        inOrderTraversal(root->rightChild);
    }

}
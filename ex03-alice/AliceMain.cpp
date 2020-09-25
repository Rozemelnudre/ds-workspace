#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctype.h>
#include <iomanip>
#include <map>
#include <set>
#include <iterator>
#include <algorithm>
#include "Node.cpp"

using namespace std;
using namespace ds_course;

int main(){  

    Node* root = NULL;
    Node* parent = NULL;
    Node* child = NULL;

    bool isParent = true;

    map<int,Node*> nodemap; 
    vector<int> parents;
    vector<int> children;
    string line;

    int currentnode;
    
    while(getline(cin, line)){
        istringstream treeline(line);

        while(treeline >> currentnode){
            if(currentnode == 0){
                break;
            }


            if(isParent){

                

                /*jauns node jātaisa tikai tad, ja jau neeksistē viens!*/

                if(nodemap.find(currentnode) == nodemap.end()){
                     
                  parent = new Node(currentnode);
                   nodemap.insert({currentnode, parent}); 
                   parents.push_back(currentnode);
                }else{
                     
                    parent = nodemap.at(currentnode);
                }
                isParent = false;
                  
            }else{
                 
                child = new Node(currentnode);
                parent->addChild(child);
                 
                nodemap.insert({currentnode, child});
                children.push_back(currentnode);

            }
            
        }
        isParent = true;
       
    }



    for(int j = 0; j < parents.size(); j++){
        if(find(children.begin(), children.end(), parents.at(j)) != children.end() == false){
            root = nodemap.at(parents.at(j));
        }
    }


    root->getPreorder();
    cout << 0 << endl;
    
}





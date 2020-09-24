#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctype.h>
#include <iomanip>
#include <map>
#include <iterator>
#include "MirrorTrees.cpp"

using namespace std;
using namespace ds_course;

int main(){  

    map<int,Node*> nodemap;
    cout << "hello" << endl;
    Node n1(13);
    cout<< "node has val" << n1.getVal() << endl;  
    vector<int> parents;
    string line;
    int linecounter = 0;
    while(getline(cin, line)){
        istringstream treeline(line);
        int currentnode;
        int counter = 0;

        while(treeline >> currentnode){
            if(currentnode == 0){
                break;
            }
            if(counter == 0){
                Node* parent = new Node(currentnode);
                nodemap.insert({currentnode, parent});
                parents.push_back(currentnode);
            }else{
                Node* child = new Node(currentnode);
                nodemap.at(parents.at(linecounter))->addChild(child);

            }
            counter++;
        }

        linecounter++;
    }
}





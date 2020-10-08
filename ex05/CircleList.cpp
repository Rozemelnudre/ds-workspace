#include <iostream>
#include <sstream>
#include <vector>
#include <ctype.h>
#include <string>
#include "CircleList.h"

using namespace ds_course;
using namespace std;

void CircleList::add(const int& e){
    cout << "adding"<< endl;
    
    CNode* newelem = new CNode;
    newelem->elem = e;
    if(cursor == NULL){
       
        newelem->next = newelem;
         cursor = newelem;
        cout << "added first elem"<< endl;
    }else{
        cout << "at adding" << endl;
        newelem->next = cursor->next;
        cursor->next = newelem;
        cout << "ater adding" << endl;
    }
    

}

void CircleList::advance(){
    cursor = cursor->next;
}

void CircleList::remove(){
    if (cursor != NULL){
       CNode * old = cursor->next;
    if (cursor == old){
        cursor = NULL;
    }else{
        cursor->next = old->next; 
        delete old;
    } 
    }
    
   
       
    
    
}

CircleList::~CircleList(){
    while (!empty()) remove(); 
}

CircleList::CircleList(): cursor(NULL){
}

const int& CircleList::front() const {
    return cursor->next->elem; 
}

const int& CircleList::back() const{
    return cursor->elem;
}

bool CircleList::empty() const { 
    return cursor == NULL; 
}
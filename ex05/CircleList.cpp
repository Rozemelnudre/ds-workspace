#include <iostream>
#include <sstream>
#include <vector>
#include <ctype.h>
#include <string>
#include "CircleList.h"

using namespace ds_course;
using namespace std;

void CircleList::add(const int& e){

    
    CNode* newelem = new CNode;
    newelem->elem = e;
    if(cursor == NULL){
       
        newelem->next = newelem;
         cursor = newelem;
        
    }else{
    
        newelem->next = cursor->next;
        cursor->next = newelem;
    
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

int CircleList::getSize(){
    int counter = 1;
    int elem = front();
    advance();

    while(front() != elem){
        advance();
        counter++;
    }
    return counter;
}

string CircleList::to_str() {

    if(cursor == NULL){
        return "";
    }
    int count = getSize();
    string toreturn = "";

    for( int i = 0; i < count; i++){
        advance();
        toreturn += to_string(back());
        if( i != count - 1){
            toreturn += " ";
        }
    }

    return toreturn;
}
#include <iostream>
#include "Group.h"
#include "Shape.h"

using namespace ds_course;
using namespace std;

Group::Group(ShapeStack stacky){
    stack = stacky;
}

Group::~Group(){delete this;}

string Group::draw(){
    stack.iterReset();
    string resultString = "";
   while(stack.iterHasNext()){
       Shape* elem = stack.iterNext();
       string result = elem->draw();
       resultString += result;
       resultString += "\n";

   }
   return resultString;
}

Shape* Group::clone(){
    stack.iterReset();
    ShapeStack newStack;
    while(stack.iterHasNext()){
        newStack.push(stack.iterNext()->clone());
    }

    Group* cloneGroup = new Group(newStack);
    return cloneGroup;
}

void Group::transform(Matrix<double>* m){

    stack.iterReset();
    
    while(stack.iterHasNext()){

        stack.iterNext()->transform(m);
    }
}
 

#ifndef DS_SHAPESTACK
#define DS_SHAPESTACK

#include <string>
#include "Shape.h"

namespace ds_course{
    class ShapeStack {
        private:
            Shape** shapes;
            int iterCursor;
            int top;

        public:
            void iterReset(){
                iterCursor = top;
             
            }
            bool iterHasNext(){
                return iterCursor > 0;
                
            }
            Shape* iterNext(){
               
                iterCursor--;
               
                return shapes[iterCursor];
            }
            ShapeStack();
            ~ShapeStack();
            int size();
            bool empty();
            Shape* topp();
            void push(Shape* shape);
            void pop();
    };
}

ds_course::ShapeStack::ShapeStack(){
    shapes = new Shape*[1000];
    iterCursor = 0;
    top = 0;
}

ds_course::ShapeStack::~ShapeStack(){}

int ds_course::ShapeStack::size(){
    if(top != 0 ){
        return top;
    }
    return 0;
}

bool ds_course::ShapeStack::empty(){
    return(top == 0);
}

ds_course::Shape* ds_course::ShapeStack::topp(){
   
    return shapes[top - 1];
    
}

void ds_course::ShapeStack::push(ds_course::Shape* shape){
    if(top != 1000){

        shapes[top] = shape;
   
        top++;
    }else{
        std::cerr << "stack full!" << std::endl;
    }
   
}


void ds_course::ShapeStack::pop(){
    if(size() != 0){
        top--;
    }
}

#endif


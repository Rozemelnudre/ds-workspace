#ifndef DS_CIRCLELIST
#define DS_CIRCLELIST


#include <iostream>
#include <string>

namespace ds_course{
// element type
class CNode {
// circularly linked list node
private:
 
int elem;
// linked list element value
 CNode* next;
// next item in the list
 
 
 friend class CircleList;
// provide CircleList access
};


class CircleList {
// a circularly linked list
public:
 
 CircleList();
// constructor
 ~CircleList();
// destructor
 bool empty() const;
// is list empty?
 const int& front() const;
// element at cursor
 const int& back() const;
// element following cursor
 void advance();
// advance cursor
 void add(const int& e);
// add after cursor
 void remove();
// remove node after cursor

int getSize();

std::string to_str() ;

private:
 
 CNode* cursor;
// the cursor
};

}
#endif
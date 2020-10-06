#include <iostream>
#include <string>


typedef string Elem;
// element type
class CNode {
// circularly linked list node
private:
 
 Elem elem;
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
 const Elem& front() const;
// element at cursor
 const Elem& back() const;
// element following cursor
 void advance();
// advance cursor
 void add(const Elem& e);
// add after cursor
 void remove();
// remove node after cursor
private:
 
 CNode* cursor;
// the cursor
};
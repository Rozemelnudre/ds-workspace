#include <iostream>
#include <string>
#include <exception>
#include "CircleList.cpp"

using namespace std;
using namespace ds_course;



class OutOfBoundsException {
private:
string message;
public:
string getMessage() const;
OutOfBoundsException(const string& mesg);
~OutOfBoundsException();

};

OutOfBoundsException::OutOfBoundsException(const string& msg) { 
    message = msg;
    cout << "OutOfBoundsException" << endl; 
    cerr << message << endl;
}
OutOfBoundsException::~OutOfBoundsException() { delete this; }
string OutOfBoundsException::getMessage() const { return message; }

void INS(CircleList& cl, int position, int value);
void DEL(CircleList& cl, int position);




int main(){

    CircleList cl;
    int count;
    string line;
    int elem;
    string command;
    int commandposition;
    int cursorposition = 0;
    

    cin >> count;
    cin.ignore(10000,'\n');

    getline(cin, line);
    istringstream treeline(line);
    treeline >> elem;
    cl.add(elem);

    for(int i = 0; i < count - 1; i++){
        treeline >> elem;
        cl.add(elem);
        cl.advance();
        cursorposition++;
        cursorposition = cursorposition % count;
    }

    cl.advance();
    cursorposition++;
    cursorposition = cursorposition % count;
   

    while(getline(cin, line)){
         istringstream treeline(line);

         treeline >> command;

         if(command == "DEL"){
            treeline >> commandposition;
            DEL(cl, commandposition);
            count--;
           
            

         }else if(command == "INS"){
            treeline >> commandposition;
            treeline >> elem;
            INS(cl, commandposition, elem);
            count++;
         }
    }

    while(cursorposition != 0){
        cl.advance();
        cursorposition++;
        cursorposition = cursorposition % count;
    }


    for(int m = 0; m < count; m++){
        cout << cl.back();
        cl.advance();
        if(m != count - 1 ){
            cout << " ";
        }else{
            cout << endl;
        }


    }
     

}


void INS(CircleList& cl, int position, int value){
    int count = cl.getSize();
    int oneBeforePosition;
    int cursorposition = 0;

    if(position > count){
        throw OutOfBoundsException("unavailable position");
    }

    if (position == 0){
        oneBeforePosition = count - 1;
    }else{
        oneBeforePosition = position - 1;
    }


     while(cursorposition != oneBeforePosition){
        cl.advance();
        cursorposition++;
        cursorposition = cursorposition % count;


    }

    cl.add(value);
    
    if(position == 0){
       cursorposition++; 
    }
    count++;

    

    
    while(cursorposition != 0){
        cl.advance();
        cursorposition++;
        cursorposition = cursorposition % count;
    }

    cout <<cl.back() << " " << cl.front() << endl;


}

void DEL(CircleList& cl, int position){
    int count = cl.getSize();
    int oneBeforePosition;
    int cursorposition = 0;

    if(position >= count){
        throw OutOfBoundsException("unavailable position");
    }

    if (position == 0){
        oneBeforePosition = count - 1;
    }else{
        oneBeforePosition = position - 1;
    }

            
    while(cursorposition != oneBeforePosition){
        cl.advance();
        cursorposition++;
        cursorposition = cursorposition % count;

    }


    cl.remove();
    if(position == 0){
       cursorposition--; 
    }
    count --;
    
    

    
    while(cursorposition != 0){
        cl.advance();
        cursorposition++;
        cursorposition = cursorposition % count;
    }

}


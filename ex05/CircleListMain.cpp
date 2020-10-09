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
string getMessage(){
    return message;
}
OutOfBoundsException(const string& mesg):message(mesg){}
~OutOfBoundsException();

};

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
    cout << "added " << elem << endl;

    for(int i = 0; i < count - 1; i++){
        treeline >> elem;
        cl.add(elem);
        cout << "added " << elem << endl;
        cl.advance();
        cursorposition++;
        cursorposition = cursorposition % count;
    }

    cout << "list is made" << endl;
    cl.advance();
    cursorposition++;
    cursorposition = cursorposition % count;
    cout << "count is " << count<< " and position " << cursorposition << " and size "  << cl.getSize()<< endl;

    while(getline(cin, line)){
         istringstream treeline(line);

         treeline >> command;
         cout <<  "am at the command" << endl;

         if(command == "DEL"){
            treeline >> commandposition;

            try{
                cout << "before del front is " << cl.front()  << " and back " << cl.back()<< endl;
                DEL(cl, commandposition);
                cout << "passed del and front is " << cl.front()  << " and back " << cl.back()<< endl;
                count--;
            }catch(const OutOfBoundsException& e){
                cout << "OutOfBoundsException" << endl;
            }
           
            

         }else if(command == "INS"){
            treeline >> commandposition;
            treeline >> elem;
            cout << "inserting " << elem << " at " << commandposition << endl;

            try{
                INS(cl, commandposition, elem);

                cout << "now front in try block" << cl.front() << " and back  " << cl.back() << endl;
                count++;
                cout << "passes function ins" << endl;
                cout<< cl.getSize() << " size is " << endl;
                cout << cursorposition << "here curr posit" << endl;
                cout<< cl.getSize() << " size is " << endl;
            }catch(const OutOfBoundsException& e){
                cout << "OutOfBoundsException" << endl;
            }

            cout << cursorposition << "here curr posit" << endl;
         }
    }

    while(cursorposition != 0){
        cout << "advancing" << endl;
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
    cout<< count << "inside of ins size is " << endl;
    int oneBeforePosition;
    int cursorposition = 0;

    if(position > count){
        throw new OutOfBoundsException("unavailable position");
    }

    if (position == 0){
        oneBeforePosition = count - 1;
    }else{
        oneBeforePosition = position - 1;
    }

    cout << "onebeforepositionis " << oneBeforePosition << endl;

     while(cursorposition != oneBeforePosition){
        cl.advance();
        cursorposition++;
        cursorposition = cursorposition % count;


    }
    cout << "inserting at cursposit " << cursorposition << endl;

    cl.add(value);

    
    while(cursorposition != 0){
        cout << "advancing" << endl;
        cl.advance();
        cursorposition++;
        cursorposition = cursorposition % count;
    }
    cout << "after adding the position is " << cursorposition << endl;

    cout << "now front " << cl.front() << " and back  " << cl.back() << endl;


}

void DEL(CircleList& cl, int position){
    int count = cl.getSize();
    int oneBeforePosition;
    int cursorposition = 0;

     if(position > count){
        throw new OutOfBoundsException("unavailable position");
    }

    if (position == 0){
        oneBeforePosition = count - 1;
    }else{
        oneBeforePosition = position - 1;
    }

    cout << "in del onebefore is " << oneBeforePosition << endl;

            
    while(cursorposition != oneBeforePosition){
        cl.advance();
        cursorposition++;
        cursorposition = cursorposition % count;

    }
    cout << "before delete cursorposition is " << cursorposition << endl;


    cl.remove();
    count --;

    
    while(cursorposition != 0){
        cout << "advancing" << endl;
        cl.advance();
        cursorposition++;
        cursorposition = cursorposition % count;
    }

    cout << "after deleting the position is " << cursorposition << endl;

}


#include <iostream>
#include <string>
#include "CircleList.cpp"

using namespace std;
using namespace ds_course;

int main(){

    CircleList cl;
    int count;
    string line;
    int elem;
    string command;
    int commandposition;
    int cursorposition = 0;

    cin >> count;
    cout << "countis " << count << endl;
    cin.ignore(10000,'\n');

    getline(cin, line);
    istringstream treeline(line);
    cout << line << endl;
    treeline >> elem;
    cout << "elem is " << elem << endl;
    cl.add(elem);

    for(int i = 0; i < count - 1; i++){
        treeline >> elem;
        cout << "elem is " << elem << endl;
        cl.add(elem);
        cl.advance();
        cout << "position before is " << cursorposition << endl;
        cursorposition++;
        cursorposition = cursorposition % count;
        cout << "position after is " << cursorposition << endl;
    }

    while(getline(cin, line)){
         istringstream treeline(line);

         treeline >> command;

         if(command == "DEL"){
             treeline >> commandposition;

            while(cursorposition != commandposition - 1){
                cl.advance();
                cursorposition++;
                cursorposition = cursorposition % count;

            }

            cl.remove();
            count--;

         }else if(command == "INS"){
                 treeline >> commandposition;
                 treeline >> elem;

            while(cursorposition != commandposition - 1){
                cl.advance();
                cursorposition++;
                cursorposition = cursorposition % (count - 1);

            }

            cl.add(elem);
            cl.advance();
            cursorposition++;
            cursorposition = cursorposition % (count - 1);

         }
    }

    for(int m = 0; m < count; m++){
        cout << cl.front();
        cl.advance();
        if(m != count - 1 ){
            cout << " ";
        }else{
            cout << endl;
        }


    }

     

}
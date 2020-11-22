#include <iostream>
#include <sstream>


using namespace std;


int main(){

    string line;
    string command;
    string word;
  
    
    while(getline(cin, line)){
        istringstream inputLine(line);

        
        

        inputLine >> command;
        //cout << "right now doing " << command << endl;

        if(command == "I"){

            /*insert all words on the line*/
            while(inputLine >> word){

            }
           
        }else if(command == "E"){
            


        }else if(command == "G"){
          
         

        }else if(command == "L"){
           
          
           
        }else if (command == "D"){
            
        }

    }

    return 0;
}

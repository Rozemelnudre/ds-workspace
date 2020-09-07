#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctype.h>
#include "Periodic.h"

using namespace std;
using namespace ds_course;

int main()
{    
    Periodic pal;
    string mode;
    cin >> mode;
    string inputString;
    long long int inputDec;
    string inputHex;

    //cout << '\'' << mode << '\'' << endl;
    cin.ignore(10000,'\n');

    string inputLine;
    while (getline(cin, inputLine)) {
        istringstream sstr(inputLine);
        if (sstr.peek() == '#') {
            continue;
        }
        else {
            if (mode == "str") {
                sstr >> inputString;
                int res = pal.findPeriod(inputString);
                cout << inputString << " " << res << endl;
            } else if (mode == "hex") {
                sstr >> inputHex;
                for (int i=0; i<inputHex.length(); i++){
                    inputHex[i] = tolower(inputHex[i]);
                }
                long long int i,c=0;
  	            for(i=0;i<inputHex.length();i++){
                    if(inputHex[i]!='0'){
                        c=i;
                        break;
                    }
  	            }
                string word = inputHex.substr(c);
                int res = pal.findPeriodHex(word);
                cout << word << " " << res << endl;
            } else if (mode == "dec"){
                sstr >> inputDec;
                int res = pal.findPeriod(inputDec);
                cout << inputDec << " " << res << endl;
            }
           
        }
    }
}




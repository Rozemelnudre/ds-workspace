#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Periodic.h"

using namespace std;
using namespace ds_course;

int main()
{    
    Periodic pal;
    string mode;
    cin >> mode;
    string inputString;
    int inputDec;
    int inputHex;

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
            }
        }
    }
}



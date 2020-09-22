#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctype.h>
#include <iomanip>

using namespace std;
using namespace ds_course;

int main()

{    
    int count;
    cin >> count;
    Student stdts[count] = {};
    string temp;
    string tempage = "";
    string tempheight = "";
    double height;
    int age;
    int studentcounter = 0;
    long long int delimiter = 0;
    

    //cout << '\'' << mode << '\'' << endl;
    cin.ignore(10000,'\n');

    string inputLine;
    while (getline(cin, inputLine)) {
        istringstream sstr(inputLine);
        if (sstr.peek() == '#') {
            continue;
        }
        else {
           sstr >> age;
           sstr >> height;

            Student newbie;
            newbie.age = age;
            newbie.height = height;

            stdts[studentcounter] = newbie;
            studentcounter++;
            
           
        }
    }



   
    cout << maxStudent.age << " " << fixed << setprecision(5) << maxStudent.height << endl;
    cout << minStudent.age << " " << fixed << setprecision(5) << minStudent.height << endl;
    return 0;
}





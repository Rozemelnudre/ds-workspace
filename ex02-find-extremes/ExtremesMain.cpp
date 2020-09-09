#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctype.h>
#include "Students.h"

using namespace std;
using namespace ds_course;

int main()

{    
    int count;
    cin >> count;
    Student stdts[count] = {};
    string temp = "";
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
           sstr >> temp;

           for (int j = 0; j < temp.length(); j++){
               if (isspace(temp[j])){
                   delimiter = j;
               }
               break;
           }

            tempage = temp.substr(0,2);
            tempheight = temp.substr(2);

            std::istringstream ( tempage ) >> age;
            std::istringstream ( tempheight ) >> height;

            Student newbie;
            newbie.age = age;
            newbie.height = height;

            stdts[studentcounter] = newbie;
            studentcounter++;
            
           
        }
    }

    Student maxStudent = getMax(stdts,count);
    Student minStudent = getMin(stdts, count);

    cout << minStudent.age << " " << minStudent.height << endl;
    cout << maxStudent.age << " " << maxStudent.height << endl;
    return 0;
}

Student getMin(Student *ss, int count){
    Student group[count] = *ss;
    Student minimum = group[0];

    for (int i = 1; i < count; i++){
        if(minimum.compareTo(group[1]) == -1){
            minimum = group[i];
        }
    }
    return minimum;
}

Student getMax(Student *ss, int count){
    Student group[count] = *ss;
    Student maximum = group[0];

    for (int i = 1; i < count; i++){
        if(maximum.compareTo(group[1]) == -1){
            maximum = group[i];
        }
    }
    return maximum;
}


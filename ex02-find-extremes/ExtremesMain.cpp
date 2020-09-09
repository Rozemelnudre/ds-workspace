#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctype.h>
#include "Students.h"
#include <iomanip>

using namespace std;
using namespace ds_course;
Student getMin(Student *ss, int count);
Student getMax(Student *ss, int count);
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

    Student maxStudent = getMax(stdts,count);
    Student minStudent = getMin(stdts, count);

   
    cout << maxStudent.age << " " << fixed << setprecision(5) << maxStudent.height << endl;
    cout << minStudent.age << " " << fixed << setprecision(5) << minStudent.height << endl;
    return 0;
}

Student getMin(Student *ss, int count){
    Student minimum = ss[0];

    for (int i = 1; i < count; i++){
        if(minimum.compareTo(ss[1]) == -1){
            minimum = ss[i];
        }
    }
    return minimum;
}

Student getMax(Student *ss, int count){
    Student maximum = ss[0];

    for (int i = 1; i < count; i++){
        if(maximum.compareTo(ss[1]) == 1){
            maximum = ss[i];
        }
    }
    return maximum;
}


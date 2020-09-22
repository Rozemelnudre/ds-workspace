#include <iostream>
#include <sstream>
#include <vector>
#include <ctype.h>
#include <string>
#include "Student.h"

using namespace ds_course;
using namespace std;

Student::Student() {

}


int Student::compareTo(Student ss){
    if (age == ss.age){
        if (height == ss.height){
            return 0;
        }else if (height < ss.height){
            return -1;
        }else {return 1;}

    }else if(age - ss.age < 0){
        return -1;
    } else {
        return 1;
    }

}

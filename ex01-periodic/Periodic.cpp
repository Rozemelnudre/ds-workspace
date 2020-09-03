#include <string>
#include <iostream>
#include <sstream>
#include "Periodic.h"

using namespace ds_course;
using namespace std;

Periodic::Periodic() {

}

bool Periodic::isPeriodic(int number)
{
    int *digits = new int[20];
    int count = 0;
    for (int i = 0;; i++) {
        digits[i] = number % 10;
        number = number / 10; 
        if (number == 0) {
            break;
        }
        count++;
    }
    //cout << "  count in isPeriodic(" << number << ") = " << count << endl;
    for (int j = 0; j < count; j++) {
        if (digits[j] != digits[count-j]) {
            return false;
        }
    }
    return true;
}


bool Periodic::isPeriodic(std::string word) {
    int count = word.length();
    if (count == 0) {
        return true;
    }
    for (int j = 0; j < count; j++) {
        if (word.at(j) != word.at((count-1)-j)) {
            return false;
        }
    }
    return true;
}



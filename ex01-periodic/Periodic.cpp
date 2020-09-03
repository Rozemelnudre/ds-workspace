#include <string>
#include <iostream>
#include <sstream>
#include "Periodic.h"

using namespace ds_course;
using namespace std;

Periodic::Periodic() {

}

int Periodic::findPeriod(int number)
{
    return 17;
}


int Periodic::findPeriod(std::string word) {
    // calculate half of string length, if odd, calculate 'smallest' value
    int maxPeriod;
    if (word.length() % 2 != 0) {
        maxPeriod = (word.length() - 1) / 2;
    }
    else {
        maxPeriod = word.length() / 2;
    }
    //if length is 0, maxPeriod is 0 and not periodic
    if (maxPeriod == 0) {
        return 0;
    }
    //loop through all possible period lengths
    for (int j = 0; j <= maxPeriod; j++) {
        //check if divisible by this period. If not, move on, if yes keep going
        if (word.length() % j == 0) {
            //use a for loop to iterate over the string and split it
            //then compare all the parts
        }
        

        }
    }
    return true;
}

int Periodic::findPeriodHex(int n) {
    return 17;
}



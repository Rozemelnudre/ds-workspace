#include <string>
#include <iostream>
#include <sstream>
#include "Periodic.h"

using namespace ds_course;
using namespace std;

Periodic::Periodic() {

}


int Periodic::findPeriod(std::string word) {
  int period = 0;
  int firstInd = 0;
  int secondInd = 1; 

  if(word.size() == 0){
    period = 0;
  } 

 	while(secondInd < word.size()){ 
 		if(word[firstInd] == word[secondInd]) 
 			firstInd++; 
 		else{ 
 			if(firstInd != 0) {
        secondInd--; 
        firstInd = 0;
       } 
		} 
 		secondInd++; 
 	} 
 	if((secondInd-firstInd) != word.size() && word.size() % (secondInd-firstInd) == 0){ 
        period = secondInd-firstInd;
 	} 
  return period;
}



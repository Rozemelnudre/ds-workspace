#include <iostream>
#include <sstream>
#include <vector>
#include <ctype.h>
#include <string>
#include "Periodic.h"

using namespace ds_course;
using namespace std;

Periodic::Periodic() {

}


int Periodic::findPeriod(std::string word) {
  int period = 0;
  int firstInd = 0;
  int secondInd = 1; 

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
 	if((secondInd-firstInd) != word.size() && word.size() % (secondInd-firstInd) == 0 && word.size() != 0){ 
        period = secondInd-firstInd;
 	}else {
		period = 0;
	 }
  return period;
}

int Periodic::findPeriodHex(long long int number) {	
  string word = to_string(number);
  int period = 0;
  int firstInd = 0;
  int secondInd = 1; 

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
 	if((secondInd-firstInd) != word.size() && word.size() % (secondInd-firstInd) == 0 && word.size() != 0){ 
        period = secondInd-firstInd;
 	}else {
		period = 0;
	 }
  return period;
}


int Periodic::findPeriod(long long int number) {
  string oldword = to_string(number);	
  long long int i,c=0;
  for(i=0;i<oldword.length();i++){
     if(oldword[i]!='0'){// check the first index where 0 doesnt occur
         c=i;
         break;
     }
  }
  string word = oldword.substr(c);
  int period = 0;
  int firstInd = 0;
  int secondInd = 1; 

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
 	if ((secondInd-firstInd) != word.size() && word.size() % (secondInd-firstInd) == 0 && word.size() != 0){ 
        period = secondInd-firstInd;
 	}else {
		period = 0;
	 }
  return period;
}



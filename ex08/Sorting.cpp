#include "TreeNode.h"
#include <string.h>

using namespace std;
using namespace ds_workspace;

string reverseStr(string str) { 
    string swapped = str;
    int n = str.length(); 
    for (int i = 0; i < n / 2; i++) {
        swap(swapped[i], swapped[n - i - 1]); 
    }
    return swapped;
        
}


string compare1(string first, string second, int mode){
    string max = "stub";
    if(mode == 0){
        /*lex*/
        if(first < second){
            return first;
        }else if(first > second){
           return second;
        }
    }else if(mode == 1){
        /*shortlex*/
        if(first.length() < second.length()){
            return first;
        }else if(first.length() == second.length()){
            if(first < second){
                return first;
            }else if(first > second){
                return second;
            }
        }else{
            return second;
        }
    }else if(mode == 2){
        string firstSwap;
        string secSwap;
        firstSwap = reverseStr(first);
        secSwap = reverseStr(second);
        

        if(firstSwap < secSwap){
            return first;
        }else if(firstSwap > secSwap){
           return second;
        }
        /*colex*/
    }
    return max;
}

string compare(string first, string second, int mode){
  string shortest;
    if(mode == 0){
      string shortest;
        /*lex*/
        int leng1 = first.length();
        int leng2 = second.length();
        int itLeng;
        if(leng1 > leng2){
            itLeng = leng2;
            shortest = second;
        }else{
            itLeng = leng1;
            shortest = first;
        }
        for(int i = 0; i < itLeng; i++){
            if(tolower(first[i]) > tolower(second[i])){
                return second;
            }else if(tolower(first[i]) < tolower(second[i])){
                return first;
            }else{
                if(first[i] < second[i]){
                    return first;
                }else if(first[i] > second[i]){
                    return second;
                }
            }
        }
      return shortest;
    }else if(mode == 1){
        /*shortlex*/
        if(first.length() < second.length()){
            return first;
        }else if(first.length() == second.length()){
                   int leng1 = first.length();
        int leng2 = second.length();
        int itLeng;
        if(leng1 > leng2){
            itLeng = leng2;
            shortest = second;
        }else{
            itLeng = leng1;
            shortest = first;
        }
        for(int i = 0; i < itLeng; i++){
            if(tolower(first[i]) > tolower(second[i])){
                return second;
            }else if(tolower(first[i]) < tolower(second[i])){
                return first;
            }else{
                if(first[i] < second[i]){
                    return first;
                }else if(first[i] > second[i]){
                    return second;
                }
            }
        }
          return shortest;
        }else{
            return second;
        }
    }else if(mode == 2){
        string firstSwap;
        string secSwap;
        firstSwap = reverseStr(first);
        secSwap = reverseStr(second);
        
        int leng1 = firstSwap.length();
        int leng2 = secSwap.length();
        int itLeng;
        if(leng1 > leng2){
            itLeng = leng2;
            shortest = second;
        }else{
            itLeng = leng1;
            shortest = first;
        }
        for(int i = 0; i < itLeng; i++){
            if(tolower(firstSwap[i]) > tolower(secSwap[i])){
                return second;
            }else if(tolower(firstSwap[i]) < tolower(secSwap[i])){
                return first;
            }else{
                if(firstSwap[i] < secSwap[i]){
                    return first;
                }else if(firstSwap[i] > secSwap[i]){
                    return second;
                }
            }
        }
        return shortest;
    }
    return shortest;
}


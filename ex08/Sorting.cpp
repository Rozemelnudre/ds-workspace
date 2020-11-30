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


string compare(string first, string second, int mode){
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


#include "TreeNode.h"
#include <string.h>

using namespace std;
using namespace ds_workspace;
string compare1(string first, string second, int mode);
string compare2(string first, string second, int mode);
string compare(string first, string second, int mode);

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

string compare2(string first, string second, int mode){
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
            cout << "comparing chars " << first[i] << " " << second[i] << endl;
            if(tolower(first[i]) > tolower(second[i])){
                cout << "return second " << endl;
                return second;
            }else if(tolower(first[i]) < tolower(second[i])){
                cout << "return first" << endl;
                return first;
            }else{
                cout << "comparing equals" << endl;
                if((i != itLeng - 1 && tolower(first[i+1]) != tolower(second[i+1])) || i == itLeng -1 ){
                    cout << "not a prefix" << endl;
                    if(first[i] < second[i]){
                        return first;
                    }else if(first[i] > second[i]){
                        return second;
                    }
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

string compare(string first, string second, int mode){
  string shortest = first;
    if(mode == 0){
      /*first compare the strings as lower case*/
      string low1 = first;
      int leng1 = first.length();
      string low2 = second;
      int leng2 = second.length();
      int i;
      for (i = 0; i < leng1; i++){
        low1[i] = tolower(first[i]);
      }
      for (i = 0; i < leng2; i++){
        low2[i] = tolower(second[i]);
      }
      //cout << low1 << " " << low2 << endl;
      if(leng1 > leng2){
        shortest = second;
      }else if(leng1 < leng2){
        shortest = first;
      }
      
      if(low1 > low2){
        return second;
      }else if(low1 < low2){
        return first;
      }else{

        /*check char by char the capitals*/
        for(i = 0; i < shortest.length(); i++){
   
          if(first[i] < second[i]){
            return first;
          }else if(second[i] < first[i]){
            return second;
          }
        }
      }
      return shortest;


    }else if(mode == 1){
      /*shrtlex*/
      int leng1 = first.length();
      int leng2 = second.length();
      string low1 = first;
      string low2 = second;

      if(leng1 > leng2){
        return second;
      }else if(leng1 < leng2){
        return first;
      }else{
        /*length equal, use lex*/
        string low2 = second;
        string low1 = first;
        int i;
        for (i = 0; i < leng1; i++){
          low1[i] = tolower(first[i]);
        }
        for (i = 0; i < leng2; i++){
          low2[i] = tolower(second[i]);
        }

        if(low1 > low2){
          return second;
        }else if(low1 < low2){
          return first;
        }else{

          /*check char by char the capitals*/
          for(i = 0; i < shortest.length(); i++){
    
            if(first[i] < second[i]){
              return first;
            }else if(second[i] < first[i]){
              return second;
            }
          }
        }

      }
      return shortest;

  
    }else if(mode == 2){
      /*reverse and do lex*/

      string rev1 = reverseStr(first);
      string rev2 = reverseStr(second);
      int leng1 = first.length();
      int leng2 = second.length();
      string low1 = first;
      string low2 = second;
      int i;
      for (i = 0; i < leng1; i++){
        low1[i] = tolower(rev1[i]);
      }
      for (i = 0; i < leng2; i++){
        low2[i] = tolower(rev2[i]);
      }

      if(low1 > low2){
        return second;
      }else if(low1 < low2){
        return first;
      }else{

        /*check char by char the capitals*/
        for(i = 0; i < shortest.length(); i++){
   
          if(first[i] < second[i]){
            return first;
          }else if(second[i] < first[i]){
            return second;
          }
        }
      }

      return shortest;
    }
    return shortest;
}


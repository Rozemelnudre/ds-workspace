#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctype.h>
#include <iomanip>
#include "Ratio.h"
#include "Matrix.h"

using namespace ds_course;
using namespace std;

int main(){
    string firstLine;
    string matrixType1;
    int rows1;
    int cols1;
    string matrixType2;
    int rows2;
    int cols2;
    string typeis;
    string inputLine;


    getline(cin, firstLine);
    istringstream sstr(firstLine);
    sstr >> matrixType1;
    sstr >> rows1;
    sstr >> cols1;
    cout << "read first things " << matrixType1 << " " << rows1 << " " << cols1 << endl;

    if(matrixType1 == "MZ"){
        int elem;
        Matrix<int> m1(rows1, cols1);
        cin >> m1;

        getline(cin, firstLine);
        istringstream sstr(firstLine);
        sstr >> matrixType2;
        sstr >> rows2;
        sstr >> cols2;

        Matrix<int> m2(rows2, cols2);
        cin >> m2;

        string operation;
        cin >> operation;

        if(operation == "ADD"){

            try{
                Matrix<int> result = m1 + m2;
                cout << matrixType1 << " " << result.getRows() << " " << result.getCols() << endl;
                cout << result;
            }catch (const std::out_of_range& e){
                cout << "out_of_range" << endl;
            }
            
        }else if(operation == "SUB"){
            
            try{
                Matrix<int> result = m1 - m2;
                cout << matrixType1 << " " << result.getRows() << " " << result.getCols() << endl;
                cout << result;
            }catch (const std::out_of_range& e){
                cout << "out_of_range" << endl;
            }

        }else if(operation == "MUL"){
            
            try{
                Matrix<int> result = m1 * m2;
                cout << matrixType1 << " " << result.getRows() << " " << result.getCols() << endl;
                cout << result;
            }catch (const std::out_of_range& e){
                cout << "out_of_range" << endl;
            }

        }
        

    }else if(matrixType1 == "MQ"){
         int elem;
        Matrix<Ratio> m1(rows1, cols1);
        cin >> m1;

        getline(cin, firstLine);
        istringstream sstr(firstLine);
        sstr >> matrixType2;
        sstr >> rows2;
        sstr >> cols2;

        Matrix<Ratio> m2(rows2, cols2);
        cin >> m2;

        string operation;
        cin >> operation;

        if(operation == "ADD"){

            try{
                Matrix<Ratio> result = m1 + m2;
                cout << matrixType1 << " " << result.getRows() << " " << result.getCols() << endl;
                cout << result;
            }catch (const std::out_of_range& e){
                cout << "out_of_range" << endl;
            }
            
        }else if(operation == "SUB"){
            
            try{
                Matrix<Ratio> result = m1 - m2;
                cout << matrixType1 << " " << result.getRows() << " " << result.getCols() << endl;
                cout << result;
            }catch (const std::out_of_range& e){
                cout << "out_of_range" << endl;
            }

        }else if(operation == "MUL"){
            
            try{
                Matrix<Ratio> result = m1 * m2;
                cout << matrixType1 << " " << result.getRows() << " " << result.getCols() << endl;
                cout << result;
            }catch (const std::out_of_range& e){
                cout << "out_of_range" << endl;
            }

        }
        
    }else if(matrixType1 == "MR"){
         int elem;
        Matrix<double> m1(rows1, cols1);
        cin >> m1;

        getline(cin, firstLine);
        istringstream sstr(firstLine);
        sstr >> matrixType2;
        sstr >> rows2;
        sstr >> cols2;

        Matrix<double> m2(rows2, cols2);
        cin >> m2;

        string operation;
        cin >> operation;

        if(operation == "ADD"){

            try{
                Matrix<double> result = m1 + m2;
                cout << matrixType1 << " " << result.getRows() << " " << result.getCols() << endl;
                cout << result;
            }catch (const std::out_of_range& e){
                cout << "out_of_range" << endl;
            }
            
        }else if(operation == "SUB"){
            
            try{
                Matrix<double> result = m1 - m2;
                cout << matrixType1 << " " << result.getRows() << " " << result.getCols() << endl;
                cout << result;
            }catch (const std::out_of_range& e){
                cout << "out_of_range" << endl;
            }

        }else if(operation == "MUL"){
            
            try{
                Matrix<double> result = m1 * m2;
                cout << matrixType1 << " " << result.getRows() << " " << result.getCols() << endl;
                cout << result;
            }catch (const std::out_of_range& e){
                cout << "out_of_range" << endl;
            }

        }
        
    }

}
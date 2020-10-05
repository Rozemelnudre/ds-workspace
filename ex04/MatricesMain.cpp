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

    if(matrixType1 == "MZ"){
        int elem;
        Matrix<int> m1(rows1, cols1);
        
        for(int i = 0; i < rows1; i++){
            getline(cin, firstLine);
            istringstream sstr(firstLine);
            for(int j = 0; j < cols1; j++){
                sstr >> elem;
                m1.a[i][j]= elem;
            }
        }

        getline(cin, firstLine);
        istringstream sstr(firstLine);
        sstr >> matrixType2;
        sstr >> rows2; 
        sstr >> cols2;

 

        Matrix<int> m2(rows2, cols2);
           for(int k = 0; k < rows2; k++){
            getline(cin, firstLine);
            istringstream sstr(firstLine);
            for(int m = 0; m < cols2; m++){
                sstr >> elem;
                m2.a[k][m]= elem;
            }
        }

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
        Ratio elem;
        Matrix<Ratio> m1(rows1, cols1);

        
        for(int i = 0; i < rows1; i++){
            getline(cin, firstLine);
            istringstream sstr(firstLine);
            for(int j = 0; j < cols1; j++){
                sstr >> elem;
                m1.a[i][j]= elem;
            }
        }


        getline(cin, firstLine);
        istringstream sstr(firstLine);
        sstr >> matrixType2;
        sstr >> rows2; 
        sstr >> cols2;


        Matrix<Ratio> m2(rows2, cols2);
           for(int k = 0; k < rows2; k++){
            getline(cin, firstLine);
            istringstream sstr(firstLine);
            for(int m = 0; m < cols2; m++){
                sstr >> elem;
                m2.a[k][m]= elem;
            }
        }

        string operation;
        cin >> operation;
        if(operation.compare("ADD") == 0){

            try{
                Matrix<Ratio> result = m1 + m2;
                cout << matrixType1 << " " << result.getRows() << " " << result.getCols() << endl;
                cout << result;
            }catch (const std::out_of_range& e){
                cout << "out_of_range" << endl;
            }
            
        }else if(operation.compare("SUB") == 0){
            
            try{
                Matrix<Ratio> result = m1 - m2;
                cout << matrixType1 << " " << result.getRows() << " " << result.getCols() << endl;
                cout << result;
            }catch (const std::out_of_range& e){
                cout << "out_of_range" << endl;
            }

        }else if(operation.compare("MUL") == 0){
            
            try{
                Matrix<Ratio> result = m1 * m2;
                cout << matrixType1 << " " << result.getRows() << " " << result.getCols() << endl;
                cout << result;
            }catch (const std::out_of_range& e){
                cout << "out_of_range" << endl;
            }

        }
        
    }else if(matrixType1 == "MR"){
        double elem;
        Matrix<double> m1(rows1, cols1);
        
        for(int i = 0; i < rows1; i++){
            getline(cin, firstLine);
            istringstream sstr(firstLine);
            for(int j = 0; j < cols1; j++){
                sstr >> elem;
                m1.a[i][j]= elem;
            }
        }


        getline(cin, firstLine);
        istringstream sstr(firstLine);
        sstr >> matrixType2;
        sstr >> rows2; 
        sstr >> cols2;


        Matrix<double> m2(rows2, cols2);
           for(int k = 0; k < rows2; k++){
            getline(cin, firstLine);
            istringstream sstr(firstLine);
            for(int m = 0; m < cols2; m++){
                sstr >> elem;
                m2.a[k][m]= elem;
            }
        }

        string operation;
        cin >> operation;
        if(operation == "ADD"){

            try{
                Matrix<double> result = m1 + m2;
                cout << matrixType1 << " " << result.getRows() << " " << result.getCols() << endl;
                cout << fixed << setprecision(5) << result;
            }catch (const std::out_of_range& e){
                cout << "out_of_range" << endl;
            }
            
        }else if(operation == "SUB"){
            
            try{
                Matrix<double> result = m1 - m2;
                cout << matrixType1 << " " << result.getRows() << " " << result.getCols() << endl;
                cout<< fixed << setprecision(5) << result;
            }catch (const std::out_of_range& e){
                cout << "out_of_range" << endl;
            }

        }else if(operation == "MUL"){
            
            try{
                Matrix<double> result = m1 * m2;
                cout << matrixType1 << " " << result.getRows() << " " << result.getCols() << endl;
                cout << fixed << setprecision(5) << result;
            }catch (const std::out_of_range& e){
                cout << "out_of_range" << endl;
            }

        }
        
    }

}
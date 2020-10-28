#include <iostream>
#include "Matrix.h"
#include "Shape.h"
#include "Polygon.cpp"
#include "Circle.cpp"
#include "ShapeStack.h"
#include "Transformation.h"
#include "Group.cpp"
#include <string>
#include <sstream>

using namespace std;
using namespace ds_course;

int main(){

    string inputLine;
    Transformation matrixClass;
    Matrix<double> transfm(3,3);
    string command;
    int sideNumber;
    int groupFigCount;
    string color;
    string transformation;
    int angle;
    double dx;
    double dy;
    Shape* newShape;
    ShapeStack stack;

    while (getline(cin, inputLine)) {
        istringstream sstr(inputLine);
        sstr >> command;

        if(command == "POLYGON"){
            
            sstr >> color;
            sstr >> sideNumber;

            
            stack.push(new Polygon(color, sideNumber));

        }else if(command == "CIRCLE"){
            sstr >> color;
            
            stack.push(new Circle(color));
        }else if(command == "TRANSF"){
            sstr >> transformation;

            if(transformation == "ROT"){
                sstr >> angle;
                transfm = matrixClass.getROT(angle);

            }else{
                sstr >> dx;
                sstr >> dy;
                if(transformation == "TRA"){
                   transfm = matrixClass.getTRA(dx,dy);
                }else if ( transformation == "SHE"){
                   transfm = matrixClass.getSHA(dx,dy);
                }else if (transformation == "SCA"){
                    transfm = matrixClass.getSCA(dx,dy);
                }
            }
        
            stack.topp()->transform(&transfm);
        }else if (command == "COPY"){
            
            stack.push(stack.topp()->clone());

        }else if (command == "GROUP"){
            sstr >> groupFigCount;
            ShapeStack separateStack;

            for(int i = 0; i < groupFigCount; i++){
                newShape = stack.topp();

                separateStack.push(newShape);
                stack.pop();
            }
            
            stack.push(new Group(separateStack));
        }else if ( command == "SHOW"){
            cout << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"100\" height=\"100\">\n";
            string result = stack.topp()->draw();
            cout  << result<< "\n";

            cout <<  "<rect x=\"0\" y=\"0\" width=\"100\" height=\"100\" 7 stroke=\"#999999\" fill=\"none\" stroke-width=\"1\"/>\n";
            cout << "</svg>";
        }



    }
    return 0;
}


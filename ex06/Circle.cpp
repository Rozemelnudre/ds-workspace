#include "Circle.h"
#include "Matrix.h"
#include <string>
#include <cmath>

using namespace std;
using namespace ds_course;

Circle::Circle(string ccolor){
    n = 1000;
    double pi = 3.141592;
    int leng = ccolor.length();
    for (int j = 0; j < leng; j++){
        ccolor[j] = tolower(ccolor[j]);
    }
    color = ccolor;
    double angle = 0;
    double turningAngle = 360.0/n;

    for (int i = 0; i < n; i++){
        double x = cos(angle*pi/180);
        double y = sin(angle*pi/180);
        
        int yy = (int)round(sin(angle*pi/180)*100.0);
       

        points[i] = new Matrix<double>(3,1);
       
        points[i]->a[0][0] = x;
        points[i]->a[1][0] = y;
        points[i]->a[2][0] = 1;
       
        angle += turningAngle;
    }
}

Circle::~Circle() {
    for (int i = 0; i < n; i++){
        delete points[i];
    }

    delete [] points;

}

Shape* Circle::clone(){
    Circle* newFigure = new Circle(color);
    for(int i = 0; i < n; i++){
       *(newFigure->points[i]) = *(points[i]); 
    }

    return newFigure;
}

void Circle::transform(Matrix<double>* m){
    for(int i = 0; i < n; i++){
        *(points[i]) = *m * *(points[i]);
    }
}

string Circle::draw(){
    string returnString = "<path d = \"M";

    for(int i = 0; i < n; i++){
        returnString += " ";
        returnString += to_string(points[i]->a[0][0]);
        returnString += " ";
        returnString += to_string(points[i]->a[1][0]);

        if(i != n - 1){
            returnString += " L";
        }else{
            returnString += "\" fill = \"";
            returnString += color;
            returnString += "\"/>";
        }
    }
    return returnString;

}

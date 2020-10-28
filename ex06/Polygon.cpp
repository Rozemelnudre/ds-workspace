#include "Polygon.h"
#include "Matrix.h"
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;
using namespace ds_course;

Polygon::Polygon(string ccolor, int nn){
    double pi = 3.141592;
    int leng = ccolor.length();
    for (int j = 0; j < leng; j++){
        ccolor[j] = tolower(ccolor[j]);
    }
    color = ccolor;
    
    n = nn;
    double angle = 0;
    double turningAngle = 360.0/n;

    for (int i = 0; i < n; i++){
        double x = 0;
        double y = 0;
        
        int xx = (int)round(cos(angle*pi/180)*100.0);

        int yy = (int)round(sin(angle*pi/180)*100.0);
       

        points[i] = new Matrix<double>(3,1);
        points[i]->a[0][0] = xx / 100.0;
        points[i]->a[1][0] = yy / 100.0;
        points[i]->a[2][0] = 1;
       
        angle += turningAngle;
    }
}

Polygon::~Polygon(){
     for (int i = 0; i < n; i++){
        delete points[i];
    }

    delete [] points;
    
}

Shape* Polygon::clone(){
    Polygon* newFigure = new Polygon(color, n);
    for(int i = 0; i < n; i++){
       *(newFigure->points[i]) = *(points[i]); 
    }
    

    return newFigure;
}

/*ja nestrādā, pointeris uz Matricu vai &*/
void Polygon::transform(Matrix<double>* m){
    for(int i = 0; i < n; i++){
        *(points[i]) = *m * *(points[i]);
    }
}

string Polygon::draw(){


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

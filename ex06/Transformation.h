#ifndef DS_TRANSFORMATIONS
#define DS_TRANSFORMATIONS
#include "Matrix.h"
#include <iostream>
#include <string>
#include <cmath>

namespace ds_course{
    class Transformation {
        public:
        Matrix<double> getTRA(double dx, double dy){
            Matrix<double> retmat(3,3);
            retmat.a[0][0] = 1;
            retmat.a[0][1] = 0;
            retmat.a[0][2] = dx;
            retmat.a[1][0] = 0;
            retmat.a[1][1] = 1;
            retmat.a[1][2] = dy;
            retmat.a[2][0] = 0;
            retmat.a[2][1] = 0;
            retmat.a[2][2] = 1;

            return retmat;
        }
        Matrix<double> getROT(double angle){
            Matrix<double> retmat(3,3);
            retmat.a[0][0] = cos(angle);
            retmat.a[0][1] = -sin(angle);
            retmat.a[0][2] = 0;
            retmat.a[1][0] = sin(angle);
            retmat.a[1][1] = cos(angle);
            retmat.a[1][2] = 0;
            retmat.a[2][0] = 0;
            retmat.a[2][1] = 0;
            retmat.a[2][2] = 1;

            return retmat;
        }
        Matrix<double> getSCA(double dx, double dy){
            Matrix<double> retmat(3,3);
            retmat.a[0][0] = dx;
            retmat.a[0][1] = 0;
            retmat.a[0][2] = 0;
            retmat.a[1][0] = 0;
            retmat.a[1][1] = dy;
            retmat.a[1][2] = 0;
            retmat.a[2][0] = 0;
            retmat.a[2][1] = 0;
            retmat.a[2][2] = 1;

            return retmat;
        }
        Matrix<double> getSHA(double dx, double dy){
            Matrix<double> retmat(3,3);
            retmat.a[0][0] = 1;
            retmat.a[0][1] = dx;
            retmat.a[0][2] = 0;
            retmat.a[1][0] = dy;
            retmat.a[1][1] = 1;
            retmat.a[1][2] = 0;
            retmat.a[2][0] = 0;
            retmat.a[2][1] = 0;
            retmat.a[2][2] = 1;

            return retmat;
        }
    };
}

#endif


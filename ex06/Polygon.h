#ifndef DS_POLYGON
#define DS_POLYGON

#include <string>
#include "Matrix.h"
#include "Shape.h"

namespace ds_course
{
    class Polygon : public Shape
    {
        private:
            int n;
            std::string color;
            Matrix<double>** points = new Matrix<double>*[1000];
        public:
            Polygon(std::string color, int n);
            ~Polygon();
            std::string draw();
            void transform(Matrix<double>* m);
            Shape* clone();



    };
}
#endif
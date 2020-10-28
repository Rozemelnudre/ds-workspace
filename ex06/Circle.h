#ifndef DS_CIRCLE
#define DS_CIRCLE

#include <string>
#include "Shape.h"

namespace ds_course
{
    class Circle : public Shape
    {
        private:
            int n;
            std::string color;
            Matrix<double>** points = new Matrix<double>*[1000];
        public:
            Circle(std::string color);
            ~Circle();
            std::string draw();
            void transform(Matrix<double>* m);
            Shape* clone();

    };
}

#endif
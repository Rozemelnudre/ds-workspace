#ifndef DS_GROUP
#define DS_GROUP

#include <string>
#include "ShapeStack.h"
#include "Matrix.h"
#include "Shape.h"

namespace ds_course
{
    class Group : public Shape
    {
        private:
            ShapeStack stack;
        public:
            Group(ShapeStack stack);
            ~Group();
            std::string draw();
            void transform(Matrix<double>* m);
            Shape* clone();

    };
}
#endif
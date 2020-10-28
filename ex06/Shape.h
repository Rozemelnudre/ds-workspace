#ifndef DS_SHAPE
#define DS_SHAPE
#include <string>
#include "Matrix.h"

namespace ds_course{
class Shape{
    public:
    virtual std::string draw() = 0;
    virtual void transform(Matrix<double>* m) = 0;
    virtual Shape* clone() = 0;
};

}
#endif
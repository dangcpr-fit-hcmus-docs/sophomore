#include "IShape.h"
#include <math.h>
#define _USE_MATH_DEFINES
class Circle: public IShape {
private:
    double _r;
public:
    double r() { return _r; }
public:
    Circle() {}
    Circle(double r);
    double perimeter() {
        return _r * 2 * M_PI;
    }
    double area() {
        return _r * _r * M_PI;
    }
    string toString() ;
    IShape* generate(int, int);
    string className() { return "Circle"; }
};
#pragma once
#include <string>
#include <math.h>
#define _USE_MATH_DEFINES
using namespace std;

class IShape {
public:
    virtual double perimeter() = 0;
    virtual double area() = 0;
    virtual string toString() = 0;
    virtual IShape* generate(int, int) = 0;
    virtual string className() = 0;
};
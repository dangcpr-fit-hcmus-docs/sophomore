#include "Triangle.h"
#include <sstream>
using namespace std;

#include "RandomDoubleGenerator.h"

Triangle::Triangle(double a, double b, double c) {
    _a = a;
    _b = b;
    _c = c;
}

string Triangle::toString() {
    stringstream builder;
    builder << "Triangle: a=" << _a << ", b=" << _b << ", c=" << _c;
    
    string result = builder.str();
    return result;
}

IShape* Triangle::generate(int left, int right) {
    double a = RandomDoubleGenerator::instance()->next(left, right);
    double b = RandomDoubleGenerator::instance()->next(left, right);
    double c = RandomDoubleGenerator::instance()->next(left, right);
    
    IShape* result = new Triangle(a, b, c);
    return result;
}
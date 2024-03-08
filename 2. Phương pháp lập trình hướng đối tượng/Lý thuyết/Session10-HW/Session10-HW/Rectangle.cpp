#include "Rectangle.h"
#include <sstream>
using namespace std;

#include "RandomDoubleGenerator.h"

Rectangle::Rectangle(int a, int b) {
    _a = a;
    _b = b;
}

string Rectangle::toString() {
    stringstream builder;
    
    builder << "Rectangle: a=" << _a << ", b=" << _b; 
    
    string result = builder.str();
    return result;
}

IShape* Rectangle::generate(int left, int right) {
    double a = RandomDoubleGenerator::instance()->next(left, right);
    double b = RandomDoubleGenerator::instance()->next(left, right);
    
    IShape* result = new Rectangle(a, b);
    return result;
}
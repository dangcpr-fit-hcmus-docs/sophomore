#include "IShape.h"

class Rectangle: public IShape {
private:
    double _a;
    double _b;
public:
    double a() { return _a; }
    double b() { return _b; }
public:
    Rectangle() {};
    Rectangle(int a, int b);
    double perimeter() {
        return (_a + _b) * 2;
    }
    double area() {
        return _a * _b;
    }
    string toString() ;
    IShape* generate(int, int);
    string className() { return "Rectangle"; }
};
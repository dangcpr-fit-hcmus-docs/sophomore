#include "IShape.h"

class Triangle: public IShape {
private:
    double _a;
    double _b;
    double _c;
    
public:
    double a() { return _a; }
    double b() { return _b; }
    double c() { return _c; }
    
public:
    Triangle() {};
    Triangle(double a, double b, double c);
    double perimeter() {
        return _a + _b + _c;
    }
    double area() {
        double C = perimeter() / 2;
        return sqrt(C * (C - _a) * (C - _b) * (C - _c));
    }
    string toString();
    IShape* generate(int, int);
    string className() { return "Triangle"; }
};
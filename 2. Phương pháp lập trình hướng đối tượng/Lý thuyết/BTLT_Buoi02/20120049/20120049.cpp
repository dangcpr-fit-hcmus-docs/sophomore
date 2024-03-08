/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

// Class forward declaration (tham chieu vong)
class Point2D;
class Line2D;

// Class declaration
class Point2D {
private:
    int _x;
    int _y;
public:
    int X() { return _x; }
    int Y() { return _y; }
    void setX(int value) { _x = value; }
    void setY(int value) { _y = value; }
public: // Constructor - Khai báo
    Point2D();
    Point2D(int);
    Point2D(int, int);
    //~Point2D();
public:
    string toString();
};

class Line2D {
private:
    Point2D _start;
    Point2D _end;
public:
    Point2D start() { return _start; }
    Point2D end() { return _end; }
    void setStart(Point2D value) { _start = value; }
    void setEnd(Point2D value) { _end = value; }
public:
    Line2D();
    Line2D(Point2D, Point2D);
    string toString();
    float length(); // Độ dài của đường thẳng
};

// In class exercise: Cài đặt các hàm còn thiếu của Line ở đây
Line2D::Line2D() {
    _start = (0);
    _start.setY(0);
    _end.setX(0);
    _end.setY(0);
}
Line2D::Line2D(Point2D a, Point2D b) {
    _start = a;
    _end = b;
}
string Line2D::toString() {
    stringstream out;
    out << "( (" << this->_start.X() << ", " << this->_start.Y() << ") (" << this->_end.X() << ", " << this->_end.Y() << ") )";
    string result = out.str();
    return result;
}
float Line2D::length() {
    int a1 = (this->_start.X() - this->_end.X()) * (this->_start.X() - this->_end.X());
    int a2 = (this->_start.Y() - this->_end.Y())* (this->_start.Y() - this->_end.Y());
    float a = sqrt(a1 + a2);
    return a;
}
// class implementation - Cai dat thiet su
// Hàm tạo không có đối số - Max 1 - 
Point2D::Point2D() {
    _x = 0;
    _y = 0;
}

// Hàm tạo có đối số - Vô hạn
Point2D::Point2D(int a, int b) {
    _x = a;
    _y = b;
}

Point2D::Point2D(int i) {
    _x = i;
    _y = i;
}

string Point2D::toString() {
    stringstream out;
    out << "(" << this->_x << ", " << this->_y << ")";
    string result = out.str();
    return result;
}

//Point2D::~Point2D() {
    //cout << "Destructor of " << this->toString() << endl;
//}

int main()
{
    Point2D b(2, 4);
    Point2D c(3);

    Line2D line(b, c);
    cout << line.toString() << endl; // ((2, 4), (3, 3))
    cout << line.length() << endl;   // In ra độ dài của đường thẳng

    return 0;
}

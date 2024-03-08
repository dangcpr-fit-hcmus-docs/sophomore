#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

class CPoint2D;
class CCircle;
class CPoint2D {
private:
    double _x;
    double _y;
public:
    double X() { return _x; }
    double Y() { return _y; }
    void setX(double value) { _x = value; }
    void setY(double value) { _y = value; }
    double Distance();
};

double CPoint2D::Distance() {
    double dx = this->_x;
    double dy = this->_y;
    double d = sqrt(dx * dx + dy * dy);
    return d;
}
class CCircle {
private:
    CPoint2D m_pt2DCenter;
    double m_dRadius;
public:
    CPoint2D center() { return m_pt2DCenter; }
    double radius() { return m_dRadius; }
    void setCen(CPoint2D x) { m_pt2DCenter = x; }
    void setRad(double x) { m_dRadius = x; }
    void init();
    void output();
    void move(double, double);
    double getPerimeter();
    double getArea();
    double dis2Cir(CCircle);
    bool isInside(CCircle);
    bool isOverlap(CCircle);
    bool isBoundary(CCircle);
    bool isIntersection(CCircle);
    bool isContact(CCircle);
    bool isOutside(CCircle);
};
void CCircle::init() {
    double x, y, z;
    cout << "Nhap toa do tam x: ";  cin >> x; m_pt2DCenter.setX(x);
    cout << "Nhap toa do tam y: ";  cin >> y; m_pt2DCenter.setY(y);;
    cout << "Nhap ban kinh: "; cin >> z; m_dRadius = z;
}
void CCircle::output() {
    cout << "Tam (" << this->m_pt2DCenter.X() << ", " << this->m_pt2DCenter.Y() << ")\n";
    cout << "Ban kinh: " << m_dRadius << endl;
}
void CCircle::move(double dX, double dY) {
    double xNew = this->m_pt2DCenter.X() + dX;
    double yNew = this->m_pt2DCenter.Y() + dY;
    m_pt2DCenter.setX(xNew);
    m_pt2DCenter.setY(yNew);
}
double CCircle::getPerimeter() {
    double Per = 2 * this->m_dRadius * M_PI;
    return Per;
}
double CCircle::getArea() {
    double rad = this->m_dRadius;
    double Area = M_PI * rad * rad;
    return Area;
}
double CCircle::dis2Cir(CCircle cir) {
    double x = this->m_pt2DCenter.X();
    double y = this->m_pt2DCenter.Y();
    double rad = this->m_dRadius;
    double dx = x - cir.center().X();
    double dy = y - cir.center().Y();
    double d = sqrt(dx * dx + dy * dy);
    return d;
}
bool CCircle::isInside(CCircle cir) {
    double d = dis2Cir(cir);
    double rad = this->m_dRadius;
    double RadCir = cir.radius();
    if (d < RadCir - rad) return 1;
    else return 0;
}
bool CCircle::isOverlap(CCircle cir) {
    double d = dis2Cir(cir);
    if (d == 0) return 1;
    else return 0;
}
bool CCircle::isBoundary(CCircle cir) {
    double d = dis2Cir(cir);
    double rad = this->m_dRadius;
    double RadCir = cir.radius();
    if (d < rad - RadCir) return 1;
    else return 0;
}
bool CCircle::isIntersection(CCircle cir) {
    double d = dis2Cir(cir);
    double rad = this->m_dRadius;
    double RadCir = cir.radius();
    if (d > abs(rad - RadCir) && d < rad + RadCir) return 1;
    else return 0;
}
bool CCircle::isContact(CCircle cir) {
    double d = dis2Cir(cir);
    double rad = this->m_dRadius;
    double RadCir = cir.radius();
    if (d == rad + RadCir) return 1;
    else return 0;
}
bool CCircle::isOutside(CCircle cir) {
    double d = dis2Cir(cir);
    double rad = this->m_dRadius;
    double RadCir = cir.radius();
    if (d > rad + RadCir) return 1;
    else return 0;
}
int main() {
    CCircle A, B;
    A.init();
    B.init();
    A.output();
    B.output();
    //A.move(2, 3);
    //cout << "Sau khi doi:\n";
    A.output();
    B.output();
    cout << "Chu vi: " << A.getPerimeter() << endl;
    cout << "Dien tich: " << A.getArea() << endl;
    cout << "A nam trong B? " << A.isInside(B) << endl;
    cout << "A trung B? " << A.isOverlap(B) << endl;
    cout << "A chua B? " << A.isBoundary(B) << endl;
    cout << "A giao B? " << A.isIntersection(B) << endl;
    cout << "A tiep xuc B? " << A.isContact(B) << endl;
    cout << "A nam ben ngoai B? " << A.isOutside(B) << endl;
}
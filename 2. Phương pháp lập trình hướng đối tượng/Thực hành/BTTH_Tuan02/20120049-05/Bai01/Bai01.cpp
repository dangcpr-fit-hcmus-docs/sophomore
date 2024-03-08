#include <iostream>
#include <math.h>
using namespace std;

class CPoint2D;
class CPoint2D {
private:
    float _x;
    float _y;
public:
    float X() { return _x; }
    float Y() { return _y; }
    void setX(double value) { _x = value; }
    void setY(double value) { _y = value; }
    CPoint2D();
    CPoint2D(float, float);
    float Distance(CPoint2D);
};
CPoint2D::CPoint2D() {
    float x, y;
    cout << "Nhap x: ";  cin >> x; _x = x;
    cout << "Nhap y: ";  cin >> y; _y = y;
    cout << "(" << _x << ", " << _y << ")";
}
CPoint2D::CPoint2D(float x, float y) {
    _x = x;
    _y = y;
}
float CPoint2D::Distance(CPoint2D a) {
    float dx = this->_x - a.X();
    float dy = this->_y - a.Y();
    float d = sqrt(dx * dx + dy * dy);
    return d;
}
int main()
{
    CPoint2D a;
    CPoint2D b(4, 5);
    cout << endl << "Khoang cach x, y: " << a.Distance(b);
    return 0;
}
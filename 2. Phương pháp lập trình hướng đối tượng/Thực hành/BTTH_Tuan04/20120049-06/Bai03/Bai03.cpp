#include <iostream>
#include "Triangle.h"
int main()
{
    ArrayTriangle arr("Triangle.txt");
    cout << "Cac tam giac da doc:\n";
    arr.printArrTri();
    cout << "So tam giac da doc: " << arr.numTri() << endl;
    cout << "So tam giac khong hop le: " << arr.delInvaildTri() << endl;
    cout << "So tam giac con lai: " << arr.numTri() << endl;
    cout << "So tam giac deu: " << arr.equiTri() << endl;
    cout << "So tam giac vuong can: " << arr.rightIsoTri() << endl;
    cout << "So tam giac vuong: " << arr.rightTri() << endl;
    cout << "So tam giac nhon: " << arr.acuteTri() << endl;
    cout << "So tam giac tu: " << arr.obtuseTri() << endl;
}
#include <iostream>
#include <string>
using namespace std;

class CStudent;
double Input() {
    double x;
    cin >> x;
    while (x < 0 || x > 10) {
        cout << "Vui long nhap lai: ";
        cin >> x;
    }
    return x;
}
class CStudent {
private:
    string _fullname;
    double _literature;
    double _math;
public:
    string getFullname() { return _fullname; }
    double getLiterature() { return _literature; }
    double getMath() { return _math; }
    void setFullname(string full) { _fullname = full; }
    void setLiterature(double liter) { _literature = liter; }
    void setMath(double math) { _math = math; }
    CStudent();
    double getAverage();
    string Grade();
};
CStudent::CStudent() {
    string s;
    double Liter, Math;
    cout << "Nhap ten: "; getline(cin, s); setFullname(s);
    cout << "Ten: " << getFullname() << endl;
    cout << "Nhap diem Van: ";  Liter = Input(); setLiterature(Liter);
    cout << "Diem Van: " << getLiterature() << endl;
    cout << "Nhap diem Toan: "; Math = Input(); setMath(Math);
    cout << "Diem Toan: " << getMath() << endl;
}
double CStudent::getAverage() {
    double a = this->getLiterature();
    double b = this->getMath();
    return (a + b) / 2;
}
string CStudent::Grade() {
    double TB = getAverage();
    if (TB >= 9) return "Xuat sac";
    else if (TB >= 8) return "Gioi";
    else if (TB >= 6.5) return "Kha";
    else if (TB >= 5) return "Trung binh";
    else return "Yeu";
}
int main()
{
    CStudent A;
    cout << "Diem TB: " << A.getAverage() << endl;
    cout << "Xep loai: " << A.Grade();
    return 0;
}
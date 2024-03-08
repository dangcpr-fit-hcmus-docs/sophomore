#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;
class CRand;
class CRand {
public:
    int Random(int);
    int Random(int, int);
    double Random();
};
int CRand::Random(int n) {
    srand((unsigned)time(0));
    int x = rand() % n;
    return x;
}
int CRand::Random(int a, int b) {
    srand((unsigned)time(0));
    int x = rand() % (b - a + 1) + a;
    return x;
}
double CRand::Random() {
    double x = rand() / (double)RAND_MAX;
    return x;
}
int main()
{
    CRand D; 
    int n, a, b;
    cout << "Nhap n: "; cin >> n;
    cout << "So nguyen ngau nhien trong [0," << n << ") la: " << D.Random(n) << endl;
    cout << "Nhap a, b: "; cin >> a >> b;
    cout << "So nguyen ngau nhien trong [" << a <<"," << b << "] la: " << D.Random(a, b) << endl;
    cout << "So thuc ngau nhien trong [0,1] la: " << D.Random();
    return 0;
}
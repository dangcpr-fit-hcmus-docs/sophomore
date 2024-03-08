#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class RandomInteger;
class RandomFraction;

class RandomInteger {
public:
    //RandomInteger();
    unsigned int next();
    unsigned int next(int);
    unsigned int next(int, int);
    ~RandomInteger();
};

class RandomFraction {
private:
    int _num;
    int _den;
    RandomInteger _rng;
public:
    void setNum(int num) { _num = num; };
    void setDen(int den) { _den = den; };
    RandomFraction();
    void MinFrac();
    string toString();
    ~RandomFraction();
};

class ArrayFraction {
private:
    vector<RandomFraction> _F;
public:
    ArrayFraction();
    void Output();
    ~ArrayFraction();
};
unsigned int RandomInteger::next() {
    unsigned int x = rand() & 0xff;
    x |= (rand() & 0xff) << 8;
    x |= (rand() & 0xff) << 16;
    x |= (rand() & 0xff) << 24;
    return x;
}
unsigned int RandomInteger::next(int right) {
    unsigned int x = rand() & 0xff;
    x |= (rand() & 0xff) << 8;
    x |= (rand() & 0xff) << 16;
    x |= (rand() & 0xff) << 24;
    x = x % right;
    return x;
}
unsigned int RandomInteger::next(int left, int right) {
    unsigned int x = rand() & 0xff;
    x |= (rand() & 0xff) << 8;
    x |= (rand() & 0xff) << 16;
    x |= (rand() & 0xff) << 24;
    x = x % (left - right + 1) + left;
    return x;
}
RandomInteger::~RandomInteger(){}

RandomFraction::RandomFraction() {
    _num = _rng.next(500);
    do {
        _den = _rng.next(500);
    } while (_den == 0);
}
void RandomFraction::MinFrac() {
    unsigned int a = _num; unsigned int b = _den;
    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    _num /= a; _den /= b;
}
string RandomFraction::toString() {
    stringstream ss;
    ss << _num << "/" << _den << "\n";
    string s = ss.str();
    return s;
}
RandomFraction::~RandomFraction(){}

ArrayFraction::ArrayFraction() {
    for (int i = 0; i < 20; i++) {
        RandomFraction tmp;
        tmp.MinFrac();
        _F.push_back(tmp);
    }
}
void ArrayFraction::Output() {
    for (int i = 0; i < 20; i++) {
        cout << _F[i].toString();
    }
}
ArrayFraction::~ArrayFraction() {}
int main() {
    srand(time(NULL));
    ArrayFraction F;
    F.Output();
    return 0;
}
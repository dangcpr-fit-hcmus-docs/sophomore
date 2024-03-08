// DemoCopyConstructorCopyAssignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*#include <iostream>
#include <string>
#include <sstream>
using namespace std;


// Forward declaration, thường trong main
class Fraction;
class IntegerRandomizer;
class DynamicFractionArray;

// .h: class declartion
class Fraction {
private:
    int _num;
    int _den;
public:
    int numerator() { return _num; }
    int denominator() { return _den; }
    void setNumerator(int value) { _num = value; }
    void setDenominator(int value) { _den = value; }
public:
    Fraction();
    Fraction(int num, int den);
    string toString();

    // Copy assignment operator
};

class IntegerRandomizer {

public:
    IntegerRandomizer() {
        srand(time(NULL));
    }

    int next() {
        return rand();
    }
    int next(int _not) {
        int res;
        do {
            res = rand();
        } while (res == _not);
        return res;
    }
};

//.cpp Implementation
Fraction::Fraction() {
    _num = 0;
    _den = 1;
}

Fraction::Fraction(int num, int den) : _num(num), _den(den) {}

string Fraction::toString() {
    stringstream builder;
    builder << _num << "/" << _den;

    string result = builder.str();
    return result;
}
class FractionRandomizer {
private:
    IntegerRandomizer _rng;
public:
    Fraction next() {
        int num = _rng.next();
        int den = _rng.next(0);
        Fraction tmp(num, den);
        return tmp;
    }
};
class DynamicFractionArray {
private:
    Fraction* _a = NULL;
    int _maxSize;
    int _currentSize;
    const int _length = 10;
public:
    DynamicFractionArray() {
        _a = new Fraction[_length];
        _maxSize = _length;
        _currentSize = 0;
    }

    DynamicFractionArray(const DynamicFractionArray& other) {
        _maxSize = other._maxSize;
        _currentSize = other._currentSize;
        _a = new Fraction[_maxSize];

        for (int i = 0; i < _currentSize; i++) {
            _a[i] = other._a[i];
        }
    }

    const DynamicFractionArray& operator=(const DynamicFractionArray& other) {
        _maxSize = other._maxSize;
        _currentSize = other._currentSize;
        _a = new Fraction[_maxSize];

        for (int i = 0; i < _currentSize; i++) {
            _a[i] = other._a[i];
        }

        return other;
    }

    ~DynamicFractionArray() {
        cout << "Destructor" << endl;

        if (_a != NULL) {
            delete[] _a;
        }
    }

    Fraction getAt(int index) {
        if (index < _currentSize) {
            return _a[index];
        }
        else {
            throw "Index out of bound";
        }
    }

    Fraction operator[] (int index) {
        return getAt(index);
    }

    int size() { return _currentSize; }

    void push_back(Fraction value) {
        if (_currentSize >= _maxSize) {
            // Cấp phát vùng nhớ mới
            _maxSize = _maxSize + _length;
            Fraction* temp = new Fraction[_maxSize];

            // Di chuyển dữ liệu cũ qua
            for (int i = 0; i < _currentSize; i++) {
                temp[i] = _a[i];
            }

            // Giải phóng vùng nhớ cũ
            delete[] _a;

            // Giao quyền quản lí lại cho _a
            _a = temp;
        }

        _a[_currentSize] = value;
        _currentSize++;
    }
    void removeAt(int index) {
        for (int i = index + 1; i < _currentSize; i++) {
            _a[i - 1] = _a[i];
        }

        _currentSize--;
    }
};
int main()
{
    DynamicFractionArray a;
    FractionRandomizer rng;

    for (int i = 0; i < 20; i++) {
        a.push_back(rng.next());
    }

    for (int i = 0; i < a.size(); i++) {
        cout << a[i].toString() << " ";
    }
    cout << endl;
}*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    multimap<int, int> nums;
    vector<int> result;
    int n, tmp, target;
    cin >> n; //Size of array 
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        nums.insert({ tmp,i });
    }
    cin >> target;
    for (auto i = nums.begin(); i != nums.end(); ++i) {
        auto it = nums.find(target - i->first);
        if (it->second != i->second && i->first + it->first == target) {
            result.push_back(i->second);
            result.push_back(it->second);
            break;
        }
    }
    cout << "[" << result[0] << ", " << result[1] << "]";
}

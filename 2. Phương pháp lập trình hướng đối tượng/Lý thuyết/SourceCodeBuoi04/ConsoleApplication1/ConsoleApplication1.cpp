// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;

//Forward declaration
class Fraction;
class FractionToLowestTermConverter;
class FractionToMixedFractionConverter;
class FractionToDecimalConverter;
class Integer;
class RandomIntegerGenerator;
class RandomFractionGenerator;
class RandomDateGenerator;
class Fullname;
class RandomFullnameGenerator;


class Fullname {
private:
    string _firstname;
    string _middlename;
    string _lastname;
public:
    Fullname(string first, string middle, string last) {
        _firstname = first;
        _middlename = middle;
        _lastname = last;
    }

    string toString() {
        stringstream builder;

        builder << _firstname << " "
            << _middlename << " "
            << _lastname;

        string result = builder.str();
        return result;
    }
};

class RandomIntegerGenerator {
public:
    RandomIntegerGenerator();
public:
    int next();
    int next(int);
    int next(int, int);
};

class RandomFullnameGenerator {
private:
    vector<string> _firstNames;
    vector<string> _middleNames;
    vector<string> _lastNames;
    RandomIntegerGenerator _rng;

public:
    RandomFullnameGenerator();

    Fullname next();
};

// Class declaration
class Fraction {
private:
    int _num;
    int _den;
public:
    int Numerator() const { return _num; }
    int Denominator() const { return _den; }
    void setNumerator(int value) { _num = value; }
    void setDenominator(int value) { _den = value; }
    Fraction lowestTerm() const;
public:
    Fraction();
    Fraction(int, int);
    Fraction(int);
    string toString();    
};

class FractionToLowestTermConverter
{
public:
    string convert(const Fraction& f, void* args = NULL);
    Fraction convertBack(const string value);
};

class FractionToMixedFractionConverter {
public:
    string convert(const Fraction& f, void* args = NULL);
    Fraction convertBack(const string value);
};

class FractionToDecimalConverter {
public:
    string convert(const Fraction& f, void* args = NULL);
    Fraction convertBack(const string value);
};

class Integer {
public:
    static int gcd(int a, int b);
};





RandomFullnameGenerator::RandomFullnameGenerator() {
    _firstNames = {
        "Dinh", "Ly", "Tran", "Le", "Nguyen", "Vuong", "Mai", "Do"
    };
    _middleNames = {
        "Thien", "Vuong", "Tai", "Huong", "Linh", "Mai"
    };
    _lastNames = {
        "Dung", "Tuan", "Huy", "Dieu", "Lan", "Ngoc"
    };
}

Fullname RandomFullnameGenerator::next() {
    

    int index = _rng.next(_firstNames.size());
    string first = _firstNames[index];

    index = _rng.next(_middleNames.size());
    string middle = _middleNames[index];

    index = _rng.next(_lastNames.size());
    string last = _lastNames[index];

    Fullname result(first, middle, last);
    return result;
}

RandomIntegerGenerator::RandomIntegerGenerator() {
    srand(time(NULL));
}

int RandomIntegerGenerator::next() {
    int result = rand();
    return result;
}

/// <summary>
/// Sinh số ngẫu nhiên trong nửa khoảng [0, max)
/// </summary>
/// <param name="ceiling">Giá trị tối đa</param>
/// <returns>Số nguyên ngẫu nhiên</returns>
int RandomIntegerGenerator::next(int ceiling) {
    int result = rand() % ceiling;
    return result;
}

/// <summary>
/// Sinh số ngẫu nhiên trong đoạn [left, right]
/// </summary>
/// <param name="left">Biên trái</param>
/// <param name="right">Biên phải</param>
/// <returns>Số nguyên ngẫu nhiên</returns>
int RandomIntegerGenerator::next(int left, int right) {
    int result = rand() % (left - right + 1) +  left;
    return result;
}

int Integer::gcd(int a, int b) {
    while (a * b != 0) {
        if (a > b) {
            a = a - b;
        }
        else {
            b = b - a;
        }
    }
    return a;
}

/// <summary>
/// Chuyển đổi phân số sang dạng hiển thị tối giản
/// </summary>
/// <param name="f">Phân số cần chuyển đổi</param>
/// <returns>Chuỗi phân số ở dạng tối giản</returns>
string FractionToLowestTermConverter::convert(const Fraction& f, void* args) {
    Fraction lowest = f.lowestTerm();

    stringstream builder;
    
    builder << lowest.Numerator() << "/" << lowest.Denominator();

    string result = builder.str();
    return result;
}

Fraction FractionToLowestTermConverter::convertBack(const string value) {
    // TODO
    Fraction result;
    return result;
}

string FractionToMixedFractionConverter::convert(const Fraction& f, void* args) {
    auto lowest = f.lowestTerm();
    stringstream builder;

    if (lowest.Numerator() >= lowest.Denominator()) {
        int fullNumber = lowest.Numerator() / lowest.Denominator();
        builder << fullNumber << " ";

        int num = lowest.Numerator() % lowest.Denominator();
        builder << num << "/";
    }
    else {
        builder << lowest.Numerator() << "/";
    }

    builder << lowest.Denominator();
    
    string result = builder.str();
    return result;
}

Fraction FractionToMixedFractionConverter::convertBack(const string value) {
    // TODO
    Fraction result;
    return result;
}

string FractionToDecimalConverter::convert(const Fraction& f, void* args) {
    float value = ((float) f.Numerator()) / f.Denominator();
    int* precision = (int*)args;
    int number = *precision;

    stringstream builder;

    builder << setprecision(number) << value;

    string result = builder.str();
    return result;
}

Fraction FractionToDecimalConverter::convertBack(const string value) {
    // TODO
    Fraction result;
    return result;
}


/// <summary>
/// Trả về dạng tối giản của phân số
/// </summary>
/// <returns>Phân số đã tối giản</returns>
Fraction Fraction::lowestTerm() const {
    int gcd = Integer::gcd(_num, _den);
    int num = _num / gcd;
    int den = _den / gcd;
    
    Fraction result(num, den);
    return result;
}

Fraction::Fraction() {
    _num = 0;
    _den = 1;
}

Fraction::Fraction(int num, int den):_num(num), _den(den) {
}

Fraction::Fraction(int num) {
    _num = num;
    _den = 1;
}

string Fraction::toString() {
    stringstream builder;
    
    builder << _num << "/" << _den;
    
    string result = builder.str();
    return result;
}

int main()
{
   /* Fraction f(8, 6);

    FractionToLowestTermConverter lowestTermConverter;
    string view1 = lowestTermConverter.convert(f);
    cout << view1 << endl;

    FractionToMixedFractionConverter mixedConverter;
    string view2 = mixedConverter.convert(f);
    cout << view2 << endl;

    FractionToDecimalConverter decimalConverter;
    int precision = 3;
    string view3 = decimalConverter.convert(f, &precision);

    cout << view3 << endl;*/

    RandomFullnameGenerator rng;
    vector<Fullname> a;
    int minimum = 10;
    int maximum = 270;

    for (int i = 0; i < 10; i++) {
        Fullname person = rng.next();
        a.push_back(person);
    }

    for (int i = 0; i < a.size(); i++) {
        cout << a[i].toString() << endl;
    }


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

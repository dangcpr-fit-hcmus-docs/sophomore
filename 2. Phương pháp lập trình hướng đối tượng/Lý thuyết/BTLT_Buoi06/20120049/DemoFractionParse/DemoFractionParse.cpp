// DemoFractionParse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <tuple>
#include <sstream>
#include <regex>
#include <vector>
#include <memory>
#include <fstream>
using namespace std;

class Integer {
public:
    /// <summary>
    /// Chuyển chuỗi sang số nguyên
    /// Error code: Không phụ thuộc ngôn ngữ
    /// 0: Success Thành công
    /// 1: Lỗi chuỗi ko đúng định dạng
    /// 2: Không có giá trị đầu vào
    /// 3: Miền giá trị không đúng
    /// </summary>
    /// <param name="value">Chuỗi</param>
    /// <returns></returns>
    static tuple<bool, int, string, int> parse(string value) {
        bool successful = true;
        int errorCode = 0;
        string message = "";
        int number = 0;

        if (value.size() == 0) {
            errorCode = 3;
            message = "Input string cannot be empty";
        }
        else {
            try {
                number = stoi(value);
            }
            catch (exception ex) {
                successful = false;
                errorCode = 1;
                message = ex.what();
            }
        }

        auto result = make_tuple(
            successful, errorCode, message, number
        );
        return result;
    }

    // Ưu: Luồng xử lí ko bị bẻ gãy đột ngột bởi exception
    // Nhược: 1. Thất bại ko biết tại sao?
    // 2. Không có cách gì thông báo cho người dùng
    // 3. Giá trị mặc định đôi khi không nên có
    static bool tryParse(string value, int& number) {
        bool successful = false;

        try {
            number = stoi(value);
            successful = true;
        }
        catch (exception ex) {
            successful = false;
        }

        return successful;
    }
};

class StringHelper {
public:
    static vector<string> split(string line, string separator) {
        vector<string> result;

        int startPosition = 0;
        size_t foundPosition = line.find(separator, startPosition);

        while (foundPosition != string::npos) {
            string token = line.substr(startPosition, foundPosition - startPosition);
            result.push_back(token);

            startPosition = foundPosition + separator.size();
            foundPosition = line.find(separator, startPosition);
        }
        
        // Chuoi con lai
        string token = line.substr(startPosition, line.size() - startPosition);
        result.push_back(token);
        return result;
    }
};

class Fraction { // Data transfer object 
private:
    int _num;
    int _den;
public:
    int Numerator() { return _num; }
    int Denominator() { return _den; }
    void setNumerator(int value) { _num = value; }
    void setDenominator(int value) { _den = value; }
    int gcd();
public:
    Fraction() {
        _num = 0;
        _den = 1;
    }
    Fraction(int num, int den): _num(num), _den(den) {}
    ~Fraction() {
        cout << "Fraction destructor" << endl;
    }
    string toString() {
        stringstream builder;
        builder << _num << "/" << _den;

        string result = builder.str();
        return result;
    }

    // Không nên viết như thế này!
    void input() { 
        cout << "Nhap tu:";
        cin >> _num;
        cout << "Nhap mau:";
        cin >> _den;
    }

    // Không ưa thích
    // 1. Truy cập tới giao diện bên trong lớp DTO
    // 2. friend phá vỡ nguyên tắc hdt mà bạn học chỉ để phục vụ cú pháp ngôn ngữ
    friend istream& operator>>(istream& is, Fraction& f) {
        cout << "Nhap tu:";
        is >> f._num;
        cout << "Nhap mau:";
        is >> f._den;

        return is;
    }

    /// <summary>
    /// Chuyển chuỗi sang phân số
    /// </summary>
    /// <param name="line">Phân số dưới định dạng Tu/Mau</param>
    /// <returns>
    /// 0: Thành công
    /// 1: Không có dữ liệu (chuỗi rỗng)
    /// 2: Chuỗi không đúng định dạng
    /// 3: Không đúng miền giá trị (mẫu = 0)
    /// </returns>
    static tuple<bool, int, string, shared_ptr<Fraction>> parse(string line) {
        bool successful = false;
        int errorCode = 0;
        string message = "";
        shared_ptr<Fraction> f = NULL;
        
        if (line.size() == 0) {
            errorCode = 1;
            message = "Input string cannot be empty";
        }
        else {
            string pattern = "\\d+\\/\\d+";
            bool isMatched = regex_match(line, regex(pattern));

            if (!isMatched) {
                errorCode = 2;
                message = "Invalid fraction format";
            }
            else {
                // Tách chuỗi ra làm 2 phần dựa trên dấu /
                const string separator = "/";
                auto tokens = StringHelper::split(line, separator);
                int num = stoi(tokens[0]);
                int den = stoi(tokens[1]);

                if (den == 0) {
                    errorCode = 3;
                    message = "Denominator cannot be 0";
                }
                else {
                    successful = true;
                    f = make_shared<Fraction>(num, den);
                    // f= new Fraction(num, den)
                }
            }
        }
        
        auto result = make_tuple(successful, errorCode, message, f);
        return result;
    }
};
int Fraction::gcd() {
    int num = abs(_num);
    int den = abs(_den);
    while (num != den) {
        if (num > den) num -= den;
        else den -= num;
    }
    return num;
}
class VectorFraction {
private:
    vector<shared_ptr<Fraction>> _F;
public:
    VectorFraction(vector<shared_ptr<Fraction>> F) { _F = F; }
    vector<shared_ptr<Fraction>> getVectorFraction() { return _F; }
    int gcd();
    Fraction sum();
    string minSum();
};
//int VectorFraction::gcd() {
  //  for (int i = 1; i < _F.size(); i++) {
//
  //  }
//}
Fraction VectorFraction::sum() {
    long long Mul = 1, Sum = 0;
    for (int i = 0; i < _F.size(); i++) {
        Mul *= _F[i]->Denominator();
    }
    for (int i = 0; i < _F.size(); i++) {
        Sum += (Mul / _F[i]->Denominator()) * _F[i]->Numerator();
    }
    Fraction FSum(Sum, Mul);
    return FSum;
}

string VectorFraction::minSum() {
    stringstream ss;
    Fraction sum = VectorFraction::sum();
    if (sum.Numerator() % sum.Denominator() == 0) {
        ss << sum.Numerator() / sum.Denominator();
    }
    else if (sum.Numerator() / sum.Denominator() < 1) {
        ss << sum.Numerator() / sum.gcd() << "/" << sum.Denominator() / sum.gcd();
    }
    else {
        int gcd = sum.gcd();
        int num = sum.Numerator() / gcd;
        int den = sum.Denominator() / gcd;
        int z = num / den;
        ss << z << ' ' << num - z * den << '/' << den;
    }
    string s = ss.str();
    return s;
}
int main()
{
    // Thao tác với Tuple
    /*auto point = make_tuple(1, 2);
    get<0>(point) = 99;

    cout << get<0>(point) << ", " << get<1>(point) << endl;

    int x;
    int y;
    tie(x, y) = point;
    x = 101;

    cout << get<0>(point) << ", " << y << endl;*/

    // 1. Chuyển chuỗi sang số nguyên
    
    bool successful = false;
    int errorCode = 0;
    string message = "";
    shared_ptr<Fraction> f ; // reference counting

    //do {
    //    cout << "Please enter a fraction:";
    //    string line = "";
    //    getline(cin, line);
    //   
    //    tie(successful, errorCode, message, f) = 
    //        Fraction::parse(line);
    //    
    //    if (successful) {
    //        cout << f->toString() << endl; // Converter
    //    }
    //    else {
    //        cout << "Cannot convert string into fraction. Reason: " 
    //            << message << endl;
    //        cout << "Please enter again!" << endl;
    //    }
    //} while (!successful);

    const string filepath = "data.txt";
    ifstream reader;
    reader.open(filepath);

    vector<shared_ptr<Fraction>> a;

    while (!reader.eof()) {
        string line;
        getline(reader, line);

        tie(successful, errorCode, message, f) =
                   Fraction::parse(line);

        a.push_back(f);
    }
    reader.close();

    for (int i = 0; i < a.size(); i++) {
        cout << a[i]->toString() << " ";
    }
    cout << endl;
    // Bài tập về nhà:
    // Xuất ra tổng của tất cả các phân số vào tập tin output.txt
    // Tổng cần phải rút gọn tối thiểu
    // 4/1 => 4        Minimal fraction
    // 8/6 => 1 1/3    Mixed fraction
    // 8/10 => 4/5     Lowest term
    VectorFraction F(a);

    const string outputPath = "output.txt";
    ofstream writer;
    writer.open(outputPath);

    writer << F.minSum();
    writer.close();




    // 2. Tách chuỗi
    // 3. Exception
    // 4. Nhập phân số một cách tự nhiên

   
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

#include <iostream>
#include <string>
#include <vector>
using namespace std;
char add(char a, char b) {
    if (a == '0' && b == '0') return '0';
    else if ((a == '0' && b == '1') || (a == '1' && b == '0')) return '1';
    else if (a == '1' && b == '1') return '2';
    else if ((a == '2' && b == '0') || (a == '0' && b == '2')) return '2';
    else if ((a == '2' && b == '1') || (a == '1' && b == '2')) return '3';
}
string addBinary(string b1, string b2) {
    string result = "";
    int tmp = 0;
    int size_b1 = b1.size() - 1;
    int size_b2 = b2.size() - 1;
    while (size_b1 >= 0 || size_b2 >= 0 || tmp == 1) {
        if (size_b1 >= 0) tmp += b1[size_b1] - '0';
        if (size_b2 >= 0) tmp += b2[size_b2] - '0';
        result = char(tmp % 2 + '0') + result;
        tmp /= 2;
        size_b1--; size_b2--;
    }
    result = result.substr(result.size() - max((int)b1.size(), (int)b2.size()), max((int)b1.size(), (int)b2.size()));
    return result;
}

void offsetTwo(string& b, int n) {
    for (int i = b.size(); i < n; i++) {
        b.insert(b.begin(), '0');
    }
    for (int i = 0; i < b.size(); i++) {
        if (b[i] == '0') b[i] = '1';
        else b[i] = '0';
    }
    b = addBinary(b, "1");
}
string subBinary(string b1, string b2) {
    //Chuyen b2 sang so bu 2 cua b2
    string result = "";
    offsetTwo(b2, b1.size());
    for (int i = b1.size(); i < b2.size(); i++) {
        b1.insert(b1.begin(), '0');
    }
    //Cong b1 voi so bu 2 cua b2;
    result = addBinary(b1, b2);
    result = result.substr(result.size() - max(b1.size(), b2.size()), max(b1.size(), b2.size()));
    return result;
}

void convert(char& a) {
    if (a == '0') a = '1';
    else a = '0';
}
string multBinary(string M, string Q) {
    string result = "";
    string A = "";
    for (int i = 0; i < Q.size(); i++) {
        A.insert(A.begin(), '0');
    }
    string Q1 = "0";
    bool SA = M[0] - '0';
    int k = Q.size();
    for (int i = k; i > 0; i--) {
        string Q0Q1 = Q[Q.size() - 1] + Q1;
        if (Q0Q1 == "10") {
            A = subBinary(A, M);
            A = A.substr(A.size() - min((int)A.size(), k), min((int)A.size(), k));
            SA = 1;
        }
        else if (Q0Q1 == "01") {
            A = addBinary(A, M);
            A = A.substr(A.size() - min((int)A.size(), k), min((int)A.size(), k));
            SA = 0;
        }
        result = A + Q + Q1;
        result.erase(result.size() - 1, 1);
        if (SA == 0) {
            result.insert(result.begin(), '0');
        }
        else {
            result.insert(result.begin(), '1');
        }
        A = result.substr(0, k);
        Q = result.substr(k, k);
        Q1 = result.substr(2 * k, 1);
    }
    return result.substr(0, 2 * k);
}
bool check0(string a, int k) {
    for (int i = k; i < a.size(); i++) {
        if (a[i] == '1') return 0;
    }
    return 1;
}
vector<string> divBinary(string Q, string M) {
    vector<string> res;
    string result = "";
    string A = "";
    if (Q[0] == '0') {
        for (int i = 0; i < Q.size(); i++) {
            A.insert(A.begin(), '0');
        }
    }
    else {
        for (int i = 0; i < Q.size(); i++) {
            A.insert(A.begin(), '1');
        }
    }
    //bool SA = M[0] - '0';
    int k = Q.size();
    A = A.substr(A.size() - min((int)A.size(), k), min((int)A.size(), k));
    for (int i = k; i > 0; i--) {
        result = A + Q;
        result.erase(0, 1);
        result.insert(result.end(), '0');
        A = result.substr(0, k);
        Q = result.substr(k, k);
        A = subBinary(A, M);
        if (A[0] == '1' || check0(A, 0) == 0) {
            Q[Q.size() - 1] = '0';
            A = addBinary(A, M);
            A = A.substr(A.size() - min((int)A.size(), k), min((int)A.size(), k));
            //SA = 1;
        }
        else {
            Q[Q.size() - 1] = '1';
            //SA = 0;
        }
    }
    res.push_back(A);
    res.push_back(Q);
    return res;
}
int main()
{
    string A, B;
    cout << "Bit dau tien la bit dau:\n";
    cout << "So nhi phan thu 1: "; cin >> A;
    cout << "So nhi phan thu 2: "; cin >> B;
    cout << "Tong: " << addBinary(A, B) << endl;
    cout << "Hieu: " << subBinary(A, B) << endl;
    cout << "Tich: " << multBinary(A, B) << endl;
    vector<string> divB = divBinary(A, B);
    cout << "Thuong: " << divB[1] << endl;
    cout << "So du: " << divB[0] << endl;
    return 0;
}
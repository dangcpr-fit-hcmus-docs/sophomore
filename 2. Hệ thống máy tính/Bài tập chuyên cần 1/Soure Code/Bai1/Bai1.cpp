#include <iostream>
#include <string>
#include <math.h>
#include <regex>
using namespace std;

string DecToBin(int k) {
    string result = "";
    if (k == 0) return "0";
    while (k != 0) {
        int r = k % 2;
        result.insert(0, to_string(r));
        k = k / 2;
    }
    return result;
}

string DecToHex(int k) {
    string result = "";
    if (k == 0) return "0";
    while (k != 0) {
        int r = k % 16;
        if (r <= 9) result.insert(0, to_string(r));
        else {
            string tmp;
            switch (r) {
            case 10: tmp = 'A'; break;
            case 11: tmp = 'B'; break;
            case 12: tmp = 'C'; break;
            case 13: tmp = 'D'; break;
            case 14: tmp = 'E'; break;
            case 15: tmp = 'F'; break;
            }
            result.insert(0, tmp);
        }
        k = k / 16;
    }
    return result;
}

int BinToDec(string k) {
    int result = 0;
    for (int i = k.size() - 1; i >= 0; i--) {
        result += ((int)k[i] - 48) * pow(2, k.size() - i - 1);
    }
    return result;
}
int HexToDec(string k) {
    int result = 0;
    for (int i = k.size() - 1; i >= 0; i--) {
        int tmp = 0;
        switch (k[i]) {
        case 'A': case 'a': tmp = 10; break;
        case 'B': case 'b': tmp = 11; break;
        case 'C': case 'c': tmp = 12; break;
        case 'D': case 'd': tmp = 13; break;
        case 'E': case 'e': tmp = 14; break;
        case 'F': case 'f': tmp = 15; break;
        default: tmp = (int)k[i] - 48;
        }
        result += tmp * pow(16, k.size() - i - 1);
    }
    return result;
}

string BinToHex(string k) {
    string result = "";
    for (int i = k.size() - 1; i >= 0; i -= 4) {
        string stmp;
        int start = i - 3;

        if (start < 0) stmp = k.substr(0, i + 1);
        else stmp = k.substr(start, 4);

        int itmp = BinToDec(stmp);
        string stmp2;
        switch (itmp) {
        case 10: stmp2 = 'A'; break;
        case 11: stmp2 = 'B'; break;
        case 12: stmp2 = 'C'; break;
        case 13: stmp2 = 'D'; break;
        case 14: stmp2 = 'E'; break;
        case 15: stmp2 = 'F'; break;
        default: stmp2 = to_string(itmp);
        }
        result.insert(0, stmp2);
    }
    return result;
}
int main()
{
    int k; string s;
    cout << "Chon chuc nang: \n";
    cout << "1. Base-10 to Base-2\n";
    cout << "2. Base-10 to Base-16\n";
    cout << "3. Base-2 to Base-10\n";
    cout << "4. Base-16 to Base-10\n";
    cout << "5. Base-2 to Base-16\n";
    cout << "0. Thoat chuong trinh\n";

    string option;
    cout << "Chuc nang ban chon: "; getline(cin, option);

    while (!regex_match(option, regex("[012345]")) || option == "") {
        cout << "Vui long nhap lai: "; getline(cin, option);
    }

    if (option == "1") {
        cout << "\nNhap so base-10: ";  cin >> k;
        cout << "Ket qua: " << DecToBin(k) << endl;
    }
    else if (option == "2") {
        cout << "\nNhap so base-10: ";  cin >> k;
        cout << "Ket qua: " << DecToHex(k) << endl;
    }
    else if (option == "3") {
        cout << "\nNhap so base-2: ";  cin >> s;
        cout << "Ket qua: " << BinToDec(s) << endl;
    }
    else if (option == "4") {
        cout << "\nNhap so base-16: "; cin >> s;
        cout << "Ket qua: " << HexToDec(s) << endl;
    }
    else if (option == "5") {
        cout << "\nNhap so base-2: "; cin >> s;
        cout << "Ket qua: " << BinToHex(s) << endl;
    }
}
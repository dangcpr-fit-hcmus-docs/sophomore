#include <iostream>
using namespace std;
class CStaticArray;
void Swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}
class CStaticArray {
private:
    int _n;
    int _arr[100];
public:
    int* getArray() { return _arr; }
    int getNum() { return _n; }
    void setArray(int arr[]) {
        for (int i = 0; i < 100; i++) {
            _arr[i] = arr[i];
        }
    }
    void setNum(int n) {
        _n = n;
    }
    CStaticArray(int);
    int Size();
    int GetEle(int);
    void Find(int);
    void MaxMin();
    void Ascending();
    void Descending();
};
CStaticArray::CStaticArray(int n) {
    this->setNum(n);
    for (int i = 0; i < this->getNum(); i++) {
        cout << "arr[" << i << "] = ";
        cin >> this->_arr[i];
    }
    for (int i = 0; i < this->getNum(); i++) {
        cout << this->_arr[i]  << ' ';
    }
}
int CStaticArray::Size() {
    return sizeof(int) * this->getNum();
}
int CStaticArray::GetEle(int i) {
    return this->_arr[i];
}
void CStaticArray::Find(int k) {
    cout << "Cac vi tri thoa man: ";
    for (int i = 0; i < this->getNum(); i++) {
        if (this->_arr[i] == k) cout << i << ' ';
    }
}
void CStaticArray::MaxMin() {
    int max = 0;
    int min = 0;
    for (int i = 0; i < this->getNum(); i++) {
        if (this->_arr[i] < this->_arr[min])
            min = i;
        if (this->_arr[i] > this->_arr[max])
            max = i;
    }
    cout << "Phan tu be nhat la phan tu: arr[" << min << "] = " << this->_arr[min] << endl;
    cout << "Phan tu lon nhat la phan tu: arr[" << max << "] = " << this->_arr[max] << endl;
}
void CStaticArray::Ascending() {
    for (int i = 0; i < this->getNum() - 1; i++) {
        for (int j = i + 1; j < this->getNum(); j++) {
            if (this->_arr[i] > this->_arr[j]) {
                Swap(this->_arr[i], this->_arr[j]);
            }
        }
    }
    cout << "Mang sap xep tang: ";
    for (int i = 0; i < this->getNum(); i++) {
        cout << this->_arr[i] << ' ';
    }
}
void CStaticArray::Descending() {
    for (int i = 0; i < this->getNum() - 1; i++) {
        for (int j = i + 1; j < this->getNum(); j++) {
            if (this->_arr[i] < this->_arr[j]) {
                Swap(this->_arr[i], this->_arr[j]);
            }
        }
    }
    cout << "Mang sap xep giam: ";
    for (int i = 0; i < this->getNum(); i++) {
        cout << this->_arr[i] << ' ';
    }
}
int main() {
    int n;
    cout << "Nhap so phan tu: ";  cin >> n;
    CStaticArray A(n);
    cout << "\nSize : " << A.Size();
    cout << "\nLay gia tri phan tu thu: "; cin >> n;
    cout << "Phan tu thu " << n << " la " << A.GetEle(n) << endl;
    A.MaxMin();
    A.Ascending(); cout << endl;
    A.Descending(); cout << endl;
}
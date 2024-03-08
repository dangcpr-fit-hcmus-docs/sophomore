#include <iostream>
#include <exception>
using namespace std;


class Fraction {
private:
	double _num;
	double _den;
public:
	Fraction() {
		_num = 0;
		_den = 1;
	};
	Fraction(double num, double den) {
		_num = num;
		_den = den;
	}
	~Fraction() {};
	double num() { return _num; }
	double den() { return _den; }
	void setNum(double num) { _num = num; }
	void setDen(double den) { _den = den; }
	bool operator < (const Fraction& f) {
		if (_num / _den < f._num / f._den)
			return 1;
		else
			return 0;
	}
	void operator = (Fraction const &f) {
		_num = f._num;
		_den = f._den;
	}
	friend ostream& operator << (ostream& os, const Fraction& f) {
		os << f._num << '/' << f._den;
		return os;
	}
	friend istream& operator >> (istream& is, Fraction& f) {
		is >> f._num >> f._den;
		return is;
	}
};

template<class T>
class MyArray {
private:
	T* array;
	int n;
public:
	T& operator[] (int);
	MyArray();
	MyArray(int l);
	~MyArray();
	void setArray(T*, int);
	void sort();
	void print();
	void input();
};
template<class T>
T& MyArray<T>::operator[] (int index) {
	if (index >= n) {
		cout << "Array index out of bound, exiting";
		exit(0);
	}
	return array[index];
}
template<class T>
MyArray<T>::MyArray() {
	array = NULL;
}
template<class T>
MyArray<T>::MyArray(int l) {
	array = new T[l];
	n = l;
}
template<class T>
MyArray<T>::~MyArray() {
	if (array != NULL)
		delete[] array;
}
template<class T>
void MyArray<T>::setArray(T * a, int l) {
	if (array != NULL)
		delete[] array;
	n = l;
	array = new T[n];
	for (int i = 0; i < n; i++) {
		array[i] = a[i];
	}
}
template<class T>
void MyArray<T>::sort() {
	T temp;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (array[i] < array[j]) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
}
template<class T>
void MyArray<T>::print() {
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << array[i] << " ";
	cout << endl;
}
template<class T>
void MyArray<T>::input() {
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}
}

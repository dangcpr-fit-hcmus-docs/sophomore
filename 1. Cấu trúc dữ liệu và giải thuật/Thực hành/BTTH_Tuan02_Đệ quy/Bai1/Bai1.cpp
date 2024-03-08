#include <iostream>
#include <math.h>
using namespace std;

void swap(char& a, char& b) {
	char tmp = a;
	a = b;
	b = tmp;
}

int TongDaySoNguyen(int n) {
	if (n == 1) return n;
	else {
		return TongDaySoNguyen(n - 1) + n;
	}
}
int Fibo(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else
		return Fibo(n - 1) + Fibo(n - 2);
}
int UCLN(int a, int b) {
	if (a == b) return a;
	else {
		if (a > b) UCLN(a - b, b);
		else UCLN(a, b - a);
	}
}
int recursiveBinarySearch(int* a, int left, int right, int key) {
	int mid = (left + right) / 2;
	if (a[mid] == key) return mid;
	else if (left == right) return -1; //khong tim duoc phan tu
	else {	
		if (a[mid] > key) return recursiveBinarySearch(a, left, mid - 1, key);
		else return recursiveBinarySearch(a, mid + 1, right, key);
	}
}
void permutation(char* a, int start) {
	int end = strlen(a) - 1;
	if (start == end) cout << a << ' ';
	else {
		for (int i = start; i <= end; i++) {
			swap(a[start], a[i]);
			permutation(a, start + 1);
			swap(a[start], a[i]);
		}
	}
}
int main() {
	cout << TongDaySoNguyen(6);
	cout << '\n' << Fibo(21);
	cout << '\n' << UCLN(12, 7);
	int n = 11, k = 6;
	int* a = NULL;
	a = (int*)malloc(n * 4);
	a[0] = 0; a[1] = 3; a[2] = 4; a[3] = 6; a[4] = 6; a[5] = 7; a[6] = 9; a[7] = 11; a[8] = 14; a[9] = 16; a[10] = 18;
	cout << '\n' << recursiveBinarySearch(a, 0, n - 1, 18) << '\n';
	char b[6] = "ABC";
	permutation(b, 0);
	free(a);
	return 0;
}
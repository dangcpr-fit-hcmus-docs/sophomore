#include <iostream>
#include <vector>
#include<random>
#define MAX_ELEMENT_IN_ARRAY 20
using namespace std;

struct sv {
    string ms;
    float diem;
};
void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void SwapDS(sv& a, sv& b) {
    sv temp = a;
    a = b;
    b = temp;
}
vector<int> generate_random_array(int n)
{
    vector<int> a;
    a.resize(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<unsigned long long> dis(0, MAX_ELEMENT_IN_ARRAY);

    for (int i = 0; i < n; i++)
        a[i] = dis(gen);
    return a;
}
void printArray(vector<int>& a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << ' ';
    }
}
void printDS(sv a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i].ms << ' ';
    }
}

void interchangeSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) swap(a[i], a[j]);
        }
    }
}
void interchangeSortDiem(sv a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].diem > a[j].diem) swap(a[i], a[j]);
        }
    }
}

void insertionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        int x = a[i];
        int pos = i - 1;
        while (pos >= 0 && x < a[pos]) {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = x;
    }
}

int binarySearch(vector<int>& a, int k, int n) {
    int left = 0, right = n - 1, mid = (left + right) / 2;
    while (left <= right) {
        if (k == a[mid]) return mid;
        else if (k >= a[mid]) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
        mid = (left + right) / 2;
    }
    return left;
}
void binaryInsertionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        int x = a[i];
        int t = binarySearch(a, a[i], i);
        for (int j = i; j > t; j--) {
            a[j] = a[j - 1];
        }
        a[t] = x;
    }
}

void shellSort(vector<int>& a) {
    int n = a.size();
    for (int gap =  n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int x = a[i];
            int pos = i - gap;
            while (pos >= 0 && x < a[pos]) {
                a[pos + 1] = a[pos];
                pos--;
            }
            a[pos + 1] = x;
        }
    }
}

void selectionSort(vector<int>& a) {
    int n = a.size();
    int index = 0;
    for (int i = 0; i < n - 1; i++) {
        index = i;
        int j;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[index]) index = j;
        }
        swap(a[i], a[index]);
    }
}

void bubbleSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        bool haveSwap = 0;
        for (int j = 1; j < n; j++) {
            if (a[j - 1] > a[j]) {
                swap(a[j - 1], a[j]);
                haveSwap = 1;
            }
        }
        if (haveSwap == 0) break;
    }
}

void shakerSort(vector<int>& a) {
    int n = a.size();
    int left = 0, right = n - 1, stop = 0;
    while (left < right) {
        for (int i = right; i > left; i--) {
            if (a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
                stop = i;
            }
        }
        left = stop;
        for (int i = left; i < right; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                stop = i;
            }
        }
        right = stop;
    }
}


int main()
{
    vector<int> a = generate_random_array(10);
    sv b[5] = { {"1514431",10},{"1613234", 9.0},{"1514920", 9.0}, {"1712000", 7.0}, {"1812000", 4.0} };
    int n = sizeof(b) / sizeof(b[0]);
    printArray(a); cout << endl;
    //binaryInsertionSort(a); cout << endl;
    //bubbleSort(a); cout << endl;
    //insertionSort(a); cout << endl;
    //interchangeSort(a); cout << endl;
    //selectionSort(a); cout << endl;
    //shakerSort(a); cout << endl;
    //shellSort(a); cout << endl;
    printArray(a); cout << endl << endl;
    printDS(b, n); cout << endl;
    interchangeSortDiem(b, n);
    printDS(b, n);
    return 0;
}
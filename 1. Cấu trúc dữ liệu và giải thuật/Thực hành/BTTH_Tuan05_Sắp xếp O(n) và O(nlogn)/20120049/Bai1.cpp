#include <iostream>
#include <vector>
#include <random>
#define MAX_ELEMENT_IN_ARRAY 1000
using namespace std;

int minmax(int a, int b, int m, int n) {
    if (a < b) return m;
    else
        return n;
}
int max(int a, int b) {
    if (a > b) return a;
    else
        return b;
}
void print(vector<int> a) {
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
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
//HeapSort
void buildHeap(vector<int>& a, int left, int n) {
    if (2 * left + 2 <= n) {
        if (a[left] >= a[2 * left + 1] || a[left] >= a[2 * left + 2]) {
            int x = minmax(a[2 * left + 1], a[2 * left + 2], 2 * left + 1, 2 * left + 2);
            swap(a[left], a[x]);
            buildHeap(a, x, n);
        }
    }
    else if (2 * left + 1 <= n)
        if (a[left] >= a[2 * left + 1]) swap(a[left], a[2 * left + 1]);
}
void heapSort(vector<int>& a, int n) {
    int left = n / 2 - 1;
    while (left >= 0) {
        buildHeap(a, left, n - 1);
        left--;
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        buildHeap(a, 0, i - 1);
    }
}

//MergeSort
void merge(vector<int>& a, int l, int mid, int r) {
    int i = l;
    int j = mid + 1;
    vector<int> temp;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            temp.push_back(a[i]);
            i++;
        }
        else {
            temp.push_back(a[j]);
            j++;
        }
    }
    while (i <= mid) {
        temp.push_back(a[i]);
        i++;
    }
    while (j <= r) {
        temp.push_back(a[j]);
        j++;
    }
    for (i = l; i <= r; i++) {
        a[i] = temp[i - l];
    }
}
void mergeSort(vector<int>&a, int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}

//QuickSort
int partition(vector<int>& a, int l, int r) {
    int pivot = l;
    int i{ l + 1 }, j{ r };
    while (1) {
        while (i <= j && a[i] < a[pivot]) i++;
        while (i <= j && a[j] > a[pivot]) j--;
        if (i >= j) break;
        swap(a[i], a[j]);
        i++; j--;
    }
    swap(a[j], a[pivot]);
    return j;
}
void quickSort(vector<int>& a, int l, int r) {
    if (l < r) {
        int pivot = partition(a, l, r);
        quickSort(a, l, pivot - 1);
        quickSort(a, pivot + 1, r);
    }
}

//countingSort
void countingSort(vector<int>& a) {
    int max = a[0];
    for (int i = 1; i < a.size(); i++) {
        if (a[i] > max) max = a[i];
    }
    vector<int> temp;
    temp.resize(max + 1);
    for (int i = 0; i < a.size(); i++) {
        temp[a[i]]++;
    }
    for (int i = 1; i < temp.size(); i++) {
        temp[i] += temp[i - 1];
    }
    vector<int> b;
    b.resize(a.size());
    for (int i = 0; i < b.size(); i++) {
        b[temp[a[i]] - 1] = a[i];
        b[temp[a[i]] - 1]--;
    }
    a = b;
}

//RadixSort
void countingSortforRS(vector<int>& a, int exp) {
    vector<int> temp;
    temp.resize(10);
    for (int i = 0; i < a.size(); i++) {
        temp[(a[i] / exp) % 10]++;
    }
    for (int i = 1; i < temp.size(); i++) {
        temp[i] += temp[i - 1];
    }
    vector<int> b ;
    b.resize(a.size());
    for (int i = b.size() - 1; i >= 0; i--) {
        b[temp[(a[i] / exp) % 10] - 1] = a[i];
        temp[(a[i] / exp) % 10]--;
    }
    a = b;
}
void radixSort(vector<int>& a) {
    int max = a[0];
    for (int i = 1; i < a.size(); i++) {
        if (a[i] > max) max = a[i];
    }
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSortforRS(a, exp);
    }
}
int main()
{
    vector<int> a = generate_random_array(10);
    int n = a.size();
    heapSort(a, n); //decrease
    //mergeSort(a, 0, n - 1); //increase
    //quickSort(a, 0, n - 1); //increase
    //countingSort(a); //increase
    //radixSort(a); //increase
    print(a);
}
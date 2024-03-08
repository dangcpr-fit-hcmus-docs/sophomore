#include <iostream>
#include <math.h>
#include <vector>
#include <random>
#include <time.h>   // Thư viện thời gian
using namespace std;

vector<int> generate_random_array(int n)
{
    vector<int> a;
    a.resize(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<unsigned long long> dis(0, 200000);

    for (int i = 0; i < n; i++)
        a[i] = dis(gen);
    return a;
}
void print(vector<int> a) {
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
}
void input(vector<int>& a, int n) {
    int k;
    for (int i = 0; i < n; i++) {
        cin >> k;
        a.push_back(k);
    }
}
int minmax(int a, int b, int m, int n) {
    if (a < b) return n;
    else
        return m;
}
int binarySearch(vector<int> a, int tmp, int k, int l, int n, int t) {
    int left = l, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (k == a[mid] - tmp) {
            t++;
            right--;
            a.erase(a.begin() + mid);
        }
        else {
            if (a[mid] - tmp < k) left = mid + 1;
            else right = mid - 1;
        }
    }
    return t;
}
void buildHeap(vector<int>& c, int left, int n) {
    if (2 * left + 2 <= n) {
        if (c[left] <= c[2 * left + 1] || c[left] <= c[2 * left + 2]) {
            int x = minmax(c[2 * left + 1], c[2 * left + 2], 2 * left + 1, 2 * left + 2);
            swap(c[left], c[x]);
            //swap(a[left], a[x]);
            //swap(b[left], b[x]);
            buildHeap(c, x, n);
        }
    }
    else if (2 * left + 1 <= n)
        if (c[left] <= c[2 * left + 1]) {
            swap(c[left], c[2 * left + 1]);
            //swap(a[left], a[2 * left + 1]);
            //swap(b[left], b[2 * left + 1]);
        }
}
void heapSort(vector<int>& c, int n) {
    int left = n / 2 - 1;
    while (left >= 0) {
        buildHeap(c, left, n - 1);
        left--;
    }
    for (int i = n - 1; i >= 0; i--) {
        //swap(a[0], a[i]);
        //swap(b[0], b[i]);
        swap(c[0], c[i]);
        buildHeap(c, 0, i - 1);
    }
}
void creTempVector(vector<int> a, int n, vector<int>& b, vector<int>& c) {
    b.resize(n);
    c.resize(n);
    for (int i = 0; i < n; i++) {
        b[i] = a[i] + (int)pow(i + 1, 1.5);
        c[i] = a[i] - ((int)sqrt(i + 1) + 1);
    }
}
unsigned long long countPairs(vector<int>& b, vector<int>& c, int n, int k)
{
    unsigned long long count = 0;
    int i;
    heapSort(b, n);
    heapSort(c, n);
    int t = 0;
    for (i = 0; i < n - 1; i++)
        t = binarySearch(c, b[i], k, 0, n, t);
    return t;
}
int main(int argc, char* argv[]) {
    vector<int> a, b, c;
    //clock_t start, end;
    //double duration;
    int n;
    cin >> n;
    //a = generate_random_array(n);
    input(a, n);
    //start = clock();
    creTempVector(a, n, b, c);
    cout << countPairs(b, c, n, 0);
    //end = clock();
    //duration = (double)(end - start) / CLOCKS_PER_SEC;
    //printf("interchangeSort take %f seconds", duration);
}
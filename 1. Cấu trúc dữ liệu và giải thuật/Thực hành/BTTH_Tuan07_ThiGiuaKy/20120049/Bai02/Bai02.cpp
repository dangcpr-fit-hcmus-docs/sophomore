#include <iostream>
#include <vector>
//#include <random>
//#include <time.h>   // Thư viện thời gian
//#define MAX_ELEMENT_IN_ARRAY 300000
using namespace std;

int minmax(int a, int b, int m, int n) {
    if (a < b) return n;
    else
        return m;
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
/*vector<int> generate_random_array(int n)
{
    vector<int> a;
    a.resize(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<unsigned long long> dis(0, MAX_ELEMENT_IN_ARRAY);

    for (int i = 0; i < n; i++)
        a[i] = dis(gen);
    return a;
}*/
void input(vector<int>& a, int n) {
    int k;
    for (int i = 0; i < n; i++) {
        cin >> k;
        a.push_back(k);
    }
}
//HeapSort
void buildHeap(vector<int>& a, vector<int>& b, vector<int>& c, int left, int n) {
    if (2 * left + 2 <= n) {
        if (c[left] <= c[2 * left + 1] || c[left] <= c[2 * left + 2]) {
            int x = minmax(c[2 * left + 1], c[2 * left + 2], 2 * left + 1, 2 * left + 2);
            swap(c[left], c[x]);
            swap(a[left], a[x]);
            swap(b[left], b[x]);
            buildHeap(a, b, c, x, n);
        }
    }
    else if (2 * left + 1 <= n)
        if (c[left] <= c[2 * left + 1]) {
            swap(c[left], c[2 * left + 1]);
            swap(a[left], a[2 * left + 1]);
            swap(b[left], b[2 * left + 1]);
        }
}
void heapSort(vector<int>& a, vector<int>& b, vector<int>& c, int n) {
    int left = n / 2 - 1;
    while (left >= 0) {
        buildHeap(a, b, c, left, n - 1);
        left--;
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        swap(b[0], b[i]);
        swap(c[0], c[i]);
        buildHeap(a, b, c, 0, i - 1);
    }
}
int binarySearch(vector<int>& a, int tmp, int k, int l, int n) {
    int left = l, right = n - 1, mid = (left + right) / 2, min = -1;
    while (left <= right) {
        if (k >= a[mid] + tmp) {
            left = mid + 1;
        }
        else {
            min = mid;
            right = mid - 1;
        }
        mid = (left + right) / 2;
    }
    return min;
}
vector<int> createMinus(vector<int> a, vector<int> b) {
    int n = a.size();
    vector<int> c;
    c.resize(n);
    for (int i = 0; i < n; i++) {
        c[i] = a[i] - b[i];
    }
    return c;
}
unsigned long long handle(vector<int>& a, vector<int>& b) {
    vector<int> c = createMinus(a, b);
    unsigned long long t = 0;
    int n = a.size();
    heapSort(a, b, c, n);
    for (int i = 0; i < n - 1; i++) {
        int b = binarySearch(c, c[i], 0, i + 1, n);
        if (b > 0) t += (n - b);
    }
    return t;
}
int main(int argc, char* argv[]) {
    int n;
    cin >> n;
    vector<int> a, b;
    input(a, n);
    input(b, n);
    cout << handle(a, b);
}
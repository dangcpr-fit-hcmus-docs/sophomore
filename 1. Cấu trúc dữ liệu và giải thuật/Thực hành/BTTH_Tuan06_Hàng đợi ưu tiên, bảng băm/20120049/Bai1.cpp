#include <iostream>
#include <vector>
using namespace std;
int min(int a, int b, int m, int n) {
    if (a < b) return m;
    else
        return n;
}
void print(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << ' ';
    }
}
//Heap
void heapifyDown(vector<int>& a, int left, int n) {
    if (2 * left + 2 <= n) {
        if (a[left] >= a[2 * left + 1] || a[left] >= a[2 * left + 2]) {
            int x = min(a[2 * left + 1], a[2 * left + 2], 2 * left + 1, 2 * left + 2);
            swap(a[left], a[x]);
            heapifyDown(a, x, n);
        }
    }
    else if (2 * left + 1 <= n)
        if (a[left] >= a[2 * left + 1]) swap(a[left], a[2 * left + 1]);
}
void minHeap(vector<int>& a, int n) {
    int left = n / 2 - 1;
    while (left >= 0) {
        heapifyDown(a, left, n - 1);
        left--;
    }
}

int getMin(vector<int> a) {
    return a[0];
}
int extractMin(vector<int>& a) {
    int x = a[0];
    a[0] = a[a.size() - 1];
    a.pop_back();
    minHeap(a, a.size());
    return x;
}
void insert(vector<int>& a, int x) {
    a.push_back(x);
    minHeap(a, a.size());
}
int main()
{
    vector<int> a;
    a = { 6,7,2,1,5,6,8,0,4,7,8,2,1 };
    int n = a.size();
    minHeap(a, n);
    cout << "Node min: " << getMin(a) << '\n';
    cout << "Node min: " << extractMin(a) << '\n';
    insert(a, 8);
    print(a);
}
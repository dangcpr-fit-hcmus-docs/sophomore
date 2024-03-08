//Du doan do phuc tap thoi gian la O(n).
#include <iostream>
#include <chrono>
using namespace std;
int squaresum(int n, int& count_assign, int& count_compare) {
    count_assign = 0;
    count_compare = 0;
    int i = 1; ++count_assign;
    int sum = 0; ++count_assign;
    while (++count_compare && i <= n) {
        sum += i * i; ++count_assign;
        i += 1; ++count_assign;
    }
    return sum;
}
int main()
{
    int a, b;
    auto begin = std::chrono::high_resolution_clock::now();
    cout << squaresum(10, a, b) << '\n';
    //cout << squaresum(50, a, b) << '\n';
    //cout << squaresum(100, a, b) << '\n'; 
    //cout << squaresum(500, a, b) << '\n';
    //cout << squaresum(1000, a, b) << '\n';
    //cout << squaresum(5000, a, b) << '\n';
    //cout << squaresum(10000, a, b) << '\n';
    //cout << squaresum(50000, a, b) << '\n';
    //cout << squaresum(100000, a, b) << '\n';
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //Tính thời gian sử dụng
    cout << "Thoi gian chay: " << elapsed.count() * 1e-9;
}
//Do phuc tap thoi gian cua thuat toan la O(n^3)
#include <iostream>
#include <chrono>
using namespace std;
long long somesum(int n, int& count_comparison, int& count_assignment, int& basic) {
    long long sum = 0;  
    int i = 1, j;
    int a = 0, b = 0, c = 0;
    while (i <= n) {
        a++;
        j = n - i;
        while (j <= i * i) {
            sum = sum + i * j;
            j += 1;
            b++;
            c++;
        }
        i += 1;
        b++;
    }
    a++;
    count_comparison = a + b;
    count_assignment = c;
    basic = b;
    return sum;
}
int main()
{
    int a, b, basic; //basic la so thao tac co ban
    auto begin = std::chrono::high_resolution_clock::now();
    cout << somesum(10, a, b, basic) << '\n';
    //cout << somesum(50, a, b, basic) << '\n';
    //cout << somesum(100, a, b, basic) << '\n'; 
    //cout << somesum(500, a, b, basic) << '\n';
    //cout << somesum(1000, a, b, basic) << '\n';
    //cout << somesum(5000, a, b, basic) << '\n';
    //cout << somesum(10000, a, b, basic) << '\n';
    //cout << somesum(50000, a, b, basic) << '\n';
    //cout << somesum(100000, a, b, basic) << '\n';
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //Tính thời gian sử dụng
    cout << "Thoi gian chay: " << elapsed.count() * 1e-9;
}
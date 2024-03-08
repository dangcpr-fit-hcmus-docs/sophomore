//Du doan do phuc tap thoi gian cua thuat toan la O(n*(log(n))^2)
#include <iostream>
#include <chrono>
using namespace std;
long long sum(int n, int& count_assignment, int& count_comparison, int& basic) {
    long long sum = 0;
    int a = 0, b = 0, c = 0, d = 0;
    for (int i = 1; i < n; i *= 2) {
        a++;
        for (int j = n; j > 0; j /= 2) {
            b++;
            for (int k = j; k < n; k += 2) {
                c++; d++;
                sum += (i + j * k);
            }
            c++;
        }
        b++;
    }
    a++;
    count_comparison = a + b + c;
    count_assignment = c;
    basic = c;
    return sum;
}
int main()
{
    int a, b, basic; //basic la so thao tac co ban
    auto begin = std::chrono::high_resolution_clock::now();
    cout << sum(10, a, b, basic) << '\n';
    //cout << sum(50, a, b, basic) << '\n';
    //cout << sum(100, a, b, basic) << '\n'; 
    //cout << sum(500, a, b, basic) << '\n';
    //cout << sum(1000, a, b, basic) << '\n';
    //cout << sum(5000, a, b, basic) << '\n';
    //cout << sum(10000, a, b, basic) << '\n';
    //cout << sum(50000, a, b, basic) << '\n';
    //cout << sum(100000, a, b, basic << '\n';
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //Tính thời gian sử dụng
    cout << "Thoi gian chay: " << elapsed.count() * 1e-9;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<time.h>

using namespace std;

long long chiPhi(){
    return -1;
}

int main(){
    //Bo cmt cac dong duoi day neu ban muon giao tiep chuong trinh thong qua file

    // if (fopen("./input1.txt", "r")) {
    //     freopen("./input1.txt", "r", stdin);
    //     //freopen("./output1.txt", "w", stdout);
    // }

    /* 1. Read the input */
    clock_t start, end;

    int N, K;
    cin >> N;
    vector<int> price(N);
    for (int i = 0; i < N; ++i) cin >> price[i];
    cin >> K;
    vector<int> type(K);
    for (int i = 0; i < K; ++i) cin >> type[i];

    /* 2. Perform algorithm */

    start = clock();
    cout << chiPhi(); 

    end = clock();
    
    //Luu y rang ban se phai cmt dong duoi day lai khi nop bai, neu khong se bi sai output.
    
    //cerr << "Execution time: " << ((double) (end - start)) / CLOCKS_PER_SEC << "s";
    return 0;
}
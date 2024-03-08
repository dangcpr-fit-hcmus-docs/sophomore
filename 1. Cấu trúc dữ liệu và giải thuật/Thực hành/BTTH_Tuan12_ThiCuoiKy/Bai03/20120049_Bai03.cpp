#include<vector>
#include<iostream>
#include<algorithm>
#include<time.h>
#include<queue>

using namespace std;

//Tu o vuong (i, j), cac ban co the di den (i + dx[k], j + dy[k]) voi k = 0 -> 3.
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

//Co the ban se phai khai bao struct ViTri hoac dung pair<int,int>
struct ViTri {
    int x;
    int y;
};

int doTimDuongDi(vector<vector<int>> maze) {
    return -1;
}

int main() {
    //Bo cmt cac dong duoi day neu ban muon giao tiep chuong trinh thong qua file

    // if (fopen("./input1.txt", "r")) {
    //     freopen("./input1.txt", "r", stdin);
    //     //freopen("./output1.txt", "w", stdout);
    // }

    clock_t start, end;
    double cpu_time_used;

    int N;
    cin >> N;
    vector<vector<int>> maze(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> maze[i][j];

    start = clock();

    /* Design your algorithm here */

    //co the ban se phai khai bao: distance[i][j] - khoang cach ngan nhat tu vi tri (0, 0) den (i, j)
    vector<vector<int>> distance(N, vector<int>(N, -1));
    cout << doTimDuongDi(maze);

    end = clock();

    //Luu y rang ban se phai cmt dong duoi day lai khi nop bai, neu khong se bi sai output.
    //cerr << "Execution time: " << ((double) (end - start)) / CLOCKS_PER_SEC << "s";

    return 0;
}
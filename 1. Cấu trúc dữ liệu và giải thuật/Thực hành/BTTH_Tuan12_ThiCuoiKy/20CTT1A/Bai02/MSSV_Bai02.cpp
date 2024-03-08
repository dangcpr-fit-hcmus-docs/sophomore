#include<vector>
#include<iostream>
#include<algorithm>
#include<time.h>

using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;
};

Node* insert(Node* node, int key);
void preOrder(Node *root);
void inOrder(Node *root);
int xuLyYeuCau(Node* root, int key){
    return -1;
}

int main(){
    //Bo cmt cac dong duoi day neu ban muon giao tiep chuong trinh thong qua file

    // if (fopen("./input1.txt", "r")) {
    //     freopen("./input1.txt", "r", stdin);
    //     //freopen("./output1.txt", "w", stdout);
    // }

    clock_t start, end;
    double cpu_time_used;

    int N;
    cin >> N;
    vector<int> inputs(N);
    for (int i = 0; i < N; ++i)
        cin >> inputs[i];

    int K;
    cin >> K;

    start = clock();

    /* Design your algorithm here */

    Node *root = NULL;
    // Insert?

    // XuLyYeucau?
    cout << xuLyYeuCau(root, 0); 

    end = clock();
    
    //Luu y rang ban se phai cmt dong duoi day lai khi nop bai, neu khong se bi sai output.
    //cerr << "Execution time: " << ((double) (end - start)) / CLOCKS_PER_SEC << "s";

    return 0;
}
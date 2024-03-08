#include<vector>
#include<iostream>
#include<algorithm>
#include<time.h>

using namespace std;

struct node
{
    int key;
    node* left;
    node* right;
    int height;
};
int xuLyYeuCau(node* root, int x, node*& tmp);
node* createNode(int key) { //Ham so 1
    node* p = new node;
    p->key = key;
    p->left = NULL;
    p->right = NULL;
    p->height = 1;
    return p;
}
int height(node* a) {
    if (a == NULL) return 0;
    return a->height;
}
node* rightRotate(node* a) {
    node* b = a->left;
    node* tmp = b->right;

    b->right = a;
    a->left = tmp;

    a->height = max(height(a->left), height(a->right) + 1);
    b->height = max(height(b->left), height(b->right) + 1);

    return b;
}
node* leftRotate(node* b) {
    node* a = b->right;
    node* tmp = a->left;

    a->left = b;
    b->right = tmp;

    b->height = max(height(b->left), height(b->right) + 1);
    a->height = max(height(a->left), height(a->right) + 1);

    return a;
}

int getBalance(node* a) {
    if (a == NULL) return 0;
    return height(a->left) - height(a->right);
}
node* insert(node*& root, int x) { //Ham so 2
    if (root == NULL) {
       return createNode(x);
    }
    if (x < root->key)
        root->left = insert(root->left, x);
    else if (x > root->key) root->left = insert(root->left, x);
    else return root;
    root->height = 1 + max(height(root->left), height(root->right));

    int b = getBalance(root);
    if (b > 1 && x < root->left->key) return rightRotate(root);
    if (b < -1 && x > root->right->key) return leftRotate(root);
    if (b > 1 && x > root->left->key) {
        root->left = leftRotate(root->left);
        return leftRotate(root);
    }
    if (b < -1 && x < root->left->key) {
        root->left = leftRotate(root->left);
        return leftRotate(root);
    }
    return root;
}
int xuLyYeuCau(node* root, int x, node*& tmp) {
    int price = -1;
    while (root != NULL) {
        if (x < root->key) {
            tmp = root;
            root = root->left;
        }
        else if (x > root->key) {
            price = root->key;
            tmp = root;
            root = root->right;
        }
        else {
            price = root->key;
            break;
        }
    }
    return price;
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
    node* root = NULL;
    vector<int> inputs(N);
    for (int i = 0; i < N; ++i) {
        cin >> inputs[i];
        insert(root, inputs[i]);
    }
    node* tmp = root;
    int K; cin >> K;
    start = clock();

    /* Design your algorithm here */

    // Insert?

    // XuLyYeucau?
    cout << xuLyYeuCau(root, K, root);

    end = clock();

    //Luu y rang ban se phai cmt dong duoi day lai khi nop bai, neu khong se bi sai output.
    //cerr << "Execution time: " << ((double) (end - start)) / CLOCKS_PER_SEC << "s";

    return 0;
}
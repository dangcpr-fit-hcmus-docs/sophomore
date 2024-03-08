#include <iostream>
#include <vector>
using namespace std;
struct node {
    int key;
    int height;
    node* left;
    node* right;
};

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
        root = createNode(x);
    }
    else if (x < root->key) root->left = insert(root->left, x);
    else root->right = insert(root->right, x);
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
node* getRightMin(node* root)
{
    node* temp = root;
    while (temp->left != NULL) temp = temp->left;
    return temp;
}
node* remove(node*& root, int x) { //Ham so 3
    if (root == NULL) return root;
    if (x < root->key) root->left = remove(root->left, x);
    else if (x > root->key) root->right = remove(root->right, x);
    else {
        if (root->left == NULL || root->right == NULL) {
            node* temp = NULL;
            if (root->left) temp = root->left;
            else temp = root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else *root = *temp;
            delete temp;
        }
        else {
            node* temp = getRightMin(root->right);
            root->key = temp->key;
            root->right = remove(root->right, temp->key);
        }
    }

    if (root == NULL) return root;
    int b = getBalance(root);
    if (b > 1 && getBalance(root->left) >= 0) return rightRotate(root);
    if (b < -1 && getBalance(root->right) <= 0) return leftRotate(root);
    if (b > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return leftRotate(root);
    }
    if (b < -1 && getBalance(root->right) > 0) {
        root->left = leftRotate(root->left);
        return leftRotate(root);
    }
    return root;
}
node* search(node* root, int x, node*& tmp) { //Ham so 4
    while (root != NULL) {
        if (x < root->key) {
            tmp = root;
            root = root->left;
        }
        else if (x > root->key) {
            tmp = root;
            root = root->right;
        }
        else {
            break;
        }
    }
    return root;
}
bool isAVL(node* root) { //Ham so 5
    if (root == NULL) return 1;
    int l = height(root->left);
    int r = height(root->right);
    if (abs(l - r) <= 1 && isAVL(root->left) && isAVL(root->right))
        return 1;
    return 0;
}
void NLR(node* root) { //Ham so 6
    if (root == NULL) return;
    else {
        cout << "(" << root->key << "," << root->height << ")";
        NLR(root->left);
        NLR(root->right);
    }
}
void LNR(node* root) { //Ham so 7
    if (root == NULL) return;
    else {
        LNR(root->left);
        cout << "(" << root->key << "," << root->height << ")";
        LNR(root->right);
    }
}
void LRN(node* root) { //Ham so 8
    if (root == NULL) return;
    else {
        LRN(root->left);
        LRN(root->right);
        cout << "(" << root->key << "," << root->height << ")";
    }
}
void levelOrder(node* root) { //Ham so 9
    vector<node*> q;
    if (root == NULL) return;
    q.push_back(root);
    do {
        if (q[0]->left != NULL) q.push_back(q[0]->left);
        if (q[0]->right != NULL) q.push_back(q[0]->right);
        cout << "(" << q[0]->key << "," << q[0]->height << ")";
        q.erase(q.begin());
    } while (q.size() != 0);
}
void countLesser(node* root, int x, int& count) { //Ham so 10
    if (root == NULL) return;
    else {
        countLesser(root->left, x, count);
        countLesser(root->right, x, count);
    }
    if (root->key < x) count++;
}
void countGreater(node* root, int x, int& count) { //Ham so 11
    if (root == NULL) return;
    else {
        countGreater(root->left, x, count);
        countGreater(root->right, x, count);
    }
    if (root->key > x) count++;
}
void countLeaves(node* root, int& count) { //Cau 12
    if (root == NULL) return;
    else {
        countLeaves(root->left, count);
        countLeaves(root->right, count);
    }
    if (root->height == 1) count++;
}
void removeTree(node*& root) { //Ham so 13
    if (root == NULL) return;
    else {
        removeTree(root->left);
        removeTree(root->right);
        delete root;
        root = NULL;
    }
}
int main()
{
    node* root = NULL;
    node* tmp = NULL;
    int count = 0;
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 45);
    root = insert(root, 70);
    root = insert(root, 80);
    root = insert(root, 25);
    root = insert(root, 50);
    root = insert(root, 20);
    NLR(root); cout << endl;
    LNR(root); cout << endl;
    LRN(root); cout << endl;
    levelOrder(root); cout << endl;
    node* search1 = search(root, 45, tmp);
    if (count == NULL) cout << "Khong tim thay node" << endl;
    else cout << search1->key << endl;
    countLeaves(root, count); cout << count << endl;
    count = 0;
    countLesser(root, 37, count); cout << count << endl;
    count = 0;
    countGreater(root, 37, count); cout << count << endl;
    remove(root, 40);
    removeTree(root);
    root = NULL;
    tmp = NULL;
    search1 = NULL;
}
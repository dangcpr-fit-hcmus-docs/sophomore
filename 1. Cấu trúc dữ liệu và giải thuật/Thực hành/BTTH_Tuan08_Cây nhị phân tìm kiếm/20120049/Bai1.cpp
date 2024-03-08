#include <iostream>
#include <vector>
using namespace std;
struct node {
    int key;
    node* left;
    node* right;
};

node* createNode(int data) {
    node* p = new node;
    if (p == NULL) return NULL;
    else {
        p->key = data;
        p->left = NULL;
        p->right = NULL;
    }
    return p;
}

void insert(node*& root, int x) {
    if (root == NULL) {
        node* p = createNode(x);
        root = p;
        return;
    }
    if (x == root->key) return;
    else {
        if (x < root->key) insert(root->left, x);
        else insert(root->right, x);
    }
}

void NLR(node* root) {
    if (root == NULL) return;
    else {
        cout << root->key << ' ';
        NLR(root->left);
        NLR(root->right);
    }
}
void LNR(node* root) {
    if (root == NULL) return;
    else {
        LNR(root->left);
        cout << root->key << ' ';
        LNR(root->right);
    }
}
void LRN(node* root) {
    if (root == NULL) return;
    else {
        LRN(root->left);
        LRN(root->right);
        cout << root->key << ' ';
    }
}
void levelOrder(node* root) {
    vector<node*> q;
    if (root == NULL) return;
    q.push_back(root);
    do {
        if (q[0]->left != NULL) q.push_back(q[0]->left);
        if (q[0]->right != NULL) q.push_back(q[0]->right);
        q.erase(q.begin());
    } while (q.size() != 0);
}
int height(node* root) {
    if (root == NULL) return -1;
    else {
        int left = height(root->left);
        int right = height(root->right);
        return max(left, right) + 1;
    }
}
int countNode(node* root) {
    int t = 0;
    vector<node*> q;
    if (root == NULL) return t;
    t++;
    q.push_back(root);
    do {
        cout << q[0]->key << ' ';
        if (q[0]->left != NULL) {
            t++; 
            q.push_back(q[0]->left);
        }
        if (q[0]->right != NULL) {
            t++;
            q.push_back(q[0]->right);
        }
        q.erase(q.begin());
    } while (q.size() != 0);
    return t;
}
node* search(node*& root, int x, node*& tmp) {
    /*if (root->key == x || root == NULL) return root;
    else {
        if (x < root->key) {
            search(root->left, x, tmp);
        }
        else {
            search(root->right, x, root);
        }
        tmp = root;
    }*/
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
node* getRightMin(node* root)
{
    node* temp = root;
    while (temp->left != NULL) temp = temp->left; 
    return temp;
}
void remove(node*& root, int key)
{
    node* parent = NULL;
    node* p = root;
    search(p, key, parent);
    if (p == NULL) {
        return;
    }
    if (p->left == NULL && p->right == NULL)
    {
        if (p != root)
        {
            if (parent->left == p) {
                parent->left = NULL;
            }
            else {
                parent->right = NULL;
            }
        }
        else {
            root = NULL;
        }
        free(p);
    }
    else if (p->left && p->right)
    {
        node* tmp = getRightMin(p->right);
        int val = tmp->key;
        remove(root, tmp->key);
        p->key = val;
    }
    else {
        node* child;
        if (p->left) {
            child = p->left;
        }
        else {
            child = p->right;
        }
        if (p != root)
        {
            if (p == parent->left) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }
        }
        else {
            root = child;
        }
        free(p);
    }
}
void removeTree(node*& root) {
    if (root == NULL) return;
    else {
        removeTree(root->left);
        removeTree(root->right);
        delete root;
    }
}
int heightNode(node* root, int x) {
    if (root == NULL) return -1;
    if (root->key == x) {
        if (root->left == NULL && root->right == NULL) return 0;
        int l = 0, r = 0;
        if (root->left != NULL) l = heightNode(root->left, root->left->key);
        if (root->left != NULL) r = heightNode(root->right, root->right->key);
        return max(l, r) + 1;
    }
    else if (root->key > x) return heightNode(root->left, x);
    else return heightNode(root->right, x);
}
bool isBST(node* root) {
    if (root == NULL) return 1;
    if (root->left != NULL)
        if (root->left->key > root->key) return 0;
    if (root->right != NULL)
        if (root->right->key < root->key) return 0;
    return isBST(root->right) && isBST(root->left);
}
int main()
{
    node* root = NULL;
    insert(root, 7);
    insert(root, 5);
    insert(root, 9);
    insert(root, 4);
    insert(root, 6);
    insert(root, 11);
    insert(root, 8);
    insert(root, 12);
    insert(root, 10);
    insert(root, 13);
    NLR(root); cout << endl;
    LNR(root); cout << endl;
    LRN(root); cout << endl;
    levelOrder(root); 
    cout << endl << countNode(root);
    cout << endl << height(root);
    int height = 0;
    cout << endl << heightNode(root, 7);
    cout << endl << isBST(root);
    remove(root, 11);
    removeTree(root);
    root = NULL;
}
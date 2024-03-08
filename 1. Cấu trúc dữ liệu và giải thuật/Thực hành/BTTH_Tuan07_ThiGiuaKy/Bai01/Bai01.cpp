#include <iostream>
using namespace std;

struct node {
    int key;
    node* next;
};
struct List {
    node* head;
    node* tail;
};

void printList(List L) {
    node* p = L.head;
    while (p != NULL) {
        cout << p->key << ' ';
        p = p->next;
    }
}

node* initializeNode(int key) {
    node* p = new node;
    if (p == NULL) return NULL;
    p->key = key;
    p->next = NULL;
    return p;
}
void initializeList(List& L, node*& head) {
    L.head = head;
    node* p = L.head;
    while (p->next != NULL) {
        p = p->next;
    }
    L.tail = p;
}
void addElement(List& L, int value) {
    node* p = initializeNode(value);
    if (L.head == NULL) {
        L.head = p;
        L.tail = p;
    }
    else {
        L.tail->next = p;
        L.tail = p;
    }
}
void removeTail(List& L) {
    node* p = L.head;
    if (L.head == L.tail) {
        L.head = NULL;
        L.tail = NULL;
    }
    else {
        while (p->next->next != NULL) {
            p = p->next;
        }
        p->next = NULL;
        L.tail = p;
    }
}
void addElementAt(List& L, int index, node* pNew) {
    node* p = L.head;
    int i = 1;
    while (i != index) {
        p = p->next;
        i++;
    }
    removeTail(L);
    pNew->next = p->next;
    p->next = pNew;
}
void reList(List& L, int n) {
    for (int i = 1; i < n; i += 2) {
        node* pNew = L.tail;
        addElementAt(L, i, pNew);
    }
}
int main(int argc, char* argv[]) {
    int n, k;
    cin >> n;
    List L; L.head = NULL; L.tail = NULL;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        addElement(L, k);
    }
    reList(L, n);
    printList(L);
}
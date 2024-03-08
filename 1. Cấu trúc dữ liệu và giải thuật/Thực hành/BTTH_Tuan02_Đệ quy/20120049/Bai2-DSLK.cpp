#include <iostream>
#include <math.h>
using namespace std;

struct node {
    int key;
    node* next;
};
struct List {
    node* head;
    node* tail;
};

int numElement(List L) {
    node* p = L.head;
    int num = 0;
    while (p != NULL) {
        num++;
        p = p->next;
    }
    return num;
}
bool sameNode(List L, node* pFind) {
    node* p = L.head;
    if (pFind == NULL) return false;
    while (p != pFind) {
        if (p->key == pFind->key) return true;
        else p = p->next;
    }
    return false;
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
        initializeList(L, p);
    }
    else {
        p->next = L.head;
        L.head = p;
    }
}
void removeElement(List& L) {
    node* pDel = L.head;
    L.head = L.head->next;
    delete pDel;
    pDel = NULL;
}
void removeAllElement(List& L) {
    while (L.head != NULL) {
        removeElement(L);
    }
}
void addElementAt(List& L, int index, int value) {
    node* pNew = initializeNode(value);
    node* p = L.head;
    if (L.head == NULL) {
        initializeList(L, pNew);
    }
    else if (index == 0) {
        pNew->next = L.head;
        L.head = pNew;
    }
    else {
        if (index >= numElement(L)) {
            cout << "Vi tri them khong hop le.";
        }
        else {
            int i = 0;
            while (i != index - 1) {
                p = p->next;
                i++;
            }
            pNew->next = p->next;
            p->next = pNew;
        }
    }
}
void removeElementAt(List& L, int index) {
    node* p = L.head;
    if (L.head == NULL) return;
    else if (index == 0) {
        removeElement(L);
    }
    else {
        if (index >= numElement(L)) {
            cout << "Vi tri xoa khong hop le.";
        }
        else {
            int i = 0;
            while (i != index - 1) {
                p = p->next;
                i++;
            }
            node* pDel = p->next;
            if (pDel->next == NULL) {
                delete pDel;
                p->next = NULL;
                L.tail = p;
                pDel = NULL;
            }
            else {
                p->next = pDel->next;
                delete pDel;
                pDel = NULL;
            }
        }
    }
}
void removeDuplicateElements(List& L) {
    node* p = L.head;
    if (L.head == NULL) return;
    node* pDel = NULL;
    while (p != NULL) {
        if (sameNode(L, p->next) == false) {
            p = p->next;
        }
        else
        {
            if (p->next->next == NULL) {
                pDel = p->next;
                L.tail = p;
                p->next = NULL;
                delete pDel;
                pDel = NULL;
            }
            else {
                pDel = p->next;
                p->next = pDel->next;
                pDel->next = NULL;
                delete pDel;
                pDel = NULL;
            }
        }
    }
}
void printElement(List L) {
    node* p = L.head;
    while (p != NULL) {
        if (p->next != NULL) cout << p->key << "->";
        else cout << p->key;
        p = p->next;
    }
}

void midElement(List L) {
    node* p = L.head;
    if (L.head == NULL) return;
    int mid = round((1 + numElement(L)) / 2.0);
    node* midEle = NULL;
    int i = 0;
    do {
        midEle = p;
        p = p->next;
        i++;
    } while (i != mid);
    cout << "\nPhan tu chinh giua la: " << midEle->key;
}
void reverseList(List& L) {
    node* cur = L.head;
    node* pre = NULL;
    node* next = NULL;
    if (L.head == NULL) return;
    while (cur != NULL) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    L.head = pre;
}

int main()
{
    List L;
    L.head = NULL;
    L.tail = NULL;
    addElement(L, 4);
    addElement(L, 2);
    addElement(L, 3);
    addElement(L, 2);
    addElement(L, 1);
    addElementAt(L, 2, 7); //Vi tri cac node duoc tinh tu 0
    addElement(L, 1);
    removeDuplicateElements(L);
    //removeElement(L);
    //removeAllElement(L);
    //removeElementAt(L, 6); //Vi tri cac node duoc tinh tu 0
    cout << "Danh sach da nhap la: ";
    printElement(L);
    midElement(L);
    reverseList(L);
    cout << "\nDanh sach da dao nguoc: ";
    printElement(L);
    return 0;
}
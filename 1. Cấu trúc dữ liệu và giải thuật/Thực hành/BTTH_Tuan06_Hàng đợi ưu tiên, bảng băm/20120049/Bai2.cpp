#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <string.h>
#include <vector>
using namespace std;
auto const p = 31;
auto const m = 1000000000 + 9;
struct CongTy {
    string tenCTy;
    string MST;
    string dChi;
};
struct node {
    CongTy cty;
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

node* initializeNode(CongTy key) {
    node* p = new node;
    if (p == NULL) return NULL;
    p->cty = key;
    p->next = NULL;
    return p;
}
void addElement(List& L, CongTy value) {
    node* p = initializeNode(value);
    if (p == NULL) return;
    if (L.head == NULL) {
        L.head = p;
        L.tail = p;
    }
    else {
        L.tail->next = p;
        L.tail = p;
    }
}

unsigned long long pow(int a, int p) {
    unsigned long long res = 1;
    for (int i = 1; i <= p; i++) res *= a;
    return res;
}

//Ham so 1: ham bam
unsigned long long hashString(const string& tenCongTy) {
    const int p = 31;
    const unsigned long long m = 100019;
    unsigned long long sum = 0;
    if (tenCongTy.length() <= 18) {
        for (int i = tenCongTy.length() - 1; i >= 0; i--) {
            sum = sum + (int)tenCongTy[i] * pow(p, i);
        }
    }
    else {
        for (int i = tenCongTy.length() - 1; i >= tenCongTy.length() - 18; i--) {
            sum = sum + (int)tenCongTy[i] * pow(p, i);
        }
    }
    sum = sum % m;
    return sum;
}
vector<CongTy> readFile(string file) {
    ifstream f;
    f.open(file, ios::in);
    string header;
    CongTy temp;
    vector<CongTy> cty;
    getline(f, header);
    while (!f.eof()) {
        getline(f, temp.tenCTy,'|');
        getline(f, temp.MST, '|');
        getline(f, temp.dChi);
        cty.push_back(temp);
    }
    f.close();
    return cty;
}

//Ham so 2: xu li dung do
void conflict(vector<List>& CT, vector<CongTy> cty) {
    for (int i = 0; i < CT.size(); i++) {
        CT[i].head = NULL;
        CT[i].tail = NULL;
    }
    for (int i = 0; i < cty.size(); i++) {
        addElement(CT[hashString(cty[i].tenCTy)], cty[i]);
    }
}

//Ham so 3: Xay dung bang bam
vector<List> hashTable(string tenFile) {
    vector<List> CT;
    vector<CongTy> cty = readFile(tenFile);
    CT.resize(100019);
    CT.size();
    conflict(CT, cty);
    return CT;
}

//Ham tim kiem
CongTy search(string cty, vector<List> CT) {
    int codeHash = hashString(cty);
    CongTy result;
    CongTy notResult; notResult.tenCTy = "-1"; notResult.MST =  "-1"; notResult.dChi = "-1";
    for (node* p = CT[codeHash].head; p != NULL; p = p->next) {
        if (p->cty.tenCTy == cty) return p->cty;
    }
    return notResult;
}
void printCTy(CongTy cty) {
    cout << "Ten cong ty: " << cty.tenCTy << '\n';
    cout << "MST: " << cty.MST << '\n';
    cout << "Dia chi: " << cty.dChi;
}
int main()
{
    string a = "abcdefghijk123456899965";
    //cout << hashString(a);
    vector<List> b = hashTable("mst.txt");
    CongTy result = search("CONG TY TNHH MTV THUONG MAI SAN XUAT NGUYEN THI KIM NGAN", b);
    cout << "Thong tin cong ty can tim:" << '\n';
    printCTy(result);
}
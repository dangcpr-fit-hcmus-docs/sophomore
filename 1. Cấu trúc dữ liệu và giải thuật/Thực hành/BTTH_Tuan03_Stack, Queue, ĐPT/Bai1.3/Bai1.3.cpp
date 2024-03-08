#pragma warning(disable:4996)
#include <iostream>
using namespace std;
struct node {
    char data;
    node* next;
};
struct stack {
    node* bot;
    node* top;
};

//Cac ham cai dat stack
void creStack(stack& s) {
    s.bot = NULL;
    s.top = NULL;
}
int count(stack s) {
    int i = 0;
    if (s.top == NULL) return 0;
    for (node* p = s.bot; p != NULL; p = p->next) {
        i++;
    }
    return i;
}
node* creNode(char data) {
    node* p = new node;
    if (p == NULL) return NULL;
    p->data = data;
    p->next = NULL;
    return p;
}
void push(stack& s, char data) {
    node* add = creNode(data);
    if (s.bot == NULL) {
        s.bot = add;
        s.top = add;
    }
    else {
        s.top->next = add;
        s.top = add;
    }
}
char pop(stack& s) {
    char data;
    if (s.bot == NULL) return NULL;
    else if (count(s) == 1) {
        node* pDel = s.top;
        data = pDel->data;
        delete pDel;
        creStack(s);
        return data;
    }
    else {
        node* pre;
        for (pre = s.bot; pre->next != s.top; pre = pre->next) {
            continue;
        }
        node* pDel = pre->next;
        data = pDel->data;
        delete pDel;
        pre->next = NULL;
        s.top = pre;
        return data;
    }
}
bool empty(stack s) {
    if (s.top == NULL) return 1;
    else return 0;
}

//Kiem tra ngoac
bool check(const char* bra) {
    stack s;
    creStack(s);
    for (int i = 0; i < strlen(bra); i++) {
        if (bra[i] == '(' || bra[i] == '[' || bra[i] == '{')
            push(s, bra[i]);
        else {
            if (empty(s)) return false;
            else {
                if ((s.top->data == '(' && bra[i] == ')') || (s.top->data == '[' && bra[i] == ']') || (s.top->data == '{' && bra[i] == '}'))
                    pop(s);
                else return false;
            }
        }
    }
    return true;
}
int main()
{
    char a[] = "[(])";
    char b[] = ")([]";
    char c[] = "({[]})";
    char d[] = "({})[]";
    char e[] = "(){}[]";
    cout << check(a) << '\n';
    cout << check(b) << '\n';
    cout << check(c) << '\n';
    cout << check(d) << '\n';
    cout << check(e) << '\n';
    return 0;
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

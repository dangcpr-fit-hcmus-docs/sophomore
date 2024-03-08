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

//infix to postfix
int priority(char s) {
    if (s == '(') return 0;
    else if (s == '+' || s == '-') return 1;
    else if (s == '*' || s == '/' || s == '^') return 2;
    else return 3;
}
char* postfix(const char* in) {
    char* post = (char*)calloc(strlen(in), 1);
    stack s;
    creStack(s);
    int j = 0;
    for (int i = 0; i < strlen(in); i++) {
        if (in[i] >= '0' && in[i] <= '9')
            post[j++] = in[i];
        else if (priority(in[i]) == 0)
            push(s, in[i]);
        else if (in[i] == ')') {
            while (s.top->data != '(') {
                post[j++] = pop(s);
            }
            pop(s);
        }
        else {
            if (count(s) == 0) {
                push(s, in[i]);
            }
            else if (priority(s.top->data) >= priority(in[i])) {
                post[j++] = pop(s);
                push(s, in[i]);
            }
            else
                push(s, in[i]);
        }
    }
    while (!empty(s)) {
        post[j++] = pop(s);
    }
    return post;
}
int main()
{
    char a[] = "(2*(3+4)/5)^2";
    const char* t = postfix(a);
    cout << t;
    return 0;
}
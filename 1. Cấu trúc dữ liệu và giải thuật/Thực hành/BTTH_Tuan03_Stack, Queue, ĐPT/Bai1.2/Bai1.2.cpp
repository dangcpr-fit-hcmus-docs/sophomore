#pragma warning(disable:4996)
#include <iostream>
using namespace std;
struct node {
    string data;
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
node* creNode(string data) {
    node* p = new node;
    if (p == NULL) return NULL;
    p->data = data;
    p->next = NULL;
    return p;
}
void push(stack& s, string data) {
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
string pop(stack& s) {
    string data;
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

//infix to postfix and back up
bool isOperator(char s) {
    switch (s) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
        return true;
    }
    return false;
}
string preToPost(string pre) {
    stack s;
    creStack(s);
    for (int i = pre.length() - 1; i >= 0; i--) {
        if (isOperator(pre[i])) {
            string a = pop(s);
            string b = pop(s);
            string temp = a + b + pre[i];
            push(s, temp);
        }
        else {
            push(s, string(1, pre[i]));
        }
    }
    return s.top->data;
}
string postToPre(string post) {
    stack s;
    creStack(s);
    for (int i = 0; i < post.length(); i++) {
        if (isOperator(post[i])) {
            string a = pop(s);
            string b = pop(s);
            string temp = post[i] + b + a;
            push(s, temp);
        }
        else {
            push(s, string(1, post[i]));
        }
    }
    return s.top->data;
}
int main()
{
    string pre = "*2/+345";
    string post = "24*25+3^/";
    cout << preToPost(pre) << '\n' << postToPre(post);
    return 0;
}
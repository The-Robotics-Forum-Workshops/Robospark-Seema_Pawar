#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

class Stack {
    public :
        int top = -1;
        char arr[MAX];
        void push(char x);
        char pop();
        char peek();
        bool isEmpty();
};

void Stack::push(char x) {
    if (top<MAX) {
        arr[++top] = x;
    }
    else cout<<"Stack Overflow\n";
}

char Stack::pop() {
    if (top>=0) {
        return arr[top--];
    }
    else cout<<"Stack is empty\n";
}

char Stack::peek() {
    if (top==-1) {
        cout<<"Stack is empty\n";
    }
    else return arr[top];
}

bool Stack::isEmpty() {
    if (top>=0) {
        return false;
    }
    else return true;
}

int priority(char symbol) {
    int val;
    switch (symbol) {
        case '^' :
            val = 3;
            break;
        case '/' :
            val = 2;
            break;
        case '*' :
            val = 2;
            break;
        case '+' :
            val = 1;
            break;
        case '-' :
            val = 1;
            break;
        default :
            val = -1;
    }
    return val;
}

int main() {
    Stack s;
    string inf;
    int i=0,j=0,len;
    cout<<"Enter an infix expression : ";
    cin>>inf;
    cout<<inf;
    len = sizeof(inf);
    char post[len],symbol,top;
    for (i=0;i<len;i++) {
        symbol = inf[i];
        if (symbol=='(') {
            s.push(symbol);
        }
        else if (symbol==')') {
            top = s.peek();
            while (top != '(') {
                post[j++] = s.pop();
            }
            s.pop();
        }
        else if (symbol=='^' || symbol=='/' || symbol=='*' ||symbol=='+' || symbol=='-') {
            top = s.peek();
            while ((top!='(' || !s.isEmpty()) && (priority(top)>=priority(symbol))) {
                post[j++] = s.pop();
            }
            if (top=='(') {
                s.pop();
            }
        }
        else {
            post[j++] == symbol;
        }
    }
    while (!s.isEmpty()) {
        post[j++] = s.pop();
    }
    for (i=0;i<len;i++) {
        cout<<post[i];
    }
}

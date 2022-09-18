#include <bits/stdc++.h>
using namespace std;

int main () {
    stack<char> s;
    string exp;
    int i,len;
    cout<<"Enter bracket expression : ";
    cin>>exp;
    len = exp.length();
    for (i=0;i<len;i++) {
        if (s.empty()) {
            s.push(exp[i]);
        }
        else if ((s.top()=='(' && exp[i]==')') || (s.top()=='[' && exp[i]==']') || (s.top()=='{' && exp[i]=='}')) {
            s.pop();
        }
        else s.push(exp[i]);
    }
    if (s.empty()) {
        cout<<"Balanced\n";
    }
    else cout<<"Not Balanced\n";
}
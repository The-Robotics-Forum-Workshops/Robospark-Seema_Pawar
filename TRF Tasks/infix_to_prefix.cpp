#include <bits/stdc++.h>
using namespace std;

int priority(char c) {
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

void convert(string inf) {
	stack<char> s; 
	string post;
	for (int i = 0; i < inf.length(); i++) {
		char c = inf[i];
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9'))
			post += c;
		else if (c == '(')
			s.push('(');
		else if (c == ')') {
			while (s.top() != '(') {
				post += s.top();
				s.pop();
			}
			s.pop();
		}
		else {
			while (!s.empty()
				&& priority(inf[i]) <= priority(s.top())) {
				if (c == '^' && s.top() != '^')
					break;
				else {
					post += s.top();
					s.pop();
				}
			}
			s.push(c);
		}
	}
	while (!s.empty()) {
		post += s.top();
		s.pop();
	}
    reverse(post.begin(), post.end());
	cout<<post<<endl;
}

int main() {
	string inf;
    cout<<"Enter an infix infression : ";
    cin>>inf;
    reverse(inf.begin(), inf.end());
	convert(inf);
	return 0;
}

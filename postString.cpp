#include <iostream>
#include <string>
#include <stack>
using namespace std;
string getPostString (string s) {
	string postS = "";
	stack<char> op;
	int len = s.length();

	for (int i = 0; i < len; i++) {
		switch (s[i]) {
			case ' ':
				break;
			case '(':
				op.push('(');
				break;
			case ')':
				while (!op.empty() && op.top() != '(') {
					postS += op.top();
					op.pop();
				}
				if (!op.empty() && op.top() == '(') {
					op.pop();
				}
				break;
			case '*':
			case '/':
				while (!op.empty() && op.top() != '(' && op.top() != '+' && op.top() != '-') {
					postS += op.top();
					op.pop();
				}
				op.push(s[i]);
				break;
			case '+':
			case '-':
				while (!op.empty() && op.top() != '(') {
					postS += op.top();
					op.pop();
				}
				op.push(s[i]);
				break;
			default:
				while (i < len && s[i] >= '0' && s[i] <= '9') {
					postS += s[i];
				        i++;	
				}
				postS += '#';
				i--;
				break;
		}
	}

	while (!op.empty()) {
		postS += op.top();
		op.pop();
	}

	return postS;
}
int main (int argc, char* argv[]) {
	string s = "3 + 2 / 1 + 34";
	string postS = getPostString(s);
	cout << s << endl;
	cout << postS << endl;
	return 0;
}

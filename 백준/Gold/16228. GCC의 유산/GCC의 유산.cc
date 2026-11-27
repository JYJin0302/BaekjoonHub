#include <bits/stdc++.h>
using namespace std;


stack<char> oper;
stack<int> num;
int n1, n2;

int cal(int op) {
    n2 = num.top(); num.pop();
    n1 = num.top(); num.pop();
	switch (op) {
	case '<':
		return min(n1, n2);
	case '>':
		return max(n1, n2);
	case '+':
		return n1 + n2;
	case '-':
		return n1 - n2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	
	int n1, n2;
	char op;

	string digit = "";
	

	for (char i : s) {

		if (i == '?') continue;
		if (i >= '0' && i <= '9') digit += i;
		else {
            if (digit != "") num.push(stoi(digit));
            digit = "";
            
			if ((oper.empty() || i == '(' || oper.top() == '(') && i != ')') {
				oper.push(i);
				continue;
			}
			op = oper.top();
            if (i == ')' && op == '('){
                oper.pop();
                continue;
            }

			if (i == '+' || i == '-') {
                while (op != '(' && !oper.empty()) {
					num.push(cal(op));
					oper.pop();
					if (!oper.empty()) op = oper.top();
				}
			}
			else if (i == '>' || i == '<') {
                while (op != '+' && op != '-' && op != '(' && !oper.empty()) {
					num.push(cal(op));
					oper.pop();
					if (!oper.empty()) op = oper.top();
				}
			}
			else if (i == ')') {
                while (op != '(') {
					num.push(cal(op));
					oper.pop();
					op = oper.top();
				}
                oper.pop();
			}

			if (i != ')') oper.push(i);
		}
	}

	
	if (digit != "") num.push(stoi(digit));
    while (!oper.empty()) {
        op = oper.top();
        num.push(cal(op));
        oper.pop();
    }
	cout << num.top();
}
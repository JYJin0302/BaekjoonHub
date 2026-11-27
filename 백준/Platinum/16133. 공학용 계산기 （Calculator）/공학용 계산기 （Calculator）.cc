#include <bits/stdc++.h>
using namespace std;
using ll = long long;

stack<char> oper;
stack<ll> num;
ll n1, n2;

// 숫자 두 개를 필요로 하는 연산자를 이용한 계산
ll cal(char op) {
	n2 = num.top();
	num.pop();
	if (op != '#') {
		n1 = num.top();
		num.pop();
	}
	switch (op) {
	case '+':
		return n1 + n2;
	case '-':
		return n1 - n2;
	case '*':
		return n1 * n2;
	case '/':
		return n1 / n2;
	case '^':
		return powl(n1, n2);
	case '#':
		return sqrtl(n2);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	ll n1, n2;


	string digit = "";

	for (char now : s) {
		// 숫자
		if (now >= '0' && now <= '9') digit += now;
		// 연산자
		// 연산 순위 : 괄호 > 제곱근(r -> l) > 지수(r -> l) > 곱셈 나눗셈(l -> r) > 덧셈 뻴셈(l -> r)
		else {
			if (digit != "") num.push(stoll(digit));
			digit = "";
			// 연산을 할 수 없는 경우
			if ((oper.empty() || now == '(' || oper.top() == '(') && now != ')') {
				oper.push(now);
				continue;
			}

			char pre = oper.top();
			if (now == ')' && pre == '(') {
				oper.pop();
				continue;
			}

			if (now == '+' || now == '-') {
				while (pre != '(' && !oper.empty()) {
					num.push(cal(pre));
					oper.pop();
					if (!oper.empty()) pre = oper.top();
				}
			}
			else if (now == '*' || now == '/') {
				while (pre != '+' && pre != '-' && pre != '(' && !oper.empty()) {
					num.push(cal(pre));
					oper.pop();
					if (!oper.empty()) pre = oper.top();
				}
			}
			else if (now == '^') {
				while (pre == '#' && !oper.empty()) {
					num.push(cal(pre));
					oper.pop();
					if (!oper.empty()) pre = oper.top();
				}
			}
			else if (now == '#') {

			}
			else if (now == ')') {
				while (pre != '(') {
					num.push(cal(pre));
					oper.pop();
					if (!oper.empty()) pre = oper.top();
				}
				oper.pop();
			}
			else if (now == '=') {
				while (!oper.empty()) {
					num.push(cal(pre));
					oper.pop();
					if (!oper.empty()) pre = oper.top();
				}
			}
			if (now != ')') oper.push(now);
		}
	}
	cout << num.top();
}
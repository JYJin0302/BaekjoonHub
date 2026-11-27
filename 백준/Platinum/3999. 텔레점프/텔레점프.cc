#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve() {
	int a, b, c;
	cin >> a >> b >> c;

	int n = a + b + c;
	vector<int> ans = {0};
	int cnt = c / 3;
	int cur = 0;

	auto oper = [&](int x) {
		cur += x;
		ans.push_back(cur);
	};

	if (c % 3 == 2) {
		for (int j = 0; j < cnt + 1; j++) {
			oper(3);
		}
		oper(-1);
		for (int j = 0; j < cnt; j++) {
			oper(-3);
		}
		oper(-1);
		for (int j = 0; j < cnt + 1; j++) {
			oper(3);
		}

		a -= 2;
		c = 0;
	} else {
		for (int j = 0; j < cnt; j++) {
			oper(3);
		}
		oper(1);
		for (int j = 0; j < cnt; j++) {
			oper(-3);
		}
		oper(1);
		for (int j = 0; j < cnt; j++) {
			oper(3);
		}

		a -= 2;
		c -= cnt * 3;

		if (c) {
			if (b == 3) {
				while (a) {
					oper(1);
					a--;
				}
				oper(2);
				oper(2);
				oper(-3);
				oper(2);
				b = 0;
			} else {
				oper(2);
				oper(2);
				oper(-3);
				oper(2);
				oper(2);
				b -= 4;
			}
		}
	}

	// a, b only
	if(b){
		while(a > 1) {
			oper(1);a--;
		}

		while(cur + 2 <= n) oper(2), b--;
		if (cur == n) oper(-1);
		else oper(1);
		a = 0;
		while(b){
			oper(-2);
			b--;
		}
	}
	while(a) oper(1), a--;

	for(auto f : ans) cout <<f << ' ';
	cout << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	cin >> t;
	while (t--) { solve(); }
	return 0;
}
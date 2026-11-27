#include <bits/stdc++.h>
using namespace std;

set<int> p;

bool isPrime(int x) {

	if (x <= 1) return 0;

	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) return 0;
	}
	return 1;
}

void choose(int len, string t = "", int i = 0) {

	if (i == len) {
		string s = t;
		reverse(s.begin(), s.end());

		bool ok = isPrime(stoi(s + t));
		if (ok) p.insert(stoi(s + t));

		ok = isPrime(stoi(s + t.substr(1, len)));
		if (ok) p.insert(stoi(s + t.substr(1, len)));

		return;
	}

	for (int j = 0; j <= 9; j++) {
		
		if (i == len - 1 && j == 0) continue;

		choose(len, t + char('0' + j), i + 1);
	}
}


int main() {

	int l, r;
	cin >> l >> r;

	for (int i = 1; i <= 4; i++) {
		choose(i);
	}

	for (auto i : p) if (i >= l && i <= r) cout << i << '\n';
	cout << -1;


}
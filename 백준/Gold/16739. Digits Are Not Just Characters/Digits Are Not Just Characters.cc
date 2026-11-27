#include <bits/stdc++.h>
using namespace std;

bool isDigit(char c) {
	return c >= '0' && c <= '9';
}

void cmp(string& a, string& b) {

	int n = a.size();
	int m = b.size();

	int ai = 0, bi = 0;
	while (ai < n && bi < m) {
		
		if (isDigit(a[ai]) && isDigit(b[bi])) {
			int na = 0;
			int nb = 0;

			while (ai < n && isDigit(a[ai])) {
				na = na * 10 + (a[ai] - '0');
				ai++;
			}
			while (bi < m && isDigit(b[bi])) {
				nb = nb * 10 + (b[bi] - '0');
				bi++;
			}

			if (na == nb) {
				continue;
			}

			if (na < nb) {
				cout << "+\n";
			}
			else cout << "-\n";
			return;
		}
		else if (a[ai] == b[bi]) {
			ai++;
			bi++;
		}
		else if (isDigit(a[ai])) {
			cout << "+\n";
			return;
		}
		else if (isDigit(b[bi])) {
			cout << "-\n";
			return;
		}
		else {
			if (a[ai] < b[bi]) {
				cout << "+\n";
			}
			else cout << "-\n";
			return;
		}
	}

	if (ai == n && bi == m) cout << "+\n";
	else if (ai == n) cout << "+\n";
	else cout << "-\n";
}

int main() {

	int n;
	cin >> n;

	string s;
	cin >> s;

	for (int i = 0; i < n; i++) {
		string inp;
		cin >> inp;

		cmp(s, inp);
	}
}
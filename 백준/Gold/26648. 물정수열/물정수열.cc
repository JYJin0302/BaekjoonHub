#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> A(n), B(n), C(n);
	for (auto& i : A) cin >> i;
	for (auto& i : B) cin >> i;
	for (auto& i : C) cin >> i;

	int l = -1, r = -1;
	bool ok = 1;

	for (int i = 0; i < n; i++) {
		vector<int> tmp = { A[i], B[i], C[i] };
		sort(tmp.begin(), tmp.end());

		int nl = tmp[0], nr = tmp[2];

		nl = max(l + 1, nl);
		if (nr < nl) ok = 0;

		l = nl, r = nr;
	}

	if (ok) cout << "YES";
	else cout << "NO";
}
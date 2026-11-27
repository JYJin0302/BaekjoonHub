#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<int> A(n);
	for (auto& i : A) cin >> i;

	vector<pair<int, int>> boots(m);
	for (auto& i : boots){
		cin >> i.first >> i.second;
	}

	int c = 0;
	vector<bool> ok(n);
	ok[0] = 1;

	while (!ok[n - 1]) {

		int a, b;
		tie(a, b) = boots[c];
		c++;

		for (int i = 0; i < n; i++) {

			if (!ok[i] || A[i] > a) continue;

			for (int j = min(n - 1, i + b); j > i; j--) {
				if (A[j] <= a) ok[j] = 1;
			}
		}
	}

	cout << c - 1;

}
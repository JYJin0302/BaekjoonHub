#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<bool> used(n + 1);
	vector<int> A(n), P(n);
	for (auto& i : A) cin >> i;

	for (int i = n - 1; i >= 0; i--) {

		vector<int> tmp;
		for (int j = 1; j <= n; j++) if (!used[j]) tmp.push_back(j);

		for (int j = 0; j < tmp.size(); j++) {
			A[j] ^= tmp[j];
		}

		P[i] = A[i];
		used[A[i]] = 1;
	}

	for (int i : P) cout << i << ' ';
}
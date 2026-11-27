#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<string, int> ix;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int m;
	cin >> m;

	vector<int> A;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		string s;
		int x;
		cin >> s >> x;

		if (ix[s] == 0) {
			ix[s] = ++cnt;
			A.push_back(x);
		}
		else {
			A[ix[s] - 1] += x;
		}
	}

	bool ok = 0;
	for (int i = 0; i < cnt; i++) {
		for (int j = i + 1; j < cnt; j++) {

			if (floor(1.0 * A[i] * 1.618) == A[j]) ok = 1;
			if (floor(1.0 * A[j] * 1.618) == A[i]) ok = 1;
		}
	}

	if (ok) cout << "Delicious!";
	else cout << "Not Delicious...";
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int r, s, p;
	cin >> r >> s >> p;

	vector<int> A;
	for (int i = 0; i < p; i++) {
		int a, b;
		cin >> a >> b;

		int v = r + 1 - a;
		if (b <= s) v += s - b+1;
		else v += b - s;

		A.push_back(v);
	}

	sort(A.begin(), A.end());

	int ans = A[0];
	for (int i = 1; i < p; i++) {
		ans = max(ans + 1, A[i]);
	}
	cout << ans;
}

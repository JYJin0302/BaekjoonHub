#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int root[10001];

int find(int n) {
	if (root[n] == n) return n;
	return root[n] = find(root[n]);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int tot = 0, ans = 0;
	vector<tuple<int, int, int>> C, D;

	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		tot += c;
		if (d) {
			D.push_back({ a, b, c });
		}
		else {
			C.push_back({ c, a, b });
		}
	}

	for (int i = 1; i <= n; i++) root[i] = i;
	for (auto i : D) {
		int a, b, c;
		tie(a, b, c) = i;

		ans += c;
		a = find(a), b = find(b);
		root[a] = b;
	}

	sort(C.rbegin(), C.rend());
	for (auto i : C) {
		int a, b, c;
		tie(a, b, c) = i;

		b = find(b), c = find(c);
		if (b == c) continue;
		root[b] = c;
		ans += a;
	}

	cout << tot - ans;
}
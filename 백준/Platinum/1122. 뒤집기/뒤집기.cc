#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int dist[202020];
int root[202020];

int find(int n) {
	if (root[n] == n) return n;
	return root[n] = find(root[n]);
}

void solve() {
	int a, b, k;
	cin >> a >> b >> k;
	if (a == 0) {
		cout << 0 << '\n';
		return;
	}
	if (a + b < k) {
		cout << -1 << '\n';
		return;
	}

	int n = a + b;
	for (int i = 0; i <= n + 10; i++) { root[i] = i; }
	memset(dist, -1, sizeof dist);
	dist[a] = 0;
	root[a] = a + 2;
	queue<int> q;
	q.push(a);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		int ta = v, tb = n - v;

		int r = min(ta, k);
		int na = ta - r + (k - r);
		int nb = tb - (k - r) + r;

		r = min(tb, k);
		int na2 = ta - (k - r) + r;
		int nb2 = tb - r + (k - r);

		if (na > na2) swap(na, na2);

		for (int ix = na; ix <= na2;) {
			ix = find(ix);
			if (ix > na2) break;
			dist[ix] = dist[v] + 1;
			q.push(ix);
			root[ix] = ix + 2;
		}
	}

	cout << dist[0] << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) { solve(); }
	return 0;
}
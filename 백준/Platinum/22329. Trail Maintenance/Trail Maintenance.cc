#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int root[202];
int find(int n) {
	if (root[n] == n) return n;
	return root[n] = find(root[n]);
}
void solve() {
	int n, m;
	cin >> n >> m;

	vector<array<int, 3>> edge, tmp;

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({c, a, b});


		if ((int)edge.size() < n - 1) {
			cout << -1 << endl;
			continue;
		}
		sort(all(edge));

		tmp.clear();
		for (int i = 1; i <= n; i++) root[i] = i;
		int cnt = 0;
		ll tot = 0;
		for (auto f : edge) {
			int u = f[1], v = f[2];
			u = find(u), v = find(v);
			if (u != v) {
				tmp.push_back(f);
				cnt++;
				tot += f[0];
				root[v] = u;
			}
		}
		swap(tmp, edge);

		if (cnt == n - 1) {
			cout << tot << endl;
		} else cout << -1 << endl;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	return 0;
}
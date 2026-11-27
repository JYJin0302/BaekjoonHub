#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<int> adj[101010];

void solve() {
	int n, m, k;
	cin >> n >> m >> k;

	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<bool> vis(n + 1);
	vector<int> ans(n + 1);

	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		queue<int> q;
		vector<int> lst;
		q.push(i);
		vis[i] = 1;
		while (!q.empty()) {
			int a = q.front();
			q.pop();
			lst.push_back(a);
			for (auto f : adj[a]) {
				if (!vis[f]) {
					vis[f] = 1;
					q.push(f);
				}
			}
		}

		if ((int)lst.size() < k) {
			cout << "impossible\n";
			return;
		}

		for (int j = 0; j < (int)lst.size(); j++) { ans[lst[j]] = j % k + 1; }
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	cout << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
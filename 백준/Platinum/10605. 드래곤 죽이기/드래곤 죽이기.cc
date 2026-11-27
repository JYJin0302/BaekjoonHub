#include <bits/stdc++.h>
using namespace std;

int citycnt;
vector<vector<int>> adj;
vector<bool> visit;
vector<int> city;

void dfs(int v) {
	visit[v] = 1;
	city[v] = citycnt;
	for (int i : adj[v]) {
		if (!visit[i]) dfs(i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;

	while (n || m || k) {

		adj = vector<vector<int>>(n + 1);
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		visit = vector<bool>(n + 1);
		city = vector<int>(n + 1);
		citycnt = 0;
		for (int i = 1; i <= n; i++) {
			if (!visit[i]) {
				dfs(i);
				citycnt++;
			}
		}

		vector<vector<pair<int, int>>> dragon(citycnt);
		for (int i = 0; i < k; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			dragon[city[a]].push_back({ b ,c });
		}

		int ans = 0;
		for (int i = 0; i < citycnt; i++) {
			
			int tans = 0;
			int l = 0, r = 100000;
			while (l <= r) {

				int mid = (l + r) / 2;
				int cnt = 0;
				for (auto t : dragon[i]) {
					int a, b;
					tie(a, b) = t;

					if (b >= mid) cnt += a;
				}

				if (cnt > mid) {
					l = mid + 1;
				}
				else {
					tans = mid;
					r = mid - 1;
				}
			}

			ans += tans;
		}

		cout << ans << '\n';
		cin >> n >> m >> k;
	}
}
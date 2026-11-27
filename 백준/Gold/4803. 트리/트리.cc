#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vi;

bool no_tree = 0;

void dfs(int v, int pv = -1) {

	vi[v] = 1;
	for (auto i : adj[v]) if (i != pv) {
		if (!vi[i]) dfs(i, v);
		else no_tree = 1;
	}
}

int main() {

	int n, m;
	cin >> n >> m;

	int case_cnt = 0;
	while (!(n == 0 && m == 0)) {

		adj = vector<vector<int>>(n+1);
		vi = vector<bool>(n + 1);
		no_tree = 0;

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;

			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (!vi[i]) {
				no_tree = 0;
				dfs(i);
				if (!no_tree) ans++;
			}
		}

		case_cnt++;
		cout << "Case " << case_cnt << ": ";

		if (ans == 0) cout << "No trees.\n";
		else if (ans == 1) cout << "There is one tree.\n";
		else cout << "A forest of " << ans << " trees.\n";

		cin >> n >> m;
	}

}
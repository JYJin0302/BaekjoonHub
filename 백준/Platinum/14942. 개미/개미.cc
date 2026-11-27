#include <bits/stdc++.h>
using namespace std;

int n, a, b, c;
vector<vector<pair<int, int>>> base;
vector<int> path;
vector<int> from;

void dfs(int v = 1, int pv = 0) {
	for (auto i : base[v]) {
		tie(a, b) = i;
		if (a == pv) continue;
		from[a] = v;
		path[a] = path[v] + b;
		dfs(a, v);
	}
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	cin >> n;
	
	vector<int> energy(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> energy[i];
	}

	base = vector<vector<pair<int, int>>> (n+1);

	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		base[a].push_back({ b, c });
		base[b].push_back({ a,c });
	}

	path = vector<int>(n + 1);
	from = vector<int>(n + 1);
	dfs();
	
	vector<int> ans(n + 1);
	for (int i = 1; i <= n; i++) {
		int curr = i;
		int nextr = from[curr];
		while (curr != 1 && energy[i] - (path[curr] - path[nextr]) >= 0) {
			energy[i] -= path[curr] - path[nextr];
			curr = from[curr];
			nextr = from[nextr];
		}
		ans[i] = curr;
	}
	
	for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
	
}
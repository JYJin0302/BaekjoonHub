#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, a, b;
	cin >> n >> m;
	vector<int> topo(n+1);
	vector<vector<int>> base(n + 1);
	vector<int> ans;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		base[a].push_back(b);
		topo[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (topo[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		a = q.front();
		q.pop();
		ans.push_back(a);
		for (int i : base[a]) {
			topo[i]--;
			if (topo[i] == 0) q.push(i);
		}
	}
	
	for (int i : ans) cout << i << ' ';
}
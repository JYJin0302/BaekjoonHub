#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> root;
vector<vector<int>> adj;

int find(int n) {
	if (root[n] == n) return n;
	return root[n] = find(root[n]);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;

	root = vector<int>(n + 1);
	for (int i = 1; i <= n; i++) root[i] = i;
	vector<int> topo(n + 1);
	adj = vector<vector<int>>(n + 1);

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
		topo[a]++;
		topo[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (topo[i] == 1) q.push(i);
	}

	while (!q.empty()) {

		int a = q.front();
		q.pop();

		for (int i : adj[a]) if (topo[i] != 1) {

			root[a] = root[i];
			topo[i]--;

			if (topo[i] == 1) {
				q.push(i);
			}
		}
	}

	while (m--) {

		int a, b;
		cin >> a >> b;

		a =	find(a), b = find(b);
		if (a == b) cout << "1\n";
		else cout << "2\n";
	}

}
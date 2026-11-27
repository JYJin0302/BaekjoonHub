#include <bits/stdc++.h>
using namespace std;

// 같은 것들 끼리 묶은(분리 집합) 후에 위상정렬

vector<int> root;

int find(int n) {
	if (root[n] == n) return n;

	return root[n] = find(root[n]);
}



int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	int n, m;
	cin >> n >> m;

	root = vector<int>(n);
	for (int i = 1; i < n; i++) root[i] = i;

	vector<pair<int, int>> game;

	int a, b;
	char c;
	for (int i = 0; i < m; i++) {
		
		cin >> a >> c >> b;
		if (c == '=') {
			int x = find(a);
			int y = find(b);
			root[x] = y;
		}
		else if (c == '>') {
			game.push_back({ b, a });
		}
		else game.push_back({ a, b });
	}
	for (int i = 0; i < n; i++) find(i);

	vector<int> topo(n, -1); //오름차순
	vector<vector<int>> adj(n);

	for (auto& i : game) {
		tie(a, b) = i;
		a = find(a);
		b = find(b);
		adj[a].push_back(b);
		if (topo[a] == -1) topo[a] = 0;
		if (topo[b] == -1) topo[b] = 1;
		else topo[b]++;
	}

	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (topo[i] == 0) q.push(i);
	}

	while (!q.empty()) {

		a = q.front();
		q.pop();
		for (int i : adj[a]) {
			topo[i]--;
			if (topo[i] == 0) q.push(i);
		}
	}

	bool ok = true;
	for (int i : topo) {
		if (i > 0) {
			ok = false;
			break;
		}
	}


	if (ok) cout << "consistent";
	else cout << "inconsistent";
}
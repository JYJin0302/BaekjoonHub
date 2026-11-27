#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
vector<int> rev[100001];

int rep[100001];
int topo[100001];
int val[100001];

void dfs(int v, int pv = -1) {
	for (auto i : adj[v]) if (i != pv && rep[i] == 0) {
		rep[i] = rep[v];
		dfs(i, v);
	}

	for (auto i : rev[v]) if (i != pv && rep[i] == 0) {
		rep[i] = rep[v];
		dfs(i, v);
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a, b;
	cin >> n >> a >> b;

	while (a--) {
		int x, y;
		cin >> x >> y;

		adj[x].push_back(y);
		rev[y].push_back(x);
		topo[y]++;
	}

	vector<pair<int, int>> edge(b);
	for (auto& i : edge) cin >> i.first >> i.second;

	for (int i = 1; i <= n; i++) {
		if (rep[i] == 0) {
			rep[i] = i;
			dfs(i);
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (topo[i] == 0) {
			q.push(i);
			val[i] = 1;
		}
	}
	while (!q.empty()) {
		int a = q.front();
		q.pop();

		for (auto i : adj[a]) {
			val[i] = val[a] + 1;
			topo[i]--;
			if (topo[i] == 0) q.push(i);
		}
	}

	for (auto i : edge) {
		int x, y;
		tie(x, y) = i;

		if (rep[x] != rep[y]) {
			if (rep[x] < rep[y]) swap(x, y);
			cout << x << ' ' << y << '\n';
		}
		else {
			if (val[x] > val[y]) swap(x, y);
			cout << x << ' ' << y << '\n';
		}
	}

}
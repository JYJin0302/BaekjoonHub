#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> adj[100001];
int topo[100001];

int val[100001];
bool ck[100001];

int root[100001], sz[100001];
int find(int n) {
	if (root[n] == n) return n;
	return root[n] = find(root[n]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		root[i] = i;
		sz[i] = 1;
	}

	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
		topo[a]++, topo[b]++;
	}

	vector<pair<int, int>> edge;
	vector<int> vtx;

	priority_queue<pair<int, int>> pq;
	for (int i = 1; i <= n; i++) {
		pq.push({ -topo[i], i });
	}
	while (!pq.empty()) {
		int a, b;
		tie(a, b) = pq.top();
		pq.pop();

		if (ck[b]) continue;
		vtx.push_back(b);
		ck[b] = 1;
		
		val[b] = -a;
		for (auto i : adj[b]) {

			topo[i]--;
			if (!ck[i]) {
				edge.push_back({ b, i });
				pq.push({ -topo[i], i });
			}
		}
	}

	/*
	cout << "EDGE:\n";
	for (auto i : edge) cout << i.first << ' ' << i.second << '\n';
	cout << "vtx: ";
	for (auto i : vtx) cout << i << ' ';
	cout << '\n';
	for (int i = 1; i <= n; i++) cout << val[i] << ' ';
	*/

	reverse(edge.begin(), edge.end());
	reverse(vtx.begin(), vtx.end());

	int ans = 0;
	int idx = 0;
	for (int i = 0; i < n; i++) {
		int curr_v = vtx[i];

		while (idx < m && edge[idx].first == curr_v) {
			int a, b;
			tie(a, b) = edge[idx];

			a = find(a), b = find(b);

			if (a != b) {
				sz[a] += sz[b];
				root[b] = a;

				ans = max(ans, sz[a] * val[a]);
			}
			idx++;
		}

	}
	cout << ans;
}
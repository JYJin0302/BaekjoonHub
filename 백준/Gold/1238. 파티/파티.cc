#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int n, m, x, a, b, c;
	cin >> n >> m >> x;

	vector<vector<pair<int ,int>>> base(n+1);
	vector<vector<pair<int ,int>>> rebase(n+1);

	while (m--) {
		cin >> a >> b >> c;
		base[a].push_back({ b, c });
		rebase[b].push_back({ a,c });
	}

	vector<bool> check(n + 1);
	vector<int> path(n + 1, INF);
	vector<int> repath(n + 1, INF);

	priority_queue<pair<int , int>> pq;
	path[x] = 0;
	pq.push({ 0, x });
	while (!pq.empty()) {
		tie(a, b) = pq.top();
		pq.pop();
		if (check[b]) continue;
		check[b] = 1;
		for (auto k : base[b]) {			
			tie(a, c) = k;
			
			if (path[a] > path[b] + c) {
				path[a] = path[b] + c;
				pq.push({ -path[a], a });
			}
		}
	}
	check = vector<bool>(n + 1);

	repath[x] = 0;
	pq.push({ 0, x });
	while (!pq.empty()) {
		tie(a, b) = pq.top();
		pq.pop();
		if (check[b]) continue;
		check[b] = 1;
		for (auto k : rebase[b]) {
			tie(a, c) = k;

			if (repath[a] > repath[b] + c) {
				repath[a] = repath[b] + c;
				pq.push({ -repath[a], a });
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, path[i] + repath[i]);
	}
	cout << ans;
}
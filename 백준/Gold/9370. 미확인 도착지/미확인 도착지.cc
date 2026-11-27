#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
// 시작지에서의 최소거리
// 특정 도로를 건넌 후의 최소거리

int n, m, t;
int s, g, h;
vector<vector<pair<int, int>>> adj;
vector<int> findpath(int k) {
	vector<int> temp(n + 1, INF);

	temp[k] = 0;

	priority_queue<pair<int, int >> pq;
	pq.push({ 0, k });
	while (!pq.empty()) {
		int a, b;
		tie(a, b) = pq.top();
		pq.pop();

		for (auto i : adj[b]) {
			int x, y;
			tie(x, y) = i;

			if (temp[b] + y < temp[x]) {
				temp[x] = temp[b] + y;
				pq.push({ -temp[x], x });
			}
		}
	}

	return temp;
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {

		cin >> n >> m >> t;
		cin >> s >> g >> h;

		adj = vector<vector<pair<int, int>>>(n + 1);
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;

			adj[a].push_back({ b, c });
			adj[b].push_back({ a,c });
		}

		vector<int> target(t);
		for (auto& i : target) cin >> i;

		vector<int> path1(n + 1), path2(n + 1);
		path1 = findpath(s);

		int addnum;

		if (path1[g] > path1[h]) {
			path2 = findpath(g);
			addnum = path1[g];
		}
		else {
			path2 = findpath(h);
			addnum = path1[h];
		}

		vector<int> ans;
		for (int i : target) {
			if (path2[i] + addnum == path1[i]) ans.push_back(i);
		}
		sort(ans.begin(), ans.end());

		for (int i : ans) cout << i << ' ';
		cout << '\n';

	}
}
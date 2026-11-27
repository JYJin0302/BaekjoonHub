#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int dy[] = { -1, -1, -1, 0, 1, 1, 1, 0 };


int n, m;
int idx[55][55];
bool vs[55][55];

int ans[2500], h[2500];
vector<int> adj[2500];

bool inGrid(int x, int y) {
	return x >= 0 && x <= n+1&& y >= 0 && y <= m+1;
}

void dfs(int v, int pv = -1) {

	int mh = -1;
	for (auto i : adj[v]) if (i != pv) {
		dfs(i, v);
		mh = max(mh, h[i]);
	}
	h[v] = mh + 1;
	if (v != 0) ans[h[v]]++;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	string tt(m + 2, '.');
	vector<string> A(n+2, tt);

	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < m; j++) {
			A[i][j + 1] = s[j];
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (A[i][j] == '.' || idx[i][j] != 0) continue;
			cnt++;

			queue<pair<int, int>> q;
			q.push({ i, j });
			idx[i][j] = cnt;
			while (!q.empty()) {

				int a, b;
				tie(a, b) = q.front();
				q.pop();

				for (int k = 0; k < 8; k++) {
					int na = a + dx[k];
					int nb = b + dy[k];

					if (inGrid(na, nb) && A[na][nb] == 'x' && idx[na][nb] == 0) {
						idx[na][nb] = cnt;
						q.push({ na, nb });
					}
				}
			}
		}
	}

	if (cnt == 0) {
		cout << -1;
		return 0;
	}

	vector<pair<int, int>> edge;

	deque<tuple<int, int, int>> dq;
	dq.push_back({ 0, 0, 0 });
	while (!dq.empty()) {

		int a, b, th;
		tie(a, b, th) = dq.front();
		dq.pop_front();

		for (int i = 1; i < 8; i += 2) {
			int na = a + dx[i];
			int nb = b + dy[i];

			if (inGrid(na, nb) && !vs[na][nb]) {
				vs[na][nb] = 1;

				if (A[na][nb] == 'x') {
					int tix = idx[na][nb];

					if (th != tix) edge.push_back({ th, tix });
					dq.push_back({ na, nb, tix });
				}
				else {
					dq.push_front({ na, nb, th });
				}
			}
		}
	}

	sort(edge.begin(), edge.end());
	edge.erase(unique(edge.begin(), edge.end()), edge.end());

	
	for (auto i : edge) {
		adj[i.first].push_back(i.second);
	}

	dfs(0);

	int ix = 0;
	while (ans[ix]) {
		cout << ans[ix] << ' ';
		ix++;
	}

	
}
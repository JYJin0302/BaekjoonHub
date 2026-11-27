#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int A[55];
vector<int> adj[55];
const double eps = 1e-10;

bool E[55];
int dfsn[55];
int G[55];
double B[55];
double V[55];

int ord = 0;
vector<int> stk;
int dfs(int v) {
	dfsn[v] = ++ord;
	stk.push_back(v);
	int ret = dfsn[v];
	for (auto f : adj[v]) {
		if (!E[f]) continue;

		if (dfsn[f] == -1) {
			ret = min(ret, dfs(f));
		} else if (G[f] == -1) {
			ret = min(ret, dfsn[f]);
		}
	}
	if (ret == dfsn[v]) {
		double res = 1010;
		while (!stk.empty()) {
			auto a = stk.back();
			stk.pop_back();
			res = min(res, B[a]);
			G[a] = v;
			if (a == v) break;
		}
		V[v] = res;
	}
	return ret;
}

void solve() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			if (c == 'Y') { adj[i].push_back(j); }
		}
	}

	double L = 1, R = 1000;
	while (R - L > eps) {
		double md = (L + R) / 2;

		for (int i = 0; i < n; i++) B[i] = A[i] - md;

		vector<bool> vis(n);
		double res = 0;
		queue<int> q;
		for (int i = 0; i < n; i++) {
			if (B[i] < 0) {
				res += B[i];
				if (!vis[i]) {
					vis[i] = 1;
					q.push(i);
					while (!q.empty()) {
						int a = q.front();
						q.pop();
						for (auto f : adj[a]) {
							if (!vis[f]) {
								vis[f] = 1;
								q.push(f);
							}
						}
					}
				}
			}
		}

		bool done = 1;
		ord = 0;
		for (int i = 0; i < n; i++) {
			dfsn[i] = -1;
			G[i] = -1;
			E[i] = !vis[i];
			if (E[i]) done = 0;
		}

		if (!done) {
			for (int i = 0; i < n; i++) {
				if (E[i] && dfsn[i] == -1) { dfs(i); }
			}
			vector<int> topo(n);

			for (int i = 0; i < n; i++) {
				if (!E[i]) continue;
				for (auto j : adj[i]) {
					if (!E[j]) continue;

					int ti = G[i], tj = G[j];
					if (ti != tj) { topo[tj]++; }
				}
			}

			for (int i = 0; i < n; i++) {
				if (E[i] && G[i] == i && topo[i] == 0) { res += V[i]; }
			}
		}

		if (res <= 0) {
			R = md;
		} else L = md;
	}

	cout << setprecision(20);
	cout << (L+R)/2 << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
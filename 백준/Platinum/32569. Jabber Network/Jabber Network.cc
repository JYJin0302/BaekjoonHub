#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<pair<int, int>> adj[3030];

ll S[3030];
int edx[3030][3030];

int T[2020];

void setup(int s, int t) {
	memset(T, -1, sizeof T);
	T[s] = 1;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		auto f = q.front();
		q.pop();
		for (auto [a, b] : adj[f])
			if (a != t && T[a] == -1) {
				T[a] = 1;
				q.push(a);
			}
	}
}

int s1, s2;
ll dp[3030];
ll tot[3030];
void dfs(int v, int pv = -1) {
	dp[v] = 0;
	tot[v] = S[v];
	for (auto [a, b] : adj[v])
		if (a != pv) {
			dfs(a, v);
			dp[v] += dp[a] + tot[a];
			tot[v] += tot[a];
		}
}

ll curAns = 1e18;
ll curI = -1;
void getAns(int v, int pv = -1, ll pU = 0, ll pT = 0) {
	ll totU = pU + dp[v] + pT;
	ll totT = pT + tot[v];
	if (curAns > totU || (curAns == totU && curI > v)) {
		if (adj[v].size() < 3 || v == s1 || v == s2) {
			curAns = totU;
			curI = v;
		}
	}

	for (auto [a, b] : adj[v])
		if (a != pv) { getAns(a, v, totU - dp[a] - tot[a], totT - tot[a]); }
}

void solve() {
	int n;
	cin >> n;

	vector<pair<int, int>> edg(n - 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		edg[i] = mp(a, b);
		adj[a].push_back(mp(b, i));
		adj[b].push_back(mp(a, i));

		edx[b][a] = edx[a][b] = i;
	}

	int d;
	cin >> d;

	vector<array<ll, 3>> D;
	while (d--) {
		int a, b, t;
		cin >> a >> b >> t;

		D.push_back({a, b, t});
	}

	for (int i = 0; i < n - 1; i++) {
		// solve();
		auto [a, b] = edg[i];

		setup(a, b);
		s1 = a, s2 = b;
		for (int j = 1; j <= n; j++) S[j] = 0;
		for (auto f : D) {
			int a = f[0], b = f[1];
			if (T[a] != T[b]) {
				S[a] += f[2];
				S[b] += f[2];
			}
		}

		pair<int, int> ans;
		dfs(a, b);
		curAns = 1e18;
		curI = -1;
		getAns(a, b);
		ans.x = curI;
		dfs(b, a);
		curAns = 1e18;
		curI = -1;
		getAns(b, a);
		ans.y = curI;

		if (ans.x > ans.y) swap(ans.x, ans.y);
		cout << ans.x << ' ' << ans.y << '\n';

		// update
		auto iter = adj[a].begin();
		while ((*iter) != mp(b, i)) iter++;
		adj[a].erase(iter);
		iter = adj[b].begin();
		while ((*iter) != mp(a, i)) iter++;
		adj[b].erase(iter);
		adj[ans.x].push_back(mp(ans.y, i));
		adj[ans.y].push_back(mp(ans.x, i));
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	return 0;
}
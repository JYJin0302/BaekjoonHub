#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<pair<int, int>> adj[101010];
bool vis[101010];

vector<int> eLst, vLst;
void dfs(int v) {
	vLst.push_back(v);
	for (auto [a, b] : adj[v]) {
		if (!vis[a]) {
			vis[a] = 1;
			eLst.push_back(b);
			dfs(a);
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(mp(b, i));
		adj[b].push_back(mp(a, i));
	}

	if (n <= 2) {
		cout << -1 << '\n';
		return;
	}

	vector<vector<int>> tmpE, tmpV;

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			eLst.clear();
			vLst.clear();
			dfs(i);
			tmpV.push_back(vLst);
			tmpE.push_back(eLst);
		}
	}

	if ((int)tmpE.size() > 2) {
		cout << -1 << '\n';
	} else if ((int)tmpE.size() == 2) {
		if ((int)tmpE[0].size() == (int)tmpE[1].size()) cout << -1 << '\n';
		else {
			cout << (int)tmpV[0].size() << ' ' << (int)tmpV[1].size() << '\n';
			for (int j = 0; j < 2; j++) {
				for (auto f : tmpV[j]) cout << f << ' ';
				cout << '\n';
				for (auto f : tmpE[j]) cout << f << ' ';
				cout << '\n';
			}
		}
	} else {
		cout << n - 1 << ' ' << 1 << '\n';
		for (int i = 0; i < n - 1; i++) cout << tmpV[0][i] << ' ';
		cout << '\n';
		for (int i = 0; i < n - 2; i++) { cout << tmpE[0][i] << ' '; }
		cout << '\n';
		cout << tmpV[0].back() << '\n';
		cout << '\n';
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) { solve(); }
	return 0;
}
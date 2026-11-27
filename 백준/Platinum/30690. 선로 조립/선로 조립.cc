#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define mp make_pair
vector<int> adj[202020];

int U[202020], D[202020];
int dp_max[202020], dp_v[202020];

void dfs(int v, int pv = -1) {
	vector<int> tmp = { 0 };
	for (auto f : adj[v]) if (f != pv) {
		dfs(f, v);
		dp_max[v] = max(dp_max[v], dp_max[f]);
		tmp.push_back(dp_v[f] + 1);
	}

	sort(tmp.rbegin(), tmp.rend());

	if (tmp.size() >= 2) dp_max[v] = max(dp_max[v], tmp[0] + tmp[1]);
	dp_v[v] = tmp[0];
	D[v] = dp_max[v];
}

void dfs2(int v, int pv = -1, int pval = -1, int p_mval = 0) {
	vector<pair<int, int>> tmp, tmp2;
	tmp.push_back(mp(pval + 1, pv));
	tmp2.push_back(mp(p_mval, pv));
	for (auto f : adj[v]) if (f != pv) {
		tmp.push_back(mp(dp_v[f] + 1, f));
		tmp2.push_back(mp(dp_max[f], f));
	}
	sort(tmp.rbegin(), tmp.rend());
	while (tmp.size() < 3) tmp.push_back(mp(0, -1));
	sort(tmp2.rbegin(), tmp2.rend());
	while (tmp2.size() < 3) tmp2.push_back(mp(0, -1));

	/*cout << "Curr: " << v << '\n';
	for (auto f : tmp) cout << '{' << f.first << "," << f.second << "} ";
	cout << '\n';
	for (auto f : tmp2) cout << '{' << f.first << "," << f.second << "} ";
	cout << '\n';*/
	for (auto f : adj[v]) if (f != pv) {
		int res = tmp2[0].first;
		if (tmp2[0].second == f) res = tmp2[1].first;

		vector<int> tt;
		for (int x = 0; x < 3; x++) if (tmp[x].second != f) tt.push_back(tmp[x].first);

		res = max(res, tt[0] + tt[1]);
		U[f] = res;

		int nval = tt[0];
		//cout << "Go: " << f << ": " << nval << ' ' << res << '\n';
		dfs2(f, v, nval, res);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1);
	dfs2(1);
	while (q--) {

		int u, v;
		cin >> u >> v;

		if (dp_v[u] < dp_v[v])  swap(u, v);
		cout << U[v] + D[v] + 1 << '\n';
	}
}
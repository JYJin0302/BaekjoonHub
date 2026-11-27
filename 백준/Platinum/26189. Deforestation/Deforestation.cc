#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, ans = 0;
vector<int> adj[100101];
ll val[100101], dp[101010];

int tx = 0;
void getIn(int pv = 0) {

	ll a, b;
	cin >> a >> b;

	int ix = ++tx;
	val[ix] = a;

	if (pv != 0) {
		adj[ix].push_back(pv);
		adj[pv].push_back(ix);
	}

	while (b--) {
		getIn(ix);
	}
}

void dfs(int v, int pv = 0) {

	vector<ll> tmp;
	for (auto i : adj[v]) if (i != pv) {
		dfs(i, v);
		tmp.push_back(dp[i]);
	}
	tmp.push_back(0);

	for (auto& i : tmp) {
		if (i != 0 && i % m == 0) {
			ans += (i / m) - 1;
			i = m;
		}
		else {
			ans += i / m;
			i %= m;
		}
	}
	sort(tmp.begin(), tmp.end());

	int tot = 0;
	for (auto i : tmp) {
		tot += i;
		if (tot > m) {
			tot -= i;
			ans++;
		}
	}

	tot += val[v];
	if (tot != 0 && tot % m == 0) {
		ans += (tot / m) - 1;
		tot = m;
	}
	else {
		ans += tot / m;
		tot %= m;
	}
	dp[v] = tot;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> m;

	tx = 0;
	getIn();

	dfs(1);

	cout << ans+1;
}
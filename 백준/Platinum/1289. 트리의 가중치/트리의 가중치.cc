#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, mod = 1e9 + 7;
ll ans = 0;

vector<vector<pair<ll, ll>>> adj;
vector<ll> subCnt;
vector<ll> pathSum;

void dfs(int v, int pv = 0) {
	for (auto i : adj[v]) {
		
		ll a, b;
		tie(a, b) = i;

		if (a != pv) {
			dfs(a, v);
			subCnt[v] += subCnt[a];

			ans += (pathSum[v] * (pathSum[a] + 1) % mod) * b;
			ans %= mod;
			pathSum[v] += (pathSum[a] + 1) * b;
			pathSum[v] %= mod;

		}
	}

	subCnt[v]++;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;

	adj = vector<vector<pair<ll, ll>>> (n+1);
	for (int i = 0; i < n - 1; i++) {

		ll a, b, w;
		cin >> a >> b >> w;

		adj[a].push_back({ b, w });
		adj[b].push_back({ a, w });
	}
		
	subCnt = vector<ll>(n + 1);
	pathSum = vector<ll>(n + 1);

	dfs(1);
	
	for (auto i : pathSum) {
		ans += i;
		ans %= mod;
	}
	cout << ans << '\n';
}
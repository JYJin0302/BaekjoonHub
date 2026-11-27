#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> A;
vector<pair<ll, ll>> adj[100001];
ll dist[100001];

int ans = 0;
bool cut = 0;
void dfs(int v, int pv = -1) {

	if (cut) {
		ans++;
		for (auto i : adj[v]) if (i.first != pv) {
			dfs(i.first, v);
		}
		return;
	}


	for (auto i : adj[v]) if (i.first != pv) {
		dist[i.first] = dist[v] + i.second;

		if (A[i.first] < dist[i.first]) {
			cut = 1;
			dfs(i.first, v);
			cut = 0;
		}
		else dfs(i.first, v);
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	A = vector<ll>(n);
	for (auto& i : A) cin >> i;

	for (int i = 1; i < n; i++) {
		ll a, b;
		cin >> a >> b;

		a--;
		adj[i].push_back({ a, b });
		adj[a].push_back({ i, b });
	}

	dfs(0);

	cout << ans;
}
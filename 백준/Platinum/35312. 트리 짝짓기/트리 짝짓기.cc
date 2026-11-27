#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<int> adj[202020];
ll F[202020];

const int mod = 998244353;
ll mul[202020];
ll fastPow(ll b, ll ex) {
	ll res = 1;
	while (ex) {
		if (ex & 1) res = res * b % mod;
		b = b * b % mod;
		ex >>= 1;
	}
	return res;
}

ll ans = 1;
int dfs(int v, int pv = -1) {
	int cnt = 1;
	for (auto f : adj[v])
		if (f != pv) {
			int r = dfs(f, v);
			cnt += r;
		}
	ans = ans * mul[cnt] % mod;
	return cnt & 1;
}

void solve() {
	int n;
	cin >> n;

	n *= 2;
	for (int i = 1; i <= n; i++) adj[i].clear();
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ans = 1;
	dfs(1);
	cout << ans << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	F[0] = 1;
	for (int i = 1; i <= 200000; i++) { F[i] = F[i - 1] * i % mod; }
	mul[0] = mul[1] = 1;

	for (int i = 2; i <= 200000; i++) {
		ll p2 = fastPow(2, i / 2);
		mul[i] = F[i] * fastPow(p2, mod - 2) % mod * fastPow(F[i / 2], mod - 2) % mod;
	}

	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) { solve(); }
	return 0;
}
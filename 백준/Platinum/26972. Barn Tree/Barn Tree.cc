#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

ll gcd(ll a, ll b) {
	if (a > b) swap(a, b);
	if (a == 0) return b;
	return gcd(b % a, a);
}

ll fastPow(ll b, ll ex, ll m) {
	ll res = 1;
	while (ex) {
		if (ex & 1) res = res * b % m;
		b = b * b % m;
		ex >>= 1;
	}
	return res;
}

vector<int> adj[200001];
vector<pair<ll, ll>> adj2[200001];
bool v[200001];
int topo[200001];

void solve() {

	int n;
	cin >> n;

	ll tot = 0;
	vector<ll> A(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		tot += A[i];
	}
	tot /= n;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);

		topo[a]++, topo[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) if (topo[i] == 1) q.push(i);
	vector<tuple<ll, ll, ll>> move;

	while (!q.empty()) {

		int a = q.front();
		q.pop();
		v[a] = 1;

		for (auto i : adj[a]) {
			if (!v[i]) {
				topo[i]--;

				ll nd = tot - A[a];
				if (nd >= 0) {
					if (nd > 0) move.push_back({ i, a, nd });
					A[i] -= nd;
				}
				else {
					move.push_back({ a, i, -nd });
					A[i] -= nd;
				}

				if (topo[i] == 1) q.push(i);
			}
		}
	}

	memset(topo, 0, sizeof(topo));

	for (auto i : move) {
		ll a, b, c;
		tie(a, b, c) = i;
		//cout << a << ' ' << b << ' ' << c << '\n';

		adj2[a].push_back({ b, c });
		topo[b]++;
	}

	for (int i = 1; i <= n; i++) {
		if (topo[i] == 0) q.push(i);
	}

	cout << move.size() << '\n';
	while (!q.empty()) {
		int a = q.front();
		q.pop();

		for (auto i : adj2[a]) {
			ll x, y;
			tie(x, y) = i;

			cout << a << ' ' << x << ' ' << y << '\n';
			topo[x]--;
			if (topo[x] == 0) q.push(x);
		}
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}
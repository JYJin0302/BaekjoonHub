#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#define INF 100000000
#define pb push_back
#define all(x) (x).begin(),(x).end()

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };


void solve() {

	int n, m;
	cin >> n >> m;

	vector<ll> cost(n + m + 1);
	map<string, int> si;
	map<int, string> is;
	for (int i = 1; i <= n; i++) {
		string s;
		ll x;

		cin >> s >> x;
		cost[i] = x;
		si[s] = i;
		is[i] = s;
	}

	vector<string> inp;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;

		inp.push_back(s);

		string t;
		int idx = 0;
		while (s[idx] != '=') {
			t += s[idx];
			idx++;
		}

		if (si[t] == 0) si[t] = n + 1 + i;
		is[n + 1 + i] = t;
	}

	
	vector<ll> topo(n + m + 1);
	vector<vector<pair<ll, ll>>> adj(n+m+1);  // 재료 -> idx

	for (int i = 0; i < m; i++) {
		
		string s = inp[i], t;
		ll idx = 0;
		while (s[idx] != '=') {
			t += s[idx];
			idx++;
		}
		idx++;
		
		while (idx < s.size()) {
			ll k = s[idx++] - '0';
			string temp;
			while (idx < s.size() && s[idx] != '+') {
				temp += s[idx];
				idx++;
			}
			idx++;
			ll ti = si[temp];
			adj[ti].push_back({ n + 1 + i, k });
			topo[n + 1 + i]++;
		}
	}

	priority_queue<tuple<ll, ll>> pq;
	for (int i = 1; i <= n; i++) {
		pq.push({ -cost[i], i });
	}

	vector<bool> found(n + m + 1);
	while (!pq.empty()) {
		ll a, b;
		tie(a, b) = pq.top();
		pq.pop();
		if (found[b]) continue;
		found[b] = 1;
		a = -min(-a, (ll)1000000001);
		if (is[b] == "LOVE") {
			a *= -1;
			
			cout << a;
			return;
		}

		for (auto i : adj[b]) {
			
			ll x, y;
			tie(x, y) = i;

			cost[x] += y * -a;
			cost[x] = min(cost[x], (ll)1000000001);
			topo[x]--;

			if (topo[x] == 0) {
				ll tx = si[is[x]];
				pq.push({ -cost[x], tx });
			}
		}
	}

	cout << -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T = 1;
	//cin >> T;

	while (T--) {
		solve();
	}
}
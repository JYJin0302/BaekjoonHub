#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e17;
vector<pair<ll, ll>> adj[5001];
vector<pair<ll, ll>> rev[5001];

ll distF[5001], distT[5001];
ll dS[5001];

vector<ll> dp, tmp;

ll cost(ll l, ll r) {
	return (dS[r] - dS[l - 1]) * (r - l);
}

void solve(int l, int r, int sl, int sr) {
	if (l > r) return;

	int m = (l + r) >> 1;

	ll ansV = INF, ansi = -1;
	for (int i = sl; i <= min(sr, m); i++) {
		ll tans = dp[i - 1] + cost(i, m);
		if (tans < ansV) {
			ansV = tans;
			ansi = i;
		}
	}

	tmp[m] = ansV;
	solve(l, m - 1, sl, ansi);
	solve(m + 1, r, ansi, sr);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, b, s, r;
	cin >> n >> b >> s >> r;
	// 1-b 지사, b+1 본부
	memset(distF, -1, sizeof(distF));
	memset(distT, -1, sizeof(distT));

	for (int i = 0; i < r; i++) {
		ll a, b, c;
		cin >> a >> b >> c;

		adj[a].push_back({ b, c });
		rev[b].push_back({ a, c });
	}

	priority_queue<pair<ll, ll>> pq;
	pq.push({0, b+1 });
	while (!pq.empty()) {
		ll x, y;
		tie(x, y) = pq.top();
		pq.pop();

		if (distT[y] != -1) continue;
		distT[y] = -x;

		for (auto i : adj[y]) {
			ll nx, ny;
			tie(nx, ny) = i;

			if (distT[nx] == -1) {
				pq.push({ x - ny, nx });
			}
		}
	}
	pq.push({ 0, b+1 });
	while (!pq.empty()) {
		ll x, y;
		tie(x, y) = pq.top();
		pq.pop();

		if (distF[y] != -1) continue;
		distF[y] = -x;

		for (auto i : rev[y]) {
			ll nx, ny;
			tie(nx, ny) = i;

			if (distF[nx] == -1) {
				pq.push({ x - ny, nx });
			}
		}
	}

    for (int i = 1; i <= b; i++) {
        dS[i] = distF[i] + distT[i];
    }
    sort(dS, dS + b+1);
    for (int i = 1; i <= b; i++) dS[i] += dS[i - 1];

	dp = vector<ll>(b + 1);
	tmp = vector <ll>(b + 1);
	
	for (int i = 1; i <= b; i++) dp[i] = cost(1, i);

	for (int i = 2; i <= s; i++) {
		solve(1, b, 1, b);
		swap(tmp, dp);
	}
	cout << dp[b];
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> dp, tmp;
ll A[100001], B[100001];
ll ans = 0;
int n, d;

void solve(int l, int r, int sl, int sr) {
	if (l > r) return;

	int m = (l + r) >> 1;

	int tl = max(sl, m - d);

	ll ansV = -1, ansi = -1;

	for (int i = tl; i <= min(m, sr); i++) {
		ll tans = A[m] * (m - i) + B[i];
		if (tans > ansV) {
			ansV = tans;
			ansi = i;
		}
	}
	ans = max(ans, ansV);

	solve(l, m - 1, sl, ansi);
	solve(m + 1, r, ansi, sr);
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> d;

	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) cin >> B[i];

	solve(1, n, 1, n);

	cout << ans;
}
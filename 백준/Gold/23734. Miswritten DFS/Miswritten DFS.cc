#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int l[100001];
int r[100001];
ll cnt[100001];

void dfs(int v) {
	cnt[v] = 1;
	if (l[v] != 0) dfs(l[v]);
	if (r[v] != 0) dfs(r[v]);

	cnt[v] += cnt[l[v]] * 2 + cnt[r[v]];
	cnt[v] = min(cnt[v], (ll)1e18);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];

	dfs(1);

	//for (int i = 1; i <= n; i++) cout << cnt[i] << ' ';

	ll ans = 1, tot = 1;
	while (tot < k) {
		int lx = l[ans], rx = r[ans];

		if (lx != 0) {
			if (tot + 2 * cnt[lx] < k) {
				ans = rx;
				tot += 2 * cnt[lx] + 1;
			}
			else {
				ans = lx;
				tot++;
				if (tot + cnt[lx] <= k) tot += cnt[lx];
			}
		}
		else {
			ans = rx;
			tot++;
		}
	}

	cout << ans;
}
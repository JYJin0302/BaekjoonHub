#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int k, m;
int fastPow(int b, int ex) {
	int res = 1;
	while (ex) {
		if (ex & 1) res = res * b;
		b *= b;
		ex >>= 1;
	}
	return res;
}
int ans[10000010], adj_idx[10000010];
int ansIdx = 0;
void dfs(int v) {
	while(adj_idx[v] < k){
		int nx = v % fastPow(k, m - 2);
		nx = nx * k + adj_idx[v];
		adj_idx[v]++;
		dfs(nx);
	}
	ans[ansIdx++] = v;
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> k >> m;
	// k진수 m자리 수

	if (m == 1) {
		for (int i = 0; i < k; i++) cout << i << ' ';
		return 0;
	}

	dfs(0);

	for (int i = ansIdx - 2; i >= 0; i--) cout << ans[i] % k << ' ';

}
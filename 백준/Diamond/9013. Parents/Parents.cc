#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second

int MAX_N = 100000;

int n, k;
int val[100001];
vector<int> adj[100001];
int dp[100001][101][2];
// dp[x] : x의 서브트리에서 k개 선택시 최대값, 0:x미포함 1:x포함
int cnt[100001];

void dfs(int v, int pv = -1) {
	dp[v][0][0] = 0;
	dp[v][0][1] = 0;
	cnt[v] = 0;

	for (auto i : adj[v]) if (i != pv) {
		dfs(i, v);

		vector<pair<int, int>> tmp(k + 1, { -1e9, -1e9 });
		for (int j = 0; j <= min(k, cnt[v]); j++) {
			for (int w = 0; w <= min(k, cnt[i]); w++) {
				if (j + w <= k) {
					tmp[j + w].x = max(tmp[j + w].x, dp[v][j][0] + max(dp[i][w][1], dp[i][w][0]));
					tmp[j + w].y = max(tmp[j + w].y, dp[v][j][1] + dp[i][w][0]);
				}
				
				//tmp[j].x = max(tmp[j].x, dp[v][w][0] + max(dp[i][j - w][1], dp[i][j - w][0]));
				//tmp[j].y = max(tmp[j].y, dp[v][w][1] + dp[i][j - w][0]);
			}
		}
		cnt[v] += cnt[i];

		for (int j = 0; j <= min(cnt[v],k); j++) {
			dp[v][j][0] = max(dp[v][j][0], tmp[j].x);
			dp[v][j][1] = max(dp[v][j][1], tmp[j].y);
		}
	}

	cnt[v]++;
	for (int j = min(cnt[v], k); j > 0; j--) {
		dp[v][j][1] = dp[v][j - 1][1] + val[v];
	}
	dp[v][0][1] = -1e9;
	/*
	cout << "DP: " << v << '\n';
	for (int i = 0; i <= k; i++) {
		int vx = dp[v][i][0];
		if (vx < -1e5) cout << "X ";
		else cout << vx << ' ';
	}
	cout << '\n';
	for (int i = 0; i <= k; i++) {
		int vx = dp[v][i][1];
		if (vx < -1e5) cout << "X ";
		else cout << vx << ' ';
	}
	cout << '\n';
	*/
}

void solve() {

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j][0] = -1e9;
			dp[i][j][1] = -1e9;
		}
		dp[i][0][0] = 0;
	}

	for (int i = 0; i < n; i++) {
		cin >> val[i];
		adj[i].clear();
	}

	for (int i = 0; i < n - 1; i++) {
		int a;
		cin >> a;
		adj[i + 1].push_back(a);
		adj[a].push_back(i + 1);
	}

	dfs(0);

	int ans = -1e9;
	for (int i = 1; i <= k; i++)ans = max({ ans,dp[0][i][0], dp[0][i][1] });
	cout << ans << '\n';

}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
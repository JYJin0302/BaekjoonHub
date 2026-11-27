#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

int n, m;
vector<vector<int>> adj, dp;

void dfs(int v, int pv = -1) {

	dp[v][1] = 0;

	for (int i : adj[v]) if (i != pv) {
		dfs(i, v);
		
		for (int j = n; j >= 1; j--) {
			int tt = INF;
			for (int k = 1; k < j ; k++) {
				tt = min(tt, dp[v][j - k] + dp[i][k]);
			}
			dp[v][j] = min(dp[v][j] + 1, tt);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;

	adj = vector<vector<int>>(n + 1);
    dp = vector<vector<int>>(n+1, vector<int>(n+1, INF));
    
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1);
    
    int ans = INF;
    for (int i = 1; i <= n; i++){
        ans = min(ans, dp[i][m] + (i > 1));
    }
    
    cout << ans;
}
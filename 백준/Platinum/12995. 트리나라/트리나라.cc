#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define INF 100000000
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define vvl vector<vl>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FOR(i, a) for (int i = 0; i < (a); i++)

int n, k, mod = 1e9+7;
vvl adj, dp;  // dp: 노드, 자기 노드를 포함한 개수 -> 경우의 수

void dfs(int v, int pv = -1) {

	for(int i : adj[v]) if (i != pv) {
		
		dfs(i, v);
		
		vl temp(k+1);
		temp = dp[v];

		for (int j = 1; j <= k; j++) {
			
			for (int kk = 1; kk <= k; kk++) {
				
				if (j + kk > k) continue;

				temp[j + kk] += dp[v][j] * dp[i][kk];
				temp[j + kk] %= mod;
			}
		}

		dp[v] = temp;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;

	adj = vvl(n + 1);
	dp = vvl(n + 1, vl(k + 1));

	for (int i = 0; i< n-1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	FOR(i, n) {
		dp[i + 1][1] = 1;
	}

	dfs(1);

	int ans = 0;
	FOR(j, n) {
		ans += dp[j + 1][k];
		ans %= mod;
	}
	cout << ans;
}
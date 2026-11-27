#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
int n;
int dp[1 << 16][16];  // 방문한 곳, 현재위치 -> 다 돌기까지 필요한 최소 비용
vector<vector<int>> path;

int findpath(int u, int p) {
	if (dp[u][p] != -1) return dp[u][p];

	if (u == (1 << n) - 1) return dp[u][p] = path[p][0];
	int temp = INF;
	for (int i = 1; i < n; i++) {
		if ((u & (1 << i)) == 0) {
			temp = min(temp, path[p][i] + findpath(u + (1 << i), i));
		}
	}
	return dp[u][p] = temp;
}

int main() {

	
	cin >> n;

	path = vector<vector<int>>(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> path[i][j];
			if (path[i][j] == 0) path[i][j] = INF;
		}
	}
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = -1;
		}
	}

	int ans = INF;
	for (int i = 1; i < n; i++) {
		ans = min(ans, findpath(1 + (1<<i), i) + path[0][i]);
	}

	cout << ans;
}
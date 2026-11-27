#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int MAX_N = 5000;

bool isB[5001];
vector<int> adj[5001];

int dpMin[5010][5010];
int dpMax[5010][5010];

// dp[a][b] : v를 포함한 v의 서브트리 에서 b개의 검은돌을 가지는 최소, 최대 노드 개수

int ans[5010][5010];
int cnt[5001];

void dfs(int v, int pv = -1) {
	cnt[v] = 0;

	for (auto i : adj[v]) if (i != pv) {
		dfs(i, v);

		vector<int> tmpM(MAX_N+1, -1e6), tmpm(MAX_N+1, 1e6);

		for (int j = 0; j <= cnt[v]; j++) {
			for (int k = 0; k <= cnt[i]; k++) {
				tmpM[j+k] = max(tmpM[j+k], dpMax[v][j]+dpMax[i][k]);
				tmpm[j+k] = min(tmpm[j+k], dpMin[v][j] + dpMin[i][k]);
			}
		}
		cnt[v] += cnt[i];

		for (int j = 0; j <= cnt[v]; j++) {
			dpMax[v][j] = max(dpMax[v][j], tmpM[j]);
			dpMin[v][j] = min(dpMin[v][j], tmpm[j]);
		}
	}
	for(int i = 0; i <= cnt[v]; i++) {
		dpMax[v][i]++, dpMin[v][i]++;
	}
	if (isB[v]) {
		cnt[v]++;
		for (int i = cnt[v]; i > 0; i--) {
			dpMax[v][i] = dpMax[v][i - 1];
			dpMin[v][i] = dpMin[v][i - 1];
		}
		dpMax[v][0] = 0;
		dpMin[v][0] = 0;
	}
	dpMin[v][0] = 0;

	/*
	cout << "Dp: " << v << '\n';
	for (int i = 0; i <= cnt[v]; i++) {
		int val = dpMin[v][i];
		if (abs(val) > MAX_N) cout << "X ";
		else cout << dpMin[v][i] << ' ';
	}
	cout << '\n';
	for (int i = 0; i <= cnt[v]; i++) {
		int val = dpMax[v][i];
		if (abs(val)> MAX_N) cout << "X ";
		else cout << dpMax[v][i] << ' ';
	}
	cout << '\n';
	*/
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, b;
	cin >> n >> b;

	for (int i = 0; i < b; i++) {
		int x;
		cin >> x;
		isB[x] = 1;
	}

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= MAX_N; i++) {
		for (int j = 0; j <= MAX_N; j++) {
			dpMin[i][j] = 1e6;
			dpMax[i][j] = -1e6;
		}

		dpMin[i][0] = 0;
		dpMax[i][0] = 0;
	}
	dfs(1);

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			int v = dpMin[i][j];
			if (abs(v) < MAX_N) {
				ans[j][v]++;
				ans[j][dpMax[i][j] + 1]--;
			}
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans[i][j] += ans[i][j - 1];
		}
	}

	int q;
	cin >> q;

	int res = 0;
	while (q--) {
		int a, b;
		cin >> a >> b;

		if (ans[b][a] > 0) res++;
	}

	cout << res;
}
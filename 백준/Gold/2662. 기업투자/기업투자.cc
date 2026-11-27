#include <bits/stdc++.h>
using namespace std;

int dp[21][301][2];  // dp[...][...][1] = [...][...]을 구하는데 쓰인 돈
int base[21][301];
int n, m, a;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		for (int j = 1; j <= m; j++) {
			cin >> base[j][a];
		}
	}

	for (int i = 1; i <= m; i++) {

		for (int j = 1; j <= n; j++) {
			
			for (int k = 0; k <= j; k++) {
				if (dp[i][j][0] < dp[i - 1][j - k][0] + base[i][k]) {
					dp[i][j][0] = dp[i - 1][j - k][0] + base[i][k];
					dp[i][j][1] = k;
				}
			}
		}
	}
	int ans = dp[m][n][0];
	int ind = n;
	vector<int> ansv;
	for (int i = m; i >= 1; i--) {
		ansv.push_back(dp[i][ind][1]);
		ind -= dp[i][ind][1];
	}

	cout << ans << '\n';
	for (auto i = ansv.rbegin(); i != ansv.rend(); i++) {
		cout << *i << ' ';
	}

}
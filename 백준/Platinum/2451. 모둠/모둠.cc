#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int A[3001][3001];
int B[3001][3001];
// B[i][j] : i부터 j까지의 그룹 내에서 서로 모르는 쌍의 개수
int C[3001][3001];
// C[i][j] : 그룹[i,j], 그룹[j+1, n] 사이의 아는 쌍의 개수
int dp[3001], from[3001];

void setDp() {

	for (int i = 1; i <= n; i++) {
		dp[i] = 1e7;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			A[i][j] += A[i][j - 1];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			B[i][j] = B[i][j - 1] + j - i - (A[j][j] - A[j][i - 1]);
			B[j][i] = B[i][j];
		}
	}

	for (int i = n; i >= 1; i--) {
		C[i][i] = A[i][n] - A[i][i];
		for (int j = i-1; j >= 1; j--) {
			C[j][i] = C[j+1][i] + A[j][n] - A[j][i];
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		while (x != 0) {
			A[i][x] = 1;
			cin >> x;
		}
	}

	setDp();

	dp[0] = 0;

	for (int i = 1; i <= n; i++) {

		for (int j = 0; j < i; j++) {
			if (dp[i] > dp[j] + B[j + 1][i] + C[j + 1][i]) {
				dp[i] = dp[j] + B[j + 1][i] + C[j + 1][i];
				from[i] = j;
			}
		}
	}

	cout << dp[n] << '\n';
	vector<int> ans;
	int ix = n;
	while (ix) {
		int nx = from[ix];
		ans.push_back(ix - nx);
		ix = nx;
	}

	reverse(ans.begin(), ans.end());

	cout << ans.size() << ' ';
	for (auto i : ans) cout << i << ' ';

}
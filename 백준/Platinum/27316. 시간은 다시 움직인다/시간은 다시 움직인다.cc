#include <bits/stdc++.h>
using namespace std;
using ll = long long;


const int MAX_N = 200501;
const int MAX_M = 450;

bool dp[MAX_N+1][MAX_M+1];
// dp[a][b] : b번 능력 사용 후 a까지 도달 가능성

void solve() {

	int n;
	cin >> n;

	int mx = 0;
	vector<int> A(MAX_N+1), sA(MAX_N+1);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		x++;
		mx = max(mx, x);
		A[x] = 1;
	}
	for (int i = 1; i <= MAX_N; i++) {
		sA[i] = sA[i - 1] + A[i];
	}
	
	dp[0][0] = 1;
	for (int i = 1; i <= MAX_N; i++) {
		if (sA[i] == 0) dp[i][0] = 1;
		for (int j = 1; j*j <= (i+1); j++) {
			if (A[i] == 0) {
				dp[i][j] |= dp[i - 1][j];
			}

			if (i - 2*j >= 0 && sA[i] - sA[i-j] == 0) dp[i][j] |= dp[i - 2 * j][j - 1];
		}
	}


	bool ok = 0;
	for (int i = 0; i <= MAX_M; i++) {
		if (dp[MAX_N][i]) ok = 1;
	}

	if (ok) cout << "YES";
	else cout << "NO";

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}

}
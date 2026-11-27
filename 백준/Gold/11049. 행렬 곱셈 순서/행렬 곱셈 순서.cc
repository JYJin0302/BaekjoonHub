#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> A;
int dp[500][500];  // dp[i][j] -> i부터 j까지 곱했을 때의 최소횟수

int solve(int l, int r) {

	if (dp[l][r] != 0) return dp[l][r];

	if (r == l) return 0;
	if (r - l == 1) {
		return dp[l][r] = A[l].first * A[l].second * A[r].second;
	}

	int temp = min(A[l].first * A[l].second * A[r].second + solve(l+1, r), A[l].first * A[r].first * A[r].second + solve(l, r-1));
	for (int t = l+2; t < r; t++) {
		temp = min(temp, A[l].first * A[t].first * A[r].second + solve(l, t - 1) + solve(t, r));
	}

	return dp[l][r] = temp;
}



int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	int n;
	cin >> n;
	A = vector<pair<int, int>> (n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		A[i] = { a, b };
	}
    

	cout << solve(0, n - 1);

}
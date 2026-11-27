#include <bits/stdc++.h>
using namespace std;


int score[1000][1000];  // 최고 점수
int point[1000][1000];  // 선택한 방향 -> -1: 왼쪽, 1: 오른쪽
vector<int> A;

int solve(int l, int r) {

	if (l > r) return 0;

	if (score[l][r] != 0) {
		return score[l][r];
	}

	if (l == r) {
		point[l][r] = -1;
		return score[l][r] = A[l];
	}

	if (r - l == 1) {
		if (A[l] > A[r]) point[l][r] = -1;
		else point[l][r] = 1;
		return score[l][r] = max(A[l], A[r]);
	}

	int tt1 = -1, tt2 = -1;
	solve(l + 1, r);
	if (point[l+1][r] == -1) {
		tt1 = solve(l + 2, r) + A[l];
	}
	else {
		tt1 = solve(l + 1, r - 1) + A[l];
	}
	solve(l, r - 1);
	if (point[l][r-1] == -1) {
		tt2 = solve(l + 1, r - 1) + A[r];
	}
	else tt2 = solve(l, r - 2) + A[r];

	if (tt1 < tt2) {
		point[l][r] = 1;
		return score[l][r] = tt2;
	}
	else {
		point[l][r] = -1;
		return score[l][r] = tt1;
	}

}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		memset(score, 0, sizeof(score));
		A = vector<int>(n);
		for (auto& i : A) cin >> i;

		for (int i = 0; i < n; i++) score[i][i] = A[i];
		solve(0, n - 1);


		cout << score[0][n - 1] << '\n';
	}
}
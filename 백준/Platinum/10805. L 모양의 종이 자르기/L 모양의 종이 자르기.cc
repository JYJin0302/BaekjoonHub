#include <bits/stdc++.h>
using namespace std;


int dp[55][55][55][55];

int solve(int h1, int w1, int h2, int w2) {
	if (h1 > w1) {
		swap(h1, w1);
		swap(h2, w2);
	}

	if (h2 == 0 || w2 == 0) {
		h2 = w2 = 0;
	}

	if (dp[h1][w1][h2][w2] != 0) return dp[h1][w1][h2][w2];
	if (h1 == w1 && h2 + w2 == 0) return dp[h1][w1][h2][w2] = 1;

	// cut row
	int res = h1 * w1 - h2 * w2;
	for (int i = 1; i < h1 - h2; i++) {
		res = min(res, solve(i, w1, 0, 0) + solve(h1 - i, w1, h2, w2));
	}
	for (int i = h1 - h2; i < h1; i++) {
		res = min(res, solve(h1 - i, w1 - w2, 0, 0) + solve(i, w1, i - (h1 - h2), w2));
	}

	// cut col
	for (int i = 1; i < w1 - w2; i++) {
		res = min(res, solve(h1, i, 0, 0) + solve(h1, w1 - i, h2, w2));
	}
	for (int i = w1 - w2; i < w1; i++) {
		res = min(res, solve(h1 - h2, w1 - i, 0, 0) + solve(h1, i, h2, i - (w1 - w2)));
	}

	
	return dp[h1][w1][h2][w2] = res;
}

int main() {

	int h1, w1, h2, w2;
	cin >> h1 >> w1 >> h2 >> w2;
	cout << solve(h1, w1, h2, w2);

}
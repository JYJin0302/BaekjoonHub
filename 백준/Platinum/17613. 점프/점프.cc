#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[33];
map<pair<int, int>, int> mp;

int ans = 0;

int solve(int x, int y) {

	if (x > y) return 0;
	if (mp[{x, y}] != 0) return mp[{x, y}];
	//cout << "GO: " << x << ' ' << y << '\n';


	int ty = log2(y);
	if (pow(2, ty+1) == y + 1) {
		return mp[{x, y}] = max(ty + 1, solve(x, y - 1));
	}

	if (pow(2, ty) > x) {
		return mp[{x, y}] = max(solve(x, pow(2, ty) - 1), solve(pow(2, ty), y));
	}

	if (x == pow(2, ty) && y == pow(2, ty + 1) - 1) {
		return dp[ty+1];
	}

	int tx = log2(x);
	return mp[{x, y}] = solve(x - pow(2, tx) + 1, y - pow(2, tx) + 1) + tx;
	
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	dp[1] = 1;
	for (int i = 2; i <= 32; i++) {
		dp[i] = dp[i - 1] + i - 1;
	}

	int t;
	cin >> t;
	while (t--) {

		int x, y;
		cin >> x >> y;

		ans = solve(x, y);

		cout << ans << '\n';
	}
}
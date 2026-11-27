#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#define INF 100000000
#define pb push_back
#define all(x) (x).begin(),(x).end()

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

ll n, k;
ll dp[1 << 16][100];  // dp[i][j]: i을 썼을 때 나머지가 j 인 경우의 수
vector<int> remain[16][100];

vector<string> A;
void setremain() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {

			int tj = j;
			for (char c : A[i]) {
				tj = tj * 10 + (c - '0');
				tj %= k;
			}

			remain[i][tj].push_back(j);
		}
	}
}

ll solve_dp(int x, int y) {

	if (dp[x][y] != -1) return dp[x][y];

	ll cnt = 0;
	for (int i = 0; i < n; i++) {
		if ((1 << i) & x) {
			ll nx = x ^ (1 << i);

			for (int j : remain[i][y]) {
				cnt += solve_dp(nx, j);
			}
		}
	}

	return dp[x][y] = cnt;
}

ll GCD(ll x, ll y) {
	if (x == 0) return y;
	return GCD(y % x, x);
}

void solve() {

	cin >> n;
	A = vector<string>(n);
	for (auto& i : A) cin >> i;

	cin >> k;

	memset(dp, -1, sizeof(dp));
	dp[0][0] = 1;
	setremain();

	ll num = solve_dp((1 << n) - 1, 0);

	ll den = 1;
	for (int i = 1; i <= n; i++) den *= i;

	ll gcd = GCD(num, den);

	cout << num / gcd << '/' << den / gcd;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T = 1;
	//cin >> T;

	while (T--) {
		solve();
	}
}
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#define INF 100000000
#define pb push_back
#define all(x) (x).begin(),(x).end()

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

ll n, mod = 1e9+7;
vector<vector<ll>> mat_mul(vector<vector<ll>> a, vector<vector<ll>> b) {
	vector<vector<ll>> ret(3, vector<ll>(3));

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				ret[i][j] += a[i][k] * b[k][j] % mod;
				ret[i][j] %= mod;
			}
		}
	}

	return ret;
}

void solve() {

	
	cin >> n;

	vector<vector<ll>> mat(3, vector<ll>(3, 1));
	mat[1][1] = 0, mat[2][2] = 0;

	ll size = 1;
	int cnt = 1;
	while (size <= n) size *= 2, cnt++;
	cnt--;

	vector<vector<vector<ll>>> dp(cnt);
	dp[0] = mat;
	for (int i = 1; i < cnt; i++) {
		dp[i] = mat_mul(dp[i - 1], dp[i - 1]);
	}

	for (ll i = 0; i < cnt; i++) {
		if ((1ll << i) & n) mat = mat_mul(mat, dp[i]);
	}

	cout << mat[0][0];
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
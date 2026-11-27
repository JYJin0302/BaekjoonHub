#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int n;
int A[1010];
int tmp[1010];
vector<pair<int, int>> ans;
void oper(int l, int r, bool simul = 0) {
	if (!simul) ans.push_back(mp(l, r));

	int pos = 1;
	for (int j = 1; j <= n; j++) {
		if (pos == l) pos += 3;
		if (j == r) {
			tmp[j] = A[l];
			tmp[j + 1] = A[l + 1];
			tmp[j + 2] = A[l + 2];
			j += 3;
		}
		tmp[j] = A[pos++];
	}
	swap(A, tmp);

	// for (int i = 1; i <= n; i++) cout << A[i] << ' ';
	// cout << '\n';
}

int dp[101010];
pair<int, int> from[101010];

vector<int> goOper(vector<int> v, int l, int r) {
	vector<int> res(5), tmp(10);
	int pos = 0;
	for (int j = 0; j < 5; j++) {
		if (pos == l) pos += 3;
		if (j == r) {
			tmp[j] = v[l];
			tmp[j + 1] = v[l + 1];
			tmp[j + 2] = v[l + 2];
			j += 3;
		}
		tmp[j] = v[pos++];
	}

	for (int j = 0; j < 5; j++) res[j] = tmp[j];
	return res;
}

void setup() {
	vector<int> v = {1, 2, 3, 4, 5};
	memset(dp, -1, sizeof dp);
	dp[12345] = 0;

	queue<vector<int>> q;
	q.push(v);
	while (!q.empty()) {
		auto a = q.front();
		q.pop();

		int ix = 0;
		for (int j = 0; j < 5; j++) ix = ix * 10 + a[j];

		for (int l = 0; l < 3; l++) {
			for (int r = 0; r < 3; r++) {
				if (l != r) {
					vector<int> tst = goOper(a, l, r);
					int nx = 0;
					for (int f = 0; f < 5; f++) nx = nx * 10 + tst[f];

					if (dp[nx] == -1) {
						dp[nx] = ix;
						from[nx] = mp(r, l);
						q.push(tst);
					}
				}
			}
		}
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];

	setup();

	int tar = n;
	for (int j = n; j >= 6; j--) {
		int pos = tar;
		while (A[pos] != j) pos--;
		while (pos <= 2) {
			oper(2, 1);
			for (int i = 1; i <= 5; i++)
				if (A[i] == j) pos = i;
		}
		if (pos != j) oper(pos - 2, j - 2);
	}

	// solve 5
	int ix = 0;
	for (int i = 1; i <= 5; i++) ix = ix * 10 + A[i];
	while (ix != 12345) {
		// cout << "Go ; " << ix << " => " << from[ix].x << ' ' << from[ix].y << '\n';
		if (from[ix].x == from[ix].y) {
			cout << "WTf\n";
			return;
		}
		oper(from[ix].x + 1, from[ix].y + 1);
		ix = dp[ix];
	}

	cout << (int)ans.size() << '\n';
	for (auto [a, b] : ans) cout << a << ' ' << b << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
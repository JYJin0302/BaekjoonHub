#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int n;
ld dp[1 << 16];
int A[20];

ld getDp(int s) {
	if (dp[s] > -0.5) return dp[s];
	ld res = 0;
	vector<int> idx;
	for (int i = 0; i < n; i++) {
		if (s & (1 << i)) idx.push_back(i);
	}

	int tn = (int)idx.size();
	for (int a = 0; a < tn; a++) {
		for (int b = a + 1; b < tn; b++) {
			for (int c = b + 1; c < tn; c++) {
				int ns = s ^ (1 << idx[a]) ^ (1 << idx[b]) ^ (1 << idx[c]);
				if (A[idx[a]] + A[idx[b]] > A[idx[c]]) {
					ld v1 = A[idx[a]];
					ld v2 = A[idx[b]];
					ld v3 = A[idx[c]];
					ld p = (v1 + v2 + v3) / 2;
					res = max(res, getDp(ns) + sqrtl(p * (p - v1) * (p - v2) * (p - v3)));
				}
			}
		}
	}
	return dp[s] = res;
}

void solve() {
	cin >> n;

	for (int i = 0; i < n; i++) cin >> A[i];
	sort(A, A + n);

	for(int i =0; i < (1 << n); i++) dp[i] = -1;
	ld ans = 0;
	for (int i = 0; i < (1 << n); i++) ans = max(ans, getDp(i));
	cout << setprecision(20);
	cout << ans << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	return 0;
}
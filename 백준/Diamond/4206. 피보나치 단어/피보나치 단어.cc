#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

string B[101];
int len[101];
ll dp[101][101];
ll dp2[101];

string s;
bool L[30][601010];
bool R[30][601010];

void setup(int ix) {
	//if (len[ix] < (int)s.size()) return;

	int n = len[ix];
	for (int j = 0; j <= n; j++) {
		L[ix][j] = 0;
		R[ix][j] = 0;
	}

	string tar = s;
	for (auto f : B[ix]) tar += f;
	int tn = (int)tar.size();

	vector<int> z(tn);
	int l = 0, r = 0;
	for (int i = 1; i < tn; i++) {
		if (i <= r) z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < tn && tar[z[i]] == tar[i + z[i]]) z[i]++;
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
		if (i + z[i] == tn && z[i] <= n) L[ix][z[i]] = 1;
	}

	// cout << tar << '\n';
	// cout << "setup " << ix << ' ' << "L : ";
	// for (auto f : z) cout << f << ' ';
	// cout << '\n';

	tar = s;
	reverse(all(tar));
	for (auto j = B[ix].rbegin(); j != B[ix].rend(); j++) tar += *j;
	z = vector<int> (tn);
	l = 0, r = 0;
	for (int i = 1; i < tn; i++) {
		if (i <= r) z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < tn && tar[z[i]] == tar[i + z[i]]) z[i]++;
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
		if (i + z[i] == tn && z[i] <= n) R[ix][z[i]] = 1;
	}

	// cout << tar << '\n';
	// cout << "setup " << ix << ' ' << "R : ";
	// for (auto f : z) cout << f << ' ';
	// cout << '\n';
}

ll getDp2(int l, int r) {
	if (dp[l][r] != -1) return dp[l][r];
	if (len[l] + len[r] < (int)s.size()) return dp[l][r] = 0;
	if (l >= 2 && len[l - 2] >= (int)s.size()) return dp[l][r] = getDp2(l - 2, r);
	if (r && len[r - 1] >= (int)s.size()) return dp[l][r] = getDp2(l, r - 1);

	ll res = 0;
	for (int i = 1; i <= min(len[l], (int)s.size() - 1); i++) {
		if (L[l][i] && (int)s.size() - i <= len[r] && R[r][(int)s.size() - i]) res++;
	}
	//cout << B[l] << ' '<< B[r] << " => " << res << '\n';
	return dp[l][r] = res;
}

ll getDp(int n) {
	if (dp2[n] != -1) return dp2[n];
	if (len[n] < (int)s.size()) return dp2[n] = 0;
	if (len[n] == (int)s.size()) {
		for (int j = 0; j < len[n]; j++) {
			if (s[j] != B[n][j]) return dp2[n] = 0;
		}
		return dp2[n] = 1;
	}
	return dp2[n] = getDp(n - 1) + getDp(n - 2) + getDp2(n - 1, n - 2);
}

void solve(int n) {
	cin >> s;
	for (int i = 0; i <= n; i++) {
		dp2[i] = -1;
		for (int j = 0; j <= n; j++) dp[i][j] = -1;
	}

	for (int j = 0; j <= min(n, 26); j++) setup(j);
	ll ans = getDp(n);
	cout << ans << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	B[0] = "0";
	B[1] = "1";
	len[0] = len[1] = 1;
	for (int i = 2; i <= 26; i++) {
		B[i] = B[i - 1] + B[i - 2];
		len[i] = (int)B[i].size();
		// if ((int)B[i].size() > 100000) break;
	}
	for (int i = 27; i <= 100; i++) len[i] = len[26];

	int t = 1;
	// cin >> t;
	int n;
	for (int i = 1; cin >> n; i++) {
		cout << "Case " << i << ": ";
		solve(n);
	}
	return 0;
}
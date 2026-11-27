#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve() {
	string s;
	cin >> s;

	int n = (int)s.size();

	string tar = "KSA";
	int err = -1;
	for (int i = 0; i < n; i++) {
		if (s[i] != tar[i % 3]) { err = i; }
	}
	if (err == -1) {
		cout << 0 << '\n';
		return;
	}

	int ans = 0;
	int tt = err % 3;
	int curLen = n - err - 1;
	while (err >= 0) {
		if (s[err] == tar[tt]) {
			curLen++;
			tt = (tt + 2) % 3;
			err--;
			continue;
		}

		if (err >= 2 && s[err - 2] == tar[tt]) {
			err -= 3;
			tt = (tt + 2) % 3;
			ans++;
			curLen++;
			continue;
		}

		if (err == 0) break;
		err -= 2;
		ans++;
	}

	if (err == 0) {
		ans += 2;
		curLen++;
	}

	int nd = n - curLen;
	assert(nd % 2 == 0);
	ans += nd / 2 * 3;
	cout << ans << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) { solve(); }
	return 0;
}
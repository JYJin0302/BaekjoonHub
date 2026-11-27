#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
typedef long long ll;

void solve() {
	int a, b, c, d, e, f;
	cin >> a >> b >> e >> f >> c >> d;

	int ans = 0;
	int val1 = a + 2 * b;
	int val2 = e + 2 * f;

	int val = min(val1, val2);

	if (val1 > val2) {
		if (a == 0 && (val1 - val2) & 1) val--;
		ans += val * 2;
	} else if (val1 < val2) {
		if (e == 0 && (val2 - val1) & 1) val--;
		ans += val * 2;
	} else {
		ans += val * 2;
	}

	if (d) {
		if (ans) { ans += d * 2; }
	}
	ans += c * 2;
	cout << ans << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

ll pw10[20];
vector<ll> val;

ll tot = 0;
ll D;
int track[20];
ll suf[20];

bool choose(int ix, int len) {
	if (ix == (int)val.size() - 1) {
		ll nd = D - tot;
		ll cur = val[ix];
		if (nd % cur == 0 && abs(nd / cur) <= 9) {
			int res = nd / cur;
			if (res >= 0) {
				track[ix] = res;
				track[len - 1 - ix] = 0;
			} else {
				track[ix] = 0;
				track[len - 1 - ix] = -res;
			}

			return 1;
		}
		return 0;
	}
	if (tot + suf[ix] * 9 < D || tot - suf[ix] * 9 > D) return 0;

	if (ix == 0) {
		for (int j = -8; j <= 9; j++) {
			if (j < 1) {
				track[ix] = 1;
				track[len - 1 - ix] = -j + 1;
			} else {
				track[ix] = j;
				track[len - 1 - ix] = 0;
			}
			tot += val[ix] * j;
			if (choose(ix + 1, len)) return 1;
			tot -= val[ix] * j;
		}
	} else {
		for (int j = -9; j <= 9; j++) {
			if (j <= 0) {
				track[ix] = 0;
				track[len - 1 - ix] = -j;
			} else {
				track[ix] = j;
				track[len - 1 - ix] = 0;
			}
			tot += val[ix] * j;
			if (choose(ix + 1, len)) return 1;
			tot -= val[ix] * j;
		}
	}
	return 0;
}

bool find(int len) {
	int l = len - 1, r = 0;

	val.clear();
	while (l > r) {
		val.push_back(pw10[l] - pw10[r]);
		l--, r++;
	}

	for (int j = (int)val.size() - 1; j >= 0; j--) {
		suf[j] = val[j];
		if (j != (int)val.size() - 1) suf[j] += suf[j + 1];
	}

	for (int i = 0; i < len; i++) track[i] = 0;
	tot = 0;
	return choose(0, len);
}

void solve() {
	cin >> D;

	pw10[0] = 1;
	for (int i = 1; i < 18; i++) { pw10[i] = pw10[i - 1] * 10; }

	for (int i = 2; i <= 15; i++) {
		if (find(i)) {
			for (int j = 0; j < i; j++) cout << track[j];
			cout << '\n';
			return;
		}
	}

	cout << -1 << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) { solve(); }
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;

	ll l = -1e18, r = 1e18, ai = -1, a2 = -1;
	for(int i = 1; i <= q; i++) {
		ll x;
		char c;
		cin >> x >> c;

		if (c == '^') {
			l = max(l, x + 1);
		}
		else {
			r = min(r, x - 1);
		}

		
		if (l == r && ai == -1) {
			ai = i;
		}
		if (l > r && a2 == -1) a2 = i;
		
	}

	if (l < r) cout << "Hmm...";
	else if (l == r) cout << "I got it!\n" << ai;
	else cout << "Paradox!\n" << a2;
}
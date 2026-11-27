#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, ans = 1000000000, ansh;
vector<int> h;

void build(int t) {
	int tb = b;
	int sec = 0;
	for (int i : h) {
		tb += i - t;
		if (i > t) {
			sec += (i - t) * 2;
		}
		else sec += (t - i);
	}

	if (tb < 0) return;
	if (sec < ans) {
		ans = sec;
		ansh = t;
	}

}


int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	
	cin >> n >> m >> b;

	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a;
			h.push_back(a);
		}
	}

	int r = *max_element(h.begin(), h.end());
	int l = *min_element(h.begin(), h.end());

	for (int i = r; i >= l; i--) {
		build(i);
	}

	cout << ans << ' ' << ansh;
}
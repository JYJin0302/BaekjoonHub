#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.flush();

	int n, k;
	cin >> n >> k;

	int ans = 0;
	if (k == 0) ans = n / 2;
	else ans = 1 + n / 2;

	cout << "! " << ans << endl;

	int x = 1, y = 1;
	for (int i = 0; i < n; i++) {
		if (k) {
			cout << x << ' ' << y << endl;
		}
		else {
			cin >> x >> y;
			swap(x, y);
		}
		k = 1 - k;
	}

}
#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, a, b, c, x, y, z;
	cin >> n;

	int Ma, Mb, Mc, ma, mb, mc;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		if (i == 0) {
			tie(Ma, Mb, Mc) = { a, b, c };
			tie(ma, mb, mc) = { a, b, c };
		}
		else {
			x = a + max(Ma, Mb);
			y = b + max({ Ma, Mb, Mc });
			z = c + max(Mb, Mc);
			tie(Ma, Mb, Mc) = { x, y, z };
			x = a + min(ma, mb);
			y = b +min({ ma, mb, mc });
			z = c + min(mb, mc);
			tie(ma, mb, mc) = { x, y, z };
		}
	}
	cout << max({ Ma, Mb, Mc }) << ' ' << min({ ma, mb, mc });

}
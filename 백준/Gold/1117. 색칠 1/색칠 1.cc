#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve() {
	
	ll W, H, f, c, x1, y1, x2, y2;
	cin >> W >> H >> f >> c >> x1 >> y1 >> x2 >> y2;

	ll tw = min(f, W - f), th = H / (c+1);

	ll area = 0;
	area += (x2 - x1) * (y2 - y1) * (c+1);
	if (x1 < tw){
		ll tt = min(tw, x2) - x1;
		area += tt * (y2 - y1 ) * (c + 1);
	}
	cout << W * H - area << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve() {
	
	int a, b, c, d;
	cin >> a>>b >> c>> d;

	ld L = acos(-1) * c * c;
	if (L / d > 1.0 * a / b) cout << "Whole pizza\n";
	else cout << "Slice of pizza\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	return 0;
}
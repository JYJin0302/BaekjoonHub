#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve() {
	int a, b, c;
	cin >> a >> b >> c;

	if (a == 60 && b == 60 && c == 60) cout << "Equilateral\n";
	else if (a + b + c == 180) {
		if (a == b || b == c || c == a) cout << "Isosceles\n";
		else cout << "Scalene\n";
	} else cout << "Error\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	return 0;
}
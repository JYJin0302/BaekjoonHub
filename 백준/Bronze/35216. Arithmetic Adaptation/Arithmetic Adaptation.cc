#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve() {
	
	int x;
	cin >> x;
	for(int i = -10; i <= 10; i++){
		if (i == 0) continue;

		int j = x - i;
		if (j != 0 && j <= 999 && j >= -999){
			cout << i << ' ' << j << '\n';
			return;
		}
	}

}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
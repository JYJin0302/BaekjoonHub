#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve() {

	int n, m;
	cin >> n >> m;

	ll ans = 0;
	for(int i = 1; i < n ;i ++){
		for(int j = 1; j < m; j++){
			// 기울기 : i, -j -> j, i
			// i (x - i/2) - j * (y - j/2) = 0;
			// i x - j y + 1/2 (j^2 - i^2) = 0; 상수 부분이 정수여야 한다.

			// base line: j x + i y - i j = 0;
			if ((i & 1) != (j & 1)) continue;
			int c = (j*j- i*i) / 2;

			for(int tx = i/2 + 1; tx < n; tx++){
				int tc = tx * i + c;
				if (tc % j) continue;
				int ty = tc / j;
				if (ty >= m) continue;

				// triplet found
				//cout << "FOUND: " << "(" << i << ", 0) (0, " << j << ") (" << tx << ", " << ty << ") \n";

				// get box
				int mx = max(i, tx);
				int my = max(j, ty);

				ans += (n - mx) * (m - my);
			}
		}
	}
	ans <<= 2; // *4

	for(int i = 2; i < n; i += 2){
		for(int h = 1; h < m; h++){
			ans += (n - i) * (m - h) * 2;
		}
	}

	for(int i = 2; i < m; i += 2){
		for(int h = 1; h < n; h++){
			ans += (m - i) * (n - h) * 2;
		}
	}
	cout << ans << '\n';

	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
 	//cin >> t;
	while (t--) { solve(); }
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

char G[101][101];

void solve() {
	int n, m, k, i, t;
	cin >> n >> m >> k >> i >> t;

	k--,i--,t--;
	G[0][0] = 'K';
	G[0][1] = 'I';
	G[0][2] = 'T';
	
	int a= 0, b = 3;
	while(1){
		if (b == m) {
			a++, b = 0;
		}
		if(a == n) break;
		if (t){
			t--;
			G[a][b] = 'T';
		}
		else if (k){
			k--;
			G[a][b] = 'K';
		}
		else {
			G[a][b] = 'I';
		}
		b++;
	}

	for(int a = 0 ;a < n; a++){
		for(int b = 0 ;b < m; b++){
			cout << G[a][b];
		}
		cout << '\n';
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
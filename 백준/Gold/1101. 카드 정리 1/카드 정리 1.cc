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

	int c2 = 0;
	vector<int> cnt(m);
	for(int i = 0; i < n; i++){
		int tc = 0, res = -1;
		for(int j =0 ;j <  m;j++){
			int v;
			cin >> v;
			if (v) tc++, res = j;
		}
		if(tc == 1){
			cnt[res]++;
		}
		else if (tc >= 2) c2++;
	}

	int ans = c2;
	for(auto f : cnt) ans += max(0, f - 1);
	ans = max(0, ans - 1);
	cout << ans << '\n';

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
}
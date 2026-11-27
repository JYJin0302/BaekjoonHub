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

	map<pair<int, int>, bool> chk;

	vector<pair<int, int>> edg;
	while(m--){
		int a, b;
		cin >> a>> b;
		edg.push_back(mp(a, b));
		chk[mp(a, b)] = 1;
	}

	vector<int> ans(n+1);
	for(auto[a,b]: edg){
		if (!chk[mp(b,a)]){
			ans[b]++;
		}
	}

	int ansx = 1;
	int ansV = ans[1];
	for(int i = 2; i <= n; i++){
		if (ansV < ans[i]){
			ansV = ans[i];
			ansx = i;
		}
	}
	cout << ansx << ' '<< ansV << '\n';

	
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
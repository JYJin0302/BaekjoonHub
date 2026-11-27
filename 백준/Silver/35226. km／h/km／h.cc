#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve() {
	
	int n;
	cin >> n;

	int mx = 1;
	vector<int> cur;
	for(int i =0 ; i< n; i++){
		string s;
		cin >> s;
		if (isdigit(s[0])){
			int x = stoi(s);
			mx = max(mx, x);
			cout << x<< '\n';
		}
		else{
			cur.clear();
			cout << (mx / 10 + 1) * 10 << '\n';
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
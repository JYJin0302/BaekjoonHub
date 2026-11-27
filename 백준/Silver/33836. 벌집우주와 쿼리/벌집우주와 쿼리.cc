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
	vector<pair<ll ,ll>> A(n);
	for(auto&[a,b]: A) cin >> a>> b;
	
	// 0, 60, 120, 180, 240, 300

	for(auto[a,b] : A){
		
		if (a == 0){
			cout << (b == 0 ? 0 : 1) << '\n';
			continue;
		}
		if (b == 0){
			cout << (a >= 0 ? 0 : 1) << '\n';
			continue;
		}
		if(a >= 0 || a >= b){
			cout << 1 << '\n';
			continue;
		}

		cout << 2 << '\n';
	}


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
 	//cin >> t;
	while (t--) { solve(); }
}
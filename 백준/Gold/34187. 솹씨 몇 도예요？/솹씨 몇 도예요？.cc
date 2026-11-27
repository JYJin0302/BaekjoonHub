#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {
	
	int l = 0, r = 2025;
	while(1){
		int md = (l+r)>>1;
		cout << "? " << md << endl;

		string s;
		cin >> s;
		if (s[0] == 'C'){
			l = md + 1;
            r = (md + r) / 2;
		}
		else if (s[0] == 'H'){
			r = md - 1;
            l = (md + l) / 2;
		}
		else{
			cout << "! " << md << endl;
			return;
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
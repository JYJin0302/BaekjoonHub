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
	string s;
	cin >> s;

	vector<pair<int, int>> ans(n+1);
	for(int i =0; i <= n; i++){
		ans[i] = mp(i*2+1, i*2+2);
	}

	bool phase = 0;
	for(int i = 0; i < n; i++){
		if (!phase){
			if (s[i] == 'O'){
				// ok
			}
			else{
				phase = 1;
				swap(ans[i].y, ans[i+1].x);
			}
		}
		else{
			if (s[i] == 'O'){
				swap(ans[i].y, ans[i+1].x);
			}
			else{
				phase = 0;
			}
		}
	}

	if (phase) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";

	for(int i = 0;i < n; i++){
		cout << ans[i].x << ' ' << ans[i].y << '\n';
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
    cin >> t;
	while (t--) { solve(); }
}
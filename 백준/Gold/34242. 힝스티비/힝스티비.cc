#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using uint = unsigned int;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int chk(char c1, char c2, char c3){
	if (c1 == '+' && c2 == '^' && c3 == '+') return 1;
	if (c1 == '-' && c2 == '^' && c3 == '-') return -1;
	return 0;
}

void solve(){

	string s;cin >> s;
	int n = s.size();

	s = "..." + s + "...";

	int ans = 0;

	for(int i = 0; i < n; i++){
		ans += chk(s[i + 3 - 2], s[i+3 -1 ], s[i+3]);
	}

	int dif = 0;
	for(int i = 3; i < n + 3; i++){
		int dd = 0;
		for(int j = 0; j < 3; j++){
			dd -= chk(s[i + j - 2], s[i + j -1 ], s[i + j]);
		}
		dd += chk(s[i - 2], s[i - 1], s[i + 1]);
		dd += chk(s[i - 1], s[i + 1], s[i + 2]);

		dif = max(dif, dd);
		
	}
	cout << ans + dif << '\n';
	
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	return 0;
}

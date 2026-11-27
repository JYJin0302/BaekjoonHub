#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using uint = unsigned int;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve(){
	
	int u, v;
	cin >> u >> v;

	string s1, s2;
	cin >> s1 >> s2;

	int n = (int)s1.size();

	if (u == v){
		for(int i =0; i < n; i++){
			if (s1[i] != s2[i]){
				if (s1[i] > s2[i]) cout << "ras\n";
				else cout << "auq\n";
				return;
			}
		}
		cout << "rasauq\n";
		return;
	}

	if (n >= 25){
		if (u > v) cout << "ras\n";
		else cout << "auq\n";
		return;
	}
	ll val1 = 0, val2 = 0;
	for(int i = 0; i < n; i++){
		val1 = val1 * u + s1[i] - '0';
		val2 = val2 * v + s2[i] - '0';
	}

	if (val1 == val2) cout << "rasauq\n";
	else if(val1 > val2) cout << "ras\n";
	else cout << "auq\n";
	
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

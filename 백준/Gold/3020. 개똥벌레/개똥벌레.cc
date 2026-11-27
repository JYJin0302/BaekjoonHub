#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using uint = unsigned int;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve(){
	
	int n, m;
	cin >> n >> m;

	vector<int> cnt(m+1);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if (i & 1){
			cnt[m - x + 1]++;
		}
		else{
			cnt[1]++;
			cnt[x+1]--;
		}
	}

	for(int i =1; i <= m ;i++) cnt[i] += cnt[i-1];

	int ans1 = cnt[1];
	int ans2 = 0;
	for(int i = 1; i <= m; i++){
		if (cnt[i] == ans1){
			ans2++;
		}
		else if (cnt[i] < ans1){
			ans1 = cnt[i];
			ans2 = 1;
		}
	}
	cout << ans1 << ' ' << ans2 << '\n';
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
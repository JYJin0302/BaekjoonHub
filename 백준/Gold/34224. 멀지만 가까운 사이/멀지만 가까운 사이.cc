#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using uint = unsigned int;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<pair<int, int>> adj[505050];
int D[505050];
void dfs(int v, int pv = -1){
	for(auto [a,b]: adj[v]) if (a != pv){
		D[a] = D[v] ^ b;
		dfs(a, v);
	}
}

void solve(){

	int n;
	cin >> n;
	for(int i =0 ; i < n-1; i++){
		int a, b, c;
		cin >> a>> b>> c;
		adj[a].push_back(mp(b ,c));
		adj[b].push_back(mp(a, c));
	}

	dfs(1);

	ll ans = 0;
	map<int, ll> cnt;
	for(int i = 1; i <= n; i++){
		ans += cnt[D[i]];
		cnt[D[i]]++;
	}
	cout << ans << '\n';
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
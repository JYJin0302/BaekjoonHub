#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using uint = unsigned int;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<int> adj[101010];
vector<int> res;

void dfs(int v, int pv = -1){
	if (int(res.size()) == 4) return;
	res.push_back(v);
	for(auto f :adj[v]) if (f != pv){
		dfs(f, v);
	}
}

void solve(){

	int n;
	cin >> n;

	map<pair<int, int>, bool> chk;
	for(int i =0 ; i < n-1; i++){
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);

		chk[mp(a, b)] = 1;
		chk[mp(b, a)] = 1;
	}

	dfs(1);

	cout << 3 << '\n';
	for(int i =0 ;i < 4; i++){
		for(int j = i+1; j < 4; j++){
			if (!chk[mp(res[i], res[j])]){
				cout << res[i] << ' ' << res[j] << '\n';
			}
		}
	}



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
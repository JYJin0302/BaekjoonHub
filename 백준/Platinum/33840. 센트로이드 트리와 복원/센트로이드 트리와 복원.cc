#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

	int n;
vector<int> adj[101010];
int sz[101010];
int cent = 0;
void dfs(int v, int pv = -1){
	sz[v] = 1;
	for(auto f : adj[v]) if(f != pv){
		dfs(f, v);
		sz[v] += sz[f];
	}
}

void goCent(int v, int pv = -1){
	for(auto f :adj[v]) if (f != pv){
		if (sz[f] > n/2) {
			goCent(f, v);
			return;
		}
	}
	cent = v;
}

bool ok = 1;
void goCheck(int v, int pv = -1){
	int sn = sz[v];
	for(auto f : adj[v]) if (f != pv){
		if (sz[f] > sz[v] / 2) ok = 0;

		goCheck(f, v);
	}

}
void solve() {
	
	cin >> n;

	vector<pair<int, int>> edg;
	for(int i =0 ; i < n-1; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);

		edg.push_back(mp(a, b));
	}

	dfs(1);
	goCent(1);

	dfs(cent);
	goCheck(cent);

	if (!ok){
		cout << -1 << '\n';
		return;
	}

	for(auto[a,b] : edg) cout << a<< ' ' << b<< '\n';


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);


	int t = 1;
 	//cin >> t;
	while (t--) { solve(); }
}
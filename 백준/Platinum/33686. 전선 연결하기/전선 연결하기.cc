#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const ll INF = 1e15;
vector<pair<ll, ll>> adj[202020];
vector<pair<ll, ll>> dst[4][202020];

map<pair<int, int>, bool> conn;

vector<pair<ll, pair<int, int>>> edg;

void dfs(int v, int pv = -1, ll pval = 0) {
	vector<pair<ll, ll>> tmp;
	vector<vector<pair<ll, ll>>> tdst(4);

	for (auto [a, b] : adj[v])
		if (a != pv) {
			dfs(a, v, b);
			tmp.push_back(mp(b, a));

			for (int i = 1; i <= 3; i++) {
				for(auto[c, d]: dst[i-1][a]){
					if (i == 3){
						if (d != INF) edg.push_back(mp(c+b, mp(v, d)));
					}
					else{
						dst[i][v].push_back(mp(c+b, d));
						sort(all(dst[i][v]));
						if (dst[i][v].size() > 3) dst[i][v].pop_back();
					}
					break;
				}
			}
		}

	if (pval) {
		tmp.push_back(mp(pval, pv));
	}
	sort(all(tmp));
	
	for(auto f : tmp){
		for(int i = 0; i < min(3, int(tmp.size())); i++){
			if (f.y != tmp[i].y){
				edg.push_back(mp(f.x + tmp[i].x, mp(f.y, tmp[i].y)));
			}
		}	
	}

	for(auto[u1, v1] : dst[1][v]){
		for(auto[u2, v2]: dst[2][v]){
			if (v1 != INF && v2 != INF && !conn[mp(v1,v2)]){
				edg.push_back(mp(u1+u2, mp(v1, v2)));
			}
		}
	}

}

int root[202020];
int find(int n){
	if (root[n] == n )return n;
	return root[n] =find(root[n]);
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(mp(b, c));
		adj[b].push_back(mp(a, c));
		conn[mp(a, b)] = conn[mp(b, a)] = 1;
	}

	for (int i = 1; i <= n; i++) {
		dst[0][i].push_back(mp(0, i));
		for (int j = 1; j <= 3; j++) { dst[j][i].push_back(mp(INF, INF)); }
	}
	//cout << "go dfs " << endl;
	dfs(1);
	// cout << "end dfs" << endl;
	
	sort(all(edg));
	for(int i =1; i <= n; i++) root[i] = i;

	int conn = 0;
	ll ans = 0;
	for(auto[a, b] : edg){
		// cout <<" CUr edg: " << a << ' '<< b.x << ' '<< b.y << endl;
		int u = find(b.x);
		int v = find(b.y);
		if (u != v){
			root[u] = v;
			ans += a;
			conn++;
			//cout << "Edg used: " << b.x << ' ' << b.y << ' ' << a << endl;
		}
	}

	if (conn != n-1 || ans >= INF){
		cout << -1 << '\n';
	}
	else cout << ans << '\n';

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int root[1010];
int find(int n){
    if (root[n] == n)return n;
    return root[n] = find(root[n]);
}

vector<int> adj[1010];
bool vis[1010];

vector<pair<int, int>> ansL;
void dfs(int v, int pv = -1){
    vis[v] = 1;
    for(auto f :adj[v]) if (f != pv){
        dfs(f, v);
        ansL.push_back(mp(v, f));
    }
}


void solve(){

    int n, k;
    cin >> n >> k;
    vector<array<int, 3>> A;
    for(int i =1; i <= n; i++) root[i] = i;
    for(int i =1; i <= n; i++){
        for(int j =1;j <= n; j++){
            int x;
            cin >> x;
            
            A.push_back({x, i, j});
        }
    }

    sort(all(A));
    reverse(all(A));

    int ans = 0;
    int cnt = n;
    for(auto f: A){
        int u = f[1], v = f[2];
        int tu = find(u), tv = find(v);
        if (tu == tv) continue;

        ans += f[0];
        cnt--;
        root[tu] = tv;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (cnt == k) break;
    }

    for(int i =1; i <= n; i++){
        if (!vis[i]) dfs(i);
    }

    cout << ans << '\n';
    for(auto[a,b] : ansL) cout << a << ' '<< b << '\n';



}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    
    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
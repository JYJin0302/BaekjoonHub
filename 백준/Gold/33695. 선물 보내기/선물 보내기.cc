#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second
 
const int mod = 1e9+7;
vector<int> adj[202020];
bool owned[2][202020];
int col[202020];
bool vis[202020];
ll ans = 1;
 
void dfs(int v){
    for(auto f : adj[v]){
        
        if (col[f] == 0 || col[f] == 3 - col[v]){
            col[f] = 3 - col[v];
        }
        else ans = 0;
        if (!vis[f]){
            vis[f] = 1;
            dfs(f);
        }
 
    }
}
 
void solve() {
    
    int n, m;
    cin >> n >> m;
 
    for(int i =0 ;i < m;i++){
        int a, b;
        char c;
        cin >> a >> b >> c;
        if (c == 'U'){
            owned[0][a] = 1;
            owned[0][b] = 1;
        }
        else if (c == 'P'){
            owned[1][a] = 1;
            owned[1][b] = 1;
        } 
        else{
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
 
    for(int i = 1;i <= n; i++){
        if (owned[0][i] && owned[1][i]) {
            cout << 0 << '\n';
            return;
        }
        if (owned[0][i]) col[i] = 1;
        else if (owned[1][i]) col[i] = 2;
    }
 
    for(int i = 1; i <= n; i++){
        if (!vis[i] && col[i]){
            vis[i]= 1;
            dfs(i);
        }
    }
 
    for(int i = 1; i <= n; i++){
        if (!vis[i]){
            vis[i] = 1;
            col[i] = 1;
            dfs(i);
            ans = ans * 2 % mod;
        }
    }
    cout << ans << '\n';
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    //cin >> t;
    while (t--) solve();
}

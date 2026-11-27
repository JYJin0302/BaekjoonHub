#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second
 
int pos[3][1001010];
vector<int> adj[1001010];
 
int spt[20][1001010];
int dep[1001010];
int dp[1001010];
 
void dfs(int v, int pv = -1){
    for(auto f :adj[v]) if (f != pv){
        dep[f] = dep[v] + 1;
        spt[0][f] = v;
        dfs(f, v);
    }
}
 
void dfs2(int v, int pv = -1){
    for(auto f :adj[v]) if (f != pv){
        dfs2(f, v);
        dp[v] += dp[f];
    }
}
 
int lca(int u, int v){
    if (dep[u] > dep[v]) swap(u, v);
    int dif = dep[v] - dep[u];
    for(int i = 0; i < 20 ;i++){
        if (dif & (1 << i)) v = spt[i][v];
    }
    for(int i = 19 ; i >= 0; i--){
        if (spt[i][u] != spt[i][v]){
            u = spt[i][u];
            v = spt[i][v];
        }
    }
    if (u != v) u = spt[0][u];
    return u;
}
 
pair<int, int> F(int v, int tar, int pv = -1){
    int cnt = 0, rem = 1;
    for(auto f : adj[v]) if (f != pv){
        auto res = F(f, tar, v);
        cnt += res.x;
        if (res.y >= tar && !dp[f]) cnt++;
        else rem += res.y;
    }
    if(v == 1 && rem >= tar) cnt++;
    return mp(cnt, rem);
}
 
void solve() {
 
    int n;
    cin >> n;
 
    for(int i = 1; i <= n; i++){
        adj[i].clear();
        dp[i] = 0;
    }
    for(int j = 0; j < 3; j++){
        for(int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            pos[j][x] = i;
        }
    }
 
    for(int i =0 ; i < n-1; i ++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    dfs(1);
    for(int j = 1; j < 20; j++) {
        for(int i = 1; i <= n ;i++){
            spt[j][i] = spt[j-1][spt[j-1][i]];
        }
    }
 
    for(int i = 1; i <= n; i++){
        int l = lca(pos[0][i], pos[1][i]);
        dp[pos[0][i]]++;
        dp[pos[1][i]]++;
        dp[l] -= 2;
 
        l = lca(pos[0][i], pos[2][i]);
        dp[pos[0][i]]++;
        dp[pos[2][i]]++;
        dp[l] -= 2;
    }   
 
    dfs2(1);
 
    int L = 1, R = n / 3, ans = -1;
    while(L <= R){
        int md = (L+R)>>1;
 
        auto res = F(1, md);
        if(res.x >= 3){
            ans = md;
            L = md + 1;
        }
        else R = md - 1;
    }
 
    cout << ans << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}

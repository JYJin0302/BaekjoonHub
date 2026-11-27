#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()
 
vector<pair<ll, ll>> adj[101010], rev[101010];
 
int dep[101010];
int spt[17][101010];
 
int lca(int u, int v){
    if (dep[u] > dep[v]) swap(u, v);
    int dif = dep[v] - dep[u];
    for(int i = 0 ;i < 17; i++){
        if (dif & (1 << i)) v = spt[i][v];
    }
 
    for(int i = 16; i >= 0; i--){
        int tu = spt[i][u];
        int tv = spt[i][v];
        if (tu != tv){
            u = tu, v = tv;
        }
    }
    if (u != v) u = spt[0][u];
    return u;
}
void solve() {
 
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m;i++){
        int a, b, c;
        cin >> a>> b >> c;
 
        adj[a].push_back(mp(b, c));
        rev[b].push_back(mp(a, c));
    }
 
    vector<ll> dist(n+1, -1);
    set<pair<ll, ll>> st;
    st.insert(mp(0, 1));
 
    vector<int> ord;
    while(!st.empty()){
        auto[a,b] = *st.begin();
        st.erase(st.begin());
 
        if (dist[b] != -1) continue;
        dist[b] = a;
        ord.push_back(b);
 
        for(auto[u, v] : adj[b]){
            if(dist[u] == -1){
                st.insert(mp(a + v, u));
            }
        }
    }
 
 
    vector<int> ans(n+1);
    for(auto f : ord){
        if (f == 1) {
            ans[1] = 1;
            continue;
        }
 
        vector<int> pre;
        for(auto[a,b] : rev[f]){
            if (dist[a] + b == dist[f]) pre.push_back(a);
        }
        sort(all(pre));
        pre.erase(unique(all(pre)), pre.end());
 
        assert(!pre.empty());
        if ((int)pre.size() == 1){
            int p = pre[0];
            ans[f] = (p == 1 ? 1 : 0);
 
            spt[0][f] = p;
            dep[f] = dep[p] + 1;
        }   
        else{
            int p = lca(pre[0], pre[1]);
            for(int i =2 ; i < (int)pre.size(); i++){
                p = lca(p, pre[i]);
            }
            ans[f] = (p == 1 ? 1 : 0);
            spt[0][f] = p;
            dep[f] = dep[p] + 1;
        }
 
        for(int j = 1; j < 17; j++){
            spt[j][f] = spt[j-1][spt[j-1][f]];
        }
    }
 
    for(auto f : adj[1]){
        if (dist[f.x] == dist[1] + f.y){
            bool ok = 0;
            for(auto k : rev[f.x]){
                if (k.x != 1 && dist[k.x] + k.y == dist[f.x]) ok = 1;
            }
 
            if (!ok) ans[f.x] = 0;
        }
    }
 
    for(int i = 2; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
 
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

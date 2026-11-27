#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<int> adj[202020];
int root[202020];
ll sz[202020];
int find(int n){
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

ll ans = 0;
void conn(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return;

    ll s1 = sz[u], s2 = sz[v];
    ans -= s1 * (s1 - 1) / 2;
    ans -= s2 * (s2 - 1) / 2;
    root[v] = u;
    sz[u] += sz[v];
    ans += sz[u] * (sz[u] - 1) / 2;
}
void solve(){

    int n, m;
    cin >> n >> m;
    
    string s;
    cin >> s;
    
    for(int i = 0; i < n; i++){
        root[i] = i;
    }

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a>> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i =0 ;i <  n;i++){
        if (s[i] == '1'){
            for(auto f :adj[i]){
                if (s[f] == '1') conn(f, i);
            }
        }
    }

    vector<ll> res;
    for(int i = n-1; i >= 0; i--){
        int ti = find(i);
        ans -= sz[ti] * (sz[ti] - 1) / 2;
        sz[ti]++;
        ans += sz[ti] * (sz[ti] - 1) / 2;
        if (s[i] == '0'){
            for(auto f : adj[i]){
                if (f > i || s[f] == '1') conn(f, i);
            }
        }

        res.push_back(ans);
    }
    reverse(all(res));
    for(auto f :res) cout <<f  << '\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}

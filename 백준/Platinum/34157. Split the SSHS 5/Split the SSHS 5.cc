#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

const int mod = 998244353;

vector<int> trap[101010];
vector<int> revTrap[101010];
vector<int> adj[101010];

ll cnt[101010];
ll dp[101010];
ll val = 1;
bool vis[101010];

ll inv[101010];

void dfs(int v, int pv = -1){
    vis[v] = 1;
    vector<int> tmp;
    for(auto f: trap[v]){
        if (!vis[f]){
            revTrap[f].push_back(v);
            tmp.push_back(f);
        }
    }

    ll valTmp = val;
    for(auto f : revTrap[v]){
        val = val * inv[cnt[f]] % mod * (cnt[f]-1) % mod;
        cnt[f]--;
    }
    dp[v] = val;

    for(auto f : adj[v]) if (f != pv){
        dfs(f, v);
    }

    for(auto f : revTrap[v]){
        cnt[f]++;
    }
    for(auto f : tmp) revTrap[f].pop_back();
    val = valTmp;
}

void solve() {
    
    int n;
    cin >> n;

    for(int i =1; i <= n; i++){
        int k;
        cin >> k;

        cnt[i] = k;
        while(k--){
            int x;
            cin >> x;
            trap[i].push_back(x);
        }
    }

    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a>> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    inv[0] = 1;
    inv[1] = 1;
    for(int i = 2; i <= 100010; i++){
        inv[i] = mod - (mod/i) * inv[mod%i] % mod;
    }

    dfs(1);

    for(int i = 2; i <= n; i++) cout << dp[i] << '\n';

    
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9+7;

ll ans;
vector<int> p, cnt;
vector<int> adj[100001];

ll f[100001], rev[100001];

ll fP(ll b, ll ex){
    ll res = 1;
    while(ex){
        if (ex % 2== 1) res = res*b % mod;
        b = b*b % mod;
        ex >>= 1;
    }
    return res;
}
void dfs(int v){
    
    for (auto i : adj[v]){
        dfs(i);
        cnt[v] += cnt[i];
    }
    
}

void dfs2(int v){
    
    cnt[v]--;
    for (auto i : adj[v]){
        // cnt[v]-1 C cnt[i]
        ll tp = f[cnt[v]] * rev[cnt[i]] % mod;
        tp = tp*rev[cnt[v] - cnt[i]] % mod;
        ans = ans*tp % mod;
        cnt[v] -= cnt[i];
        dfs2(i);
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    f[0] = 1;
    rev[0] = 1;
    for(int i = 1; i <= 100000; i++){
        f[i] = (f[i-1] * i) % mod;
        rev[i] = rev[i-1] * fP(i, mod-2) % mod;
    }
    
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        
        int n;
        cin >> n;
        
        for (int i = 0; i <= n; i++) adj[i].clear();
        
        p = vector<int>(n+1, -1);
        cnt = vector<int>(n+1, 1);
        p[1] = 0;
        vector<int> tmp(n+1);
        tmp[1] = 1;
            
        vector<int> A(n+1);
        for (int i = 1; i<= n; i++) cin >> A[i];
        
        bool ok = 1;
        if (A[1] != 1) ok = 0;
        
        for (int i = 2; i <= n; i++){
            if (A[i] - A[i-1] >= 2) {
                ok = 0;
            }
            else if (A[i] == A[i-1]+1) {
                tmp[A[i]] = i;
                p[i] = i-1;
            }
            else if (A[i] <= A[i-1]){
                int tx = tmp[A[i]];
                p[i] = p[tx];
                p[tx] = i;
                tmp[A[i]] = i;
            }
        }
        
        for (int i = 1; i <= n; i++){
            int x= p[i];
            adj[x].push_back(i);
        }
        
        dfs(0);
        ans = ok;
        dfs2(0);
        cout << "Case #" << tc << ": " << ans << '\n';
     }
    
}
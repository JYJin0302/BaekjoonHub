#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<int> adj[202020];
const int mod = 1e9 + 7;

int n, m;
int sz[202020];
ll dp[202020];

ll F[202020];
ll fastPow(ll b, ll ex){
    ll res = 1;
    while(ex){
        if (ex & 1) res = res * b % mod;
        b = b * b % mod;
        ex >>= 1;
    }
    return res;
}

ll nCr(ll n, ll r){
    ll res = F[n];
    res = res * fastPow(F[n-r], mod -2) % mod;
    res = res * fastPow(F[r], mod - 2)% mod;
    return res;
}

void dfs(int v, int pv = -1){
    sz[v] =1;
    for(auto f :adj[v])if (f != pv){
        dfs(f, v);
        sz[v] += sz[f];
    }

    int tot = sz[v] - 1;
    ll res = 1;
    for(auto f: adj[v]) if (f != pv){
        res = res * nCr(tot, sz[f]) % mod * dp[f] % mod;
        tot -= sz[f];
    }
    dp[v] = res;
    //cout << v << " | " << dp[v] << '\n';
}

ll ans = 0;
void dfs2(int v, int pv = -1, ll dpU = 1){
    ll tans =  dpU * dp[v] % mod * nCr(n-1, sz[v] - 1) % mod;
    ans = (ans + tans) % mod;
   // cout << "V : " << v << ' ' << pv << ' '<< dpU << " +> " << tans << '\n';

    int szU = n - sz[v];

    ll mul = tans;

    for(auto f: adj[v]) if (f != pv){
        ll tmp = mul * fastPow(nCr(n-1, sz[f]), mod-2) % mod;
        tmp = tmp * fastPow(dp[f], mod-2) % mod;

        dfs2(f, v, tmp);
    }

}


void solve(){
    
    cin >> n >> m;

    for(int i =0 ;i < m;i++){
        int a ,b;
        cin >> a>> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (m != n-1){
        cout << 0 << '\n';
        return;
    }

    F[0] = 1;
    for(int i =1; i <= n +10; i++){
        F[i] = F[i-1] * i % mod;

    }

    dfs(1);

    dfs2(1);

    cout << ans << '\n';
}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

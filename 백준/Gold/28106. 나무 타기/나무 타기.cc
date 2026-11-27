#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const int mod = 998244353;
int P[1001010];
int A[1001010];
vector<int> adj[1001010];
ll dp[1001010];

int n;
ll fw[1001010];

void update(int ix, ll val){
    while(ix <= n + 10){
        fw[ix] = (fw[ix] + val) % mod;
        ix += ix & -ix;
    }
}

ll getS(int ix){
    ll res = 0;
    while(ix){
        res = (res + fw[ix]) % mod;
        ix -= ix & -ix;
    }
    return res;
}


void dfs(int v, int D = 1){

    int L = D;
    int R = D + A[v];
    R = min(R, n);

    update(L, dp[v]);
    update(R+1, mod - dp[v]);

    ll val = getS(D+1);

    for(auto f : adj[v]){
        dp[f] = val;
        dfs(f, D+1);
    }

    update(L, mod - dp[v]);
    update(R + 1, dp[v]);

}

void solve(){

    cin >> n;

    int r= 0;
    for(int i =1; i <= n; i++) {
        cin >> P[i];
        if (P[i]){
            adj[P[i]].push_back(i);
        }
        else r = i;
    }

    for(int i= 1; i <= n; i++) cin >> A[i];

    dp[r] = 1;
    dfs(r);

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        if (adj[i].empty()){
            ans += dp[i];
        }
    }
    cout << ans % mod << '\n';


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
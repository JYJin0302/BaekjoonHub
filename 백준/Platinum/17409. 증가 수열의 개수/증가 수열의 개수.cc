#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;

ll seg[303030];

int n, k;
void update(int ix, ll val){
    while(ix <= n){
        seg[ix] += val;
        seg[ix] %= mod;
        ix += ix & -ix;
    }
}

ll getS(int ix){
    ll res = 0;
    while(ix){
        res+= seg[ix];
        res %= mod;
        ix -= ix & -ix;
    }
    return res;
}


void solve(){

    cin >> n >> k;

    vector<int> A(n);
    for(auto &i : A) cin >> i;

    vector<ll> dp(n, 1), ndp(n);

    for(int i = 2; i <= k; i++){
        ndp = vector<ll>(n);

        for(int j = 0; j < n ;j++){
            ndp[j] = getS(A[j]);
            update(A[j], dp[j]);
        }
        dp = ndp;
        memset(seg, 0 ,sizeof seg);
    }
    ll ans = 0;
    for(auto f : dp) ans = (ans + f) % mod;
    cout << ans << '\n';



}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
   // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

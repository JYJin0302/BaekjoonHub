#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
ll F[404040];
ll fastPow(ll b, ll ex){
    ll res = 1;
    while(ex){
        if (ex&1) res = res *b % mod;
        b = b*b % mod;
        ex >>= 1;
    }
    return res;
}

ll nCr(int n, int r){
    ll res = F[n];
    res= res* fastPow(F[n-r], mod-2) % mod;
    res= res* fastPow(F[r], mod-2) % mod;
    return res;
}

void solve(){
    
    int n, m;
    cin >> n >> m;
    n--,m--;

    F[0] = 1;
    for(int i = 1;i <= 400010; i++){
        F[i] = F[i-1]* i % mod;
    }

    ll ans = nCr(n+m-2, n-1);
    ans = ans * ans % mod;

    ll ans2 = 0;
    ans2 = nCr(n+m-2, m) * nCr(n+m-2, n) % mod;
    cout << 2 * (ans + mod - ans2) % mod << '\n';
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
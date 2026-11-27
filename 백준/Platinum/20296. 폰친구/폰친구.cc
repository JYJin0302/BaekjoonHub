#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9+7;

ll n, m, M, k;
ll f[1001001];

ll fastPow(ll base, ll e) {
    ll mt = base;
    ll res = 1;

    while(e){
        if (e % 2 == 1) {
            res *= mt;
            res %= mod;
        }
        
        mt = mt*mt % mod;
        e /= 2;
    }
    return res;
}

ll comb(ll n, ll r){
    // n C r -> n! / (n-r)! / r! -> 모듈러 역수
    if (n < r) return 0;
    ll res = f[n];
    res = res * fastPow(f[n-r], mod-2) % mod;
    res = res * fastPow(f[r], mod-2) % mod;
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> M >> k;
    k -= n*m;
    M -= m;
    
    f[0] = 1;
    for (ll i = 1; i <= 1001000; i++){
        f[i] = f[i-1]*i % mod;
    }
    
    ll a = n + k - 1, b = n-1;
    
    ll ans = 0;
    for (int i = 0; i <= n; i++){
        ll tval = 0;
        
        if (i % 2 == 0) tval = comb(a, b) * comb(n, i);
        else tval = (mod - comb(a, b)) * comb(n, i);
        tval %= mod;
        
        ans += tval;
        ans %= mod;
        
        a -= M+1;
        
        if (a <= 0) break;
    }
    cout << ans;
}
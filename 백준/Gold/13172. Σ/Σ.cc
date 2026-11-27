#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MOD 1000000007

ll fastPow(ll base, ll exp){
    
    ll res = 1ll;
    
    for (ll i = 0; i < 32; i++){
        if ((exp & (1 << i)) != 0) res *= base;
        base = base * base % MOD;
        res %= MOD;
    }
    
    return res;
}


int main(){
    
    ll m;
    cin >> m;
    
    ll ans = 0;
    
    for (int i = 0; i < m; i++){
        
        ll a, b;
        cin >> a >> b;
        
        ans += b * fastPow(a, MOD-2);
        ans %= MOD;
    }
    
    cout << ans;
}
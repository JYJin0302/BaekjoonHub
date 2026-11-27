#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod = 1e9+7;
ll power(ll x, ll y) {
    ll ret = 1;
    while (y > 0) {
        if (y % 2) {
            ret *= x;
            ret %= mod;
        }
        x *= x;
        x %= mod;
        y /= 2;
    }
    return ret;
}


int main(){
    
    ll n, k;
    cin >> n >> k;
    
    vector<ll> pp(4000001);
    pp[0] = 1;
    pp[1] = 1;
    for(int i = 2; i <= 4000000; i++){
        pp[i] = pp[i-1] * i;
        pp[i] %= mod;
    }
    
    cout << pp[n] * power(pp[n-k] * pp[k] % mod, mod-2) % mod;
    
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 998244353;
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, k, x;
    cin >> n >> k >> x;
    
    ll val = x * (x + 1) / 2, t = 1;
    val %= mod;
    
    val=(val * val) % mod;
    for(int i = 0; i < n + k - 2; i++){
         t *= x;
         t %= mod;
    }
    
    ll ans = (val * t) % mod;
    ans = (ans * k) % mod;
    for(int i = 0; i < n-k+1; i++){
        cout << ans << ' ';
    }
    
}
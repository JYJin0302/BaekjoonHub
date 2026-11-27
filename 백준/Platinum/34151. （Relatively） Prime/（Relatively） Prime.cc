#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

const int mod = 998244353;
ll fastPow(ll b, ll ex){
    ll res = 1;
    while(ex){
        if (ex & 1) res = res * b % mod;
        ex >>= 1;
        b = b* b % mod;
    }
    return res;
}

void solve() {
    
    ll p, n, m;
    cin >> p >> n >> m;

    if (n > m) swap(n, m);
    ll ans = 0;
    ll d = m/n;

    ll val1 = fastPow(p, n);

    if (val1 == 1) ans = d;
    else ans = (fastPow(val1, d) - 1) * val1 % mod * fastPow(val1 - 1, mod-2) % mod;
    if (m % n != 0){
        ans += fastPow(p, m);
        ans %= mod;
    }

    cout << ans << '\n';
    
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
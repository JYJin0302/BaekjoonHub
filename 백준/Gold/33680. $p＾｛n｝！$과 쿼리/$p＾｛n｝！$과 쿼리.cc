#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define all(x) x.begin(), x.end()

const int mod = 1e9+7;

ll fastPow(ll b, ll ex){
    ll res = 1;
    while(ex){
        if (ex &1) res= res * b % mod;
        b =b  * b % mod;
        ex >>= 1;
    }
    return res;
}

void solve(){

    ll n, p;
    cin >> p >> n;

    ll val1 = (fastPow(p, n) + mod - 1) % mod;
    ll val2 = fastPow(p - 1, mod - 2);

    cout << val1 * val2 % mod << '\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair

const int mod = 1e9 + 7;
ll f[1001010];

ll fastPow(ll b, ll ex){
    ll res = 1;
    while(ex){
        if (ex & 1) res = res* b % mod;
        b = b * b % mod;
        ex >>= 1;
    }
    return res;
}

ll nCr(int n ,int r){
    ll res = f[n];
    res = res * fastPow(f[n-r], mod-2) % mod;
    res = res * fastPow(f[r], mod-2) % mod;
    return res;
}

void solve(){
    
    ll k, n, l;
    cin >> k >> n >> l;

    string s;
    cin >> s;

    f[0] = 1;
    for(int i = 1; i <= n; i++) f[i] = f[i-1] * i  % mod;

    ll res = 1;
    ll cnt = 0;
    for(int i = n -1; i >= 0; i--){
        if (s[i] == 'O') cnt++;
        else{
            res = res * nCr(cnt, k) % mod;
            cnt -= k;
        }
    }

    ll ans = fastPow(res, l);
    cout << ans << '\n';

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}

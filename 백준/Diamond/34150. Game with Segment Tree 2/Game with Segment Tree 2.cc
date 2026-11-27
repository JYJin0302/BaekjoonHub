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
        b = b * b % mod;
        ex >>= 1;
    }
    return res;
}

ll pw2[303030];

void solve() {
    
    int K;
    cin >> K;

    pw2[0] = 1;
    for(int i = 1; i <= K; i++){
        pw2[i] = pw2[i-1] * 2 % mod;
    }

    ll ans = 0;

    ll range = 0, cnt = 1;
    ll nxt = 1;
    for(int i = 1; i < K; i++){
        // i i pair
        ll val = pw2[K-i-1] - 1;
        val = val * pw2[range] % mod;
        val = val * cnt % mod * cnt % mod;
        //cout << "pairL :" << val -1  << '\n';
        ans = (ans + val) % mod;
        // combination

        if (i == nxt){
            range++;
            nxt <<= 1;
        }
        else{
            ll m1 = pw2[K-i] - 2;
            m1 = m1 * cnt % mod * cnt % mod;
            m1 = m1 * pw2[range] % mod;

            ll m2 = 2 * cnt % mod;

            //cout << m1 << ' ' << m2 << '\n';
            ans = (ans + m1 + m2) % mod;
            cnt = (cnt * 2) % mod;
        }

    }

    cout << ans << '\n';

    
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
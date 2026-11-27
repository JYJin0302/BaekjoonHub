#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;

ll f[1010010];
ll fastPow(ll b, ll ex, ll mod) {
    ll res = 1;
    while (ex) {
        if (ex & 1) res = res * b % mod;
        ex >>= 1;
        b = b * b % mod;
    }
    return res;
}

void solve() {

    f[0] = 1;
    for (ll i = 1; i <= 1000000; i++) {
        f[i] = f[i - 1] * i % mod;
    }


    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for (auto& i : A) cin >> i;
    sort(all(A));

    ll ans = 1;
    ll rem = 0;

    for (auto i : A) {
        
        if (i == m) break;
        ll tx = i - rem;
        if (tx < 0) {
            cout << 0 << '\n';
            return;
        }

       //cout << i << ' ' << rem << ' ' << ans << '\n';
        ll val = f[m-rem] * fastPow(f[tx], mod - 2, mod) % mod * fastPow(f[m - rem - tx], mod - 2, mod) % mod;
        ans = ans * val % mod;
        rem = m - tx;
    }
    cout << ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
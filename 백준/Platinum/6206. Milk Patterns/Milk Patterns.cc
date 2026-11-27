#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int mod = 1e9 + 7;
const int mod2 = 998244353;
void solve() {

    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (auto& i : A) cin >> i;

    int l = 1, r = n, ans = 1;
    while (l <= r) {
        int md = (l + r) >> 1;
        ll dif = 1;
        for (int i = 0; i < md; i++) dif = (dif * mod2) % mod;
        map<ll, int> cnt;
        int mx = 0;
        ll cur = 0;
        for (int i = 0; i < n; i++) {
            cur = (cur * mod2 + A[i]) % mod;
            if (i >= md) {
                (cur += (mod - dif * A[i-md] % mod)) %= mod;
            }
            mx = max(mx, ++cnt[cur]);
        }

        if (mx >= k) {
            ans = md;
            l = md + 1;
        }
        else r = md - 1;
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
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

const ll mod = 998244353;

void solve() {

    int n;
    cin >> n;

    vector<int> A(n);
    for (auto& i : A) cin >> i;

    vector<ll> ans(3);

    for (int i = 0; i < 30; i++) {

        vector<int> tmp(n);
        for (int j = 0; j < n; j++) {
            if (A[j] & (1 << i)) tmp[j] = 1;
        }

        vector<ll> cnt(3);
        int ix = 0;
        for (int j = 0; j < n; j++) {
            ix = max(ix, j);
            while (ix < n && tmp[ix]) ix++;

            cnt[0] += ix - j;
            cnt[0] %= mod;
        }

        ix = 0;
        for (int j = 0; j < n; j++) {
            ix = max(ix, j);
            while (ix < n && tmp[ix] == 0) ix++;

            cnt[1] += n - ix;
            cnt[1] %= mod;
        }

        vector<ll> tc(2);
        tc[0] = 1;

        int tt = 0;
        for (int j = 0; j < n; j++) {
            tt ^= tmp[j];
            cnt[2] += tc[1 - tt];
            cnt[2] %= mod;
            tc[tt]++;
        }

        for (int f = 0; f < 3; f++) {
            ans[f] += (1ll << i) * cnt[f] % mod;
            ans[f] %= mod;
        }
    }

    for (auto f : ans) cout << f << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const ll mod = 1e9 + 7;
const ll mult = 998244353;


void solve() {

    int n, m, s;
    cin >> n >> m >> s;

    vector<int> A(n);
    for (auto& i : A) cin >> i;

    vector<int> P(m);
    for (auto& i : P) cin >> i;

    vector<int> cnt(s + 1);
    vector<ll> val(s + 1);

    ll tar = 0;
    for (int i = 0; i < m; i++) {
        tar = tar * mult + P[i];
        tar %= mod;
    }
    ll tval = 1;
    for (int i = 0; i < m; i++) {
        tval = tval * mult % mod;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {

        for (int j = 1; j <= s; j++) {
            val[j] = val[j] * mult % mod;
        }
        val[A[i]]++;
        val[A[i]] %= mod;
        cnt[A[i]]++;

        if (i >= m) {
            val[A[i - m]] += mod-tval;
            val[A[i - m]] %= mod;
            cnt[A[i - m]]--;
        }

        ll res = 0;
        ll tc = 0;
        for (int j = 1; j <= s; j++) {
            if (cnt[j]) {
                tc++;
                res += tc * val[j] % mod;
                res %= mod;
            }
        }

        if (res == tar) {
            ans.push_back(i - m + 2);
        }
    }

    cout << ans.size() << '\n';
    for (auto f : ans) cout << f << ' ';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
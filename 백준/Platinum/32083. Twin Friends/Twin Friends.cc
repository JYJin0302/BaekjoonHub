#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int mod = 998244353;
ll f[202020];

ll fastPow(ll b, ll ex, ll mod) {
    ll res = 1;
    while (ex) {
        if (ex & 1) res = res * b % mod;
        ex >>= 1;
        b = b * b % mod;
    }
    return res;
}

ll C(int n, int r) {
    if (r > n) return 0;
    ll res = f[n];
    res = res * fastPow(f[r], mod - 2, mod) % mod;
    res = res * fastPow(f[n -r], mod - 2, mod) % mod;
    return res;
}

void solve() {

    f[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        f[i] = f[i - 1] * i % mod;
    }

    int n, m; cin >> n >> m;
    string s1, s2; cin >> s1 >> s2;


    vector<int> cnt1(27), cnt2(27);
    for (auto f : s1) cnt1[f - 'A']++;
    for (auto f : s2) cnt2[f - 'A']++;

    vector<ll> dp(m + 1); //dp[i] : 현재 char 개수 여유분 = i
    dp[cnt2[0]] = 1;
    for (int i = 0; i < 26; i++) {

        vector<ll> tmp(m + 1);
        vector<ll> sdp(m + 1);
        for (int j = 0; j <= m; j++) {
            sdp[j] = dp[j];
            if (j) sdp[j] += sdp[j - 1];
            sdp[j] %= mod;
        }


        int c1 = cnt1[i];
        int c2 = cnt2[i + 1];
        for (int k = 0; k <= cnt2[i+1]; k++) {

            // dp[i+1][j];
            int nd = c1 - c2 + k;
            if (nd < 0) continue;

            ll s = sdp[m] - (nd ? sdp[nd - 1] : 0);
            s = (s % mod + mod) % mod;
            tmp[k] = s * C(cnt1[i], nd) % mod;
        }

        swap(tmp, dp);

       // for (auto f : dp) cout << f << ' ';
       // cout << '\n';
    }

    ll mul = f[n];
    for (auto d : cnt1) {
        mul = mul * fastPow(f[d], mod - 2, mod) % mod;
    }

    cout << dp[0] * mul % mod;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}
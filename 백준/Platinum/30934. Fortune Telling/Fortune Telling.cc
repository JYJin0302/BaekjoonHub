#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

const ll mod = 998244353;

ll fastPow(ll b, ll ex) {
    ll res = 1;
    while (ex) {
        if (ex & 1) res = res * b % mod;
        ex >>= 1;
        b = b * b % mod;
    }
    return res;
}

int n;
vector<ll> dp[303030];

ll b[8];
int cnt = 0;

ll getDp(int _n, int _k) {
    if (!dp[_n].empty() && dp[_n][_k] != -1) return dp[_n][_k];
    if (_n <= 6) return b[_n];

    if (dp[_n].empty()) dp[_n] = vector<ll>(n + 1, -1);

    ll res = 0;
    for (int i = 0; i < 6; i++) {
        if (_k % 6 == i) continue;

        int nn = _n - (_n + 5 - i) / 6;
        int kk = _k - (_k + 5 - i) / 6;

        res += getDp(nn, kk);
        res %= mod;
    }

    res = res * b[min(_n, 6)] % mod;
    //cout << "Solve: " << n << ' ' << k << " = " << res << '\n';
    return dp[_n][_k] = res;
}

void solve() {

    cin >> n;
    for (int i = 2; i <= 6; i++) {
        b[i] = fastPow(i, mod - 2);
    }
    for (int i = 0; i < n; i++) {
       cout << getDp(n, i)<< '\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) solve();
}
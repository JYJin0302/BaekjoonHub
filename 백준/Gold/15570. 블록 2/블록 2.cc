#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

const int mod = 1999;
ll cnt[1010];

vector<ll> mult(vector<ll>& a, vector<ll>& b) {
    int n = a.size();
    int m = b.size();

    vector<ll> res(n + m - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i + j] += a[i] * b[j] % mod;
            res[i + j] %= mod;
        }
    }
    return res;
}

vector<ll> div(vector<ll>& a, vector<ll>& b) {
    int n = a.size();
    int m = b.size();

    // a % b
    if (n < m) return a;
    vector<ll> res = a;
    for (int i = n - 1; i >= m - 1; i--) {
        ll v = res[i]; // b[m-1] = 1
        for (int j = 0; j < m; j++) {
            res[i - m + 1 + j] += mod - v * b[j] % mod;
            res[i - m + 1 + j] %= mod;
        }
    }
    while (!res.empty() && res.back() == 0) res.pop_back();
    if (res.empty()) res.push_back(0);
    return res;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    if (n == 1 || !m) {
        cout << 1 << '\n';
        return;
    }

    cnt[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) cnt[i] += cnt[j];
        cnt[i] %= mod;
    }

    if (m < n) {
        cout << cnt[m] << '\n';
        return;
    }
    if (m == n) {
        cnt[n] = (cnt[n] * 2 - 1) % mod;
        cout << cnt[n] << '\n';
        return;
    }
    m--;

    vector<ll> f(n + 1, mod - 1);
    f[0] = mod - cnt[n];
    f[n] = 1;

    vector<ll> cur = { 0, 1 }, res = { 1 };
    for (int i = 0; i < 50; i++) {
        if (m & (1ll << i)) {
            res = mult(res, cur);
            res = div(res, f);
        }
        cur = mult(cur, cur);
        cur = div(cur, f);
    }
    cnt[n] = (2 * cnt[n] + mod - 1) % mod;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += res[i] * cnt[i + 1] % mod;
        ans %= mod;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

ll f[12];
ll C(int n, int r) {
    ll res = f[n];
    res /= f[r];
    res /= f[n - r];
    return res;
}

void solve() {
    f[0] = 1;
    for (int i = 1; i <= 10; i++) f[i] = f[i - 1] * i;

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    vector<int> cnt(m);
    for (auto f : s) {
        cnt[f - '0']++;
    }

    ll ans = 0;
    ll base = 1;
    int cur = 0;
    for (int i = m - 1; i > 0; i--) {
        for (int j = 0; j < cnt[i]; j++) {
            ll val = C(n - cur, j) * base;
            for (int k = 0; k < n - cur - j; k++) val *= i;
            ans += val;
        }
        base *= C(n - cur, cnt[i]);
        cur += cnt[i];

    }

    string ts;
    for (int i = 0; i < m; i++) {
        while (cnt[i] > 0) {
            ts += char('0' + i);
            cnt[i]--;
        }
    }

    vector<string> A;
    do {
        A.push_back(ts);
    } while (next_permutation(all(ts)));

    reverse(all(s));
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == s) ans += i;
    }

    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
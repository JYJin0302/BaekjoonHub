#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

ll gcd(ll a, ll b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}

ll fastPow(ll b, ll ex, ll m) {
    ll res = 1;
    while (ex) {
        if (ex & 1) res = res * b % m;
        b = b * b % m;
        ex >>= 1;
    }
    return res;
}

void solve() {

    int n;
    cin >> n;

    vector<int> cnt(70);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;

        if (x == 0) continue;
        ll tx = log2(x);
        cnt[tx]++;
    }

    ll ans = 0;
    for (int i = 0; i < 63; i++) {
        if (cnt[i] != 0) ans = powl(2, i);

        cnt[i + 1] += cnt[i] / 2;

    }
    cout << ans;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

}
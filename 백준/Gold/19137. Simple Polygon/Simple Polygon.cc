#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    ll l, s;
    cin >> l >> s;
    if (l & 1) {
        cout << -1;
        return;
    }

    l >>= 1;
    ll mx = (l / 2) * ((l + 1) / 2);
    if (mx < s || s < l-1) {
        cout << -1;
        return;
    }

    int a = l / 2, b = l - a;

    if (mx == s) {
        cout << 4 << '\n';
        cout << 0 << ' ' << 0 << '\n';
        cout << a << ' ' << 0 << '\n';
        cout << a << ' ' << b << '\n';
        cout << 0 << ' ' << b << '\n';
        return;
    }

    ll rm = mx - s;
    ll d = rm / (b - 1);
    ll r = rm % (b - 1);
    if (r == 0) {
        cout << 6 << '\n';
        cout << 0 << ' ' << 0 << '\n';
        cout << a << ' ' << 0 << '\n';
        cout << a << ' ' << 1 << '\n';
        cout << a - d << ' ' << 1 << '\n';
        cout << a - d << ' ' << b << '\n';
        cout << 0 << ' ' << b << '\n';
        return;
    }
    if (d == 0) {
        cout << 6 << '\n';
        cout << 0 << ' ' << 0 << '\n';
        cout << a << ' ' << 0 << '\n';
        cout << a << ' ' << b - r << '\n';
        cout << a - 1 << ' ' << b - r << '\n';
        cout << a - 1 << ' ' << b << '\n';
        cout << 0 << ' ' << b << '\n';
        return;
    }
    cout << 8 << '\n';
    cout << 0 << ' ' << 0 << '\n';
    cout << a << ' ' << 0 << '\n';
    cout << a << ' ' << 1 << '\n';
    cout << a - d << ' ' << 1 << '\n';
    cout << a - d << ' ' << b - r << '\n';
    cout << a - d - 1 << ' ' << b - r << '\n';
    cout << a - d - 1 << ' ' << b << '\n';
    cout << 0 << ' ' << b << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {
    
    ll x, y, a, b, c, d;
    cin >> x >> y >> a >> b >> c >> d;

    if (a >= y) {
        cout << "NARUTO\n";
        return;
    }

    bool b1 = 0, b2 = 0;
    b1 = a > d;
    b2 = c > b;

    if (!b1 && !b2) {
        cout << "DRAW\n";
        return;
    }
    if (b1 && c < b) {
        cout << "NARUTO\n";
        return;
    }
    if (a < d && b2) {
        cout << "SASUKE\n";
        return;
    }

    // 공격 only
    ll t1 = (y + a - 1) / a;
    ll t2 = (x + c - 1) / c;
    if (t1 <= t2 && a > d) cout << "NARUTO\n";
    else if (t1 > t2 && c > b) cout << "SASUKE\n";
    else cout << "DRAW\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
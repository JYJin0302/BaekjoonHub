#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll gcd(ll a, ll b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}



int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    ll x0, y0;
    cin >> x0 >> y0;

    int n;
    cin >> n;

    int ans = 0;
    map<pair<ll, ll>, int> cnt;

    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;

        if (y >= y0 || x == x0) continue;

        x -= x0, y = y0 - y;

        x *= abs(x);
        ll gd = gcd(abs(x), abs(y));
        x /= gd, y /= gd;

        cnt[{x, y}]++;
        ans = max(ans, cnt[{x, y}]);
    }

    cout << ans;
}
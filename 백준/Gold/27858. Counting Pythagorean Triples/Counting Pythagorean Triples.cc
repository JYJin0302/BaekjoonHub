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

    ll c;
    cin >> c;

    vector<ll> ans(4);

    for (ll i = 3; i <= c; i++) {
        ll b = sqrtl(c * c - i * i);

        if (b > i && i * i + b * b == c*c) {
            ll g = gcd(i, b);
            g = gcd(g, c);
            if (g == 1) ans[0]++;
            else ans[1]++;
        }
    }

    for (ll i = c + 1; i <= 3125001; i++) {
        ll b = sqrt(i * i - c * c);
        if (c * c + b * b == i * i) {
            ll g = gcd(i, b);
            g = gcd(g, c);
            if (g == 1) ans[2]++;
            else ans[3]++;
        }
    }

    for (int i = 0; i < 4; i++) cout << ans[i] << ' ';

}
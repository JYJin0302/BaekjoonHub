#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1e9 + 7;
ll fastPow(ll b, ll ex) {
    ll res = 1;
    while (ex) {
        if (ex % 2) res = res * b % mod;
        b = b * b % mod;
        ex /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;


    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        a = a * b % mod;

        ans += fastPow(2, b - 1) * a % mod;
        ans %= mod;
    }

    cout << ans;
}
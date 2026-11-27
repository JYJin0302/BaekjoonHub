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

    ll l, n, rf, rb;
    cin >> l >> n >> rf >> rb;

    priority_queue<pair<ll, ll>> pq;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;

        pq.push({ b, a });
    }

    ll ans = 0, p = 0;
    while (!pq.empty()) {
        ll a, b;
        tie(a, b) = pq.top();
        pq.pop();

        if (b < p) continue;

        ans += a * (rf - rb) * (b - p);
        p = b;
    }

    cout << ans;
}
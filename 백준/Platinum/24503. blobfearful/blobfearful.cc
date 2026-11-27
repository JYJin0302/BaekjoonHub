#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll gcd(ll a, ll b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll k, q;
    cin >> k >> q;

    vector<pair<ll, ll>> p;
    ll tk = k;
    for (ll i = 2; i * i <= tk; i++) {
        if (tk % i == 0) {
            int cnt = 0;
            while (tk % i == 0) {
                cnt++;
                tk /= i;
            }
            p.push_back({ i, cnt });

        }
    }
    if (tk > 1) p.push_back({ tk, 1 });

    ll n = p.size();
    vector<vector<ll>> table(n);
    for (ll i = 0; i < n; i++) {

        ll b = p[i].first;
        vector<ll> tmp = { 1 };
        while (tmp.back() < p[i].second) {
            b += p[i].first;

            ll cnt = 0, tb = b;
            while (tb % p[i].first == 0) {
                cnt++, tb /= p[i].first;
            }
            tmp.push_back(tmp.back() + cnt);
        }
        table[i] = tmp;
    }

    map<ll, ll> ans;

    while(q--){

        ll x; 
        cin >> x;

        ll m = gcd(k, x);

        if (ans[m] != 0) {
            cout << ans[m] << ' ';
            continue;
        }
        ll tans = 1;
        for (int i = 0; i < n; i++) {
            ll v = p[i].second;
            while (m % p[i].first == 0) {
                v--;
                m /= p[i].first;
            }

            if (v == 0) continue;

            ll ix = lower_bound(table[i].begin(), table[i].end(), v) - table[i].begin();
            tans = max(tans, p[i].first * (ix + 1));

        }

        ans[gcd(k, x)] = tans;
        cout << tans << ' ';
    }
}
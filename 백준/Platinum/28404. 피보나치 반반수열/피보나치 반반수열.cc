#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll, ll> rev, ans;
vector<ll> f = { 1 };
map<ll, ll> tcnt;

ll solve(ll n) {
    if (ans[n] != 0) return ans[n];
    if (rev[n] == 0) {

        ll tmp = lower_bound(f.begin(), f.end(), n) - f.begin() - 1;
        int cnt = tcnt[f[tmp]];

        cnt ^= (n - f[tmp]) % 2;
        if (cnt == 1) {
            ll res = n + 1;
            if (rev[res] != 0) res++;
            return res;
        }
        else {
            ll res = n - 1;
            if (rev[res] != 0) res--;
            if (res >= f.size() || f[res] > 1e18) res = -1;
            else res = f[res];
            return res;
        }
    }

    ll res = solve(rev[n]);

    if (res == -1 || res >= f.size() || f[res] > 1e18) return -1;
    return f[res];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a = 1, b = 1;
    int cnt = 0, pv = 0;
    while (cnt <= 89) {
        cnt++;
        rev[a] = cnt;
        f.push_back(a);

        //Sleep(10);
        //cout << a << ' ' << tcnt[a] << '\n';
        ll tmp = a + b;
        if (tmp >= 5) {
            tcnt[tmp] = pv ^ ((b - 1) % 2);
            pv = tcnt[tmp];
        }
        b = a;
        a = tmp;

    }

    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 3;
    ans[4] = 6;
    ans[5] = 13;
    ans[6] = 5;

    int t;
    cin >> t;
    while (t--) {

        ll x;
        cin >> x;

        ll res = solve(x);
        if (res > 1e18) res = -1;
        cout << res << '\n';
    }
}
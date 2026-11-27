#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


pair<ll, ll> getVal(ll l, ll r, vector<ll>& v, vector<ll>& sv) {

    pair<ll, ll> res = mp(1e18, 0);

    ll v1 = 0, v2 = 0;
    auto ix = lower_bound(all(v), l) - v.begin();
    if (ix) {
        v1 += ix * l - sv[ix - 1];
    }
    ix = upper_bound(all(v), l) - v.begin();
    if (ix != v.size()) {
        v1 += sv.back() - sv[ix - 1] - (0ll + v.size() - ix) * l;
    }

    ix = lower_bound(all(v), r) - v.begin();
    if (ix) {
        v2 += ix * r - sv[ix - 1];
    }
    ix = upper_bound(all(v), r) - v.begin();
    if (ix != v.size()) {
        v2 += sv.back() - sv[ix - 1] - (0ll + v.size() - ix) * r;
    }

    res = min(mp(v1, l), mp(v2, r));
    while (l <= r) {
        ll m1 = (l * 2 + r) / 3;
        ll m2 = (l + r * 2) / 3;

        ll val1 = 0, val2 = 0;

        auto ix = lower_bound(all(v), m1) - v.begin();
        if (ix) {
            val1 += ix * m1 - sv[ix - 1];
        }
        ix = upper_bound(all(v), m1) - v.begin();
        if (ix != v.size()) {
            val1 += sv.back() - sv[ix - 1] - (0ll + v.size() - ix) * m1;
        }

        ix = lower_bound(all(v), m2) - v.begin();
        if (ix) {
            val2 += ix * m2 - sv[ix - 1];
        }
        ix = upper_bound(all(v), m2) - v.begin();
        if (ix != v.size()) {
            val2 += sv.back() - sv[ix - 1] - (0ll + v.size() - ix) * m2;
        }

        if (val1 <= val2) {
            res = min(res, mp(val1, m1));
            r = m2 - 1;
        }
        else {
            res = min(res, mp(val2, m2));
            l = m1 + 1;
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {

        int n;
        cin >> n;

        vector<pair<ll, ll>> L, R;

        vector<ll> xpos, ypos;
        for (int f = 0; f < n; f++) {
            ll x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            L.push_back(mp(x1, y1));
            R.push_back(mp(x2, y2));

            for (int tx = x1; tx <= x2; tx++) {
                for (int ty = y1; ty <= y2; ty++) {
                    xpos.push_back(tx);
                    ypos.push_back(ty);
                }
            }
        }

        sort(all(xpos));
        sort(all(ypos));

        vector<ll> sX, sY;
        ll v = 0;
        for (auto f : xpos) {
            sX.push_back(v += f);
        }
        v = 0;
        for (auto f : ypos) {
            sY.push_back(v += f);
        }

        pair<ll ,pair<ll, ll>> ans= mp(1e18, mp(0, 0));
        for (int j = 0; j < n; j++) {

            ll val = 0;
            ll ax = 0, ay = 0;

            auto [u, v] = getVal(L[j].x, R[j].x, xpos, sX);
            val += u;
            ax = v;

            auto [u2, v2] = getVal(L[j].y, R[j].y, ypos, sY);
            val += u2;
            ay = v2;

            if (ans.x > val) {
                ans = mp(val, mp(ax, ay));
            }
            else if (ans.x == val) {
                ans.y = min(ans.y, mp(ax, ay));
            }
        }

        cout << "Case #" << i << ": " << ans.y.x << ' ' << ans.y.y << ' ' << ans.x << '\n';
    }
}
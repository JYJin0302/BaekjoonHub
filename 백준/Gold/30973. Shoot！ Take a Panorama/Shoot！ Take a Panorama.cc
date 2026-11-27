#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair


void solve() {

    int n;
    cin >> n;

    ll xl, xr, yl, yr;
    cin >> xl >> yl >> xr >> yr;

    vector<pair<ll, pair<ll, ll>>> tree;
    for (int i = 0; i < n; i++) {
        ll x, y, l;
        cin >> x >> y >> l;

        tree.push_back(mp(l, mp(x, y)));
    }

    ll ans = 5e18;

    // up
    ll tl = xl - 1, tr = xr + 1;
    while (tl <= tr) {

        ll md1 = (tl * 2 + tr + (tl * 2 + tr >= 0 ? 0 : -2)) / 3;
        ll md2 = (tl + tr * 2 + (tl + tr * 2 >= 0 ? 0 : -2)) / 3;

        // (md1, yr+1)

        ll totCost = 0;
        for (int i = 0; i < n; i++) {
            totCost += tree[i].first * ((md1 - tree[i].second.first) * (md1 - tree[i].second.first) + \
                (yr + 1 - tree[i].second.second) * (yr + 1 - tree[i].second.second));
        }
        ll totCost2 = 0;
        for (int i = 0; i < n; i++) {
            totCost2 += tree[i].first * ((md2 - tree[i].second.first) * (md2 - tree[i].second.first) + \
                (yr + 1 - tree[i].second.second) * (yr + 1 - tree[i].second.second));
        }
        ans = min({ ans, totCost, totCost2 });
        
        if (totCost < totCost2) tr = md2 - 1;
        else tl = md1 + 1;
    }
    // down
    tl = xl - 1, tr = xr + 1;
    while (tl <= tr) {

        ll md1 = (tl * 2 + tr + (tl * 2 + tr >= 0 ? 0 : -2)) / 3;
        ll md2 = (tl + tr * 2 + (tl + tr * 2 >= 0 ? 0 : -2)) / 3;

        //cout << md1 << ' ' << md2 << '\n';
        // (md1, yr+1)

        ll totCost = 0;
        for (int i = 0; i < n; i++) {
            totCost += tree[i].first * ((md1 - tree[i].second.first) * (md1 - tree[i].second.first) + \
                (yl - 1 - tree[i].second.second) * (yl - 1 - tree[i].second.second));
        }
        ll totCost2 = 0;
        for (int i = 0; i < n; i++) {
            totCost2 += tree[i].first * ((md2 - tree[i].second.first) * (md2 - tree[i].second.first) + \
                (yl - 1 - tree[i].second.second) * (yl - 1 - tree[i].second.second));
        }
        ans = min({ ans, totCost, totCost2 });

        if (totCost < totCost2) tr = md2 - 1;
        else tl = md1 + 1;
    }

    // left
    tl = yl - 1, tr = yr + 1;
    while (tl <= tr) {

        ll md1 = (tl * 2 + tr + (tl * 2 + tr >= 0 ? 0 : -2)) / 3;
        ll md2 = (tl + tr * 2 + (tl + tr * 2 >= 0 ? 0 : -2)) / 3;

        // (xl-1, md1)

        ll totCost = 0;
        for (int i = 0; i < n; i++) {
            totCost += tree[i].first * ((xl-1 - tree[i].second.first) * (xl-1 - tree[i].second.first) + \
                (md1 - tree[i].second.second) * (md1 - tree[i].second.second));
        }
        ll totCost2 = 0;
        for (int i = 0; i < n; i++) {
            totCost2 += tree[i].first * ((xl - 1 - tree[i].second.first) * (xl - 1 - tree[i].second.first) + \
                (md2 - tree[i].second.second) * (md2 - tree[i].second.second));
        }
        ans = min({ ans, totCost, totCost2 });

        if (totCost < totCost2) tr = md2 - 1;
        else tl = md1 + 1;
    }
    // down
    tl = yl - 1, tr = yr + 1;
    while (tl <= tr) {
        ll md1 = (tl * 2 + tr + (tl * 2 + tr >= 0 ? 0 : -2)) / 3;
        ll md2 = (tl + tr * 2 + (tl + tr * 2 >= 0 ? 0 : -2)) / 3;

        // (xr+1, md1)

        ll totCost = 0;
        for (int i = 0; i < n; i++) {
            totCost += tree[i].first * ((xr + 1 - tree[i].second.first) * (xr + 1 - tree[i].second.first) + \
                (md1 - tree[i].second.second) * (md1 - tree[i].second.second));
        }
        ll totCost2 = 0;
        for (int i = 0; i < n; i++) {
            totCost2 += tree[i].first * ((xr + 1 - tree[i].second.first) * (xr + 1 - tree[i].second.first) + \
                (md2 - tree[i].second.second) * (md2 - tree[i].second.second));
        }
        ans = min({ ans, totCost, totCost2 });

        if (totCost < totCost2) tr = md2 - 1;
        else tl = md1 + 1;
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

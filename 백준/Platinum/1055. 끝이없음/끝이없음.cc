#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

string base, expr;
ll sz[105];

void getAns(int t, ll l, ll r) {
    //cout << "Go: " << t << ' ' << l << ' ' << r << '\n';
    if (t == 0) {
        ll n = base.size();
        for (int i = l; i <= min(n-1, r); i++) cout << base[i];
        for (int i = n; i <= r; i++) cout << '-';
        return;
    }

    int cur = 0;
    for (int i = 0; i < expr.size() && l <= r; i++) {
        if (expr[i] == '$') {
            cur += sz[t - 1];
            if (cur > r) {
                getAns(t - 1, l-cur+sz[t-1], r-cur+sz[t-1]);
                return;
            }
            if (cur > l) {
                getAns(t - 1, l-cur+sz[t-1], sz[t-1] - 1);
                l = cur;
            }
        }
        else {
            cur++;
            if (cur > l) {
                cout << expr[i];
                l++;
            }
        }
    }
    for (int i = cur; i <= r; i++) cout << '-';

}

void solve() {
    cin >> base >> expr;

    int t, l, r;
    cin >> t >> l >> r;
    l--, r--;

    int cnt = 0;
    for (auto f : expr) if (f == '$') cnt++;

    if (cnt == 1) {

        for (int i = l; i <= min(r, (int)base.size()-1); i++) {
            cout << base[i];
            l++;
        }

        int tn = expr.size();
        ll sz = base.size() + (ll)t * (expr.size() - 1);

        for (int i = l; i < min(r+1ll, sz); i++) {
            cout << expr[(i- base.size()) % (tn-1) + 1];
            l++;
        }
        for (int i = l; i <= r; i++) cout << '-';

        return;
    }

    sz[0] = base.size();
    for (int i = 1; i <= t; i++) {
        sz[i] = sz[i - 1] * cnt + expr.size() - cnt;
        if (sz[i] > r) {
            sz[i] = r+10;
            t = i;
            break;
        }
    }

    if (l >= sz[t]) {
        cout << string(r - l + 1, '-');
        return;
    }

    getAns(t, l, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}

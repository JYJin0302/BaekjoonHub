#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int n, m;
ll seg[404040];
void update(int ix, ll val) {
    for (ix += n; ix; ix >>= 1) {
        seg[ix] += val;
    }
}

ll getSum(int l, int r) {
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res += seg[l++];
        if (r & 1) res += seg[--r];
    }
    return res;
}

void solve() {

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        update(i, x);
    }

    int l = 0;
    while (m--) {
        int t, a, b;
        cin >> t;
        if (t == 1) {
            cin >> a;
            l = (l - a + n) % n;
        }
        else if (t == 2) {
            cin >> a;
            l = (l + a) % n;
        }
        else {
            cin >> a >> b;
            a--, b--;

            int tl = a + l;
            int tr = b + l;

            ll res = 0;
            if (tl >= n) {
                res += getSum(tl - n, tr - n + 1);
            }
            else if (tr < n) {
                res += getSum(tl, tr + 1);
            }
            else {
                res += getSum(tl, n) + getSum(0, tr - n + 1);
            }
            cout << res << '\n';
        }

    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
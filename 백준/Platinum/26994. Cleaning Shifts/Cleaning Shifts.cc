#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

const ll INF = 1e16;
int MAXN = 100000;
ll seg[202020];
void update(int ix, ll val) {
    for (ix += MAXN; ix; ix >>= 1) {
        seg[ix] = min(seg[ix], val);
    }
}

ll getMin(int l, int r) {
    ll res = INF;
    for (l += MAXN, r += MAXN; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = min(res, seg[l++]);
        if (r & 1) res = min(res, seg[--r]);
    }
    return res;
}

void solve() {

    ll n, l, r;
    cin >> n >> l >> r;
    l++, r++;
    vector<pair<pair<ll, ll>, ll>> A;
    for (int i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a++, b++;
        A.push_back(mp(mp(a, b), c));
    }
    sort(all(A));
    for (int i = 0; i <= MAXN * 2; i++) seg[i] = INF;
    update(l - 1, 0);

    for (auto& f : A) {
        auto& [a, b] = f.first;
        ll val = f.second;

        ll mv = getMin(a - 1, r + 1);

        if (mv == INF) {
            cout << -1 << '\n';
            return;
        }
        update(b, mv + val);
    }

    cout << getMin(r, r + 1);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const ll INF = 1e18;
ll n;
ll segL[2002020], segR[2002020];

void update(int ix, ll val, ll seg[]) {
    seg[ix + n] = val;
    for (ix += n; ix > 1; ix >>= 1) {
        seg[ix >> 1] = max(seg[ix], seg[ix^1]);
    }
}

ll getVal(int l, int r, ll seg[]) {
    ll res = -INF;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = max(res, seg[l++]);
        if (r & 1) res = max(res, seg[--r]);
    }
    return res;
}

void solve() {
    

    cin >> n;
    vector<ll> A(n);
    for (auto& i : A) cin >> i;

    vector<pair<ll, ll>> pos(n);
    for (int i = 0; i < n; i++) pos[i] = mp(A[i], i);
    sort(all(pos));

    ll ans = 0;
    for (int i = 0; i < n; i++) ans += abs(A[i] - i - 1);
    ll md = 0;

    for (int i = 0; i < n * 2 + 10; i++) segL[i] = segR[i] = -INF;
    for (int i = 1; i <= n; i++) {
        update(i, A[i - 1] - i - abs(A[i - 1] - i), segL); // A[i] >= j
        update(i, A[i - 1] + i - abs(A[i - 1] - i), segR); // A[i] <= j
    }

    for (int i = 0; i < n; i++) {
        ll res = -INF;
        ll v = A[i];
        ll C = -abs(A[i] - i - 1) - i - 1;
        res = max(res, getVal(v, n + 1, segR) - v);
        res = max(res, getVal(1, v + 1, segL) + v);
        md = max(md, res + C);

        update(pos[i].y + 1, -INF, segL);
        update(pos[i].y + 1, -INF, segR);
    }

    //cout << ans << ' ' << md << '\n';


    for (int i = 0; i < n * 2 + 10; i++) segL[i] = segR[i] = -INF;
    for (int i = 1; i <= n; i++) {
       // update(i, -A[i - 1] - i - abs(A[i - 1] - i), segL);
        //update(i, -A[i - 1] + i - abs(A[i - 1] - i), segR);
    }

    for (int i = 0; i < n; i++) {
        ll res = -INF;
        ll v = A[i];
        ll C = -abs(A[i] - i - 1) + i + 1;
        res = max(res, getVal(v, n + 1, segR) - v);
        res = max(res, getVal(1, v + 1, segL) + v);
        md = max(md, res + C);

        int ix = pos[i].y;
        update(ix + 1, -A[ix] - (ix + 1) - abs(A[ix] - ix - 1), segL);
        update(ix + 1, -A[ix] + (ix + 1) - abs(A[ix] - ix - 1), segR);
    }

    cout << ans + md << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
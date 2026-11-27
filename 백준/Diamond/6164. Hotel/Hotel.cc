#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

struct D {
    int l, r, mx, len;
    D(int val = 0) {
        l = r = mx = val;
        len = 1;
    }

    D operator+(D & o) {
        D res;
        res.l = l;
        if (res.l == len) res.l += o.l;
        res.r = o.r;
        if (res.r == o.len) res.r += r;
        res.mx = max({ mx, o.mx, r + o.l });
        res.len = len + o.len;
        return res;
    }

    void pf() {
        cout << l << ' ' << r << ' ' << mx << ' ' << len << '\n';
    }
};

int n, m;
D seg[202020];
int lazy[202020];

void goLazy(int l, int r, int n) {
    if (lazy[n] == -1) return;
    if (lazy[n] == 0) {
        seg[n] = D();
        seg[n].len = r - l + 1;
    }
    else {
        seg[n] = D(r - l + 1);
        seg[n].len = r - l + 1;
    }

    if (l != r) {
        lazy[n * 2] = lazy[n * 2 + 1] = lazy[n];
    }
    lazy[n] = -1;
}

void init(int l, int r, int n) {

    seg[n].len = r - l + 1;
    if (l == r) {
        return;
    }
    int md = (l + r) >> 1;
    init(l, md, n * 2);
    init(md + 1, r, n * 2 + 1);

}

void update(int l, int r, int n, int sl, int sr, int val) {
    goLazy(l, r, n);
    if (l > sr || r < sl) return;
    if (l >= sl && r <= sr) {
        lazy[n] = val;
        goLazy(l, r, n);
        return;
    }

    int md = (l + r) >> 1;
    update(l, md, n * 2, sl, sr, val);
    update(md + 1, r, n * 2 + 1, sl, sr, val);
    seg[n] = seg[n * 2] + seg[n * 2 + 1];
}


int getIdx(int l, int r, int n, int val, int tl = 0) {
    goLazy(l, r, n);
    //cout << "Go: " << l << ' ' << r << ' ' << n << ' ' << tl << " | ";
   // seg[n].pf();

    if (seg[n].mx < val && tl + seg[n].l < val) return -1;
    if (l == r) return l;

    int md = (l + r) >> 1;
    int t1 = getIdx(l, md, n * 2, val, tl);
    if (t1 != -1) return t1;

    int nl = 0;
    if (seg[n * 2].r == seg[n * 2].len) nl = tl + seg[n * 2].len;
    else nl = seg[n * 2].r;
    return getIdx(md + 1, r, n * 2 + 1, val, nl);
}


void solve() {

    
    cin >> n >> m;

    memset(lazy, -1, sizeof(lazy));
    int sn = 1;
    while (sn < n)sn *= 2;

    init(0, sn - 1, 1);
    update(0, sn - 1, 1, 0, n - 1, 1);
    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int val;
            cin >> val;
            int ix = getIdx(0, sn - 1, 1, val);

            if (ix != -1) {
                cout << ix + 1 - val + 1 << '\n';
                update(0, sn - 1, 1, ix -val + 1, ix, 0);
            }
            else cout << 0 << '\n';
        }
        else {
            int x, d;
            cin >> x >> d;
            x--;
            update(0, sn - 1, 1, x, x + d - 1, 1);
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
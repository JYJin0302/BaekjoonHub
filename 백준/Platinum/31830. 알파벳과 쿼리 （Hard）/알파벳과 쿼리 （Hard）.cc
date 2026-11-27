#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n, q;
string s;
struct D {
    int l = -1, r = -1, cnt = 1;
};

D seg[704040];
int lazy[704040];

void goLazy(int l, int r, int n) {
    if (lazy[n]) {
        D& cur = seg[n];
        cur.l = (cur.l + lazy[n]) % 26;
        cur.r = (cur.r + lazy[n]) % 26;
        if (l != r) {
            (lazy[n * 2] += lazy[n]) %= 26;
            (lazy[n * 2 + 1] += lazy[n]) %= 26;
        }
        lazy[n] = 0;
    }
}

D merge(D& d1, D& d2) {
    if (d2.l == -1) return d1;
    if (d1.l == -1) return d2;
    D ret;
    ret.l = d1.l;
    ret.r = d2.r;
    ret.cnt = d1.cnt + d2.cnt;
    if (d1.r == d2.l) {
        ret.cnt--;
    }
    return ret;
}
void update(int l, int r, int n, int sl, int sr, bool init = 0) {
    goLazy(l, r, n);
    if (r < sl || l > sr) return;
    if (l >= sl && r <= sr) {
        if (init) {
            seg[n] = { s[sl] - 'A', s[sr] - 'A', 1 };
        }
        else {
            lazy[n]++;
            goLazy(l, r, n);
        }
        return;
    }

    int md = (l + r) >> 1;
    update(l, md, n * 2, sl, sr, init);
    update(md + 1, r, n * 2 + 1, sl, sr, init);
    seg[n] = merge(seg[n * 2], seg[n * 2 + 1]);
}

D getVal(int l, int r, int n, int sl, int sr) {
    goLazy(l, r, n);
    if (r < sl || l > sr) return D();
    if (l >= sl && r <= sr) {
        return seg[n];
    }

    int md = (l + r) >> 1;
    D d1 = getVal(l, md, n * 2, sl, sr);
    D d2 = getVal(md + 1, r, n * 2 + 1, sl, sr);
    seg[n] = merge(seg[n * 2], seg[n * 2 + 1]);
    return merge(d1, d2);
}

void solve() {

    cin >> n >> q;
    cin >> s;
    int sn = 1;
    while (sn < n) {
        sn *= 2;
    }

    for (int i = 1; i < sn * 2; i++) {
        seg[i] = D();
    }

    for (int i = 0; i < n; i++) {
        update(0, sn - 1, 1, i, i, 1);
    }
    while (q--) {

        int t, l, r;
        cin >> t >> l >> r;
        l--, r--;
        if (t == 1) {
            D ret = getVal(0, sn - 1, 1, l, r);
            cout << ret.cnt << '\n';
        }
        else {
            update(0, sn - 1, 1, l, r);
        }

        //for (int j = 1; j < sn * 2; j++) {
        //    cout << "(" << seg[j].l << ' ' << seg[j].r << " | " << seg[j].cnt << ") ";
        //}
        //cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
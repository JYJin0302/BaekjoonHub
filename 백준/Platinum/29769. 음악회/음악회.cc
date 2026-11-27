#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

struct Node {

    int lval, lcnt;
    int rval, rcnt;
    int tval, tcnt, tdx;

    Node() {
        lval = rval = tval = -1e9;
        lcnt = rcnt = tcnt = 0;
        tdx = -1;
    }

    Node(int _lv, int _lc, int _rv, int _rc, int _tv, int _tc, int _tx) : \
        lval(_lv), lcnt(_lc), rval(_rv), rcnt(_rc), tval(_tv), tcnt(_tc), tdx(_tx) {}

};

Node seg[1111111];

void update(int l, int r, int n, int u, int v) {
    if (l > u || r < u) return;
    if (l == u && r == u) {
        seg[n] = { v, 1, v, 1, v, 1, l };
        return;
    }

    int md = (l + r) >> 1;
    update(l, md, n * 2, u, v);
    update(md + 1, r, n * 2 + 1, u, v);

    // merge

    int lval = seg[n * 2].lval;
    int lcnt = seg[n * 2].lcnt;
    if (lcnt == md - l + 1 && seg[n * 2 + 1].lval == lval) lcnt += seg[n * 2 + 1].lcnt;

    int rval = seg[n * 2 + 1].rval;
    int rcnt = seg[n * 2 + 1].rcnt;
    if (rcnt == r - md && seg[n * 2].rval == rval) rcnt += seg[n * 2].rcnt;

    vector<pair<pair<int, int>, int>> tmp;
    tmp.push_back(mp(mp(lval, lcnt), -l));
    tmp.push_back(mp(mp(rval, rcnt), -(r - rcnt+1)));
    tmp.push_back(mp(mp(seg[n * 2].tval, seg[n * 2].tcnt), -seg[n * 2].tdx));
    tmp.push_back(mp(mp(seg[n * 2 + 1].tval, seg[n * 2 + 1].tcnt), -seg[n * 2 + 1].tdx));
    if (seg[n * 2].rval == seg[n * 2 + 1].lval) {
        tmp.push_back(mp(mp(seg[n * 2].rval, seg[n * 2].rcnt + seg[n * 2 + 1].lcnt), -(md - seg[n * 2].rcnt + 1)));
    }

    pair<pair<int, int>, int> res = *max_element(tmp.begin(), tmp.end());
    seg[n] = Node(lval, lcnt, rval, rcnt, res.first.first, res.first.second, -res.second);

   // cout << "upd: " << ' ' << l << ' ' << r << '\n';
   // cout << seg[n].lval << ' ' << seg[n].lcnt << ' ' << seg[n].rval << ' ' << seg[n].rcnt << ' ' << seg[n].tval << ' ' << seg[n].tcnt << ' ' << seg[n].tdx << '\n';
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int sn = 1;
    while (sn < n) sn *= 2;


    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        update(0, sn - 1, 1, i, x);

        //seg[sn + i] = { x, 1, x, 1, x, 1, i };
    }

    int q;
    cin >> q;
    while (q--) {

        int a, b;
        cin >> a >> b;
        a--;
        update(0, sn - 1, 1, a, b);

      //  cout << seg[1].tval << ' ' << seg[1].tcnt << ' ' << seg[1].tdx << '\n';
        cout << seg[1].tdx + 1 << ' ' << seg[1].tdx + seg[1].tcnt << '\n';


    }

}
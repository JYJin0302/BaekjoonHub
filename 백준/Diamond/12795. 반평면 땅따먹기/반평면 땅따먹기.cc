#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define mp make_pair
#define all(x) x.begin(), x.end()

const ll INF = 2e18;

struct Line {
    ll a, b;
    // y = ax + b
    Line(ll _a = 0, ll _b = -INF) : a(_a), b(_b) {}
    ll val(ll x) { return a * x + b; }
};

struct Node {
    int l, r;
    Line cur;
    Node(Line init = Line()) {
        l = r = -1;
        cur = init;
    }
};

vector<Node> seg;

void update(int pos, Line u, ll l = -1e12, ll r = 1e12) {
    Line dw = seg[pos].cur, up = u;
    if (dw.val(l) > up.val(l)) swap(dw, up);
    
    if (dw.val(r) <= up.val(r)) {
        seg[pos].cur = up;
        return;
    }

    ll md = (l + r) >> 1;
    if (up.val(md) >= dw.val(md)) {
        seg[pos].cur = up;
        if (seg[pos].r == -1) {
            seg[pos].r = seg.size();
            seg.push_back(Node());
        }
        update(seg[pos].r, dw, md + 1, r);
    }
    else {
        seg[pos].cur = dw;
        if (seg[pos].l == -1) {
            seg[pos].l = seg.size();
            seg.push_back(Node());
        }
        update(seg[pos].l, up, l, md);
    }
}

ll getMax(int pos, ll v, ll l = -1e12, ll r = 1e12) {
    if (pos == -1) return -INF;
    ll md = (l + r) >> 1;

    if (v <= md) {
        return max(getMax(seg[pos].l, v, l, md), seg[pos].cur.val(v));
    }
    else {
        return max(getMax(seg[pos].r, v, md+1, r), seg[pos].cur.val(v));
    }

}

void solve() {
    int n;
    cin >> n;

    seg.push_back(Node());

    ll x, y;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        if (t == 1) {
            cin >> x >> y;
            Line tmp(x, y);
            update(0, tmp);
        }
        else {
            cin >> x;
            cout << getMax(0, x) << '\n';
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //  cin >> t;
    while (t--) {
        solve();
    }
}
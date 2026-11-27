#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second
struct D {
    int x, y;
    int a, b;
    bool operator< (D& o) {
        return mp(x, y) < mp(o.x, o.y);
    }
};

int n;
ll ans = 0;
struct Node {
    ll L0, L1, R0, R1;
    ll s0, s1;
    ll val[4];

    Node() {
        L0 = L1 = R0 = R1 = 0;
        s0 = s1 = 0;
        memset(val, 0, sizeof val);
    }
};

Node merge(Node& d1, Node& d2) {
    Node ret;
    ret.L0 = max(d1.L0, d1.s0 + d2.L0);
    ret.L1 = max(d1.L1, d1.s1 + d2.L1);
    ret.R0 = max(d2.R0, d2.s0 + d1.R0);
    ret.R1 = max(d2.R1, d2.s1 + d1.R1);

    ret.s0 = d1.s0 + d2.s0; // ok
    ret.s1 = d1.s1 + d2.s1; // ok

    ret.val[1] = max({ d1.val[1], d1.s0 + d2.val[1], d1.val[3] + d2.L1 });
    ret.val[2] = max({ d2.val[2], d2.s1 + d1.val[2], d2.val[3] + d1.R0 });
    ret.val[3] = max({ d1.val[3] + d2.s1, d1.s0 + d2.val[3], d1.s0 + d2.s1 });
    ret.val[0] = max({ d1.val[0], d2.val[0], ret.val[1] ,ret.val[2], ret.val[3], d1.R0 + d2.val[1], d1.val[2] + d2.L1 });
    return ret;
}

vector<int> xpos, ypos;

Node seg[5050];
vector<D> A;

void update(int l, int r, int n, D& d) {
    if (r < d.y || l > d.y) return;
    if (l == d.y && r == d.y) {
        seg[n].s0 += d.a;
        seg[n].s1 += d.b;

        seg[n].L0 = seg[n].R0 = max(0ll, seg[n].s0);
        seg[n].L1 = seg[n].R1 = max(0ll, seg[n].s1);

        ll val = max(seg[n].L0, seg[n].L1);

        for (int i = 0; i < 3; i++) seg[n].val[i] = val;
        seg[n].val[3] = max(seg[n].s0, seg[n].s1);
        return;
    }

    int md = (l + r) >> 1;
    update(l, md, n * 2, d);
    update(md + 1, r, n * 2 + 1, d);

    seg[n] = merge(seg[n * 2], seg[n * 2 + 1]);
}


void goSolve() {
    sort(all(A));

    int sz = 1;
    while (sz < n) sz <<= 1;

    for (int i = 0; i < n; i++) {
        if (i && A[i].x == A[i - 1].x) continue;
        for (int j = 1; j < sz * 2; j++) seg[j] = Node();

        // update(A[i])
        int ix = i;
        while (ix < n) {
            int nx = ix;
            while (ix < n && A[ix].x == A[nx].x) {
                update(0, sz - 1, 1, A[ix]);
                ix++;
            }
            ans = max(ans, seg[1].val[0]);
        }
    }
}

void solve() {

    cin >> n;


    A = vector<D>(n);
    for (auto& i : A) {
        cin >> i.x >> i.y >> i.a >> i.b;
        xpos.push_back(i.x);
        ypos.push_back(i.y);
    }

    sort(all(xpos));
    sort(all(ypos));
    xpos.erase(unique(all(xpos)), xpos.end());
    ypos.erase(unique(all(ypos)), ypos.end());

    for (auto& i : A) {
        i.x = lower_bound(all(xpos), i.x) - xpos.begin();
        i.y = lower_bound(all(ypos), i.y) - ypos.begin();
    }

    goSolve();
    for (auto& i : A) {
        i.y = ypos.size() - i.y - 1;
    }
    goSolve();

    for (auto& i : A) {
        swap(i.x, i.y);
    }
    goSolve();

    for (auto& i : A) {
        i.y = xpos.size() - i.y - 1;
    }
    goSolve();

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //  cin >> t;
    while (t--) solve();
}
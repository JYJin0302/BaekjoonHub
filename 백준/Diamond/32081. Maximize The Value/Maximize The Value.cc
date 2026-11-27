#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const ll INF = 0x3f3f3f3f3f3f3f3f;


struct Q {
    int k, s, t;
    int idx;

    bool operator<(Q& o) {
        return k < o.k;
    }
};

struct Node {
    ll mx, mL, mR, tot;
    Node(ll x = 0) {
        mx = mL = mR = tot = x;
        if (x == -INF) {
            tot = 0;
        }
    }
    

    Node operator+(Node& o) {
        Node res;
        res.mx = max({ mx, o.mx, mR + o.mL });
        res.mL = max(mL, tot + o.mL);
        res.mR = max(o.mR, o.tot + mR);
        res.tot = tot + o.tot;
        return res;
    }
};

Node seg[303030];
void update(int l, int r, int n, int ix, int val) {
    if (l > ix || r < ix) return;
    if (l == ix && r == ix) {
        ll nval = seg[n].tot + val;
        seg[n] = Node(nval);
        return;
    }

    int md = (l + r) >> 1;
    update(l, md, n * 2, ix, val);
    update(md + 1, r, n * 2 + 1, ix, val);
    seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

Node getMax(int l, int r, int n, int sl, int sr) {
    if (l > sr || r < sl) return Node(-INF);
    if (l >= sl && r <= sr) return seg[n];

    int md = (l + r) >> 1;
    Node r1 = getMax(l, md, n * 2, sl, sr);
    Node r2 = getMax(md + 1, r, n * 2 + 1, sl, sr);
    return r1 + r2;
}

void solve() {

    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> A;
    for (int i = 0; i < m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        A.push_back(mp(l, mp(i, x)));
        A.push_back(mp(r + 1 , mp(i, -x)));
    }
    sort(all(A));

    int q;
    cin >> q;

    vector<Q> qur;
    for (int i = 0; i < q; i++) {
        int k, s, t;
        cin >> k >> s >> t;
        s--, t--;
        qur.push_back(Q(k, s, t, i));
    }
    sort(all(qur));

    int sn = 1;
    while (sn <= m) sn <<= 1;

    vector<ll> ans(q);
    int cur = 0;
    for (auto f : qur) {

        //cout << "GO: " << f.idx << '\n';
        while (cur < A.size() && A[cur].x <= f.k) {
            //cout << "w: " << cur << " | ";
            auto [a, b] = A[cur].y;
            //cout << a << " " << b << '\n';
            update(0, sn - 1, 1, a, b);
            cur++;
        }

        Node res = getMax(0, sn - 1, 1, f.s, f.t);
        ans[f.idx] = res.mx;
    }
    for (auto f : ans) cout << f << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}
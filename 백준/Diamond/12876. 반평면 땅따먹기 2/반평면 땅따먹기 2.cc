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
struct Q {
    Line line;
    int l, r;
};
ll todo[303030];
vector<Node> seg;
stack<pair<int, Line>> rec;

vector<Q> qSeg[1201010];
void update(int pos, Line u, ll l = -1e9, ll r = 1e9) {
    Line dw = seg[pos].cur, up = u;
    if (dw.val(l) > up.val(l)) swap(dw, up);
    
    if (dw.val(r) <= up.val(r)) {
        rec.push(mp(pos, seg[pos].cur));
        seg[pos].cur = up;
        return;
    }

    ll md = (l + r) >> 1;
    if (up.val(md) >= dw.val(md)) {
        rec.push(mp(pos, seg[pos].cur));
        seg[pos].cur = up;
        if (seg[pos].r == -1) {
            seg[pos].r = seg.size();
            seg.push_back(Node());
            rec.push(mp(-pos*2-2, Line()));
        }
        update(seg[pos].r, dw, md + 1, r);
    }
    else {
        rec.push(mp(pos, seg[pos].cur));
        seg[pos].cur = dw;
        if (seg[pos].l == -1) {
            seg[pos].l = seg.size();
            seg.push_back(Node());
            rec.push(mp(-pos*2-1, Line()));
        }
        update(seg[pos].l, up, l, md);
    }
}

ll getMax(int pos, ll v, ll l = -1e9, ll r = 1e9) {
    if (pos == -1) return -INF;
    ll md = (l + r) >> 1;

    if (v <= md) {
        return max(getMax(seg[pos].l, v, l, md), seg[pos].cur.val(v));
    }
    else {
        return max(getMax(seg[pos].r, v, md+1, r), seg[pos].cur.val(v));
    }
}

void insert(Q& cur, int n, int l, int r) {
    if (cur.l > r || cur.r < l) return;
    if (cur.l <= l && cur.r >= r) {
        qSeg[n].push_back(cur);
        return;
    }
    int md = (l + r) >> 1;
    insert(cur, n * 2, l, md);
    insert(cur, n * 2 + 1, md + 1, r);
}

ll ans[303030];
void solve(int n, int l, int r) {
    int cur = rec.size();
    for (const auto& f : qSeg[n]) {
        update(0, f.line);
    }

    if (l == r) {
        ll x = todo[l];
        ll res = getMax(0, x);
        ans[l] = res;
    }
    else {
        int md = (l + r) >> 1;
        solve(n * 2, l, md);
        solve(n * 2 + 1, md + 1, r);
    }

    while (rec.size() > cur) {
        ll v1 = rec.top().first;
        Line l1 = rec.top().second;
        rec.pop();

        if (v1 >= 0) {
            seg[v1].cur = l1;
        }
        else {
            v1 *= -1;
            ll tv = (v1-1) >> 1;
            if (v1 & 1) {
                seg[tv].l = -1;
                seg.pop_back();
            }
            else {
                seg[tv].r = -1;
                seg.pop_back();
            }
        }
    }

}

void solve() {
    int n;
    cin >> n;
    seg.push_back(Node());

    for (int i = 0; i < n; i++) todo[i] = -INF;

    vector<Q> qList;
    vector<int> idxI(n);
    map<pair<ll, ll>, int> idx;

    ll x, y;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        if (t == 1) {
            cin >> x >> y;
            Line tmp(x, y);
            idxI[i] = qList.size();
            qList.push_back({ tmp, i, n-1 });
        }
        else if (t == 2){
            cin >> x;
            x--;
            int ix = idxI[x];
            qList[ix].r = i;
        }
        else {
            cin >> x;
            todo[i] = x;
        }
    }

   // cout << "input end\n";
    for (auto& f : qList) {
        //cout << "Go: " << f.line.a << ' ' << f.line.b << " | " << f.l << ' ' << f.r << '\n';
        insert(f, 1, 0, n-1);
    }
    //cout << "insert end\n";

    solve(1, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if (todo[i] != -INF) {
            if (ans[i] == -INF) cout << "EMPTY\n";
            else cout << ans[i] << '\n';
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
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define mp make_pair
#define all(x) x.begin(), x.end()
struct seg2d {
    struct Node {
        int v, l, r;
        Node() { v = l = r = 0; }
    };
    int M, N, sz = 2;
    vector<int> L, R;
    vector<Node> t;
    vector<vector<Node>> seg;
    seg2d(int N, int M) :N(N), M(M) {
        L.resize(2); R.resize(2); t.resize(2);
        seg.resize(2, t);
    }
    void upd1(int x, int val, int l, int r, int ny, int nx) {
        if (l == r) {
            seg[ny][nx].v = val; return;
        }
        seg[ny][nx].v = max(seg[ny][nx].v, val);
        int mid = (l + r) >> 1;
        if (x <= mid) {
            if (seg[ny][nx].l == 0) {
                seg[ny].push_back(Node());
                seg[ny][nx].l = seg[ny].size() - 1;
            }
            upd1(x, val, l, mid, ny, seg[ny][nx].l);
        }
        else {
            if (seg[ny][nx].r == 0) {
                seg[ny].push_back(Node());
                seg[ny][nx].r = seg[ny].size() - 1;
            }
            upd1(x, val, mid + 1, r, ny, seg[ny][nx].r);
        }
    }
    void upd2(int y, int x, int val, int l, int r, int ny) {
        upd1(x, val, 0, N, ny, 1);
        if (l == r) { return; }
        int mid = (l + r) >> 1;
        if (y <= mid) {
            if (L[ny] == 0) {
                seg.push_back(t); L.push_back(0);
                R.push_back(0); ++sz;
                L[ny] = sz - 1;
            }
            upd2(y, x, val, l, mid, L[ny]);
        }
        else {
            if (R[ny] == 0) {
                seg.push_back(t); L.push_back(0);
                R.push_back(0); ++sz;
                R[ny] = sz - 1;
            }
            upd2(y, x, val, mid + 1, r, R[ny]);
        }
    }
    int query1(int x1, int x2, int l, int r, int ny, int nx) {
        if (ny == 0 || nx == 0) { return 0; }
        if (x2 < l || r < x1) { return 0; }
        if (x1 <= l && r <= x2) { return seg[ny][nx].v; }
        int mid = (l + r) >> 1;
        return max(query1(x1, x2, l, mid, ny,
            seg[ny][nx].l), query1(x1, x2, mid + 1, r, ny,
                seg[ny][nx].r));
    }
    int query2(int y1, int y2, int x1, int x2, int l, int r,
        int ny) {
        if (ny == 0) { return 0; }
        if (y2 < l || r < y1) { return 0; }
        if (y1 <= l && r <= y2) { return query1(x1, x2, 0, N, ny, 1); }
        int mid = (l + r) >> 1;
        return max(query2(y1, y2, x1, x2, l, mid, L[ny]),
            query2(y1, y2, x1, x2, mid + 1, r, R[ny]));
    }
    void update(int y, int x, int val) {
        upd2(y, x, val, 0, N, 1);
    }
    int query(int y1, int x1, int y2, int x2) {
        return query2(y1, y2, x1, x2, 0, N, 1);
    }
};


vector<int> A[3];
void solve() {
    int m, n;
    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        A[i] = vector<int>(n);
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    if (m == 2) {
        vector<pair<int, int>> B(n);
        for (int i = 0; i < n; i++) {
            B[i] = mp(A[0][i], A[1][i]);
        }
        sort(all(B));

        vector<int> res;
        for (int i = 0; i < n; i++) {
            int x = B[i].second;
            int pos = lower_bound(all(res), x) - res.begin();
            if (pos == res.size())res.push_back(x);
            else res[pos] = x;
        }
        cout << res.size() << '\n';
        return;
    }

    for (int i = 1; i < 3; i++) {
        vector<pair<int, int>> tmp;
        for (int j = 0; j < n; j++) tmp.push_back(mp(A[i][j], j));
        sort(all(tmp));
        for (int j = 0; j < n; j++) A[i][tmp[j].second] = j;
    }

    vector<pair<int, pair<int, int>>> tmp;
    for (int j = 0; j < n; j++) {
        tmp.push_back(mp(A[0][j], mp(A[1][j], A[2][j])));
    }
    sort(all(tmp));

    int ans = 0;
    seg2d sg(n, n);
    for (int i = 0; i < n; i++) {
        auto& [a, b] = tmp[i].second;
        int val = sg.query(0, 0, a, b);
        ans = max(ans, val + 1);
        sg.update(a, b, val + 1);
    }
    cout << ans;

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
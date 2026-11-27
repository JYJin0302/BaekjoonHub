#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n, q;
string A[3];

struct Data {
    int t[3];
    Data() {
        t[0] = 0;
        t[1] = 1;
        t[2] = 2;
    }

    Data(int x) {
        t[0] = t[1] = t[2] = x;
    }
    bool isInit() {
        for (int i = 0; i < 3; i++) {
            if (t[i] != i) return 0;
        }
        return 1;
    }
    bool operator==(Data& o) {
        for (int i = 0; i < 3; i++) if (o.t[i] != t[i]) return 0;
        return 1;
    }

    Data operator*(Data& o) {
        Data ret;
        for (int i = 0; i < 3; i++) {
            ret.t[i] = o.t[t[i]];
        }
        return ret;
    }

    Data operator/(Data& o) {
        Data ret;
        for (int i = 0; i < 3; i++) {
            ret.t[o.t[i]] = t[i];
        }
        return ret;
    }

    Data getMin(Data& o) {
        Data ret;
        for (int i = 0; i < 3; i++) {
            ret.t[i] = min(t[i], o.t[i]);
        }
        return ret;
    }

    void pf() {
        cout << "[ ";
        for (int i = 0; i < 3; i++) cout << t[i] << ' ';
        cout << ']' << '\n';
    }
};

Data seg[101010];
Data lazy[303030];

Data seg2[303030];

void goLazy(int l, int r, int n) {
    if (!lazy[n].isInit()) {
        seg2[n] = seg2[n] / lazy[n];
        if (l == r) {
            seg[l] = seg[l] * lazy[n];
        }
        else {
            lazy[n * 2] = lazy[n * 2] * lazy[n];
            lazy[n * 2 + 1] = lazy[n * 2 + 1] * lazy[n];
        }
        lazy[n] = Data();
    }
}

void update(int l, int r, int n, int ul, int ur, Data upd) {
    goLazy(l, r, n);
    if (l > ur || r < ul) return;
    if (l >= ul && r <= ur) {
        lazy[n] = upd;
        goLazy(l, r, n);
        return;
    }

    int md = (l + r) >> 1;
    update(l, md, n * 2, ul, ur, upd);
    update(md + 1, r, n * 2 + 1, ul, ur, upd);
    seg2[n] = seg2[n * 2].getMin(seg2[n * 2 + 1]);
}

void update(int l, int r, int n, int ix, Data upd) {
    if (l > ix || r < ix) return;
    if (l == ix && r == ix) {
        seg2[n] = upd;
        return;
    }

    int md = (l + r) >> 1;
    update(l, md, n * 2, ix, upd);
    update(md + 1, r, n * 2 + 1, ix, upd);
    seg2[n] = seg2[n * 2].getMin(seg2[n * 2 + 1]);
}


Data getData(int l, int r, int n, int ix) {
    goLazy(l, r, n);
    if (l == ix && r == ix) return seg[l];

    int md = (l + r) >> 1;
    if (l <= ix && ix <= md) return getData(l, md, n * 2, ix);
    return getData(md + 1, r, n * 2 + 1, ix);
}

Data getData(int l, int r, int n, int sl, int sr) {
    goLazy(l, r, n);
    if (l > sr || r < sl) return Data(300000);
    if (l >= sl && r <= sr) return seg2[n];

    int md = (l + r) >> 1;
    Data d1 = getData(l, md, n * 2, sl, sr);
    Data d2 = getData(md + 1, r, n * 2 + 1, sl, sr);
    return d1.getMin(d2);
}

Data getDiff(int l, int r) {
    Data res;

    // cout << "Go query: " << l << " " << r << '\n';
    Data cur = getData(0, n - 1, 1, l);
    Data cur2 = getData(0, n - 1, 1, l, n - 1);
    //cur.pf();
   // cur2.pf();

    set<int> idx;
    idx.insert(l);
    for (int i = 0; i < 3; i++) if (cur2.t[i] <= r) idx.insert(cur2.t[i]);

    vector<string> tmp(3);

    for (auto f : idx) {
        Data tt = getData(0, n - 1, 1, f);
        for (int i = 0; i < 3; i++) {
            tmp[tt.t[i]] += A[i][f];
        }
    }

    vector<pair<string, int>> tt;
    for (int i = 0; i < 3; i++) tt.push_back(mp(tmp[i], i));
    sort(all(tt));

    for (int i = 0; i < 3; i++) {
        res.t[tt[i].y] = i;
    }
    //  cout << "RES: ";
    //  res.pf();

    return res;
}


void solve() {

    cin >> n >> q;
    for (int i = 0; i < 3; i++) cin >> A[i];

    for (int i = 0; i < n; i++) {
        Data tmp(n);
        for (int j = 0; j < 3; j++) {
            int j1 = (j + 1) % 3;
            int j2 = (j + 2) % 3;

            if (A[j1][i] != A[j2][i]) {
                tmp.t[j] = i;
            }
        }

        //  cout << i << ": ";
        //  tmp.pf();
        update(0, n - 1, 1, i, tmp);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        Data res = getDiff(l, r);
        update(0, n - 1, 1, l, r, res);
    }

    vector<string> ans(3, string(n, '.'));
    for (int i = 0; i < n; i++) {
        Data cur = getData(0, n - 1, 1, i);
        for (int j = 0; j < 3; j++) {
            ans[cur.t[j]][i] = A[j][i];
        }
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
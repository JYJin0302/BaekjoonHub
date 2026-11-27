#include<bits/stdc++.h>
using ll = long long;
using namespace std;

struct P {
    ll x, y;
    P() {
        x = -1;
        y = -1;
    }
    P(ll _x, ll _y) {
        x = _x;
        y = _y;
    }

    P operator-(P & o) {
        return P(x - o.x, y - o.y);
    }

    bool operator==(P& o) {
        return o.x == x && o.y == y;
    }
    bool operator!=(P& o) {
        return o.x != x || o.y != y;
    }

    bool operator<(P& o) {
        return make_pair(x, y) < make_pair(o.x, o.y);
    }

    void pf() {
        cout << x << ' ' << y;
    }
};

struct Line {
    P s, e;
    Line() {
        s = P();
        e = P();
    }
    Line(P a, P b) {
        s = a, e = b;
    }

    void pf() {
        s.pf();
        cout << ' ';
        e.pf();
    }
};

ll dot(P p1, P p2) {
    return p1.x * p2.x + p1.y * p2.y;
}
ll ccw(P p1, P p2) {
    return p1.x * p2.y - p1.y * p2.x;
}
bool pointOnLine(P p, Line l) {
    return ccw(l.s-l.e, p-l.e) == 0 && dot(l.e-p, l.s-p) < 0;
}

bool cmp(Line& a, Line& b) {
    if (a.s != b.s) {
        return a.s < b.s;
    }
    return ccw(b.e - b.s, a.e - a.s) < 0;
}
void solve() {

    int n;
    cin >> n;

    vector<Line> A(n);
    for (auto& i : A) {
        cin >> i.s.x >> i.s.y >> i.e.x >> i.e.y;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        vector<Line> lft, rgt;

        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            bool c1 = pointOnLine(A[j].s, A[i]);
            bool c2 = pointOnLine(A[j].e, A[i]);

            if (c1 && c2) continue;
            if (!c1 && !c2) continue;
            if (c2) swap(A[j].s, A[j].e);

            ll val = ccw(A[j].e - A[j].s, A[i].e - A[i].s);
            if (val > 0) rgt.push_back(A[j]);
            else if (val < 0) lft.push_back(A[j]);
        }

        sort(lft.begin(), lft.end(), cmp);
        sort(rgt.begin(), rgt.end(), cmp);

        /*cout << "curr Line : ";
        A[i].pf();
        cout << '\n';

        cout << "Left             | Right\n";
        for (int j = 0; j < max(lft.size(), rgt.size()); j++) {
            if (j < lft.size()) {
                lft[j].pf();
                cout << "     ";
            }
            else cout << "                  ";

            cout << ' ';
            if (j < rgt.size()) rgt[j].pf();
            cout << '\n';
        }*/

        int ix = 0;
        while (ix < lft.size()) {
            ll l = ix;
            while (ix < lft.size() && lft[ix].s == lft[l].s)ix++;
            ll r = ix;
            //cout << l << ' ' << r << '\n';
            // l ~ r-1
            ll tx = l;
            while(tx < r) {

                ll nx = tx;
                while (nx < r && ccw(lft[nx].e - lft[nx].s, lft[tx].e - lft[tx].s) == 0) nx++;

               // cout << "--" << tx << ' ' << nx << '\n';
                ans += (tx-l) * (nx - tx);
                tx = nx;
            }
        }

        ix = 0;
        while (ix < rgt.size()) {
            ll l = ix;
            while (ix < rgt.size() && rgt[ix].s == rgt[l].s) ix++;
            ll r = ix;
           // cout << l << ' ' << r << '\n';
            // l ~ r-1
            ll tx = l;
            while (tx < r) {

                ll nx = tx;
                while (nx < r && ccw(rgt[nx].e - rgt[nx].s, rgt[tx].e - rgt[tx].s) == 0) nx++;

                //cout << "--" << tx << ' ' << nx << '\n';
                ans += (tx-l) * (nx - tx);
                tx = nx;
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

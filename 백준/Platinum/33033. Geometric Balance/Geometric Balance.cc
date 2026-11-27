#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

struct Rnum {
    ll a, b;
    // a + b sqrt(2)

    Rnum(ll _a = 0, ll _b = 0) : a(_a), b(_b) {}
    Rnum operator+(const Rnum& o) {
        return Rnum(a + o.a, b + o.b);
    }
    Rnum operator-(const Rnum& o) {
        return Rnum(a - o.a, b - o.b);
    }
    bool operator< (const Rnum& o) {
        Rnum res = *this - o;
        long double test = res.a + 1.0 * res.b * sqrtl(2);
        return test < 0;
    }
    bool operator==(const Rnum& o) {
        return a == o.a && b == o.b;
    }

    void pf() {
        cout << a << " + " << b << "|2";
    }
};

struct Point {
    Rnum x, y;
    Point(Rnum _x = Rnum(), Rnum _y = Rnum()) : x(_x), y(_y) {}

    Point operator+(const Point& o) {
        return Point(x + o.x, y + o.y);
    }
    Point operator-(const Point& o) {
        return Point(x - o.x, y - o.y);
    }
    bool operator== (const Point& o) {
        return x == o.x && y == o.y;
    }

    bool operator<(const Point& o) {
        if (x == o.x) return y < o.y;
        return x < o.x;
    }

    void pf() {
        cout << '('; x.pf();
        cout << ", "; y.pf();
        cout << ") ";
    }
};

struct Line {
    Point s, e;
    Line(Point _s = Point(), Point _e = Point()) {
        s = _s, e = _e;
        if (e < s) swap(s, e);
    }

    bool operator<(const Line& o) {
        if (s == o.s) return e < o.e;
        return s < o.s;
    }
};

bool cmp0(Line& l1, Line& l2) {
    // ver
    if (!(l1.s.y == l2.s.y)) return l1.s.y < l2.s.y;
    return l1.s < l2.s;
}
bool cmp1(Line& l1, Line& l2) {
    // /
    if (!((l1.e.x + l1.e.y) == (l2.e.x + l2.e.y))) return (l1.e.x + l1.e.y) < (l2.e.x + l2.e.y);
    return l1.s < l2.s;
}
bool cmp2(Line& l1, Line& l2) {
    // hor
    if (!(l1.s.x == l2.s.x)) return l1.s.x < l2.s.x;
    return l1.s < l2.s;
}
bool cmp3(Line& l1, Line& l2) {
    // \
    
    if (!((l1.e.x - l1.e.y) == (l2.e.x - l2.e.y))) return (l1.e.x - l1.e.y) < (l2.e.x - l2.e.y);
    return l1.s < l2.s;

}

vector<Line> A[4];
vector<Line> seg[4]; // ver, /, hor, \\

vector<Line> tseg[4];

int n;
vector<pair<string, ll>> Q;

int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
void simul(int dir, vector<Line> res[]) {

    for (int i = 0; i < 4; i++) A[i].clear();

    int cdir = dir;
    Point cur;
    for (int i = 0; i < n; i++) {
        auto [s, d] = Q[i];

        if (s == "rotate") {
            cdir = (cdir + d / 45) % 8;
        }
        else {

            Point npos = cur;
            if (cdir % 2 == 0) {
                d *= 2;
                npos.x.a += d * dx[cdir];
                npos.y.a += d * dy[cdir];
            }
            else {
                npos.x.b += d * dx[cdir];
                npos.y.b += d * dy[cdir];
            }

            if (s == "draw") {
                A[cdir % 4].push_back(Line(cur, npos));
               /* cur.pf();
                cout << " => ";
                npos.pf();
                cout << '\n';*/
            }
            cur = npos;
        }
    }

    // merge
    sort(all(A[0]), cmp0);
    sort(all(A[1]), cmp1);
    sort(all(A[2]), cmp2);
    sort(all(A[3]), cmp3);


    for (int d = 0; d < 4; d++) {
        if (A[d].empty()) continue;
        Line cur = A[d][0];
        for (int i = 1; i < int(A[d].size()); i++) {
            if (A[d][i].s == cur.e) cur.e = A[d][i].e;
            else {
                res[d].push_back(cur);
                cur = A[d][i];
            }
        }
        res[d].push_back(cur);
        sort(all(res[d]));
    }
   /*cout << "RES:\n";
    for (int d = 0; d < 4; d++) {
        cout << "res d: " << d << " | ";
        for (auto f : res[d]) {
            f.s.pf();
            cout << " => ";
            f.e.pf();
            cout << " || ";
        }
        cout << '\n';
    }*/
}


void solve(){

    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        ll x;
        cin >> s >> x;
        Q.push_back(mp(s, x));
    }

    simul(0, seg);
    for (int i : {1, 2, 4}) {
        for (int j = 0; j < 4; j++) tseg[j].clear();
        simul(i, tseg);

        // test equlity
        bool ok = 1;
        bool isSet = 0;

        Point diff;
        for (int j = 0; j < 4; j++) {
            if (seg[j].size() != tseg[j].size()) {
                ok = 0;
                break;
            }
            if (seg[j].empty()) continue;
            if (!isSet) {
                diff = seg[j][0].s - tseg[j][0].s;
                isSet = 1;
            }
            for (int f = 0; f < (int)seg[j].size(); f++) {
                if (!(diff == seg[j][f].s - tseg[j][f].s)) ok = 0;
                if (!(diff == seg[j][f].e - tseg[j][f].e)) ok = 0;
                if (!ok) break;
            }
            if (!ok) break;
        }

        if (ok) {
            cout << i * 45 << '\n';
            return;
        }
    }
    cout << 360 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}
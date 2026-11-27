#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

const ll INF = 1e18;
struct D {
    int x, y;
    ll a, b;
    bool isEnd = 0;

    friend ostream& operator<<(ostream& os, D p) {
        return os << "(" << p.x << "," << p.y << " | " << p.a << ' ' << p.b << ' ' << p.isEnd << ")";
    }
};

bool cmp1(D& d1, D& d2) {
    if (d1.y != d2.y) return d1.y > d2.y;
    return d1.x < d2.x;
}
bool cmp2(D& d1, D& d2) {
    if (d1.x != d2.x) return d1.x < d2.x;
    return d1.y < d2.y;
}

int n, k;
ll ans = 0;
vector<D> G[1001010];

void goSolve(vector<D>& v) {
    sort(all(v), cmp2);

    int ix = 0;
    vector<ll> dp;
    vector<ll> pos;
    // 0 1
    // 0 1
    // 1 0 <- i
    // 1 0


    ll pv = -1e8;
    while (ix < v.size()) {

        int nx = ix;
        while (nx < v.size() && v[nx].x == v[ix].x) nx++;

        /* cout << "Go : ";
         for (int i = ix; i < nx; i++) {
             cout << v[i] << ' ';
         }
         cout << '\n';*/

        if (v[ix].x - k + 1 == pv) {
            // need cal
            vector<ll> tdp;
            vector<ll> tpos;
            ll tot = 0;
            for (int j = ix; j < nx; j++) {
                tot += v[j].a;
            }
            tdp.push_back(tot);
            tpos.push_back(-1);
            for (int j = ix; j < nx; j++) {
                tot += v[j].b - v[j].a;
                tdp.push_back(tot);
                tpos.push_back(v[j].y);
            }
            bool ok = 1;
            for (int j = ix; j < nx - 1; j++) {
                if (!v[j].isEnd) ok = 0;
                if (!ok) tdp[j - ix + 1] = -INF;
            }
            /*cout << "Before\n";
            for (auto f : tdp) cout << f << ' ';
            cout << '\n';
            for (auto f : tpos) cout << f << ' ';
            cout << '\n' << '\n';*/
            int n = dp.size();
            int m = tdp.size();

            ll mx = -INF;
            int tx = 0;
            while (tx < n-1 && v[ix - (n - 1) + tx].isEnd) tx++;

            ll mv1 = -INF;
            for (int i = 0; i < n - 1; i++) mv1 = max(mv1, dp[i]);
            ll ff = dp[n - 1];
            if (tpos[1] > pos[n - 1]) ff = max(ff, mv1);
            tdp[0] += ff;


            for (int j = 1; j < m; j++) {
                if (tdp[j] == -INF) continue;
                ll v1 = -INF, v2 = -INF;
                if (j + 1 < m && tpos[j + 1] < pos[n - 1]) {
                    v1 = -INF;
                }
                else {
                    v1 = mv1;
                }
                if (tx == n-1 || pos[tx+1] > tpos[j]) {
                    v2 = dp[n - 1];
                }
                else {}

                ll res = max(v1, v2);
                if (res == -INF) tdp[j] = -INF;
                else tdp[j] += res;
            }

            swap(dp, tdp);
            swap(pos, tpos);

        }
        else {
            ll mx = 0;
            for (auto b : dp) mx = max(mx, b);
            ans += mx;
            dp.clear();
            pos.clear();

            ll tot = 0;
            for (int j = ix; j < nx; j++) {
                tot += v[j].a;
            }
            dp.push_back(tot);
            pos.push_back(-1);
            for (int j = ix; j < nx; j++) {
                tot += v[j].b - v[j].a;
                dp.push_back(tot);
                pos.push_back(v[j].y);
            }

            bool ok = 1;
            for (int j = ix; j < nx - 1; j++) {
                if (!v[j].isEnd) ok = 0;
                if (!ok) dp[j - ix + 1] = -INF;
            }
        }

        /* for (auto f : dp) cout << f << ' ';
         cout << '\n';
         for(auto f : pos) cout << f << ' ';
         cout << '\n' << '\n';*/
        pv = v[ix].x;
        ix = nx;
    }

    ll mx = -INF;
    for (auto f : dp) mx = max(mx, f);
    ans += mx;
}

void solve() {

    cin >> n >> k;

    vector<D> A;
    for (int i = 0; i < n; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        A.push_back({ x, y, a, b });
    }
    sort(all(A), cmp1);

    for (int i = 0; i < n; i++) {
        if (i == n - 1 || A[i + 1].y != A[i].y) A[i].isEnd = 1;
        G[A[i].x % (k - 1)].push_back(A[i]);
    }

    for (int i = 0; i < k - 1; i++) {
        if (G[i].empty()) continue;
        goSolve(G[i]);
    }


    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}
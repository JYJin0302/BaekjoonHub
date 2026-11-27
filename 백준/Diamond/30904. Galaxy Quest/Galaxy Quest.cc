#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

struct P {
    ld x, y, z;
    P(ld x = 0, ld y = 0, ld z = 0) : x(x), y(y), z(z) {}
    bool operator==(P p) const {
        return tie(x, y) == tie(p.x, p.y);
    }
    P operator+(P p) const { return P(x + p.x, y + p.y, z + p.z); }
    P operator-(P p) const { return P(x - p.x, y - p.y, z - p.z); }
    ld dist2() const { return x * x + y * y + z * z; }
    ld dist() const { return sqrtl((double)dist2()); }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ' ' << p.z << ")";
    }
};

vector<int> adj[101010];
ld dist[101010];

void solve() {

    int n, m, q;
    cin >> n >> m >> q;
    vector<P> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i].x >> A[i].y >> A[i].z;
        dist[i] = -1;
    }
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    priority_queue<pair<ld, int>> pq;
    pq.push(mp(0, 1));
    while (!pq.empty()) {
        auto [a, b] = pq.top(); pq.pop();
        if (dist[b] < -0.5) dist[b] = -a;
        else continue;

        for (auto f : adj[b]) {
            if (dist[f] < -0.5) {
                ld dst = sqrtl((A[b] - A[f]).dist());
                pq.push(mp(a - dst, f));
            }
        }
    }

    cout << fixed << setprecision(10);
    while (q--) {

        int v, t;
        cin >> v >> t;

        if (dist[v] < -0.5 || dist[v] * 2 > t) {
            cout << "impossible\n";
            continue;
        }

        ld l = -1e10, r = 0, res = 0;
        while (l < r - 1e-9) {
            ld md = (l + r) / 2;

            ld tmp = sqrtl(1 - md);
            ld nt = dist[v] * tmp + dist[v] / tmp;

            if (nt <= t) {
                res = md;
                r = md;
            }
            else l = md;
        }

        ld ans = 2 * dist[v] / sqrtl(1 - res);
        cout << ans << '\n';

    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}
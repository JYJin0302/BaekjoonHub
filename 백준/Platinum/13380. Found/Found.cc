#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n, m, sn;
const int mod = 9973;
vector<int> adj[11];
int idx[11][11];
int conn[11][11];

struct M {
    vector<vector<int>> m;
    M(int n) {
        m = vector<vector<int>>(n, vector<int>(n));
    }

    M operator*(M& o) {
        M ret(sn);
        for (int i = 0; i < sn; i++) {
            for (int j = 0; j < sn; j++) {
                for (int k = 0; k < sn; k++) {
                    (ret.m[i][j] += m[i][k] * o.m[k][j] % mod) %= mod;
                }
            }
        }
        return ret;
    }

};


void solve() {

    ll t;
    cin >> n >> m >> t;

    memset(conn, 0, sizeof conn);
    for (int i = 1; i <= n; i++) adj[i].clear();

    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        conn[a][b] = conn[b][a] = 1;
    }

    memset(idx, -1, sizeof idx);

    vector<pair<int, int>> lst;
    queue<pair<int, int>> q;
    q.push(mp(1, n));
    lst.push_back(mp(1, n));

    sn = n * (n - 1) / 2;
    M base(sn);
    idx[1][n] = idx[n][1] = 0;
    int ord = 0;
    while (!q.empty()) {
        auto [a, b] = q.front(); q.pop();

        int u = idx[a][b];
        for (auto na : adj[a]) {
            for (auto nb : adj[b]) {
                if (na == nb) continue;

                if (idx[na][nb] != -1) {
                    int v = idx[na][nb];
                    base.m[u][v]++;
                    continue;
                }

                idx[na][nb] = idx[nb][na] = ++ord;

                base.m[u][ord]++;
                lst.push_back(mp(na, nb));
                q.push(mp(na, nb));
            }
        }
    }

    /*for (auto [a, b] : lst) cout << a << ' ' << b << " | ";
    cout << '\n';
    for (int i = 0; i <= ord; i++) {
        for (int j = 0; j <= ord; j++) {
            cout << base.m[i][j] << ' ';
        }
        cout << '\n';
    }*/

    t--;
    
    M T(sn);
    for (int i = 0; i < sn; i++) T.m[i][i] = 1;

    while (t) {
        if (t & 1) {
            T = T * base;
        }
        base = base * base;
        t >>= 1;
    }

    int ans = 0;
    for (int i = 0; i <= ord; i++) {
        int v = T.m[0][i];
        auto [a, b] = lst[i];
        for (int j = 1; j <= n; j++) {
            if (conn[a][j] && conn[b][j]) {
                ans = (ans + v) % mod;
            }
        }
    }
    cout << ans << '\n';



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
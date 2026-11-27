#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

vector<pair<ll, pair<ll, ll>>> adj[101010];
int dep[101010];
int spt[18][101010];
ll sub[101010];
int upCnt[101010];

int R[101010], Z[101010];

void dfs(int v, int pv = -1) {
    
    for (auto f : adj[v]) if (f.first != pv) {
        dep[f.first] = dep[v] + 1;
        spt[0][f.first] = v;

        if (f.second.second == 1) {
            sub[f.first] = sub[v] + f.second.first;
            upCnt[f.first] = upCnt[v] + 1;
        }

        R[f.first] = f.second.first;
        Z[f.first] = f.second.second;
        dfs(f.first, v);
    }
}

int lca(int u, int v) {

    if (dep[u] > dep[v]) swap(u, v);
    int diff = dep[v] - dep[u];

    for (int i = 0; i < 18; i++) {
        if (diff & (1 << i)) {
            v = spt[i][v];
        }
    }

    for (int i = 17; i >= 0; i--) {
        if (spt[i][u] != spt[i][v]) {
            u = spt[i][u];
            v = spt[i][v];
        }
    }

    if (u != v) u = spt[0][u];
    return u;
}

void solve() {

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;

        ll r, z;
        cin >> r >> z;

        adj[a].push_back(mp(b, mp(r, z)));
        adj[b].push_back(mp(a, mp(r, z)));
    }

    dfs(1);

    for (int i = 1; i < 18; i++) {
        for (int j = 1; j <= n; j++) {
            spt[i][j] = spt[i - 1][spt[i - 1][j]];
        }
    }

    int q;
    cin >> q;
    while (q--) {

        ll a, b, e;
        cin >> a >> b >> e;

        int c = lca(a, b);

        int curr = a, divCnt = 0;
        vector<pair<ll, ll>> route1, route2;

        while (curr != c) {

            int u = upCnt[curr];
            if (u == 0) {
                route1.push_back(mp(R[curr], Z[curr]));
                divCnt++;
                curr = spt[0][curr];
            }
            else {
                int mv = min(dep[curr] - dep[c], u);
                ll val = 0;
                int nx = curr;
                for (int j = 0; j < 18; j++) {
                    if (mv & (1 << j)) {
                        nx = spt[j][nx];
                    }
                }
                route1.push_back(mp(sub[curr] - sub[nx], 1));
                curr = nx;
            }

            if (divCnt >= 70) break;
        }

        curr = b;
        while (curr != c) {

            int u = upCnt[curr];
            if (u == 0) {
                route2.push_back(mp(R[curr], Z[curr]));
                divCnt++;
                curr = spt[0][curr];
            }
            else {
                int mv = min(dep[curr] - dep[c], u);
                ll val = 0;
                int nx = curr;
                for (int j = 0; j < 18; j++) {
                    if (mv & (1 << j)) {
                        nx = spt[j][nx];
                    }
                }
                route2.push_back(mp(sub[curr] - sub[nx], 1));
                curr = nx;
            }

            if (divCnt >= 70) break;
        }
        reverse(route2.begin(), route2.end());

        for (auto& [x, y] : route1) {
            e = max(0ll, e - x) / y;
            if (e == 0) break;
        }
        for (auto& [x, y] : route2) {
            e = max(0ll, e - x) / y;
            if (e == 0) break;
        }

        cout << e << '\n';

        //cout << "Route: \n";
        //for (auto f : route1) cout << "{" << f.first << ", " << f.second << "} ";
        //cout << '\n';
        //for (auto f : route2) cout << "{" << f.first << ", " << f.second << "} ";
        //cout << '\n';
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


vector<int> adj[101010];
int dist[101010];
int from[101010];


void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    vector<pair<int, int>> tt;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int val = 0;
        for (int j = 0; j < k; j++) {
            val = val * 2 + (s[j] - '0');
        }
        A[i] = val;
        tt.push_back(mp(val, i));
    }
    sort(all(tt));
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < k; j++) {
            int nv = A[i] ^ (1 << j);

            int ix = lower_bound(all(tt), mp(nv, -1)) - tt.begin();
            if (ix < n && tt[ix].first == nv) {
                adj[i+1].push_back(tt[ix].second+1);
            }
        }
    }

    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty()) {
        int a = q.front(); q.pop();
        for (auto f : adj[a]) {
            if (dist[f] == -1) {
                dist[f] = dist[a] + 1;
                from[f] = a;
                q.push(f);
            }
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int e;
        cin >> e;

        if (dist[e] == -1) cout << -1 << '\n';
        else {
            vector<int> route;
            int v = e;
            while (v != 0) {
                route.push_back(v);
                v = from[v];
            }
            reverse(all(route));
            for (auto f : route) cout << f << ' ';
            cout << '\n';

        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}
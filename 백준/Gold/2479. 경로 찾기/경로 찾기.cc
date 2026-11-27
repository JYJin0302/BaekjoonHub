#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


vector<int> adj[1010];
int dist[1010];
int from[1010];

void solve() {
    int n, k;
    cin >> n >> k;

    map<int, int> idx;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int val = 0;
        for (int j = 0; j < k; j++) {
            val = val * 2 + (s[j] - '0');
        }
        idx[val] = i + 1;

        for (int j = 0; j < k; j++) {
            int nv = val ^ (1 << j);
            if (idx[nv]) {
                int tp = idx[nv];
                adj[tp].push_back(i + 1);
                adj[i + 1].push_back(tp);
            }
        }
    }

    int s, e;
    cin >> s >> e;
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(s);
    dist[s] = 0;

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

    if (dist[e] == -1) cout << -1 << '\n';
    else {

        vector<int> route;
        int v = e;
        while (v != s) {
            route.push_back(v);
            v = from[v];
        }
        route.push_back(s);
        reverse(all(route));
        for (auto f : route) cout << f << ' ';
        cout << '\n';

    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}
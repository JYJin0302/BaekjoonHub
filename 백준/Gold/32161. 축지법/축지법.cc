#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int INF = 0x3f3f3f3f;
vector<int> adj[4020];

void solve() {

    int n, m, q;
    cin >> n >> m >> q;

    vector<pair<int, int>> edg;
    vector<int>pos;
    while (m--) {
        int a, b;
        cin >> a >> b;
        edg.push_back(mp(a, b));
        pos.push_back(a);
        pos.push_back(b);
    }

    sort(all(pos));
    pos.erase(unique(all(pos)), pos.end());

    for (auto [a, b] : edg) {
        int ax = lower_bound(all(pos), a) - pos.begin();
        int bx = lower_bound(all(pos), b) - pos.begin();
        adj[ax].push_back(bx);
        adj[bx].push_back(ax);
    }

    vector<pair<pair<int, int>, int>> qur;

    for(int i =0 ; i <q;i++){
        int a, b;
        cin >> a >> b;

        if (a > b) swap(a, b);

        if (a != b) qur.push_back(mp(mp(a, b), i));
    }
    sort(all(qur));

    int sn = pos.size();
    vector<int> ans(q);

    int ix = 0;
    while (ix < qur.size()) {

        int nx = ix;
        while (nx < qur.size() && qur[nx].x.x == qur[ix].x.x) nx++;

        vector<int> dist(sn + 1, INF);
        int cur = lower_bound(all(pos), qur[ix].x.x) - pos.begin();

       // cout << "Go: " << ix << ' ' << nx << ' ' << cur << '\n';
        if (cur == pos.size() || pos[cur] != qur[ix].x.x) {
            while (ix < nx) {
                //cout << ix << " | " << qur[ix].x.x << ' ' << qur[ix].x.y << ' ' << qur[ix].y << '\n';
                ans[qur[ix].y] = 1;
                ix++;
            }
            continue;
        }

        dist[cur] = 0;
        queue<int> q;
        q.push(cur);
        while (!q.empty()) {
            int a = q.front(); q.pop();
            for (auto f : adj[a]) {
                if (dist[f] == INF) {
                    dist[f] = dist[a] + 1;
                    q.push(f);
                }
            }
        }

        bool trick = 0;
        if (sn < n) trick = 1;
        for (int i = 0; i < sn; i++) if (dist[i] == INF) trick = 1;

        while (ix < nx) {
            int tar = qur[ix].x.y;
            int tx = lower_bound(all(pos), tar) - pos.begin();

            if (tx == pos.size() || pos[tx] != tar) ans[qur[ix].y] = 1;
            else {
                if (dist[tx] == INF) dist[tx] = 1;
                ans[qur[ix].y] = dist[tx];

                if (trick) ans[qur[ix].y] = min(ans[qur[ix].y], 2);
            }
            ix++;
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
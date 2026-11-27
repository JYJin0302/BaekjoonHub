#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

vector<pair<ll, ll>> adj[25005];
ll dist[25050];
vector<int> nxt[25001];

vector<int> edgidx[25001];
vector<int> flow, flowInit;
vector<bool> vs;

bool go(int x) {

    //cout << x << ' ';
    if (x == 1) return 1;

    if (vs[x]) return 0;
    vs[x] = 1;

    int sz = nxt[x].size();
    for (int i = 0; i < sz; i++) {
        if (flow[edgidx[x][i]] && go(nxt[x][i])) {
            flow[edgidx[x][i]] = 0;
            flow[edgidx[x][i] ^ 1] = 1;
            return 1;
        }
    }

    //cout << -x << ' ';

    return 0;
}

void solve() {

    int n, m, c;
    cin >> n >> m >> c;

    vector<pair<ll, pair<ll, ll>>> edg;

    while (m--) {
        ll x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back(mp(y, z));
        adj[y].push_back(mp(x, z));
        edg.push_back(mp(z, mp(x, y)));
    }

    memset(dist, -1, sizeof(dist));

    priority_queue<pair<ll, ll>> pq;
    pq.push(mp(0, 1));
    while (!pq.empty()) {

        ll a, b;
        tie(a, b) = pq.top();
        pq.pop();

        if (dist[b] != -1) continue;
        dist[b] = -a;
        for (auto& f : adj[b]) {
            if (dist[f.first] == -1){
                pq.push(mp(a - f.second, f.first));
            }
        }
    }

    for (int i = 1; i <= n; i++) adj[i].clear();

    for (auto& [z, p] : edg) {
        auto& [x, y] = p;

        if (dist[x] < dist[y])swap(x, y);

        if (dist[x] == dist[y] + z) {
            // ok
            nxt[x].push_back(y);
            edgidx[x].push_back(flowInit.size());
            flowInit.push_back(1);
            nxt[y].push_back(x);
            edgidx[y].push_back(flowInit.size());
            flowInit.push_back(0);
        }
    }


    vector<pair<ll, ll>> q;
    for (int i = 0; i < c; i++) {
        int x;
        cin >> x;
        q.push_back(mp(dist[x], x));
    }

    sort(q.begin(), q.end());
    flow = flowInit;

    int ans = 0;

    for (int i = 0; i < c; i++) {
        if (i && q[i].first != q[i - 1].first) {
            // initialize
            flow = flowInit;
            for (int j = 1; j <= n; j++) {

            }
        }

        vs = vector<bool>(n + 1);
        //cout << "Go : " << q[i].second << '\n';
        if (go(q[i].second)) ans++;
        //cout << '\n';


    }
    cout << ans;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}

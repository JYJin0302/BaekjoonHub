#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int INF = 2e9 + 10;

vector<int> adj[2020];
int S[202020];
int W[202020];

int dist[2020], distE[2020];
int from[2020];
bool inP[2020];

bool chkI[2020][2020];

int L[2020], R[2020];
vector<pair<int, int>> toIn[2020];

void solve() {

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vector<pair<pair<int, int>, int>> edgList;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        S[i] = u + v;
        W[i] = w;
        
        adj[u].push_back(i);
        adj[v].push_back(i);
        edgList.push_back(mp(mp(u, v), w));
    }

    int k;
    cin >> k;
    vector<int> route(k);
    for (auto& i : route) cin >> i;

    memset(from, -1, sizeof(from));

    for (auto f : route) inP[f] = 1;
    for (int i = 1; i < k; i++) {
        chkI[route[i]][route[i-1]] = chkI[route[i-1]][route[i]] = 1;
        from[route[i]] = route[i - 1];
    }

    priority_queue<pair<int, int>> pq;
    memset(dist, -1, sizeof(dist));
    pq.push(mp(0, a));
    while (!pq.empty()) {
        auto [u, v] = pq.top(); pq.pop();
        if (dist[v] != -1) continue;
        dist[v] = -u;

        for (auto f : adj[v]) {
            int nv = S[f] - v;
            if (dist[nv] == -1) {
                pq.push(mp(u - W[f], nv));
            }
        }
    }

    for (auto i : route) {
        queue<int> q;
        q.push(i);
        L[i] = i;
        while (!q.empty()) {
            int a = q.front(); q.pop();
            for (auto f : adj[a]) {
                int na = S[f] - a;
                if (!inP[na] && dist[na] == dist[a] + W[f]) {
                    L[na] = i;
                    q.push(na);
                }
            }
        }
    }

    memset(distE, -1, sizeof(distE));
    pq.push(mp(0, b));
    while (!pq.empty()) {
        auto [u, v] = pq.top(); pq.pop();
        if (distE[v] != -1) continue;
        distE[v] = -u;
        for (auto f : adj[v]) {
            int nv = S[f] - v;
            if (distE[nv] == -1) {
                pq.push(mp(u - W[f], nv));
            }
        }
    }

    for (int j = 0; j < k; j++) {
        int i = route[k - 1 - j];
        R[i] = i;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int a = q.front(); q.pop();
            for (auto f : adj[a]) {
                int na = S[f] - a;
                if (!inP[na] && distE[na] == distE[a] + W[f]) {
                    R[na] = i;
                    q.push(na);
                }
            }
        }
    }

    for (auto& i : edgList) {
        auto& [u, v] = i.first;
        int w = i.second;

        if (chkI[u][v]) continue;


        int fu = L[u], fv = R[v];
        if (fu && fv && fu != fv && dist[u] != -1 && distE[v] != -1) {
            int val = dist[u] + distE[v] + w;
            if (dist[fu] < dist[fv]) toIn[fu].push_back(mp(val, fv));
            else toIn[fv].push_back(mp(val, fu));
        }
        swap(u, v);
        fu = L[u], fv = R[v];
        if (fu && fv && fu != fv && dist[u] != -1 && distE[v] != -1) {
            int val = dist[u] + distE[v] + w;
            if (dist[fu] < dist[fv]) toIn[fu].push_back(mp(val, fv));
            else toIn[fv].push_back(mp(val, fu));
        }
    }

    vector<bool> used(n + 1);
    set<pair<int, int>> st;
    for (int i = 0; i < k - 1; i++) {
        int v = route[i];
        used[v] = 1;

        for (auto f : toIn[v]) st.insert(f);

        while (!st.empty()) {
            if (used[(*st.begin()).second]) {
                st.erase(st.begin());
            }
            else break;
        }

        if (st.empty()) cout << -1 << '\n';
        else cout << (*st.begin()).first << '\n';

    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
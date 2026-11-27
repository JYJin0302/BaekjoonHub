#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n;
vector<int> adj[101010];
int L[101010];
int dist[101010];
bool used[101010];

void setLevel() {

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dist[i] = 0;
            q.push(i);
        }
        else dist[i] = -1;
    }

    while (!q.empty()) {
        int a = q.front(); q.pop();
        for (auto f : adj[a]) {
            if (L[f] != -1 && dist[L[f]] == -1) {
                dist[L[f]] = dist[a] + 1;
                q.push(L[f]);
            }
        }
    }
}

bool dfs(int v) {
    for (auto f : adj[v]) {
        if (L[f] == -1 || (dist[L[f]] == dist[v] + 1 && dfs(L[f]))) {
            L[f] = v;
            used[v] = 1;
            return 1;
        }
    }
    return 0;
}


int root[101010];
int leaf[101010];
int find(int n) {
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

int topo[101010];

void solve() {

    cin >> n;

    vector<pair<int, int>> edg;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        edg.push_back(mp(a, b));
    }

    memset(L, -1, sizeof L);
    while (1) {
        setLevel();
        int flow = 0;
        for (int i = 1; i <= n; i++) {
            if (!used[i] && dfs(i)) flow++;
        }
        if (!flow) break;
    }



    for (int i = 1; i <= n; i++) root[i] = leaf[i] = i;
    for (int i = 1; i <= n; i++) {
        if (L[i] != -1) {
            int a = find(L[i]);
            int b = find(i);
            root[b] = a;
            leaf[a] = leaf[b];
        }
    }

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }

    for (auto [a, b] : edg) {
        int na = find(a);
        int nb = find(b);
        if (na == nb) continue;

        adj[na].push_back(nb);
        topo[nb]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (find(i) == i && topo[i] == 0) {
            q.push(i);
        }
    }
    vector<pair<int, int>> ans;
    int pre = -1;
    while (!q.empty()) {

        int a = q.front(); q.pop();

        if (pre != -1) {
            ans.push_back(mp(leaf[pre], a));
        }
        pre = a;

        for (auto f : adj[a]) {
            topo[f]--;
            if (topo[f] == 0) q.push(f);
        }
    }

    cout << ans.size() << '\n';
    for (auto [a, b] : ans) cout << a << ' ' << b << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}
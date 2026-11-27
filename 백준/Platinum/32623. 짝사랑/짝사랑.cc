#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<int> adj[505050];
int dfsn[505050];

vector<pair<int, int>> nEdg;

int ord = 0;
int dfs(int v, int pv = -1) {
    dfsn[v] = ++ord;
    int res = dfsn[v];
    for (auto f : adj[v]) if(f != pv){
        if (dfsn[f] == 0) {
            int tmp = dfs(f, v);
            res = min(res, tmp);
            if (v == 1) {
                if (dfsn[v] == tmp) nEdg.push_back(mp(v, f));
            }
            else if (dfsn[v] > tmp) {
                nEdg.push_back(mp(v, f));
            }
        }
        else {
            res = min(res, dfsn[f]);
            nEdg.push_back(mp(v, f));
        }
    }

    return res;
}

void solve() {

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edg;
    while (m--) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        edg.push_back(mp(a, b));
    }
    sort(all(edg));
    edg.erase(unique(all(edg)), edg.end());
    
    for (auto [a, b] : edg) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    vector<bool> t2(n + 1);
    t2[1] = 1;

    for (int i = 1; i <= n; i++) adj[i].clear();
    for (auto [a, b] : nEdg) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int a = q.front(); q.pop();
        for (auto f : adj[a]) if (!t2[f]) {
            t2[f] = 1;
            q.push(f);
        }
    }
    for (auto [a, b] : edg) {
        if (a == 1 || b == 1) t2[a + b - 1] = 1;
    }

    cout << '0';
    for (int i = 2; i <= n; i++) {
        if (t2[i]) cout << 1;
        else cout << 0;
    }
    cout << '\n';



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
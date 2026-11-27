#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n, m;
const int MAXN = 3000;
int C[4][MAXN + 1];
pair<int, int> P[MAXN + 1];
vector<pair<int, int>> conn[MAXN + 1];
vector<pair<int, int>> conn2[MAXN + 1];


vector<int> adj[404040];


int getNum(int v, int i, int j) {
    // v = 0, n-1
    // i = 0-3
    // j = 0-4
    return 2 * n + 20 * v + 5 * i + j;
}
int dfsn[404040];
int scc[404040];

int ord = 0, scnt = 0;
stack<int> st;

int dfs(int v) {
    dfsn[v] = ++ord;
    st.push(v);
    int ret = dfsn[v];
    for (auto f : adj[v]) {
        if (dfsn[f] == -1) {
            ret = min(ret, dfs(f));
        }
        else if (scc[f] == -1) {
            ret = min(ret, dfsn[f]);
        }
    }

    if (ret == dfsn[v]) {
        scnt++;
        while (!st.empty()) {
            int a = st.top(); st.pop();
            scc[a] = scnt;
            if (a == v) break;
        }
    }
    return ret;
}

vector<pair<pair<int, int>, int>> edgList;

void solve() {
    memset(dfsn, -1, sizeof(dfsn));
    memset(scc, -1, sizeof(scc));
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> C[j][i];
            C[j][i]--;
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> P[i].x >> P[i].y;
        P[i].x--, P[i].y--;
        conn2[P[i].x].push_back(mp(i, 0));
        conn2[P[i].y].push_back(mp(i, 1));
    }

    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        a--, b--, t--;
        edgList.push_back(mp(mp(a, b), t));

        for (int j = 0; j < 5; j++) {
            int v1 = getNum(a, t, j) << 1;
            int v2 = getNum(b, t, j) << 1;
            adj[v1 ^ 1].push_back(v2 ^ 1);
            adj[v2 ^ 1].push_back(v1 ^ 1);
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }
    }

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < conn2[i].size(); j++) {
            for (int k = j + 1; k < conn2[i].size(); k++) {
                int v1 = conn2[i][j].x + n * conn2[i][j].y << 1;
                int v2 = conn2[i][k].x + n * conn2[i][k].y << 1;

                adj[v1 ^ 1].push_back(v2);
                adj[v2 ^ 1].push_back(v1);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        auto [u, v] = P[i];
        int uV = i << 1;
        int vV = i + n << 1;
        adj[uV].push_back(vV ^ 1);
        adj[uV ^ 1].push_back(vV);
        adj[vV].push_back(uV ^ 1);
        adj[vV ^ 1].push_back(uV);

        for (int j = 0; j < 4; j++) {
            int nx = getNum(u, j, C[j][i]) << 1;
            adj[uV ^ 1].push_back(nx ^ 1);
            adj[nx].push_back(uV);
            nx = getNum(v, j, C[j][i]) << 1;
            adj[vV ^ 1].push_back(nx ^ 1);
            adj[nx].push_back(vV);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int w = 0; w < 4; w++) {
            for (int j = 0; j < 5; j++) {
                for (int k = j + 1; k < 5; k++) {

                    int n1 = getNum(i, w, j) << 1;
                    int n2 = getNum(i, w, k) << 1;

                    adj[n1 ^ 1].push_back(n2);
                    adj[n2 ^ 1].push_back(n1);
                }
            }
        }
    }

    int maxV = getNum(n - 1, 3, 4) << 1;
    maxV += 10;
    for (int i = 0; i < maxV; i++) {
        if (dfsn[i] == -1) dfs(i);
    }

    /*for (int i = 0; i < n; i++) {
        for (int w = 0; w < 4; w++) {
            for (int j = 0; j < 5; j++) {
                int n1 = getNum(i, w, j) << 1;
                if (scc[n1] == scc[n1 ^ 1]) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }*/

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int v1 = i << 1;
        int v2 = i + n << 1;

        if (scc[v1] == scc[v1 ^ 1] || scc[v2] == scc[v2 ^ 1]) {
            cout << "NO\n";
            return;
        }

        if (scc[v1] < scc[v1 ^ 1]) ans[i] = P[i].y;
        else ans[i] = P[i].x;

        // cout << scc[v1] << ' ' << scc[v1 ^ 1] << " | " << scc[v2] << ' ' << scc[v2 ^ 1] << '\n';

    }

    // check
    bool ok = 1;
    vector<int> pos(n, -1);
    for (int i = 0; i < n; i++) {
        if (pos[ans[i]] != -1) ok = 0;
        pos[ans[i]] = i;
    }

    for (auto& f : edgList) {
        auto [u, v] = f.first;

        int t = f.second;
        ok &= C[t][pos[u]] == C[t][pos[v]];
    }
    assert(ok);

    cout << "YES\n";
    for (auto f : pos) cout << f + 1 << ' ';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
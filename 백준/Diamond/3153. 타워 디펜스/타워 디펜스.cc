#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

int n, m;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}

char G[101][101];
int idx[101][101];

const int MAXN = 101010;
vector<int> adj[MAXN];
int dfsn[MAXN];
int scc[MAXN];
stack<int> st;
int ord = 0, scnt = 0;
int dfs(int v) {
    dfsn[v] = ord++; 
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

int getNum(int ix, int dir) {
    return ((ix << 2) + dir) << 1;
}

vector<int> conn[101][101];

void solve() {    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> G[i][j];
        }
    }

    memset(idx, -1, sizeof(idx));
    memset(dfsn, -1, sizeof(dfsn));
    memset(scc, -1, sizeof(scc));

    vector<pair<int, int>> Tlst;
    int cc = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (G[i][j] == 'T') {
                idx[i][j] = cc++;
                Tlst.push_back(mp(i, j));

                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    int nn = getNum(idx[i][j], k);
                    int tn = getNum(idx[i][j], (k + 2) % 4);

                    vector<pair<int, int>> able;

                    adj[nn].push_back(tn ^ 1);
                    adj[nn ^ 1].push_back(tn);
                    bool ok = 1;
                    while (inGrid(ni, nj)) {
                        if (G[ni][nj] == 'n') {
                            able.push_back(mp(ni, nj));
                        }
                        if (G[ni][nj] == '#') break;
                        if (G[ni][nj] == 'T') {
                            adj[nn].push_back(nn ^ 1);
                            ok = 0;
                            break;
                        }

                        ni += dx[k];
                        nj += dy[k];
                    }

                    if (ok) {
                        for (auto& [a, b] : able) {
                            conn[a][b].push_back(nn);
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (G[i][j] == 'n') {
                if (conn[i][j].size() == 1) {
                    int v = conn[i][j][0];
                    adj[v ^ 1].push_back(v);
                }
                else {
                    for (auto f1 : conn[i][j]) {
                        for (auto f2 : conn[i][j]) {
                            if (f1 == f2) continue;
                            adj[f1 ^ 1].push_back(f2);
                        }
                    }
                }

            }
        }
    }

    for (int i = 0; i < cc * 8; i++) {
        if (dfsn[i] == -1) {
            dfs(i);
        }
    }

    vector<int> conv = { 3, 2, 4, 1 };
    for (int i = 0; i < cc; i++) {
        auto [a, b] = Tlst[i];
        G[a][b] = '0';
        int res = 0;
        for (int k = 0; k < 2; k++) {
            int nn = getNum(i, k), nn2 = getNum(i, k + 2);

            if (scc[nn] < scc[nn2]) {
            }
            else {
                res += 1 << k;
            }
        }
        res = conv[res];
        G[a][b] += res;
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << G[i][j];
        }
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
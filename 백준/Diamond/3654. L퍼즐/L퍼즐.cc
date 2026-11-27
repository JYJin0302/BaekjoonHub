#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int n, m;
bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}
char G[505][505];
int idx[505][505];

const int MAXN = 500 * 500;
vector<int> adj[4*MAXN];
int dfsn[4 * MAXN];
int scc[4 * MAXN];
stack<int> stk;
int ord = 0;
int dfs(int v) {
    dfsn[v] = ord++;
    int ret = dfsn[v];
    stk.push(v);
    for (auto f : adj[v]) {
        if (dfsn[f] == -1) {
            ret = min(ret, dfs(f));
        }
        else if (scc[f] == -1) {
            ret = min(ret, dfsn[f]);
        }
    }
    if (ret == dfsn[v]) {
        while (!stk.empty()) {
            int a = stk.top();
            stk.pop();
            scc[a] = v;
            if (a == v) break;
        }
    }
    return ret;
}


int getNum(int i, int j, int dir, int inv = 0){
    int res = idx[i][j];
    res = (res << 2) + dir;
    res = (res << 1) + inv;
    return res;
}

void solve() {

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> G[i][j];
            idx[i][j] = -1;
        }
    }
    while (!stk.empty()) stk.pop();

    vector<pair<int, int>> bLst;
    bool ok = 1;
    int cB = 0, cW = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (G[i][j] == 'W') {
                cW++;

                bool tmp = 0;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (inGrid(ni, nj) && G[ni][nj] == 'B') tmp = 1;
                }
                if (!tmp) ok = 0;
            }
            else if (G[i][j] == 'B') {
                idx[i][j] = cB++;
                bLst.push_back(mp(i, j));
            }
        }
    }

    if (cB * 2 != cW) ok = 0;

    if (!ok) {
        cout << "NO\n";
        return;
    }

    ord = 0;
    for (int i = 0; i < 8*cB; i++) {
        dfsn[i] = scc[i] = -1;
        adj[i].clear();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (G[i][j] == 'B') {
                vector<int> res, nn;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (inGrid(ni, nj) && G[ni][nj] == 'W') {
                        res.push_back(1);
                        nn.push_back(getNum(i, j, k));
                    }
                    else {
                        res.push_back(0);
                        nn.push_back(-1);
                    }
                }

                if (res[0] && res[2]) {
                    adj[nn[0]].push_back(nn[2] ^ 1);
                    adj[nn[0] ^ 1].push_back(nn[2]);
                    adj[nn[2]].push_back(nn[0] ^ 1);
                    adj[nn[2] ^ 1].push_back(nn[0]);
                }
                else if (res[0]) {
                    adj[nn[0] ^ 1].push_back(nn[0]);
                    adj[nn[2]].push_back(nn[0] ^ 1);
                }
                else if (res[2]) {
                    adj[nn[2] ^ 1].push_back(nn[2]);
                }
                else ok = 0;

                if (res[1] && res[3]) {
                    adj[nn[1]].push_back(nn[3] ^ 1);
                    adj[nn[1] ^ 1].push_back(nn[3]);
                    adj[nn[3]].push_back(nn[1] ^ 1);
                    adj[nn[3] ^ 1].push_back(nn[1]);
                }
                else if (res[1]) {
                    adj[nn[1] ^ 1].push_back(nn[1]);
                }
                else if (res[3]) {
                    adj[nn[3] ^ 1].push_back(nn[3]);
                }
                else ok = 0;
            }
            else if (G[i][j] == 'W') {
                vector<int> nn;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (inGrid(ni, nj) && G[ni][nj] == 'B') {
                        nn.push_back(getNum(ni, nj, (k+2)%4));
                    }
                }

                for (auto f1 : nn) {
                    for (auto f2 : nn) {
                        if (f1 == f2) continue;
                        adj[f1].push_back(f2 ^ 1);
                    }
                }
            }
        }
    }

    if (!ok) {
        cout << "NO\n";
        return;
    }
    /*for (int i = 0; i < cB * 8; i++) {
        cout << "Adj: " << i << " | ";
        for (auto f : adj[i]) cout << f << ' ';
        cout << '\n';
    }*/

    for (int i = 0; i < 8 * cB; i++) {
        if (dfsn[i] == -1) dfs(i);
    }

    for (int i = 0; i < 8 * cB; i+= 2) {
        if (scc[i] == scc[i ^ 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
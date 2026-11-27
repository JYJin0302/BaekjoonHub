#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n, m;
char G[55][55];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}

vector<int> adj[2525];
int L[2525];
int vis[2525];
int vCnt = 0;

bool go(int v, int no = -1) {
    if (vis[v] == vCnt) return 0;
    vis[v] = vCnt;
    for (auto f : adj[v]) if (f != no) {
        if (L[f] == -1 || go(L[f], no)) {
            L[f] = v;
            return 1;
        }
    }
    return 0;
}

void solve() {

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> G[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (G[i][j] == '#') continue;
            int v1 = i * m + j;
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (inGrid(ni, nj) && G[ni][nj] != '#') {
                    int v2 = ni * m + nj;
                    adj[v1].push_back(v2);
                }
            }
        }
    }

    memset(L, -1, sizeof L);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i+j) & 1) {
                vCnt++;
                go(i*m+j);
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int ix = i * m + j;
            if ((i+j) & 1 || G[i][j] == '#') continue;
            
            if (L[ix] == -1) ret++;
            else {
                vCnt++;
                int tL = L[ix];
                L[ix] = -1;
                if (go(tL, ix)) {
                    ret++;
                }
                else L[ix] = tL;
            }
        }
    }

    memset(L, -1, sizeof L);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i + j) % 2 == 0) {
                vCnt++;
                go(i * m + j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int ix = i * m + j;
            if ((i+j)%2 == 0 || G[i][j] == '#') continue;

            if (L[ix] == -1) ret++;
            else {
                vCnt++;
                int tL = L[ix];
                L[ix] = -1;
                if (go(tL, ix)) {
                    ret++;
                }
                else L[ix] = tL;
            }
        }
    }
    cout << ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
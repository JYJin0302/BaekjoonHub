#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n, m;
char G[111][111];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}

vector<int> adj[10101];
int L[10101];
int vis[10101];
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

char ans[101][101];
void solve() {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> G[i][j];
            adj[i * m + j].clear();
            ans[i][j] = 'B';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (G[i][j] == 'X') continue;
            int v1 = i * m + j;
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (inGrid(ni, nj) && G[ni][nj] != 'X') {
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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int ix = i * m + j;
            if ((i+j) & 1 || G[i][j] == 'X') continue;
            
            if (L[ix] == -1) {
                ans[i][j] = 'A';
            }
            else {
                vCnt++;
                int tL = L[ix];
                L[ix] = -1;
                if (go(tL, ix)) {
                    ans[i][j] = 'A';
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
            if ((i+j)%2 == 0 || G[i][j] == 'X') continue;

            if (L[ix] == -1) {
                ans[i][j] = 'A';
            }
            else {
                vCnt++;
                int tL = L[ix];
                L[ix] = -1;
                if (go(tL, ix)) {
                    ans[i][j] = 'A';
                }
                else L[ix] = tL;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (G[i][j] == 'X') {
                cout << "X";
            }
            else cout << char('A' + 'B' - ans[i][j]);
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;

    while (n + m) {
        solve();
        cin >> n >> m;
    }
}
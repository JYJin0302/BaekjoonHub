#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


int n, m;
int A[101][101];
bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < n;
}

int gL[101][101];
int gR[101][101];

vector<int> adj[10101];

int conn[10101];
bool vs[10101];

bool go(int v) {
    if (vs[v]) return 0;
    vs[v] = 1;

    for (auto f : adj[v]) {
        if (conn[f] == -1 || go(conn[f])) {
            conn[f] = v;
            return 1;
        }
    }
    return 0;
}

void solve() {

    cin >> n >> m;
    memset(gL, -1, sizeof(gL));
    memset(gR, -1, sizeof(gR));

    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        A[a][b] = 1;
    }

    int oL = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == 1) continue;
            if (inGrid(i - 1, j + 1) && gL[i - 1][j + 1] != -1) {
                gL[i][j] = gL[i - 1][j + 1];
            }
            else {
                gL[i][j] = ++oL;
            }
        }
    }

    int oR = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == 1) continue;
            if (inGrid(i - 1, j - 1) && gR[i - 1][j - 1] != -1) {
                gR[i][j] = gR[i - 1][j - 1];
            }
            else {
                gR[i][j] = ++oR;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (gL[i][j] != -1) {
                adj[gL[i][j]].push_back(gR[i][j]);
            }
        }
    }

    //cout << "GL\n";
    //for (int i = 0; i < n; i++) {
    //    for (int j = 0; j < n; j++) {
    //        cout << gL[i][j] << ' ';
    //    }
    //    cout << '\n';
    //}
    //cout << "GR\n";
    //for (int i = 0; i < n; i++) {
    //    for (int j = 0; j < n; j++) {
    //        cout << gR[i][j] << ' ';
    //    }
    //    cout << '\n';
    //}

    memset(conn, -1, sizeof(conn));
    int ans = 0;
    for (int i = 1; i <= oL; i++) {
        for (int j = 1; j <= oL; j++) vs[j] = 0;
        if (go(i)) ans++;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int n;
int G[100][100];
bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < n;
}

bool col[5][105], row[5][105];
int visC[105], visR[105];
int cntC[105], cntR[105];
int res[15][15][15];

bool getAns(int x, int y,  int dir = 0, int pv = 0) {

    if (G[x][y] != -1) {
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= 3; j++) {
                ok &= row[j][i] && col[j][i];
            }
        }
        if (ok) {
            /*cout << "ANsfor: " << n << '\n';
            pf();*/

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    res[n][i][j] = G[i][j];
                }
            }
        }
        return ok;
    }

   // if (x == y) pf();

    visR[x]++;
    visC[y]++;

    bool ok = 1;
    bool nd = 0;

    int rem = n - visR[x] + 1;
    if (rem < 3 - cntR[x]) ok = 0;
    else if (rem == 3 - cntR[x]) nd = 1;
    rem = n - visC[y] + 1;
    if (rem < 3 - cntC[y]) ok = 0;
    else if (rem == 3 - cntC[y]) nd = 1;
    if (!ok) {
        visR[x]--;
        visC[y]--;
        return 0;
    }

    int nx = pv % 3 + 1;

    for (int j = nd; j <= 3; j++) {
        if (j && j != nx)continue;
        if (!j || (!row[j][x] && !col[j][y])) {

            if (j) {
                cntR[x]++;
                cntC[y]++;
            }

            row[j][x] = 1;
            col[j][y] = 1;
            G[x][y] = j;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
    
            if (!inGrid(nx, ny) || G[nx][ny] != -1) {
                dir = (dir + 1) % 4;
                nx = x + dx[dir];
                ny = y + dy[dir];
            }
            int nj = pv;
            if (j) nj = j;
            if (getAns(nx, ny, dir, nj)) return 1;

            row[j][x] = 0;
            col[j][y] = 0;
            G[x][y] = -1;
            if (j) {
                cntR[x]--;
                cntC[y]--;
            }
        }
    }
    visR[x]--;
    visC[y]--;
    return 0;
}

int ans[202][202];
void fillAns(int ix, int len) {
    if (len <= 10) {
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                ans[i + ix][j + ix] = res[len][i][j];
            }
        }
        return;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ans[ix + i][ix + j] = res[6][i][j];
            ans[ix + i][ix + len - 1 - j] = res[6][i][5 - j];
            ans[ix + len - 1 - i][ix + j] = res[6][5 - i][j];
            ans[ix + len - 1 - i][ix + len -1 - j] = res[6][5 - i][5 - j];
        }
    }
    fillAns(ix + 3, len - 6);
}

void solve() {

    for (n = 5; n <= 10; n++) {
        memset(G, -1, sizeof(G));
        memset(col, 0, sizeof(col));
        memset(row, 0, sizeof(row));
        memset(visR, 0, sizeof(visR));
        memset(visC, 0, sizeof(visC));
        memset(cntR, 0, sizeof(cntR));
        memset(cntC, 0, sizeof(cntC));
        getAns(0, 0);
    }

    int x;
    cin >> x;

    fillAns(0, x);

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            cout << ans[i][j] << ' ';
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
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n, m;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
// U R D L

bool inGrid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
char ans[55][55];
char tmp[55][55];

pair<int, int> tilt(int x, int y, int ang) {
    // 시계방향 ang 만큼 돌리기
    if (ang == 0) return mp(x, y);
    if (ang == 1) return mp(y, n - 1 - x);
    if (ang == 2) return mp(n - 1 - x, m - 1 - y);
    return mp(m - 1 - y, x);
}

void solve() {
    memset(ans, '?', sizeof ans);

    cin >> n >> m;

    string ts = "URDL";
    map<char, int> idx;
    for (int i = 0; i < 4; i++) idx[ts[i]] = i;


    int x, y;
    char d;
    cin >> x >> y >> d;
    int dir = idx[d];
    x--, y--;

    int tx = x + dx[dir];
    int ty = y + dy[dir];
    if (inGrid(tx, ty)) {
        // possible
        if (d == 'U' || d == 'D') {
            for (int j = 0; j < m; j++) {
                for (int i = 0; i < n; i++) {
                    if ((j & 1) == (y & 1)) ans[i][j] = d;
                    else ans[i][j] = char('U' + 'D' - d);
                }
                
                if (ans[0][j] == 'U') ans[0][j] = 'R';
                else ans[n - 1][j] = 'R';
            }
        }
        else {
            for (int i = 0; i < n; i++) { 
                for (int j = 0; j < m; j++){
                    if ((i & 1) == (x & 1)) ans[i][j] = d;
                    else ans[i][j] = char('R' + 'L' - d);
                }

                if (ans[i][0] == 'L') ans[i][0] = 'D';
                else ans[i][m-1] = 'D';
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++) { 
                cout << ans[i][j];
            }
            cout << '\n';
        }
        return;
    }

    int tt = 0;
    if (dir) {
        tie(x, y) = tilt(x, y, 4 - dir);
        tt = 4 - dir;
        if (dir & 1) swap(n, m);
        dir = 0;
    }

    int flip = 0;
   // cout << "TT: " << tt << ' ' << x << ' ' << y << '\n';
    if ((y & 1) && ((m - 1 - y) & 1)) {
        //cout << y << ' ' << m - 1 - y << '\n';
        if (n & 1) {
            cout << "Impossible\n";
            return;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= y; j++) {
                if (i & 1) ans[i][j] = 'L';
                else ans[i][j] = 'R';
            }
            if (i & 1) ans[i][0] = 'U';
            else ans[i][y] = 'U';

            for (int j = y + 1; j < m; j++) {
                if (i & 1) ans[i][j] = 'L';
                else ans[i][j] = 'R';
            }
            if (i != n - 1) {
                if (i & 1) ans[i][y + 1] = 'D';
                else ans[i][m - 1] = 'D';
            }
        }

    }
    else {

        if (y & 1) {
            // 좌우대칭
            flip = 1;
            y = m - 1 - y;
        }
        if (y == 0) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i & 1) ans[i][j] = 'R';
                    else ans[i][j] = 'L';
                }

                if (i & 1) ans[i][m - 1] = 'U';
                else ans[i][0] = 'U';
            }
        }
        else {

            for (int j = 0; j < y; j++) ans[0][j] = 'R';
            if (n == 2) {
                for (int j = 0; j <= y; j++) {
                    ans[1][j] = 'L';
                }
                ans[1][0] = 'U';
            }
            else {
                for (int j = 0; j <= y; j++) {
                    for (int i = 1; i < n; i++) {
                        if (j & 1) ans[i][j] = 'D';
                        else ans[i][j] = 'U';
                    }

                    if (j) {
                        if (j & 1) ans[n - 1][j] = 'L';
                        else ans[1][j] = 'L';
                    }
                }
            }

            for (int j = y + 1; j < m; j++) {
                int df = j - y;
                for (int i = 0; i < n; i++) {
                    if (df & 1) ans[i][j] = 'D';
                    else ans[i][j] = 'U';
                }

                if (df & 1) ans[n - 1][j] = 'L';
                else ans[0][j] = 'L';
            }
        }
        ans[x][y] = 'U';
    }

    /*cout << "cur " << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }*/
    if (flip) {
        memset(tmp, '?', sizeof tmp);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tmp[i][j] = ans[i][m - 1 - j];
                if (tmp[i][j] == 'L' || tmp[i][j] == 'R') {
                    tmp[i][j] = char('L' + 'R' - tmp[i][j]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = tmp[i][j];
            }
        }
    }

    if (tt) {
        tt = 4 - tt;
        memset(tmp, '?', sizeof tmp);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                auto [ti, tj] = tilt(i, j, tt);
               // cout << i << ' ' << j << ' ' << tt << " => " << ti << ' ' << tj << '\n';
                tmp[ti][tj] = ans[i][j];
                int tx = idx[tmp[ti][tj]];
                tx = (tx + tt) % 4;
                tmp[ti][tj] = ts[tx];
            }
        }
        if (tt & 1) swap(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = tmp[i][j];
            }
        }
       
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j];
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
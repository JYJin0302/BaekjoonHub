#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

int n;
char grid[33][33];
int dp[700][700];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool inGrid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int sx = -1;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            grid[i][j] = s[j];
            if (grid[i][j] == '*') {
                sx = i * n + j;
            }
        }
    }

    memset(dp, -1, sizeof(dp));
    queue<pair<int, int>> q;
    // player, box
    for (int i = 0; i < n * n; i++) {
        if (grid[i / n][i % n] == '.') {
            dp[i][sx] = 0;
            q.push(mp(i, sx));
        }
    }

    int ans = 0;
    while (!q.empty()) {

        int player, box;
        tie(player, box) = q.front();
        q.pop();
        ans = max(ans, dp[player][box]);

        int px = player / n;
        int py = player % n;

        for (int i = 0; i < 4; i++) {

            int nx = px + dx[i];
            int ny = py + dy[i];

            if (inGrid(nx, ny) && grid[nx][ny] != '#') {

                int nVal = nx * n + ny;
                if (nVal != box) {
                    if (dp[nVal][box] == -1) {
                        dp[nVal][box] = dp[player][box] + 1;
                        q.push(mp(nVal, box));
                    }
                }
                else {

                    int tx = px + dx[(i + 2) % 4];
                    int ty = py + dy[(i + 2) % 4];

                    if (inGrid(tx, ty) && grid[tx][ty] != '#') {
                        int nPos = tx * n + ty;
                        int bPos = player;
                        
                        if (dp[nPos][bPos] == -1) {
                            dp[nPos][bPos] = dp[player][box] + 1;
                            q.push(mp(nPos, bPos));
                        }
                    }
                }
            }
        }
    }

    cout << ans;

}
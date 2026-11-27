#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#define INF 100000000
#define pb push_back
#define all(x) (x).begin(),(x).end()

int n;
vector<string> grid;
int dp[50][50][2];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < n;
}

int main() {


    cin >> n;
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        grid.push_back(s);
    }

    vector<pair<int, int>> door;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '#') door.push_back({ i, j });
        }
    }

    int x, y;
    tie(x, y) = door[0];
    queue<tuple<int, int, int>> q;
    q.push({ x, y, 0 });
    q.push({ x, y, 1 });
    dp[x][y][0] = 0;
    dp[x][y][1] = 0;

    int tx, ty;
    tie(tx, ty) = door[1];
    // 0: 가로, 1: 세로
    while (!q.empty()) {
        int a, b, d;
        tie(a, b, d) = q.front();
        q.pop();

        for (int ti = 0; ti < 2; ti++) {
            int i = ti * 2 + 1 - d;
            int na = a, nb = b;
            na += dx[i], nb += dy[i];
            while (inGrid(na, nb) && grid[na][nb] != '*') {
                if (dp[na][nb][1 - d] != -1) break;
                if (grid[na][nb] == '!') {
                    dp[na][nb][1 - d] = dp[a][b][d] + 1;
                    q.push({ na, nb, 1-d });
                    
                }
                if (na == tx && nb == ty) {
                    cout << dp[a][b][d];
                    return 0;
                }
                na += dx[i], nb += dy[i];
            }
        }
    }

}
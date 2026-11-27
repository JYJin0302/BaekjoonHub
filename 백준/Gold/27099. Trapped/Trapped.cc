#include <bits/stdc++.h>
using namespace std;

char grid[101][101];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int n, m;
bool vs[101][101];

bool inGrid(int x, int y) {
    return x >= 0 && x <= 2 * n + 2 && y >= 0 && y <= 2 * m + 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    cin.ignore();
    memset(grid, ' ', sizeof(grid));

    for (int i = 0; i < n * 2 + 1; i++) {
        string s;
        getline(cin, s);

        for (int j = 0; j < s.size(); j++) {
            grid[i + 1][j + 1] = s[j];
        }
    }


    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    vs[0][0] = 1;
    while (!q.empty()) {
        int a, b;
        tie(a, b) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int na = a + dx[i];
            int nb = b + dy[i];
            if (inGrid(na, nb) && !vs[na][nb] && grid[na][nb] == ' ') {
                vs[na][nb] = 1;
                q.push({ na, nb });
            }
        }
    }

    int ans = 0;
    for (int i = 2; i <= n * 2; i += 2) {
        for (int j = 2; j <= m * 2; j += 2) {
            if (!vs[i][j]) ans++;
        }
    }
    cout << ans;
}
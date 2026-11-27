#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int n, l, r;
int grid[51][51];
bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < n;
}

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool ck = 1;

bool v[51][51];
void move() {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) v[i][j] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!v[i][j]) {
                v[i][j] = 1;
                // bfs
                vector<pair<int, int>> visited;
                int tot = 0, num = 0;

                queue<pair<int, int>> q;
                q.push({ i, j });
                while (!q.empty()) {

                    int a, b;
                    tie(a, b) = q.front();
                    visited.push_back(q.front());
                    q.pop();

                    num++;
                    tot += grid[a][b];

                    for (int k = 0; k < 4; k++) {
                        int na = a + dx[k];
                        int nb = b + dy[k];

                        if (inGrid(na, nb) && !v[na][nb]) {
                            int diff = abs(grid[na][nb] - grid[a][b]);
                            if (diff >= l && diff <= r) {
                                v[na][nb] = 1;
                                q.push({ na, nb });
                            }
                        }
                    }
                }

                if (num > 1) ck = 1;
                tot /= num;
                for (auto i : visited) {

                    int a, b;
                    tie(a, b) = i;
                    grid[a][b] = tot;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    while (ck) {
        ck = 0;

        move();

        ans += ck;
    }

    cout << ans;
}
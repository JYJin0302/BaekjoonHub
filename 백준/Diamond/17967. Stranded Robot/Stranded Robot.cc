#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;

struct pos {
    int x, y, z;
    pos() {
        x = y = z = -1;
    }
    pos(int _x, int _y, int _z) {
        x = _x;
        y = _y;
        z = _z;
    }

    bool operator==(pos& o) {
        return o.x == x && o.y == y && o.z == z;
    }
};
int n, m, p;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
int mX[501][501], MX[501][501];
int mY[501][501], MY[501][501];
int mZ[501][501], MZ[501][501];

bool inGrid(int x, int y, int z) {
    return x >= 0 && x < n&& y >= 0 && y < m&& z >= 0 && z < p;
}


unordered_map<ll, int> dp;

// unordered_map<pair<pos, int>, int, cmp> dp;
// pos, gravity direction => min dist
// direction : +x 1 -x -1, +y 2 -y -2, +z 3 -z -3

ll getKey(pos curr) {
    ll res = 0;
    res += (ll)curr.x * 500 * 500;
    res += (ll)curr.y * 500;
    res += curr.z;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n >> p;
    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 500; j++) {
            mX[i][j] = 1000;
            MX[i][j] = -1000;
            mY[i][j] = 1000;
            MY[i][j] = -1000;
            mZ[i][j] = 1000;
            MZ[i][j] = -1000;
        }
    }

    pos s, e;
    for (int k = 0; k < p; k++) {
        for (int i = 0; i < n; i++) {
            string ss;
            cin >> ss;
            for (int j = 0; j < m; j++) {
                if (ss[j] == 'R') s = { i, j, k };
                else if (ss[j] == 'T') e = { i, j, k };
                else if (ss[j] == '*') {
                    mX[j][k] = min(mX[j][k], i);
                    MX[j][k] = max(MX[j][k], i);
                    mY[i][k] = min(mY[i][k], j);
                    MY[i][k] = max(MY[i][k], j);
                    mZ[i][j] = min(mZ[i][j], k);
                    MZ[i][j] = max(MZ[i][j], k);
                }
            }
        }
    }

    queue<pos> q;
    q.push(s);
    dp[getKey(s)] = 1;

    while (!q.empty()) {

        pos curr = q.front();
        q.pop();
        
        if (curr == e) {
            cout << dp[getKey(curr)] - 1;

            return 0;
        }
        
        //cout << "Curr : " << curr.x << ' ' << curr.y << ' ' << curr.z << " : " << dp[getKey(curr)] << '\n';

        // move
        if (curr.x == mX[curr.y][curr.z] - 1) {
            for (int i = 0; i < 4; i++) {

                int ny = curr.y + dx[i];
                int nz = curr.z + dy[i];

                if (inGrid(0, ny, nz)) {
                    int nx = max(mX[ny][nz] - 1, curr.x);

                    if (inGrid(nx, ny, nz) && nx == mX[ny][nz] - 1 && dp[getKey({ nx, ny, nz })] == 0) {
                        dp[getKey({ nx, ny,nz })] = dp[getKey(curr)] + 1;
                        q.push({ nx, ny,nz });
                    }
                }
            }
        }
        else if (curr.x == MX[curr.y][curr.z] + 1) {
            for (int i = 0; i < 4; i++) {

                int ny = curr.y + dx[i];
                int nz = curr.z + dy[i];

                if (inGrid(0, ny, nz)) {
                    int nx = min(MX[ny][nz] + 1, curr.x);

                    if (inGrid(nx, ny, nz) && nx == MX[ny][nz] + 1 && dp[getKey({ nx, ny, nz })] == 0) {
                        dp[getKey({ nx, ny,nz })] = dp[getKey(curr)] + 1;
                        q.push({ nx, ny,nz });
                    }
                }
            }
        }
        if (curr.y == mY[curr.x][curr.z] - 1) {
            for (int i = 0; i < 4; i++) {

                int nx = curr.x + dx[i];
                int nz = curr.z + dy[i];

                if (inGrid(nx, 0, nz)) {
                    int ny = max(mY[nx][nz] - 1, curr.y);

                    if (inGrid(nx, ny, nz) && ny == mY[nx][nz] - 1 && dp[getKey({ nx, ny, nz })] == 0) {
                        dp[getKey({ nx, ny,nz })] = dp[getKey(curr)] + 1;
                        q.push({ nx, ny,nz });
                    }
                }
            }
        }
        else if (curr.y == MY[curr.x][curr.z] + 1) {
            for (int i = 0; i < 4; i++) {

                int nx = curr.x + dx[i];
                int nz = curr.z + dy[i];

                if (inGrid(nx, 0, nz)) {
                    int ny = min(MY[nx][nz] + 1, curr.y);

                    if (inGrid(nx, ny, nz) && ny == MY[nx][nz] + 1 && dp[getKey({ nx, ny, nz })] == 0) {
                        dp[getKey({ nx, ny,nz })] = dp[getKey(curr)] + 1;
                        q.push({ nx, ny,nz });
                    }
                }
            }
        }
        if (curr.z == mZ[curr.x][curr.y] - 1) {
            for (int i = 0; i < 4; i++) {

                int nx = curr.x + dx[i];
                int ny = curr.y + dy[i];

                if (inGrid(nx, ny, 0)) {
                    int nz = max(mZ[nx][ny] - 1, curr.z);

                    if (inGrid(nx, ny, nz) && nz == mZ[nx][ny] - 1 && dp[getKey({ nx, ny, nz })] == 0) {
                        dp[getKey({ nx, ny,nz })] = dp[getKey(curr)] + 1;
                        q.push({ nx, ny,nz });
                    }
                }
            }
        }
        else if (curr.z == MZ[curr.x][curr.y] + 1) {
            for (int i = 0; i < 4; i++) {

                int nx = curr.x + dx[i];
                int ny = curr.y + dy[i];

                if (inGrid(nx, ny, 0)) {
                    int nz = min(MZ[nx][ny] + 1, curr.z);

                    if (inGrid(nx, ny, nz) && nz == MZ[nx][ny] + 1 && dp[getKey({ nx, ny, nz })] == 0) {
                        dp[getKey({ nx, ny,nz })] = dp[getKey(curr)] + 1;
                        q.push({ nx, ny,nz });
                    }
                }
            }
        }


        // fall
        if (curr.x < mX[curr.y][curr.z] - 1) {
            int nx = mX[curr.y][curr.z] - 1;

            if (inGrid(nx, curr.y, curr.z) && dp[getKey({ nx, curr.y, curr.z })] == 0) {
                dp[getKey({ nx, curr.y, curr.z })] = dp[getKey(curr)] + 1;
                q.push({ nx, curr.y, curr.z });
            }
        }
        if (curr.x > MX[curr.y][curr.z] + 1) {
            int nx = MX[curr.y][curr.z] + 1;

            if (inGrid(nx, curr.y, curr.z) && dp[getKey({ nx, curr.y, curr.z })] == 0) {
                dp[getKey({ nx, curr.y, curr.z })] = dp[getKey(curr)] + 1;
                q.push({ nx, curr.y, curr.z });
            }
        }
        if (curr.y < mY[curr.x][curr.z] - 1) {
            int ny = mY[curr.x][curr.z] - 1;

            if (inGrid(curr.x, ny, curr.z) && dp[getKey({ curr.x, ny, curr.z })] == 0) {
                dp[getKey({ curr.x, ny, curr.z })] = dp[getKey(curr)] + 1;
                q.push({ curr.x, ny, curr.z });
            }
        }
        if (curr.y > MY[curr.x][curr.z] + 1) {
            int ny = MY[curr.x][curr.z] + 1;

            if (inGrid(curr.x, ny, curr.z) && dp[getKey({ curr.x, ny, curr.z })] == 0) {
                dp[getKey({ curr.x, ny, curr.z })] = dp[getKey(curr)] + 1;
                q.push({ curr.x, ny, curr.z });
            }
        }
        if (curr.z < mZ[curr.x][curr.y] - 1) {
            int nz = mZ[curr.x][curr.y] - 1;

            if (inGrid(curr.x, curr.y, nz) && dp[getKey({ curr.x, curr.y, nz })] == 0) {
                dp[getKey({ curr.x, curr.y, nz })] = dp[getKey(curr)] + 1;
                q.push({ curr.x, curr.y, nz });
            }
        }
        if (curr.z > MZ[curr.x][curr.y] + 1) {
            int nz = MZ[curr.x][curr.y] + 1;

            if (inGrid(curr.x, curr.y, nz) && dp[getKey({ curr.x, curr.y, nz })] == 0) {
                dp[getKey({ curr.x, curr.y, nz })] = dp[getKey(curr)] + 1;
                q.push({ curr.x, curr.y, nz });
            }
        }
    }
    cout << -1;
}

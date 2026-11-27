#include <bits/stdc++.h>
using namespace std;

struct P {
    int x, y;

    P() {
        x = -1, y = -1;
    }
    P(int pos) {
        x = pos / 8;
        y = pos % 8;
    }
    P(int a, int b) {
        x = a, y = b;
    }
    int idx() {
        return x * 8 + y;
    }

    bool operator==(P& o) {
        return x == o.x && y == o.y;
    }
    string cd() {
        string res;
        res += char('a' + x);
        res += char('1' + y);
        return res;
    }
};

int n = 8;
int dp[2][64][64][64];
// 차례, 룩 두개 위치, 킹 위치
// 0 : 킹 차례, 1 : 룩 차례

int dx[] = { -1, 0 ,1, 0 , -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1 , 1, -1, 1, -1 };

bool inGrid(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}
bool inGrid(P p) {
    return inGrid(p.x, p.y);
}

void solve(int t, P r1, P r2, P k) {

    for (auto i : { r1, r2, k }) {
        cout << char('a' + i.x) << char('1' + i.y) << ' ';
    }
    cout << '\n';
    int currVal = dp[t][r1.idx()][r2.idx()][k.idx()];
    if (currVal == 0) return;
    if (t == 0) {
        for (int i = 0; i < 8; i++) {
            int nx = k.x + dx[i];
            int ny = k.y + dy[i];

            if (inGrid(nx, ny)) {
                if (dp[1 - t][r1.idx()][r2.idx()][nx * 8 + ny] == currVal - 1) {
                    solve(1 - t, r1, r2, nx * 8 + ny);
                    return;
                }
            }
        }
        cout << "ERRor\n";
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = r1.x + dx[i];
        int ny = r1.y + dy[i];
        while (inGrid(nx, ny)) {
            if (P(nx, ny) == r2) break;
            if (dp[1 - t][nx * 8 + ny][r2.idx()][k.idx()] == currVal - 1) {
                solve(1 - t, nx * 8 + ny, r2, k);
                return;
            }
            nx += dx[i];
            ny += dy[i];
        }
    }
    swap(r1, r2);
    for (int i = 0; i < 4; i++) {
        int nx = r1.x + dx[i];
        int ny = r1.y + dy[i];
        while (inGrid(nx, ny)) {
            if (P(nx, ny) == r2) break;
            if (dp[1 - t][nx * 8 + ny][r2.idx()][k.idx()] == currVal - 1) {
                solve(1 - t, r2, nx * 8 + ny, k);
                return;
            }
            nx += dx[i];
            ny += dy[i];
        }
    }

    cout << "ERROR\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));
    // x, y -> 8*x + y

    queue<tuple<int, P, P, P>> q;

    // 체크메이트 상태 확인
    for (int i = 0; i < 8; i++) {
        int kPos;
        // 0, i
        kPos = i;
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                if (abs(i - j) > 1 && abs(i - k) > 1) {
                    dp[0][j][8 + k][kPos] = 0;
                    dp[0][8 + k][j][kPos] = 0;
                    q.push({ 0, j, 8 + k, kPos });
                }
            }
        }

        // i, 0
        kPos = i * 8;
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                if (abs(i - j) > 1 && abs(i - k) > 1) {
                    dp[0][j * 8][k * 8 + 1][kPos] = 0;
                    dp[0][k * 8 + 1][j * 8][kPos] = 0;
                    q.push({ 0, j * 8, k * 8 + 1, kPos });
                }
            }
        }

        // 7, i
        kPos = 7 * 8 + i;
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                if (abs(i - j) > 1 && abs(i - k) > 1) {
                    dp[0][6 * 8 + j][7 * 8 + k][kPos] = 0;
                    dp[0][7 * 8 + k][6 * 8 + j][kPos] = 0;
                    q.push({ 0, 6 * 8 + j, 7 * 8 + k, kPos });
                }
            }
        }
        // i, 7
        kPos = 8 * i + 7;
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                if (abs(i - j) > 1 && abs(i - k) > 1) {
                    dp[0][8 * j + 6][8 * k + 7][kPos] = 0;
                    dp[0][8 * k + 7][8 * j + 6][kPos] = 0;
                    q.push({ 0, 8 * j + 6, 8 * k + 7, kPos });
                }
            }
        }
    }

    // stalemate
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {

            // 0, 0
            if (i > 1 && j > 1) {
                dp[0][8 + i][8 * j + 1][0] = 50;
            }

            // 7, 0
            if (i < 6 && j > 1) {
                dp[0][i * 8 + 1][6 * 8 + j][7 * 8] = 50;
            }

            // 0, 7
            if (i < 6 && j > 1) {
                dp[0][8 + i][j * 8 + 6][7] = 50;
            }

            // 7, 7
            if (i < 6 && j < 6) {
                dp[0][6 * 8 + i][j * 8 + 6][7 * 8 + 7] = 50;
            }
        }
    }

    while (!q.empty()) {

        int t;
        P r1, r2, k;
        tie(t, r1, r2, k) = q.front();
        q.pop();

       // cout << "CURR: " << t << ' ' << r1.cd() << ' ' << r2.cd() << ' ' << k.cd() << '\n';

        if (t == 0) {
            // move rook
            // no check

            // r1
            bool case1 = 0;
            if (r1.x == k.x || r1.y == k.y) case1 = 1;
            if (r2.x == k.x || r2.y == k.y) {
                case1 = 1;
                swap(r1, r2);
            }

            for (int i = 0; i < 4; i++) {
                int nx = r1.x + dx[i];
                int ny = r1.y + dy[i];

                while (inGrid(nx, ny)) {
                    bool ok = 1;
                    if (P(nx, ny) == r2) break;
                    if (nx == k.x || ny == k.y) ok = 0;
                    if (dp[1][nx * 8 + ny][r2.idx()][k.idx()] != -1) ok = 0;

                    if (ok) {
                        dp[1][nx * 8 + ny][r2.idx()][k.idx()] = dp[0][r1.idx()][r2.idx()][k.idx()] + 1;
                        dp[1][r2.idx()][nx * 8 + ny][k.idx()] = dp[0][r1.idx()][r2.idx()][k.idx()] + 1;
                        q.push({ 1, nx * 8 + ny, r2, k });
                    }
                    nx += dx[i];
                    ny += dy[i];
                }
            }

            if (case1) continue;
            swap(r1, r2);
            // r2
            for (int i = 0; i < 4; i++) {
                int nx = r1.x + dx[i];
                int ny = r1.y + dy[i];

                while (inGrid(nx, ny)) {
                    bool ok = 1;
                    if (P(nx, ny) == r2) break;
                    if (nx == k.x || ny == k.y) ok = 0;
                    if (dp[1][nx * 8 + ny][r2.idx()][k.idx()] != -1) ok = 0;

                    if (ok) {
                        dp[1][nx * 8 + ny][r2.idx()][k.idx()] = dp[0][r1.idx()][r2.idx()][k.idx()] + 1;
                        dp[1][r2.idx()][nx * 8 + ny][k.idx()] = dp[0][r1.idx()][r2.idx()][k.idx()] + 1;
                        q.push({ 1, nx * 8 + ny, r2, k });
                    }
                    nx += dx[i];
                    ny += dy[i];
                }
            }
        }
        else {
            // king move

            // 이동하는 곳에서 룩을 잡을 수 있으면 안됨

            for (int i = 0; i < 8; i++) {
                int nx = k.x + dx[i];
                int ny = k.y + dy[i];

                // 여기서 킹이 갈 수 있는 모든 곳에 대해 dp가 채워져 있어야 함

                if (inGrid(nx, ny)) {
                    bool ok = 1;
                    int cnt = 0;
                    if (nx == r1.x || ny == r1.y) cnt++;
                    if (nx == r2.x || ny == r2.y) cnt++;
                    if (P(nx, ny) == r1 || P(nx, ny) == r2) ok = 0;
                    if (cnt == 2) ok = 0;

                    if (r1.x == r2.x || r1.y == r2.y) {}//ok 
                    else {
                        if (abs(r1.x - nx) <= 1 && abs(r1.y - ny) <= 1) ok = 0;
                        if (abs(r2.x - nx) <= 1 && abs(r2.y - ny) <= 1) ok = 0;
                    }

                    if (dp[0][r1.idx()][r2.idx()][nx * 8 + ny] != -1) ok = 0;

                    for (int j = 0; j < 8; j++) {
                        int tx = nx + dx[j];
                        int ty = ny + dy[j];

                        if (inGrid(tx, ty)) {
                            bool tok = 1;
                            if (tx == r1.x || ty == r1.y) tok = 0;
                            if (tx == r2.x || ty == r2.y) tok = 0;

                            if (tok && (dp[1][r1.idx()][r2.idx()][tx * 8 + ty] == -1 || dp[1][r1.idx()][r2.idx()][tx*8+ty] == 50)) ok = 0;

                        }
                    }
                    if (ok) {
                        dp[0][r1.idx()][r2.idx()][nx * 8 + ny] = dp[t][r1.idx()][r2.idx()][k.idx()] + 1;
                        dp[0][r2.idx()][r1.idx()][nx * 8 + ny] = dp[t][r1.idx()][r2.idx()][k.idx()] + 1;
                        q.push({ 0, r1, r2, nx * 8 + ny });
                    }
                }
            }
        }

    }

    int t;
    cin >> t;
    while (t--) {

        string k, r1, r2;
        cin >> k >> r1 >> r2;

        P R1((r1[0] - 'a') * 8 + (r1[1] - '1'));
        P R2((r2[0] - 'a') * 8 + (r2[1] - '1'));
        P K((k[0] - 'a') * 8 + (k[1] - '1'));

        cout << (dp[1][R1.idx()][R2.idx()][K.idx()] + 1) / 2 << '\n';
       // solve(1, R1, R2, K);
    }
}
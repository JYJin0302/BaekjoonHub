#include <bits/stdc++.h>
using namespace std;

//ofstream ofs;

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1 , 1, -1, 1, -1 };

bool inGrid(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

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

int dpP[2][64][64][64], dpQ[2][64][64][64], dpR[2][64][64][64];
// 차례, white 기물 위치, whiteKing 위치, blackKing 위치
// 0 : white 차례, 1 : black 차례

/*
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
*/

bool invalid[8][8];
int isValidPos(char type, P wP, P wK, P bK) {
    // checkmate : 1, stalemate : 0, blackKing in check : 2, else 3 
    // invalid : -1
    if (abs(wK.x - bK.x) <= 1 && abs(wK.y - bK.y) <= 1) return -1; //King attack each other
    if (wP == wK || wP == bK || wK == bK) return -1; // 2 or more pieces in same space
    if (type == 'P' && (wP.y == 0 || wP.y == 7)) return -1; // pawn on 1, 8th rank

    memset(invalid, 0, sizeof(invalid));
    for (int i = 0; i < 8; i++) {
        int nx = wK.x + dx[i];
        int ny = wK.y + dy[i];

        if (inGrid(nx, ny)) invalid[nx][ny] = 1;
    }
    if (type == 'Q') {
        for (int i = 0; i < 8; i++) {
            int nx = wP.x + dx[i];
            int ny = wP.y + dy[i];

            while (inGrid(nx, ny)) {
                invalid[nx][ny] = 1;
                if (P(nx, ny) == wK) break;
                nx += dx[i];
                ny += dy[i];
            }
        }
    }
    else if (type == 'R') {
        for (int i = 0; i < 4; i++) {
            int nx = wP.x + dx[i];
            int ny = wP.y + dy[i];

            while (inGrid(nx, ny)) {
                invalid[nx][ny] = 1;
                if (P(nx, ny) == wK) break;
                nx += dx[i];
                ny += dy[i];
            }
        }
    }
    else if (type == 'P') {
        if (wP.x > 0) invalid[wP.x - 1][wP.y + 1] = 1;
        if (wP.x < 7) invalid[wP.x + 1][wP.y + 1] = 1;
    }

    for (int i = 0; i < 8; i++) {
        int nx = bK.x + dx[i];
        int ny = bK.y + dy[i];

        if (inGrid(nx, ny) && !invalid[nx][ny]) {
            if (invalid[bK.x][bK.y]) return 2;
            return 3;
        }
    }

    if (invalid[bK.x][bK.y]) return 1;
    return 0;
}

void solve(int t, char c, P wP, P wK, P bK) {

    cout << t << ' ' << c << ' ';
    for (auto i : { wP, wK, bK }) cout << i.cd() << ' ';
    cout << '\n';
    int curr = 0;
    if (c == 'Q') curr = dpQ[t][wP.idx()][wK.idx()][bK.idx()];
    else if (c == 'P') curr = dpP[t][wP.idx()][wK.idx()][bK.idx()];
    else curr = dpR[t][wP.idx()][wK.idx()][bK.idx()];

    if (curr == 0) return;

    if (t == 0) {
        // king move
        for (int i = 0; i < 8; i++) {
            int nx = wK.x + dx[i];
            int ny = wK.y + dy[i];

            if (inGrid(nx, ny)) {
                if (c == 'Q' && dpQ[1 - t][wP.idx()][nx * 8 + ny][bK.idx()] == curr - 1) {
                    solve(1 - t, c, wP, P(nx, ny), bK);
                    return;
                }
                if (c == 'R' && dpR[1 - t][wP.idx()][nx * 8 + ny][bK.idx()] == curr - 1) {
                    solve(1 - t, c, wP, P(nx, ny), bK);
                    return;
                }
                if (c == 'P' && dpP[1 - t][wP.idx()][nx * 8 + ny][bK.idx()] == curr - 1) {
                    solve(1 - t, c, wP, P(nx, ny), bK);
                    return;
                }
            }
        }

        // piece move

        if (c == 'Q') {
            for (int i = 0; i < 8; i++) {
                int nx = wP.x + dx[i];
                int ny = wP.y + dy[i];
                while (inGrid(nx, ny)) {

                    if (P(nx, ny) == wK) break;
                    if (dpQ[1 - t][nx * 8 + ny][wK.idx()][bK.idx()] == curr - 1) {
                        solve(1 - t, c, P(nx, ny), wK, bK);
                        return;
                    }

                    nx += dx[i];
                    ny += dy[i];
                }
            }
        }
        else if (c == 'R') {
            for (int i = 0; i < 4; i++) {
                int nx = wP.x + dx[i];
                int ny = wP.y + dy[i];
                while (inGrid(nx, ny)) {

                    if (P(nx, ny) == wK) break;
                    if (dpR[1 - t][nx * 8 + ny][wK.idx()][bK.idx()] == curr - 1) {
                        solve(1 - t, c, P(nx, ny), wK, bK);
                        return;
                    }

                    nx += dx[i];
                    ny += dy[i];
                }
            }
        }
        else {
            if (wP.y == 1) {
                P tmp1(wP.x, wP.y + 1), tmp2(wP.x, wP.y + 2);
                if (dpP[1 - t][tmp2.idx()][wK.idx()][bK.idx()] == curr - 1) {
                    solve(1 - t, c, tmp2, wK, bK);
                    return;
                }
                if (dpP[1 - t][tmp1.idx()][wK.idx()][bK.idx()] == curr - 1) {
                    solve(1 - t, c, tmp1, wK, bK);
                    return;
                }
            }
            else if (wP.y == 6) {
                P tmp1(wP.x, wP.y + 1);
                if (dpQ[1 - t][tmp1.idx()][wK.idx()][bK.idx()] == curr - 1) {
                    solve(1 - t, 'Q', tmp1, wK, bK);
                    return;
                }
                if (dpR[1 - t][tmp1.idx()][wK.idx()][bK.idx()] == curr - 1) {
                    solve(1 - t, 'R', tmp1, wK, bK);
                    return;
                }
            }
            else {
                P tmp1(wP.x, wP.y + 1);
                if (dpP[1 - t][tmp1.idx()][wK.idx()][bK.idx()] == curr - 1) {
                    solve(1 - t, c, tmp1, wK, bK);
                    return;
                }
            }

        }
        cout << "ERROR: white have no move\n";
        return;
    }

    // black move

    for (int i = 0; i < 8; i++) {
        int nx = bK.x + dx[i];
        int ny = bK.y + dy[i];

        if (inGrid(nx, ny)) {
            if (c == 'Q' && dpQ[1 - t][wP.idx()][wK.idx()][nx * 8 + ny] == curr - 1) {
                solve(1 - t, c, wP, wK, P(nx, ny));
                return;
            }
            if (c == 'R' && dpR[1 - t][wP.idx()][wK.idx()][nx * 8 + ny] == curr - 1) {
                solve(1 - t, c, wP, wK, P(nx, ny));
                return;
            }
            if (c == 'P' && dpP[1 - t][wP.idx()][wK.idx()][nx * 8 + ny] == curr - 1) {
                solve(1 - t, c, wP, wK, P(nx, ny));
                return;
            }
        }
    }
    cout << "ERROR: black have no move\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dpP, -1, sizeof(dpP));
    memset(dpQ, -1, sizeof(dpQ));
    memset(dpR, -1, sizeof(dpR));
    // x, y -> 8*x + y

    queue<tuple<int, char, P, P, P>> q;
    // 차례, 타입, wP, wK, bK

    // checkmate
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 64; j++) {
            if (i == j) continue;
            for (int k = 0; k < 64; k++) {
                if (i == k || j == k) continue;

                int res = isValidPos('Q', i, j, k);
                if (res == 1) {
                    dpQ[1][i][j][k] = 0;
                    q.push({ 1, 'Q', i, j, k });
                }
                else if (res == 0) {
                    dpQ[1][i][j][k] = 100;
                }
                res = isValidPos('R', i, j, k);
                if (res == 1) {
                    dpR[1][i][j][k] = 0;
                    q.push({ 1, 'R', i, j, k });
                }
                else if (res == 0) {
                    dpR[1][i][j][k] = 100;
                }

                res = isValidPos('P', i, j, k);
                if (res == 0) {
                    dpP[1][i][j][k] = 100;
                }
            }
        }
    }

    //ofs.open("test.out");
    while (!q.empty()) {

        int t;
        char c;
        P wP, wK, bK;
        tie(t, c, wP, wK, bK) = q.front();
        q.pop();

        /*
        int tRes = 0;

        if (c == 'Q') tRes = dpQ[t][wP.idx()][wK.idx()][bK.idx()];
        else if (c == 'R') tRes = dpR[t][wP.idx()][wK.idx()][bK.idx()];
        else tRes = dpP[t][wP.idx()][wK.idx()][bK.idx()];


        ofs << t << ' ' << c << ' ';
        for (auto i : { wP, wK,bK }) {
            ofs << i.cd() << ' ';
        }
        ofs << "RES: " << tRes << '\n';
        */

        if (t == 1) {
            // white move

            // piece move
            if (c == 'Q') {
                for (int i = 0; i < 8; i++) {
                    int nx = wP.x + dx[i];
                    int ny = wP.y + dy[i];

                    while (inGrid(nx, ny)) {
                        bool ok = 1;
                        int res = isValidPos(c, P(nx, ny), wK, bK);
                        if (res == -1) break;
                        if (res == 2 || res == 1) ok = 0;

                        if (dpQ[0][nx * 8 + ny][wK.idx()][bK.idx()] != -1) ok = 0;

                        if (ok) {
                            dpQ[0][nx * 8 + ny][wK.idx()][bK.idx()] = dpQ[1][wP.idx()][wK.idx()][bK.idx()] + 1;
                            q.push({ 0, c, nx * 8 + ny, wK, bK });
                        }
                        nx += dx[i];
                        ny += dy[i];
                    }
                }

                // promotion
                if (wP.y == 7) {
                    P tmpPawn(wP.x, wP.y - 1);

                    bool ok = 1;
                    int res = isValidPos('P', tmpPawn, wK, bK);
                    if (!(res == 0 || res == 3)) ok = 0;
                    if (dpP[0][tmpPawn.idx()][wK.idx()][bK.idx()] != -1) ok = 0;
                    if (ok) {
                        dpP[0][tmpPawn.idx()][wK.idx()][bK.idx()] = dpQ[1][wP.idx()][wK.idx()][bK.idx()] + 1;
                        q.push({ 0, 'P', tmpPawn, wK, bK });
                    }
                }
            }
            else if (c == 'R') {
                for (int i = 0; i < 4; i++) {
                    int nx = wP.x + dx[i];
                    int ny = wP.y + dy[i];

                    while (inGrid(nx, ny)) {
                        bool ok = 1;
                        int res = isValidPos(c, P(nx, ny), wK, bK);
                        if (res == -1) break;
                        if (res == 2 || res == 1) ok = 0;

                        if (dpR[0][nx * 8 + ny][wK.idx()][bK.idx()] != -1) ok = 0;

                        if (ok) {
                            dpR[0][nx * 8 + ny][wK.idx()][bK.idx()] = dpR[1][wP.idx()][wK.idx()][bK.idx()] + 1;
                            q.push({ 0, c, nx * 8 + ny, wK, bK });
                        }
                        nx += dx[i];
                        ny += dy[i];
                    }
                }

                // promotion
                if (wP.y == 7) {
                    P tmpPawn(wP.x, wP.y - 1);

                    bool ok = 1;
                    int res = isValidPos('P', tmpPawn, wK, bK);
                    if (!(res == 0 || res == 3)) ok = 0;
                    if (dpP[0][tmpPawn.idx()][wK.idx()][bK.idx()] != -1) ok = 0;
                    if (ok) {
                        dpP[0][tmpPawn.idx()][wK.idx()][bK.idx()] = dpR[1][wP.idx()][wK.idx()][bK.idx()] + 1;
                        q.push({ 0, 'P', tmpPawn, wK, bK });
                    }
                }
            }
            else if (c == 'P') {

                bool ok = 1;
                P tP(wP.x, wP.y - 1);
                int res = isValidPos('P', tP, wK, bK);

                if (!(res == 0 || res == 3)) ok = 0;
                if (dpP[0][tP.idx()][wK.idx()][bK.idx()] != -1) ok = 0;

                if (ok) {
                    dpP[0][tP.idx()][wK.idx()][bK.idx()] = dpP[1][wP.idx()][wK.idx()][bK.idx()] + 1;
                    q.push({ 0, 'P', tP, wK, bK });
                }

                // move two space
                if (wP.y == 3) {
                    P tmp(wP.x, 2);
                    ok = 1;
                    if (tmp == wK || tmp == bK) ok = 0;
                    tP = P(wP.x, wP.y - 2);
                    res = isValidPos('P', tP, wK, bK);

                    if (!(res == 0 || res == 3)) ok = 0;
                    if (dpP[0][tP.idx()][wK.idx()][bK.idx()] != -1) ok = 0;

                    if (ok) {
                        dpP[0][tP.idx()][wK.idx()][bK.idx()] = dpP[1][wP.idx()][wK.idx()][bK.idx()] + 1;
                        q.push({ 0, 'P', tP, wK, bK });
                    }
                }

            }

            // king move
            for (int i = 0; i < 8; i++) {
                int nx = wK.x + dx[i];
                int ny = wK.y + dy[i];

                if (inGrid(nx, ny)) {
                    int res = isValidPos(c, wP, P(nx, ny), bK);
                    bool ok = 1;

                    if (!(res == 0 || res == 3)) ok = 0;
                    if (c == 'Q') {
                        if (dpQ[0][wP.idx()][nx * 8 + ny][bK.idx()] != -1) ok = 0;
                    }
                    else if (c == 'R') {
                        if (dpR[0][wP.idx()][nx * 8 + ny][bK.idx()] != -1) ok = 0;
                    }
                    else {
                        if (dpP[0][wP.idx()][nx * 8 + ny][bK.idx()] != -1) ok = 0;
                    }

                    if (ok) {
                        if (c == 'Q') {
                            dpQ[0][wP.idx()][nx * 8 + ny][bK.idx()] = dpQ[1][wP.idx()][wK.idx()][bK.idx()] + 1;
                        }
                        else if (c == 'R') {
                            dpR[0][wP.idx()][nx * 8 + ny][bK.idx()] = dpR[1][wP.idx()][wK.idx()][bK.idx()] + 1;
                        }
                        else {
                            dpP[0][wP.idx()][nx * 8 + ny][bK.idx()] = dpP[1][wP.idx()][wK.idx()][bK.idx()] + 1;
                        }
                        q.push({ 0, c, wP, P(nx, ny), bK });
                    }
                }
            }
        }
        else {
            // black move    

            for (int i = 0; i < 8; i++) {
                int nx = bK.x + dx[i];
                int ny = bK.y + dy[i];

                if (inGrid(nx, ny)) {

                    bool ok = 1;
                    int res = isValidPos(c, wP, wK, P(nx, ny));
                    if (res == -1 || res == 1 || res == 0) ok = 0;

                    // black king이 white piece를 잡을 수 있으면 안된다
                    if (abs(nx - wP.x) <= 1 && abs(ny - wP.y) <= 1 && !(abs(wP.x - wK.x) <= 1 && abs(wP.y - wK.y) <= 1)) ok = 0;
                    for (int j = 0; j < 8; j++) {

                        int tx = nx + dx[j];
                        int ty = ny + dy[j];

                        if (inGrid(tx, ty)) {
                            int tres = isValidPos(c, wP, wK, P(tx, ty));
                            if (tres == -1 || tres == 1 || tres == 2) continue;
                            if (c == 'Q') {
                                if (dpQ[0][wP.idx()][wK.idx()][tx * 8 + ty] == -1) ok = 0;
                            }
                            else if (c == 'R') {
                                if (dpR[0][wP.idx()][wK.idx()][tx * 8 + ty] == -1) ok = 0;
                            }
                            else {
                                if (dpP[0][wP.idx()][wK.idx()][tx * 8 + ty] == -1) ok = 0;
                            }
                        }
                    }
                    if (c == 'Q') {
                        if (dpQ[1][wP.idx()][wK.idx()][nx * 8 + ny] != -1) ok = 0;
                    }
                    else if (c == 'R') {
                        if (dpR[1][wP.idx()][wK.idx()][nx * 8 + ny] != -1) ok = 0;
                    }
                    else {
                        if (dpP[1][wP.idx()][wK.idx()][nx * 8 + ny] != -1) ok = 0;
                    }

                    if (ok) {
                        if (c == 'Q') {
                            dpQ[1][wP.idx()][wK.idx()][nx * 8 + ny] = dpQ[0][wP.idx()][wK.idx()][bK.idx()] + 1;
                        }
                        else if (c == 'R') {
                            dpR[1][wP.idx()][wK.idx()][nx * 8 + ny] = dpR[0][wP.idx()][wK.idx()][bK.idx()] + 1;
                        }
                        else {
                            dpP[1][wP.idx()][wK.idx()][nx * 8 + ny] = dpP[0][wP.idx()][wK.idx()][bK.idx()] + 1;
                        }
                        q.push({ 1, c, wP, wK, P(nx, ny) });
                    }
                }
            }
        }
    }


    int t;
    cin >> t;
    while (t--) {
        /*
        int turn;
        char c;
        string wp, wk, bk;
        cin >> turn >> c >> wp >> wk >> bk;

        P wP(8 * (wp[0] - 'a') + wp[1] - '1');
        P wK(8 * (wk[0] - 'a') + wk[1] - '1');
        P bK(8 * (bk[0] - 'a') + bk[1] - '1');
        */

        P wP, wK, bK;
        vector<string> grid(8);
        for (int i = 7; i >= 0; i--) {
            cin >> grid[i];
        }
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (grid[i][j] == 'k') bK = P(j, i);
                if (grid[i][j] == 'K') wK = P(j, i);
                if (grid[i][j] == 'P') wP = P(j, i);
            }
        }

        char t;
        cin >> t;

        int ix = 1;
        if (t == 'W') ix = 0;

        int res = dpP[ix][wP.idx()][wK.idx()][bK.idx()];

        cout << (res+1)/2 << '\n';
        //solve(turn, 'P', wP, wK, bK);
    }
}
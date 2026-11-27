#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(x) x.begin(), x.end()

const int INF = 1e9;

int sx, sy;
vector<int> xpos, ypos;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
int d8x[] = { -1, 1, 2, 2, -1, 1, -2, -2 };
int d8y[] = { -2, -2, -1, 1, 2, 2, -1, 1 };


int root[5001010];
int find(int n) {
    if (n < 0) return n;
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

void conn(int g1, int g2) {
    g1 = find(g1);
    g2 = find(g2);
    if (g1 < 0 || g2 < 0) return;
    root[g2] = g1;
}


bool isAlone[1010][1010];
int getGnum(int x, int y) {
    int ix = lower_bound(xpos.begin(), xpos.end(), x) - xpos.begin();
    int iy = lower_bound(ypos.begin(), ypos.end(), y) - ypos.begin();

    if (xpos[ix] == x || ypos[iy] == y) return -1;

    int lenX = xpos[ix] - xpos[ix - 1] - 1;
    int lenY = ypos[iy] - ypos[iy - 1] - 1;

    int res = (ix - 1)* sy + iy - 1;
    res *= 4;

    int xval = (xpos[ix] - x) % 2;
    int yval = (ypos[iy] - y) % 2;

    if (min(lenX, lenY) == 2) {
        if (lenX == 2) {
            int tmp = ypos[iy] - y;
            if (tmp % 4 == 0 || tmp % 4 == 3) {
                xval ^= 1;
            }
        }
        else {
            int tmp = xpos[iy] - x;
            if (tmp % 4 == 0 || tmp % 4 == 3) {
                yval ^= 1;
            }
        }

    }

    res += xval * 2 + yval;
    return res;
}



void connIN(int ix, int iy) {
    // area : xpos[ix], ypos[iy] <-> xpos[ix-1], ypos[iy-1]
    
    int lenX = xpos[ix] - xpos[ix - 1] - 1;
    int lenY = ypos[iy] - ypos[iy - 1] - 1;

    int mv = min(lenX, lenY);
    if (mv == 0) {
        isAlone[ix][iy] = 1;
        return;
    }

    if (mv == 1) {
        if (lenX + lenY == 2) {
            isAlone[ix][iy] = 1;
            return;
        }

        bool ok = 0;
        if (lenX == 1) {
            for (int nx = ix - 1; nx <= ix + 1; nx += 2) {
                if (nx == 0 || nx == sx) continue;
                if (xpos[nx] - xpos[nx - 1] - 1 != 0) {
                    ok = 1;
                }
            }
        }
        else {
            for (int ny = iy - 1; ny <= iy + 1; ny += 2) {
                if (ny == 0 || ny == sy) continue;
                if (ypos[ny] - ypos[ny - 1] - 1 != 0) {
                    ok = 1;
                }
            }
        }

        if (!ok) {
            isAlone[ix][iy] = 1;
        }
        return;
    }
    if (mv == 2) {
        return;
    }

    if (mv == 3 && lenX + lenY == 6) {
        vector<int> tmp;        
        tmp.push_back(getGnum(xpos[ix] - 1, ypos[iy] - 1));
        tmp.push_back(getGnum(xpos[ix] - 1, ypos[iy] - 2));
        tmp.push_back(getGnum(xpos[ix] - 2, ypos[iy] - 1));
        for (int i = 1; i < 3; i++) conn(tmp[0], tmp[i]);
        return;
    }
    vector<int> tmp;
    tmp.push_back(getGnum(xpos[ix] - 1, ypos[iy] - 1));
    tmp.push_back(getGnum(xpos[ix] - 1, ypos[iy] - 2));
    tmp.push_back(getGnum(xpos[ix] - 2, ypos[iy] - 1));
    tmp.push_back(getGnum(xpos[ix] - 2, ypos[iy] - 2));
    for (int i = 1; i < 4; i++) conn(tmp[0], tmp[i]);
}

void connOUT(int ix, int iy) {

    int lenX = xpos[ix] - xpos[ix - 1] - 1;
    int lenY = ypos[iy] - ypos[iy - 1] - 1;
    int mv = min(lenX, lenY);

    // isolation check
    for (int f = 1; f < 3; f++) {
        int nx = ix + dx[f];
        int ny = iy + dy[f];

        if (nx == 0 || nx == sx) continue;
        if (ny == 0 || ny == sy) continue;

        if (f == 1) {

            for (int k = 1; k <= 4; k++) {
                int tx = xpos[ix] - 1, ty = ypos[iy] - k;
                int g1 = getGnum(tx, ty);
                for (int i = 0; i < 8; i++) {
                    int ttx = tx + d8x[i];
                    int tty = ty + d8y[i];

                    int g2 = getGnum(ttx, tty);
                    conn(g1, g2);
                }
            }

        }
        else {
            for (int k = 1; k <= 4; k++) {
                int tx = xpos[ix] - k, ty = ypos[iy] - 1;
                int g1 = getGnum(tx, ty);
                for (int i = 0; i < 8; i++) {
                    int ttx = tx + d8x[i];
                    int tty = ty + d8y[i];

                    int g2 = getGnum(ttx, tty);
                    conn(g1, g2);
                }
            }

        }

    }

}

string mod(int x) {
    if (x == -1) return "  X ";
    string res = to_string(x);
    while (res.size() != 3) res = ' ' + res;
    res += ' ';
    return res;
}

void pf() {
    cout << "Grid: \n";
    for (int i = xpos[1] - 5; i <= xpos[sx - 2] + 5; i++) {
        for (int j = ypos[1] - 5; j <= ypos[sy - 2] + 5; j++) {
            int res = getGnum(i, j);
            res = find(res);
            cout << mod(res);
        }
        cout << '\n';
    }
}

void solve() {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        xpos.push_back(a);
        ypos.push_back(b);
    }

    xpos.push_back(-INF - 1);
    xpos.push_back(INF + 1);
    ypos.push_back(-INF - 1);
    ypos.push_back(INF + 1);

    sort(all(xpos));
    sort(all(ypos));
    xpos.erase(unique(all(xpos)), xpos.end());
    ypos.erase(unique(all(ypos)), ypos.end());
    sx = xpos.size(), sy = ypos.size();

    //cout << "X : ";
    //for (auto f : xpos) cout << f << ' ';
    //cout << '\n';
    //cout << "Y : ";
    //for (auto f : ypos) cout << f << ' ';
    //cout << '\n';
    // (sx+1) * (sy+1) * 4 개의 영역
    // 0 0, 0 1, 1 0, 1 1
    // 1 * n \ n * 1 꼴 직사각형일 때 주의


    int maxN = (sx + 1) * (sy + 1) * 4;
    for (int i = 0; i < maxN; i++) root[i] = i;

    for (int i = 1; i < sx; i++) {
        for (int j = 1; j < sy; j++) {
            connIN(i, j);
        }
    }

    for (int i = 1; i < sx; i++) {
        for (int j = 1; j < sy; j++) {
            connOUT(i, j);
        }
    }

   /* cout << "AFTER OUT: \n";
    pf();*/

    while (q--) {

        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;

        int gs = getGnum(sx, sy);
        int ge = getGnum(ex, ey);
        gs = find(gs);
        ge = find(ge);

        bool ok = 0;
        if (gs == ge) {
            int ix = lower_bound(xpos.begin(), xpos.end(), sx) - xpos.begin();
            int iy = lower_bound(ypos.begin(), ypos.end(), sy) - ypos.begin();

            if (isAlone[ix][iy]) ok = 0;
            else ok = 1;
        }

        cout << ok << '\n';
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n, m;
int P[202020];
int D[202020];

int rec[5002020];
map<pair<int, int>, int> pos;
int ord = 0;
int getIdx(int x, int y) {
    if (pos[mp(x, y)]) return pos[mp(x, y)];
    return pos[mp(x, y)] = ++ord;
}

int sptX[20][101010];
int sptY[20][101010];

int findL(int ix, int val, int spt[][101010]) {
    for (int i = 19; i >= 0; i--) {
        if (ix - (1 << i) >= 0 \
            && spt[i][ix - (1 << i) + 1] <= val) {
            ix -= 1 << i;
        }
    }
    return ix;
}
int findR(int ix, int val, int spt[][101010]) {
    for (int i = 19; i >= 0 && ix <= 100000; i--) {
        if (spt[i][ix] <= val) ix += 1 << i;
    }
    return ix;
}

void solve() {

    cin >> n >> m;

    for (int i = 1; i <= n + m; i++) {
        cin >> P[i] >> D[i];
        P[i] = n + m + 1 - P[i];
    }

    for (int i = 1; i <= n; i++) {
        sptY[0][i] = P[i];
    }
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            sptY[i][j] = sptY[i - 1][j];
            if (j + (1 << i - 1) <= n) sptY[i][j] = max(sptY[i][j], sptY[i - 1][j + (1 << i - 1)]);
        }
    }

    for (int i = 1; i <= m; i++) {
        sptX[0][i] = P[n + i];
    }
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= m; j++) {
            sptX[i][j] = sptX[i - 1][j];
            if (j + (1 << i - 1) <= m) sptX[i][j] = max(sptX[i][j], sptX[i - 1][j + (1 << i - 1)]);
        }
    }


    vector<int> ans(n + m + 1);
    for (int i = 1; i <= n + m; i++) {
        int sx, sy;
        if (i <= n) {
            sx = i, sy = 1;
            if (D[i] == 1) sy = m;
        }
        else {
            sx = 1, sy = i - n;
            if (D[i] == 1) sx = n;
        }

        vector<pair<int, int>> track;
        int ansfound = i;
        while (1) {
            track.push_back(mp(sx, sy));
            int ix = getIdx(sx, sy);
            if (rec[ix]) {
                ansfound = rec[ix];
                break;
            }

            int nx = -1, ny = -1;
            if (P[sx] > P[sy + n]) {
                // horizontal
                if (D[sx] == 1) {
                    // left
                    int ndx = findL(sy, P[sx], sptX);
                    if (ndx == 0) {
                        ansfound = sx;
                        break;
                    }
                    nx = sx, ny = ndx;
                }
                else {
                    // right
                    int ndx = findR(sy, P[sx], sptX);
                    if (ndx > m) {
                        ansfound = sx;
                        break;
                    }
                    nx = sx, ny = ndx;
                }
            }
            else {
                // vertical
                if (D[sy + n] == 1) {
                    // up
                    int ndx = findL(sx, P[sy + n], sptY);
                    if (ndx == 0) {
                        ansfound = sy + n;
                        break;
                    }
                    nx = ndx, ny = sy;
                }
                else {
                    // down
                    int ndx = findR(sx, P[sy + n], sptY);
                    if (ndx > n) {
                        ansfound = sy + n;
                        break;
                    }
                    nx = ndx, ny = sy;
                }
            }

            sx = nx, sy = ny;
        }

        //cout << "REc: " << i << " | ";
        ans[i] = ansfound;
        for (auto [a, b] : track) {
            int ix = getIdx(a, b);
            rec[ix] = ansfound;

            //cout << a << ' ' << b << " + ";
        }
       // cout << ans[i] <<  '\n';

    }

    for (int i = 1; i <= n + m; i++) {
        cout << ans[i] << '\n';
    }



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) solve();
}
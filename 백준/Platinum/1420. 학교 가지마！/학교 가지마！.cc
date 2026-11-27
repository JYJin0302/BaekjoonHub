#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

/*
0 : source
1 ~ n*m : 각 점
n*m+1~ n*m*2 : 복사본
n*m*2 + 1:  sink

*/

int n, m;
int src, snk;

bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}

int f[20202][5];
int c[20202][5];

int dx[] = { -1, 0, 1, 0 , 0};
int dy[] = { 0, 1, 0 , -1 , 0};

string A[111];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    int sx, sy, ex, ey;
    for (int i = 0; i < n; i++) {
        cin >> A[i];

        for (int j = 0; j < m; j++) {
            if (A[i][j] == 'H') {
                tie(sx, sy) = mp(i, j);
                src = i * m + j + 1 + n*m;
            }
            if (A[i][j] == 'K') {
                tie(ex, ey) = mp(i, j);
                snk = i * m + j + 1;
            }
        }
    }

    if (abs(sx - ex) + abs(sy - ey) == 1) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (A[i][j] == '#') continue;
            int val = i * m + j + 1;

            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];

                if (inGrid(ni, nj) && A[ni][nj] != '#') {

                    c[val + n*m][k] = 1;
                }
            }
            if (A[i][j] == '.') c[val][4] = 1;

        }
    }



    int ans = 0;
    while (1) {

       // cout << "Go flow\n";
        vector<int> from(2*n*m+10, -1);
        from[src] = 0;

        queue<int> q;
        q.push(src);
        while (!q.empty()) {
            int a = q.front();
            q.pop();
            int ta = a;

            bool ck = 0;
            if (a > n * m) {
                ck = 1;
                a -= n * m;
            }

            int ax = (a - 1) / m;
            int ay = (a - 1)%m;

            for (int i = 0; i < 5; i++) {
                int tx = ax + dx[i];
                int ty = ay + dy[i];
                if (!inGrid(tx, ty) || c[ta][i] - f[ta][i] <= 0) continue;
                
                int na = tx * m + ty + 1;
                if (!ck) na += n * m;
                
                if (from[na] != -1) continue;
                from[na] = (i + 2) % 4;
                if (i == 4) from[na] = 4;

                q.push(na);
            }
        }


        if (from[snk] == -1) break;

        int mf = 3;
        int tx = snk;
        while (tx != src) {
            //cout << "track: " << (tx - 1) / m << ' ' << (tx - 1) % m << " -> " << from[tx] << ' ';
            int ni = from[tx];
            int nx = tx + dx[ni] * m + dy[ni];
           // cout << nx << '\n';
            if (tx <= n * m) nx += n * m;
            else nx -= n * m;

            int ti = (ni + 2) % 4;
            if (ni == 4) ti = 4;

            mf = min(mf, c[nx][ti] - f[nx][ti]);
            tx = nx;
        }

        tx = snk;
        while (tx != src) {
            int ni = from[tx];

            int nx = tx + dx[ni] * m + dy[ni];
            if (tx <= n * m) nx += n * m;
            else nx -= n * m;

            int ti = (ni + 2) % 4;
            if (ni == 4) ti = 4;

            f[tx][ni] -= mf;
            f[nx][ti] += mf;
            tx = nx;
        }


        ans += mf;
        //cout << "ADd: " << mf << '\n';
    }
    cout << ans;

}
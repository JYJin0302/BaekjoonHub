#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n, m, k;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < n;
}

struct S {
    int x, y, dir;

    int ord[4][4];
    S() {
        x = y = dir = -1;
        memset(ord, 0, sizeof ord);
    }
};

S A[1010];

int N[22][22];
int R[22][22];
int cnt = 0, remain = 0;

void pf() {
    cout << "Shark:\n";
    for (int i = 1; i <= m; i++) cout << A[i].x << ' ' << A[i].y << ' ' << A[i].dir << '\n';

    cout << "Grid:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << N[i][j] << "|" << R[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << string(30, '-') << '\n' << '\n';
}

void simul() {

    for (int i = 1; i <= m; i++) {
        if (A[i].x == -1) continue;

        int curD = A[i].dir;
        int nxtDir = -1;
        for (int f = 0; f < 4; f++) {
            int tf = A[i].ord[curD][f];
            int nx = A[i].x + dx[tf];
            int ny = A[i].y + dy[tf];


            if (inGrid(nx, ny) && N[nx][ny] == 0) {
                nxtDir = tf;
                A[i].x = nx;
                A[i].y = ny;
                break;
            }
        }

        if (nxtDir == -1) {
            for (int f = 0; f < 4; f++) {
                int tf = A[i].ord[curD][f];
                int nx = A[i].x + dx[tf];
                int ny = A[i].y + dy[tf];


                if (inGrid(nx, ny) && N[nx][ny] == i) {
                    nxtDir = tf;
                    A[i].x = nx;
                    A[i].y = ny;
                    break;
                }
            }
        }

        A[i].dir = nxtDir;
        
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (R[i][j]) {
                R[i][j]--;
                if (!R[i][j]) N[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        if (A[i].x == -1) continue;
        bool ok = 1;
        for (int j = 1; j < i; j++) {
            if (A[j].x == A[i].x && A[j].y == A[i].y) ok = 0;
        }

        if (!ok) {
            remain--;
            A[i].x = A[i].y = -1;
            continue;
        }

        N[A[i].x][A[i].y] = i;
        R[A[i].x][A[i].y] = k;
    }


}

void solve() {

    cin >> n >> m >> k;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x) {
                A[x].x = i;
                A[x].y = j;

                N[i][j] = x;
                R[i][j] = k;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> A[i].dir;
        A[i].dir--;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < 4; j++) {
            for (int f = 0; f < 4; f++) {
                cin >> A[i].ord[j][f];
                --A[i].ord[j][f];
            }
        }
    }

    remain = m;
    while (remain > 1 && cnt < 1000) {
        cnt++;
        simul();
        //pf();
    }

    if (remain == 1) cout << cnt << '\n';
    else cout << -1 << '\n';


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}
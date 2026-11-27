#include <bits/stdc++.h>
using namespace std;

int n, m;
int A[1000][1000];

int dx[] = { 0, 1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };
char cc[] = { 'R', 'D', 'L' ,'D' };

void solve(int x, int y) {
    // x, y: avoid

    bool did = 0;
    for (int i = 0; i < m; i += 2) {

        if (i == y || i + 1 == y) {
            did = 1;

            int tx = 0, ty = i;
            int phase = 0;
            string s;

            while (!(tx == n - 1 && ty == i + 1)) {

                int nx = tx + dx[phase], ny = ty + dy[phase];
                if (nx == x && ny == y) {
                    s += 'D';
                    tx++;
                }
                else {
                    tx = nx, ty = ny;
                    s += cc[phase];
                    phase = (phase + 1) % 4;
                }
            }

            if (i + 1 != m - 1) s += 'R';
            cout << s;

        }
        else if (!did) {
            string s = string(n - 1, 'D') + 'R' + string(n- 1, 'U') + 'R';
            cout << s;
        }
        else {
            string s = string(n - 1, 'U') + 'R' + string(n - 1, 'D');
            cout << s;
            if (i != m - 2) cout << 'R';
        }
    }


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    if (n % 2 == 1 || m % 2 == 1) {
        if (n % 2 == 1) {
            
            string s = string(m - 1, 'R') + 'D' + string(m - 1, 'L') + 'D';
            for (int k = 0; k < n / 2; k++) {
                cout << s;
            }

            cout << string(m - 1, 'R');
        }
        else {

            string s = string(n - 1, 'D') + 'R' + string(n - 1, 'U') + 'R';
            for (int k = 0; k < m / 2; k++) {
                cout << s;
            }
            cout << string(n - 1, 'D');
        }

        return 0;
    }

    // find min value

    int minn = 10000;
    int x = -1, y = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i + j) % 2 == 0) continue;
            
            if (minn > A[i][j]) {
                minn = A[i][j];
                x = i, y = j;
            }
        }
    }

    solve(x, y);
}
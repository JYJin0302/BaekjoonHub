#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string A[51];

int dx[] = { 0, 0, 1, 1, 1, 1 };
int dy[] = { 0, 3, 0, 1, 2, 3 };

int n, m;

void solve() {
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> A[i];

    bool valid = 1;
    int x = 0;
    while (x < n * m) {

        int ix = x / m, iy = x % m;

        if (x == n * m) {
            break;
        }
        if (A[ix][iy] != 'X') {
            x++;
            continue;
        }

        // try B
        if (iy + 1 < m && A[ix][iy + 1] == 'X') {
            A[ix][iy] = 'L';
            A[ix][iy + 1] = 'R';
        }
        else if (ix + 1 < n && iy + 3 < m) {
            int cnt = 0, cnt2 = 0;
            for (int i = 0; i < 6; i++) {
                cnt += (A[ix + dx[i]][iy + dy[i]] == 'X');
            }
            for (int i = 0; i < 2; i++) {
                cnt2 += (A[ix][iy + 1 + i] == '.');
            }

            if (cnt == 6 && cnt2 == 2) {
                // ok

                for (int i = 0; i < 6; i++) {
                    A[ix + dx[i]][iy + dy[i]] = 'A';
                }
            }
            else valid = 0;
        }
        else valid = 0;

        x++;
    }

    if (!valid) {
        cout << -1;
        return;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j + 3 < m; j++) {

            if (A[i][j] == 'L' && A[i][j + 3] == 'R') {
                if (A[i - 1][j] == 'L' && A[i - 1][j + 3] == 'R') {
                    // A

                    int ix = i - 1, iy = j;
                    for (int k = 0; k < 6; k++) {
                        A[ix + dx[k]][iy + dy[k]] = 'A';
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 'L' || A[i][j] == 'R') A[i][j] = 'B';
        }
    }

    for (int i = 0; i < n; i++) cout << A[i] << '\n';
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

char A[101][101];

int n, m;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1 , 0 };

bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}

void solve() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i + j) & 1) {
                if (A[i][j] == '.') A[i][j] = 'E';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i + j) & 1) {}
            else if (A[i][j] == '.') {
                bool ok = 1;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (inGrid(ni, nj) && A[ni][nj] == 'E') ok = 0;
                }

                if (ok) A[i][j] = 'E';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << A[i][j];
        }
        cout << '\n';
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
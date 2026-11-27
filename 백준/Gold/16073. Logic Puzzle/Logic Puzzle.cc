#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int A[111][111];
bool ans[111][111];

void f(int x, int y) {

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            A[x + i][y + j]--;
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            cin >> A[i][j];
        }
    }



    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (A[i - 1][j - 1] == 1) {
                f(i, j);
                ans[i][j] = 1;
            }

        }
    }

    bool ok = 1;
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            if (A[i][j] != 0) ok = 0;
        }
    }

    if (!ok) cout << "impossible";
    else {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (ans[i][j]) cout << 'X';
                else cout << '.';
            }
            cout << '\n';
        }
    }

}
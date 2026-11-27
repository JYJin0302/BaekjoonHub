#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

bool G[202][202];

void solve() {

    int a, b;
    cin >> a >> b;

    if (b & 1) {
        cout << "NO\n";
        return;
    }

    if (b) {

        G[1][0] = 1;
        G[1][1] = 1;

        int cur = 1;

        for (int i = 1; i < b / 2; i++) {
            if (i & 1) {
                G[2][cur] = 1;
            }
            else G[0][cur] = 1;
            G[1][++cur] = 1;
        }
        while (a--) {
            G[1][++cur] = 1;
        }

        cout << "YES\n";
        cout << 3 << ' ' << cur + 1 << '\n';
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j <= cur; j++) {
                if (G[i][j]) cout << 'O';
                else cout << '.';
            }
            cout << '\n';
        }
        return;
    }

    if (a == 1) {
        cout << "YES\n";
        cout << 1 << ' ' << 1 << '\n' << 'O';
        return;
    }
    if (a < 4) {
        cout << "NO\n";
        return;
    }

    if (a % 3 == 1) {
        a -= 4;
        int r = 1, c = 1;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) G[i][j] = 1;
        }
        while (a) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) G[r+i][c + j] = 1;
            }
            r++, c++;
            a -= 3;
        }
        cout << "YES\n";
        cout << r+1 << ' ' << c+1 << '\n';
        for (int i = 0; i <= r; i++) {
            for (int j = 0; j <= c; j++) {
                if (G[i][j]) cout << 'O';
                else cout << '.';
            }
            cout << '\n';
        }
        return;
    }

    if (a < 8 || a == 9) {
        cout << "NO\n";
        return;
    }

    if (a % 3 == 0) {
        a -= 12;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 5; j++) {
                if (i == 0 || i == 2 || j == 0 || j == 4) {
                    G[i][j] = 1;
                }
            }
        }
        int r = 2, c = 4;
        while (a) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) G[r + i][c + j] = 1;
            }
            r++, c++;
            a -= 3;
        }
        cout << "YES\n";
        cout << r + 1 << ' ' << c + 1 << '\n';
        for (int i = 0; i <= r; i++) {
            for (int j = 0; j <= c; j++) {
                if (G[i][j]) cout << 'O';
                else cout << '.';
            }
            cout << '\n';
        }
        return;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            G[i][j] = 1;
        }
    }

    a -= 8;
    G[1][1] = 0;
    int r = 2, c = 2; 
    while (a) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) G[r + i][c + j] = 1;
        }
        r++, c++;
        a -= 3;
    }
    cout << "YES\n";
    cout << r + 1 << ' ' << c + 1 << '\n';
    for (int i = 0; i <= r; i++) {
        for (int j = 0; j <= c; j++) {
            if (G[i][j]) cout << 'O';
            else cout << '.';
        }
        cout << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}
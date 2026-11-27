#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


string G[6][6];

int col[6][10], row[6][10], box[6][10];

bool fill(int x, int y, int t = 0) {
    if (y == 6) return fill(x + 1, 0, 0);
    if (x == 6) return 1;

    if (G[x][y].size() <= t) return fill(x, y + 1, 0);

    char c = G[x][y][t];
    if (isdigit(c)) {
        if (t == 2 && c < G[x][y][0]) return 0;
        return fill(x, y, t + 2);
    }

    int bx = 2 * (x / 2) + (y >= 3);

    int mn = 1;
    if (t == 2) {
        mn = G[x][y][0] - '0' + 1;
    }
    for (int i = mn; i <= 9; i++) {
        if (!col[y][i] && !row[x][i] && !box[bx][i]) {
            col[y][i]++;
            row[x][i]++;
            box[bx][i]++;
            G[x][y][t] = char('0' + i);

            if (fill(x, y, t + 2)) return 1;
            G[x][y][t] = '-';
            col[y][i]--;
            row[x][i]--;
            box[bx][i]--;
        }
    }
    return 0;
}

void solve() {

    memset(col, 0, sizeof col);
    memset(row, 0, sizeof row);
    memset(box, 0, sizeof box);
    int k;
    cin >> k;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> G[i][j];
        }
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {

            int bx = 2 * (i / 2) + (j >= 3);
            char c = G[i][j][0];
            if (isdigit(c)) {
                int v = c - '0';
                col[j][v]++;
                row[i][v]++;
                box[bx][v]++;
            }

            if (G[i][j].size() == 3) {
                char c = G[i][j][2];
                if (isdigit(c)) {
                    int v = c - '0';
                    col[j][v]++;
                    row[i][v]++;
                    box[bx][v]++;
                }
            }

        }
    }
    fill(0, 0);

    cout << k << '\n';
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cout << G[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
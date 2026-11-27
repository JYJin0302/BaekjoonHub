#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define mp make_pair

using namespace std;

map<pair<int, pair<int, int>>, bool> chk;

pair<int, int> dir[10];

char grid[1010][1010];
int n, m, k;

bool inGrid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

queue<pair<pair<int, int>, char>> q;
void update() {

    while (!q.empty()) {
        int i, j;
        char c;
        tie(i, j) = q.front().first;
        c = q.front().second;

        q.pop();

        for (int f = 0; f < k; f++) {

            int dx = dir[f].first, dy = dir[f].second;

            if (c == '#') {
                if (chk[mp(f, mp(i, j))]) {
                    if (inGrid(i - dx, j - dy) && grid[i - dx][j - dy] == '?') {
                        q.push(mp(mp(i - dx, j - dy), '.'));
                        grid[i - dx][j - dy] = '.';
                    }
                }
                else {
                    if (inGrid(i - dx, j - dy) && grid[i - dx][j - dy] == '?') {
                        q.push(mp(mp(i - dx, j - dy), '#'));
                        grid[i - dx][j - dy] = '#';
                    }
                }
            }
            else {
                if (inGrid(i + dx, j + dy) && !chk[mp(f, mp(i + dx, j + dy))] && grid[i + dx][j + dy] == '?') {
                    q.push(mp(mp(i + dx, j + dy), '.'));
                    grid[i + dx][j + dy] = '.';
                }

            }
        }
    }
    return;
}


void pf() {
    cout << "REs:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << grid[i][j];
        }
        cout << '\n';
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(grid, '?', sizeof(grid));

    cin >> m >> n >> k;

    for (int f = 0; f < k; f++) {

        int dx, dy;
        cin >> dy >> dx;

        dir[f] = mp(dx, dy);

        int x;
        cin >> x;

        while (x--) {

            int a, b;
            cin >> b >> a;

            chk[mp(f, mp(a, b))] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] != '?') continue;

            char upd = '?';
            for (int f = 0; f < k; f++) {

                if (chk[mp(f, mp(i, j))]) upd = '#';
                int dx = dir[f].first, dy = dir[f].second;

                if (!inGrid(i - dx, j - dy) && !chk[mp(f, mp(i, j))]) {
                    upd = '.';
                }

                if (inGrid(i + dx, j + dy) && chk[mp(f, mp(i + dx, j + dy))]) {
                    upd = '.';
                }

                if (inGrid(i + dx, j + dy) && !chk[mp(f, mp(i + dx, j + dy))] && grid[i + dx][j + dy] == '#') {
                    upd = '#';
                }

                if (upd != '?') break;
            }

            if (upd != '?') {
                grid[i][j] = upd;
                q.push(mp(mp(i, j), upd));
                update();
            }

            //  pf();
        }
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == '?') cout << '.';
            else cout << grid[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == '?') cout << '#';
            else cout << grid[i][j];
        }
        cout << '\n';
    }
}

#include <bits/stdc++.h>
using namespace std;

int n, m, e, f;
string ans = "AAAAAAAAAAA";
bool Rout, Bout, frontR, frontB;
vector<string> grid;
pair<int, int> red, blue, hole;

void tiltL(int a, int b, int c, int d) {
    Rout = 0, Bout = 0, frontR = 0, frontB = 0;

    if (b < d && a == c) frontR = 1;
    if (d < b && a == c) frontB = 1;

    grid[a][b] = '.';
    grid[c][d] = '.';

    // Move Red
    while (grid[a][b - 1] != '#') {
        b--;
        if (a == e && b == f) {
            Rout = 1;
            break;
        }
    }

    // Move Blue
    while (grid[c][d - 1] != '#') {
        d--;
        if (c == e && d == f) {
            Bout = 1;
            break;
        }
    }

    if (b == d) {
        if (frontR) d++;
        if (frontB) b++;
    }
    grid[a][b] = 'R';
    grid[c][d] = 'B';
    red = { a, b };
    blue = { c, d };
}

void tiltR(int a, int b, int c, int d) {
    Rout = 0, Bout = 0, frontR = 0, frontB = 0;

    if (d < b && a == c) frontR = 1;
    if (b < d && a == c) frontB = 1;

    grid[a][b] = '.';
    grid[c][d] = '.';

    // Move Red
    while (grid[a][b + 1] != '#') {
        b++;
        if (a == e && b == f) {
            Rout = 1;
            break;
        }
    }

    // Move Blue
    while (grid[c][d + 1] != '#') {
        d++;
        if (c == e && d == f) {
            Bout = 1;
            break;
        }
    }

    if (b == d) {
        if (frontR) d--;
        if (frontB) b--;
    }
    grid[a][b] = 'R';
    grid[c][d] = 'B';
    red = { a, b };
    blue = { c, d };
}

void tiltU(int a, int b, int c, int d) {
    Rout = 0, Bout = 0, frontR = 0, frontB = 0;

    if (a < c && b == d) frontR = 1;
    if (c < a && b == d) frontB = 1;

    grid[a][b] = '.';
    grid[c][d] = '.';

    // Move Red
    while (grid[a - 1][b] != '#') {
        a--;
        if (a == e && b == f) {
            Rout = 1;
            break;
        }
    }

    // Move Blue
    while (grid[c - 1][d] != '#') {
        c--;
        if (c == e && d == f) {
            Bout = 1;
            break;
        }
    }

    if (a == c) {
        if (frontR) c++;
        if (frontB) a++;
    }
    grid[a][b] = 'R';
    grid[c][d] = 'B';
    red = { a, b };
    blue = { c, d };
}
void tiltD(int a, int b, int c, int d) {
    Rout = 0, Bout = 0, frontR = 0, frontB = 0;

    if (c < a && b == d) frontR = 1;
    if (a < c && b == d) frontB = 1;

    grid[a][b] = '.';
    grid[c][d] = '.';

    // Move Red
    while (grid[a + 1][b] != '#') {
        a++;
        if (a == e && b == f) {
            Rout = 1;
            break;
        }
    }

    // Move Blue
    while (grid[c + 1][d] != '#') {
        c++;
        if (c == e && d == f) {
            Bout = 1;
            break;
        }
    }

    if (a == c) {
        if (frontR) c--;
        if (frontB) a--;
    }
    grid[a][b] = 'R';
    grid[c][d] = 'B';
    red = { a, b };
    blue = { c, d };
}

char movec[4] = { 'L', 'R', 'U', 'D' };
void move(int a, int b, int c, int d, string moves = "") {
    // a, b, c, d: current ball position

    if (moves.size() == 10) return;

    for (int i = 0; i < 4; i++) {
        switch (i) {
        case 0:
            tiltL(a, b, c, d);
            break;
        case 1:
            tiltR(a, b, c, d);
            break;
        case 2:
            tiltU(a, b, c, d);
            break;
        case 3:
            tiltD(a, b, c, d);
            break;
        }
        if (Bout) continue;
        if (Rout) {
            if (ans.size() > moves.size() + 1) {
                ans = moves + movec[i];
            }
            return;
        }
        move(red.first, red.second, blue.first, blue.second, moves + movec[i]);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        grid.push_back(s);
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (grid[i][j] == 'R') red = { i, j };
        if (grid[i][j] == 'B') blue = { i, j };
        if (grid[i][j] == 'O') hole = { i, j };
    }

    tie(e, f) = hole;
    move(red.first, red.second, blue.first, blue.second);
    if (ans.size() == 11) cout << -1;
    else cout << ans.size() << '\n' << ans;
}
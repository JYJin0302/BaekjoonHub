#include <bits/stdc++.h>
using namespace std;

int r, c, a, b, nr, nc, ans;
char grid[50][50];
bool check[50][50];
bool escape;

queue<pair<int, int>> water;
queue<pair<int, int>> S;
queue<pair<int, int>> temp;

int step[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

bool outofgrid(int x, int y) {
    return (x < 0 || x == r) || (y < 0 || y == c);
}

void move() {
    while (!water.empty()) {
        tie(a, b) = water.front();
        water.pop();
        for (int i = 0; i < 4; i++) {
            nr = a + step[i][0];
            nc = b + step[i][1];
            if (outofgrid(nr, nc) || check[nr][nc] || grid[nr][nc] == 'D' || grid[nr][nc] == 'X') continue;
            check[nr][nc] = 1;
            grid[nr][nc] = '*';
            temp.push({ nr, nc });
        }
    }
    swap(temp, water);

    while (!S.empty()) {
        tie(a, b) = S.front();
        S.pop();
        for (int i = 0; i < 4; i++) {
            nr = a + step[i][0];
            nc = b + step[i][1];
            if (outofgrid(nr, nc) || check[nr][nc] || grid[nr][nc] == '*' || grid[nr][nc] == 'X') continue;
            check[nr][nc] = 1;
            if (grid[nr][nc] == 'D') {
                escape = true;
                return;
            }
            grid[nr][nc] = 'S';
            temp.push({ nr, nc });
        }
    }
    swap(temp, S);

    if (S.empty()) return;
    ans++;


    move();
}




int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) {
        cin >> grid[i][j];
        if (grid[i][j] == '*') { water.push({ i, j }); check[i][j] = 1; }
        if (grid[i][j] == 'S') { S.push({ i, j }); check[i][j] = 1; }
    }
    escape = false;

    ans = 0;
    move();
    if (escape) cout << ans + 1;
    else cout << "KAKTUS";
}
#include <bits/stdc++.h>
using namespace std;

int n, m, r, c, d, nx, ny;
int grid[50][50];
int ans;

int step[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
struct robot {
    int x, y;
    int face; // 0: north, 1: east, 2: south, 3: west
};
robot bot;


void act() {
    if (grid[bot.x][bot.y] == 0) {
        grid[bot.x][bot.y] = 2; // blank and cleared
        ans++;
    }

    int search = bot.face;
    for (int i = 0; i < 4; i++) {
        search = (search + 3) % 4;
        nx = bot.x + step[search][0];
        ny = bot.y + step[search][1];
        if (grid[nx][ny] == 0) {
            bot.x = nx;
            bot.y = ny;
            bot.face = search;
            act();
            return;
        }
    }

    int back = (bot.face + 2) % 4;
    nx = bot.x + step[back][0];
    ny = bot.y + step[back][1];

    if (grid[nx][ny] == 1) return;

    bot.x = nx;
    bot.y = ny;
    act();
}





int main() {
    cin >> n >> m >> r >> c >> d;

    bot.x = r;
    bot.y = c;
    bot.face = d;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
    }

    ans = 0;
    act();
    cout << ans;
}
#include <bits/stdc++.h>
using namespace std;

int n, k, l, a, b, nx, ny;
int grid[102][102]; // apple = 2, body = 1, blank = 0;
int sec;
map<int, char> order;
queue<pair<int, int>> body;

int step[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
struct Dummy {
    int x, y;
    int face; // 0: north, 1: east, 2: south, 3: west
};
Dummy snake;

bool outofgrid(int r, int c) {
    return (r == 0 || r == n+1) || (c == 0 || c == n+1);
}

void move() {
    int next = snake.face;
    if (order[sec] == 'D') next = (next + 1) % 4;
    else if (order[sec] == 'L') next = (next + 3) % 4;

    nx = snake.x + step[next][0];
    ny = snake.y + step[next][1];

    if (grid[nx][ny] == 1 || outofgrid(nx, ny)) return;

    if (grid[nx][ny] != 2) {
        tie(a, b) = body.front();
        body.pop();
        grid[a][b] = 0;
    }
    grid[nx][ny] = 1;
    body.push({ nx, ny });

    snake.x = nx;
    snake.y = ny;
    snake.face = next;

    sec++;

    move();
}





int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;
    while (k--) {
        cin >> a >> b;
        grid[a][b] = 2;
    }
    cin >> l;
    while (l--) {
        int n1;
        char c1;
        cin >> n1 >> c1;
        order[n1] = c1;
    }
    snake = { 1, 1, 1 };
    body.push({ 1, 1 });
    grid[1][1] = 1;

    sec = 0;
    move();
    cout << sec + 1;
}
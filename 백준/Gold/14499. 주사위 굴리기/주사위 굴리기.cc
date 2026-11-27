#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, k, t, temp;

struct Dice{
    int up, down, north, west, south, east;
};
Dice d;
int grid[21][21];

bool outofgrid(int t1, int t2) {
    return (t1 < 0 || t1 >= n) || (t2 < 0 || t2 >= m);
}

void move(int t) {
    int nx = x, ny = y;
    switch (t) {
    case 1:
        ny++;
        if (outofgrid(nx, ny)) return;
            
        temp = d.west;
        d.west = d.down;
        d.down = d.east;
        d.east = d.up;
        d.up = temp;
    
        break;
    case 2:
        ny--;
        if (outofgrid(nx, ny)) return;
            
        temp = d.west;
        d.west = d.up;
        d.up = d.east;
        d.east = d.down;
        d.down = temp;

        break;
    case 3:
        nx--;
        if (outofgrid(nx, ny)) return;
            
        temp = d.up;
        d.up = d.south;
        d.south = d.down;
        d.down = d.north;
        d.north = temp;

        break;
    case 4:
        nx++;
        if (outofgrid(nx, ny)) return;
            
        temp = d.up;
        d.up = d.north;
        d.north = d.down;
        d.down = d.south;
        d.south = temp;

        break;
    }

    if (grid[nx][ny] == 0) {
        grid[nx][ny] = d.down;
    }
    else {
        d.down = grid[nx][ny];
        grid[nx][ny] = 0;
    }
    cout << d.up << '\n';

    x = nx;
    y = ny;
}

int main() {
    
    cin >> n >> m >> x >> y >> k;

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
    }
    d = { 0,0,0,0,0,0 };

    while (k--) {
        cin >> t;
        move(t);
    }
}
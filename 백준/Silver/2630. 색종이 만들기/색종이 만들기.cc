#include <bits/stdc++.h>
using namespace std;
int n, blue, white;
vector<vector<int>> grid;
bool ok;

void solve(int r, int c, int size) {
    ok = true;
    int color = grid[r][c];
    for (int i = 0; i < size; i++) for (int j = 0; j < size; j++) {
        if (grid[r + i][c + j] != color) { ok = false; break; }
    }
    if (ok) {
        (color == 1 ? blue : white)++;
        return;
    }
    solve(r, c, size / 2);
    solve(r, c + size / 2, size / 2);
    solve(r + size / 2, c, size / 2);
    solve(r + size / 2, c + size / 2, size / 2);
}



int main() {
    cin >> n;
    grid = vector<vector<int>>(n, vector<int>(n));

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        cin >> grid[i][j];
    }

    blue = 0;
    white = 0;
    solve(0, 0, n);
    cout << white << '\n' << blue;
}
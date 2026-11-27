#include <bits/stdc++.h>
using namespace std;

int n, min1, zero, plu1;
vector<vector<int>> grid;
bool ok;

void solve(int r, int c, int size) {
    ok = true;
    int color = grid[r][c];
    for (int i = 0; i < size; i++) for (int j = 0; j < size; j++) {
        if (grid[r + i][c + j] != color) { ok = false; break; }
    }
    if (ok) {
        switch (color){
        case -1:
            min1++;
            return;
        case 0:
            zero++;
            return;
        case 1:
            plu1++;
            return;
        }
    }
    int t = size / 3;
    solve(r, c, t);
    solve(r+t, c, t);
    solve(r+2*t, c, t);
    solve(r, c+t, t);
    solve(r+t, c+t, t);
    solve(r+2*t, c+t, t);
    solve(r, c+2*t, t);
    solve(r+t, c+2*t, t);
    solve(r+2*t, c+2*t, t);
}



int main() {
    cin >> n;
    string inp;
    
    grid = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) {
        cin >> grid[i][j];
    }
    min1 = 0;
    plu1 = 0;
    zero = 0;

    solve(0, 0, n);
    cout << min1 << '\n' << zero  << '\n'<< plu1;
}
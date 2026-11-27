#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> grid;
bool ok;

void solve(int r, int c, int size) {
    ok = true;
    int color = grid[r][c];
    for (int i = 0; i < size; i++) for (int j = 0; j < size; j++) {
        if (grid[r + i][c + j] != color) { ok = false; break; }
    }
    if (ok) {
        cout << color;
        return;
    }
    cout << '(';
    solve(r, c, size / 2);
    solve(r, c + size / 2, size / 2);
    solve(r + size / 2, c, size / 2);
    solve(r + size / 2, c + size / 2, size / 2);
    cout << ')';
}



int main() {
    cin >> n;
    string inp;
    
    grid = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        cin >> inp;
        for (int j = 0; j < n; j++) {
            grid[i][j] = inp[j] - '0';
        }
    }
    solve(0, 0, n);
}
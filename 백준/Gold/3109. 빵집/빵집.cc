#include <bits/stdc++.h>
using namespace std;

int r, c, ans = 0;
vector<string> grid;
vector<vector<bool>> visited;
bool ok;

bool ingrid(int n, int m) {
    return (n >= 0 && n < r) && (m >= 0 && m < c);
}


void dfs(int x, int y) {
    if (y == c - 1) {
        
        ok = true;
        ans++; return;
    }
    for (int i = -1; i <= 1; i++) {
        int nx = x + i;
        int ny = y + 1;
        if (!ingrid(nx, ny) || visited[nx][ny] || grid[nx][ny] == 'x') continue;
        visited[nx][ny] = 1;
        dfs(nx, ny);
        if (ok) return;
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c;
    visited = vector<vector<bool>>(r, vector<bool>(c));
    int k;
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        grid.push_back(s);
    }
    
    for (int i = 0; i < r; i++) {
        ok = false;
        dfs(i, 0);
    }
    cout << ans;
}